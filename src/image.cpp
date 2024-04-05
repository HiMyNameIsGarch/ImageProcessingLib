#include "../include/image.h"

Image::Image() {
    m_size = Size();
    m_data = nullptr;
}
Image::Image(const Size &size) {
}

Image::Image(const Image &other) {
}

Image::~Image() {
}

Image &Image::operator=(const Image &other) {
    return *this;
}

bool Image::load(std::string imagePath) {
    return false;
}
bool Image::save(std::string imagePath) const {
    return false;
}

Image Image::operator+(const Image &i) {
    return Image();
}

Image Image::operator-(const Image &i) {
    return Image();
}

Image Image::operator*(double s) {
    return Image();
}

bool Image::getROI(Image &roiImg, Rectangle roiRect) {
    return false;
}
// maybe not
bool Image::getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    return false;
}

bool Image::isEmpty() const {
    return false;
}

// maybe not
unsigned char &Image::at(unsigned int x, unsigned int y) {
    return m_data[y][x];
}
unsigned char &Image::at(Point pt) {
    return m_data[pt.y()][pt.x()];
}

unsigned char *Image::row(int y) {
    return m_data[y];
}

void Image::release() {
}

std::ostream &operator<<(std::ostream &os, const Image &dt) {
    return os;
}
std::istream &operator>>(std::istream &is, Image &dt) {
    return is;
}

Image Image::zeros(unsigned int width, unsigned int height) {
    return Image();
}
Image Image::ones(unsigned int width, unsigned int height) {
    return Image();
}
