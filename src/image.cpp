#include "../include/image.h"
#include <cstring>
#include <fstream>
#include <limits>

#define MAX_CHAR 255
#define MAGIC_NUMBER "P2"
#define PGM_EXT "pgm"
#define PGM_COMMENT '#'
#define EXTENTION_LENGTH 3

// Default constructor
// Initialize the image with an empty size
// and set the data pointer to nullptr
Image::Image() {
    m_size = Size();
    m_data = nullptr;
}

// Constructor with width and height
// Just init the whole array
// and allocate memory for the data
Image::Image(unsigned int width, unsigned int height) {
    m_size = Size(width, height);
    m_data = new unsigned char *[height];
    for (unsigned int i = 0; i < height; ++i) {
        m_data[i] = new unsigned char[width];
    }
}


// Constructor with a size ( same as the upper constructor )
// Initialize the image with the specified size
// and allocate memory for the data
Image::Image(const Size &size) {
    m_size = size;
    m_data = new unsigned char *[size.height()];
    for (unsigned int i = 0; i < size.height(); ++i) {
        m_data[i] = new unsigned char[size.width()];
    }
}

// Copy constructor
// Copy the size and the data from the other image
// Allocate memory for the data and copy the data
// from the other image
Image::Image(const Image &other) {
    if (m_size != other.m_size) // if the size is different release the memory
        this->release();
    m_size = other.m_size;
    m_data = new unsigned char *[m_size.height()];
    for(uint i = 0; i < m_size.height(); ++i) {
        m_data[i] = new unsigned char[m_size.width()];
        for(uint j = 0; j < m_size.width(); ++j) {
            m_data[i][j] = other.m_data[i][j];
        }
    }
}

// Release the memory
// Deallocate the memory for the data
void Image::release() {
    // Release the memory
    if(this->isEmpty()) {
        return;
    }
    for (unsigned int i = 0; i < m_size.height(); ++i) {
            delete[] m_data[i];
    }
    delete [] m_data;
}

// Destructor
Image::~Image() {
    release();
}

// Assignment operator
// Copy the size and the data from the other image
Image &Image::operator=(const Image &other) {
    if(this == &other) {
        return *this;
    }
    // Release the memory
    release();
    m_size = other.m_size;

    // Allocate memory for the data
    m_data = new unsigned char *[m_size.height()];
    for(uint i = 0; i < m_size.height(); ++i) {
        m_data[i] = new unsigned char[m_size.width()];
        // Copy the data
        memcpy(m_data[i], other.m_data[i], m_size.width() * sizeof(unsigned char));
    }
    return *this;
}

// Load an image from a file
// Return true if the image was loaded successfully
// Return false if the image could not be loaded
bool Image::load(std::string imagePath) {
    std::string extension = imagePath.substr(imagePath.length() - EXTENTION_LENGTH);
    if (extension != PGM_EXT) {
        std::cerr << "Error: Invalid file extension!" << std::endl;
        return false;
    }

    std::ifstream file(imagePath);
    if (!file.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return false;
    }

    // Get the first line that must contain magic number
    std::string magicNumber;
    std::getline(file, magicNumber);
    if (magicNumber != MAGIC_NUMBER) {
        std::cerr << "Error: Invalid magic number!" << std::endl;
        return false;
    }

    // Ignore comments
    while (file.peek() == PGM_COMMENT) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Get the size of the image
    uint width, height;
    file >> width >> height;

    // Get the maximum value of the image
    uint maxVal;
    file >> maxVal;
    m_size = Size(width, height);

    // Check for comments
    m_data = new unsigned char *[height];
    for (uint i = 0; i < height; i++) {
        m_data[i] = new unsigned char [width];
        for (uint j = 0; j < width; j++) {
            // convert the value to an unsigned char
            uint d;
            file >> d;
            if(d > maxVal) {
                d = maxVal;
            }
            m_data[i][j] = d;
        }
    }

    file.close();
    return true;
}

// // Save the image to a file
// // Return true if the image was saved successfully
// // Return false if the image could not be saved
// // The image format is determined by the file extension
bool Image::save(std::string imagePath) const {
    std::string extension = imagePath.substr(imagePath.length() - EXTENTION_LENGTH);
    if (extension != PGM_EXT) {
        std::cerr << "Error: Invalid file extension!" << std::endl;
        std::cerr << "Got: " << extension << " Expected: " << PGM_EXT << std::endl;
        return false;
    }

    std::ofstream file(imagePath, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        std::cerr << "The file may not exists or the path is invalid" << std::endl;
        std::cerr << "Please check the path and try again" << std::endl;
        std::cerr << "The path: " << imagePath << std::endl;
        return false;
    }

    // Write the magic number
    file << MAGIC_NUMBER << std::endl;

    // Write a dummy comment
    file << "# Image: " << imagePath << "  saved" << std::endl;

    // Write the size of the image
    file << m_size.width() << " " << m_size.height() << std::endl;

    // Write the maximum value of the image
    file << MAX_CHAR << std::endl;

    // Write the data
    for (uint i = 0; i < m_size.height(); i++) {
        for (uint j = 0; j < m_size.width(); j++) {
            file << static_cast<int>(m_data[i][j]) << " ";
        }
        file << std::endl;
    }
    std::cout << "Image saved successfully!" << std::endl;
    file.close();
    return true;
}


// // Pixel-wise addition of two images
// // The two images must have the same size otherwise the operation will fail
// // (exception thrown)
Image Image::operator+(const Image &other) {
    if(m_size != other.size()) {
        throw std::invalid_argument("The two images must have the same size");
    }
    Image result = Image(m_size);
    for(uint i = 0; i < m_size.height(); i++) {
        for(uint j = 0; j < m_size.width(); j++) {
            uint op = m_data[i][j] + other.m_data[i][j];
            if (op > MAX_CHAR) {
                op = MAX_CHAR;
            }
            result.at(i, j) = op;
        }
    }
    return result;
}

// Pixel-wise subtraction of two images
// The two images must have the same size otherwise the operation will fail
// (exception thrown)
Image Image::operator-(const Image &other) {
    if(m_size != other.size()) {
        throw std::invalid_argument("The two images must have the same size");
    }
    Image result = Image(m_size);
    for(uint i = 0; i < m_size.height(); i++) {
        for(uint j = 0; j < m_size.width(); j++) {
            uint op =  m_data[i][j] - other.m_data[i][j];
            if (op < 0)
                op = 0;
            result.at(i, j) = op;
        }
    }
    return result;
}

// Scalar multiplication of a pixel
// Multiply each pixel value by a scalar value
// Return the result as a new image
Image Image::operator*(double s) {
    Image result = Image(m_size);
    for(uint i = 0; i < m_size.height(); i++) {
        for(uint j = 0; j < m_size.width(); j++) {
            uint n = m_data[i][j];
            n *= s;
            if (n > MAX_CHAR) {
                n = MAX_CHAR;
            }
            result.at(i, j) = static_cast<unsigned char>(n);
        }
    }
    return result;
}

// Get a region of interest (ROI) from the image
// Return true if the ROI was successfully extracted
// Return false if the ROI is invalid
// The ROI is invalid when the size of the ROI is 0 or greater than the size of the image
// also when the top left corner of the ROI is outside the image
bool Image::getROI(Image &roiImg, Rectangle roiRect) {
    // TODO test the function
    if (roiRect.size().area() == 0 || roiRect.size().area() > m_size.area()) {
        return false;
    }
    if (roiRect.size().width() > m_size.width() || roiRect.size().height() > m_size.height()){
        return false;
    }

    roiImg.m_size = roiRect.size();
    roiImg.m_data = new unsigned char*[roiImg.size().height()];
    for(uint i = 0; i < roiImg.size().height(); i++) {
        roiImg.m_data[i] = new unsigned char[roiImg.size().width()];
    }
    for(uint i = 0; i < roiImg.size().height(); i++) {
        for(uint j = 0; j < roiImg.size().width(); j++) {
            roiImg.at(i, j) = at(roiRect.topLeft().x() + i, roiRect.topLeft().y() + j);
        }
    }
    return true;
}

// maybe not
// Literally the same thing as the previous function
// Just the input is in a different format
bool Image::getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    if (width == 0 || height == 0 || width > m_size.width() || height > m_size.height()) {
        return false;
    }
    if (x + width > m_size.width() || y + height > m_size.height()) {
        return false;
    }
    roiImg.m_size = Size(width, height);
    roiImg.m_data = new unsigned char*[roiImg.size().height()];
    for(uint i = 0; i < roiImg.size().height(); i++) {
        roiImg.m_data[i] = new unsigned char[roiImg.size().width()];
    }
    for(uint i = 0; i < roiImg.size().height(); i++) {
        for(uint j = 0; j < roiImg.size().width(); j++) {
            roiImg.at(i, j) = at(x + i, y + j);
        }
    }
    return false;
}

// Check if the image is empty
bool Image::isEmpty() const {
    return m_size.area() == 0 || m_data == nullptr;
}

// Access a pixel value at a specific location using a Point object
unsigned char &Image::at(Point pt) {
    return m_data[pt.x()][pt.y()];
}
// maybe not
unsigned char &Image::at(unsigned int x, unsigned int y) const {
    return m_data[x][y];
}

// Get the whole row of the image
unsigned char *Image::row(int y) const {
    return m_data[y];
}

// Overload the stream operators
// Print the image size and the data
std::ostream &operator<<(std::ostream &os, const Image &dt) {
    // TODO
    // Check valgrind for errors
    if(dt.isEmpty()) {
        os << "Empty image" << std::endl;
        return os;
    }
    os << "Image(" << dt.m_size.width() << ", " << dt.m_size.height() << ")" << std::endl;
    for(uint i = 0; i < dt.m_size.height(); ++i) {
        for(uint j = 0; j < dt.m_size.width(); ++j) {
            uint n = dt.m_data[i][j];
            if(n)
                os << n << " ";
        }
        os << std::endl;
    }
    return os;
}

// Read the image size and the data
std::istream &operator>>(std::istream &is, Image &dt) {
    uint width, height;
    is >> width >> height;
    dt.m_size.setWidth(width);
    dt.m_size.setHeight(height);
    for(uint i = 0; i < dt.m_size.height(); ++i) {
        for(uint j = 0; j<dt.m_size.width(); ++j) {
            is >> dt.m_data[i][j];
        }
    }
    return is;
}

// Fill in the whole array with a specific value
// Return an image with the specified size and filled with the specified value
// The image is allocated on the heap
Image Image::fill_data(const Size &size, unsigned char value) {
    Image img = Image(size);
    for (unsigned int i = 0; i < size.height(); ++i) {
        for (unsigned int j = 0; j < size.width(); ++j) {
            img.at(i, j) = value;
        }
    }
    return img;
}
//
// Create an image filled with zeros
// Using the static fill_data method
Image Image::zeros(unsigned int width, unsigned int height) {
    return Image::fill_data(Size(width, height), 0);
}

// Create an image filled with ones
// Using the static fill_data method
Image Image::ones(unsigned int width, unsigned int height) {
    return Image::fill_data(Size(width, height), MAX_CHAR);
}
