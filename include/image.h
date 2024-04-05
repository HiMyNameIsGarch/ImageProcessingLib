#pragma once
#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include "rectangle.h"
#include "size.h"

class Image {
private:
    unsigned char** m_data;
    Size m_size;

public:
    Image();
    Image(const Size &size);

    // Rule of three
    Image(const Image &other);
    ~Image();
    Image& operator=(const Image &other);

    // Load and save
    bool load(std::string imagePath);
    bool save(std::string imagePath) const;

    // Operations
    // Pixel-wise addition and subtraction of two images
    // The two images must have the same size otherwise the operation will fail
    // (exception thrown)
    Image operator+(const Image &i);
    Image operator-(const Image &i);

    // Scalar multiplication of a pixel
    Image operator*(double s);

    // ROI - Region of Interest
    // Access a pixel value at a specific location
    bool getROI(Image &roiImg, Rectangle roiRect);
    bool getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int
                width, unsigned int height);

    // Getters
    bool isEmpty() const;
    Size size() const { return m_size; };

    // Acces or modify a pixel value at a specific location
    unsigned char& at(unsigned int x, unsigned int y);
    unsigned char& at(Point pt);

    // Returns a pointer to the beginning of a specified row in the image data
    // Can be used for row-wise operations
    unsigned char* row(int y);

    void release();

    // Overloads for stream operators
    friend std::ostream& operator<<(std::ostream& os, const Image& dt);
    friend std::istream& operator>>(std::istream& is, Image& dt);

    // Static
    // Create an image filled with zeros or ones
    static Image zeros(unsigned int width, unsigned int height);
    static Image ones(unsigned int width, unsigned int height);

};
#endif
