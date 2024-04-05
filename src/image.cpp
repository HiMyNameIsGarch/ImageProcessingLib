#include "../include/image.h"
#include <cstring>

// Default constructor
// Initialize the image with an empty size
// and set the data pointer to nullptr
Image::Image() {
    m_size = Size();
    m_data = nullptr;
}
// Constructor with a size
// Initialize the image with the specified size
// and allocate memory for the data
Image::Image(const Size &size) {
    m_size = size;
    m_data = new unsigned char *[size.height()];
    for (unsigned int i = 0; i < size.height(); i++) {
        m_data[i] = new unsigned char[size.width()];
    }
}

// Copy constructor
// Copy the size and the data from the other image
// Allocate memory for the data and copy the data
// from the other image
Image::Image(const Image &other) {
    m_size = other.m_size;
    for(uint i = 0; i<m_size.height(); i++) {
        for(uint j = 0; j<m_size.width(); j++) {
            m_data[i][j] = other.m_data[i][j];
        }
    }
}

// Release the memory
// Deallocate the memory for the data
void Image::release() {
    // Release the memory
    for (unsigned int i = 0; i < m_size.height(); i++) {
        delete[] m_data[i];
        // m_data[i] = nullptr;
    }
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
    if(this->isEmpty()) {
        m_size = other.m_size;
        m_data = new unsigned char *[m_size.height()];
        for (unsigned int i = 0; i < m_size.height(); i++) {
            m_data[i] = new unsigned char[m_size.width()];
        }
    }
    if (this != &other) {
        if((*this).size().area() != other.size().area()) {
            release();
            m_size = other.m_size;
            m_data = new unsigned char *[m_size.height()];
            for (unsigned int i = 0; i < m_size.height(); i++) {
                m_data[i] = new unsigned char[m_size.width()];
            }
        } else {
            m_size = other.m_size;
            for (uint i = 0; i < m_size.height(); i++) {
                delete[] this->m_data[i];
                this->m_data[i] = new unsigned char[other.size().area()];
                memcpy(this->m_data[i], other.m_data[i], static_cast<size_t>(other.size().area()));
            }
        }
    }
    return *this;
}

// // Load an image from a file
// // Return true if the image was loaded successfully
// // Return false if the image could not be loaded
// bool Image::load(std::string imagePath) {
//     return false;
// }
//
// // Save the image to a file
// // Return true if the image was saved successfully
// // Return false if the image could not be saved
// // The image format is determined by the file extension
// bool Image::save(std::string imagePath) const {
//     return false;
// }
//
// // Pixel-wise addition and subtraction of two images
// // The two images must have the same size otherwise the operation will fail
// // (exception thrown)
Image Image::operator+(const Image &i) {

    return Image();
}

Image Image::operator-(const Image &i) {
    return Image();
}

Image Image::operator*(double s) {
    return Image();
}
//
// bool Image::getROI(Image &roiImg, Rectangle roiRect) {
//     // TODO
//     return false;
// }
// // maybe not
// bool Image::getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
//     // TODO
//     return false;
// }

// Check if the image is empty
// Return true if the image is empty
bool Image::isEmpty() const {
    return m_size.area() == 0 || m_data[0] == nullptr;
}

// Access a pixel value at a specific location using a Point object
unsigned char &Image::at(Point pt) {
    return m_data[pt.y()][pt.x()];
}
// maybe not
unsigned char &Image::at(unsigned int x, unsigned int y) {
    return m_data[y][x];
}

// Get the whole row of the image
unsigned char *Image::row(int y) {
    return m_data[y];
}

// Overload the stream operators
// Print the image size and the data
std::ostream &operator<<(std::ostream &os, const Image &dt) {
    if(dt.isEmpty()) {
        os << "Empty image\n";
        return os;
    }
    os << "Image(" << dt.m_size.width() << ", " << dt.m_size.height() << ")\n" ;
    for(uint i = 0; i < dt.m_size.height(); i++) {
        for(uint j = 0; j<dt.m_size.width(); j++) {
            uint n = dt.m_data[i][j];
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
    for(uint i = 0; i < dt.m_size.height(); i++) {
        for(uint j = 0; j<dt.m_size.width(); j++) {
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
    for (unsigned int i = 0; i < size.height(); i++) {
        for (unsigned int j = 0; j < size.width(); j++) {
            img.at(j, i) = value;
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
    return Image::fill_data(Size(width, height), 1);
}
