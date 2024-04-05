#pragma once
#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include "imageProcessing.h"

constexpr size_t ROWS = 3;
constexpr size_t COLS = 3;

using ScaleKernel = void(*)();

using Matrix = const std::array<std::array<const int, COLS>, ROWS>;

class Convolution : public ImageProcessing {

private:
    static const Matrix IDENTITY_KERNEL;
    static const Matrix MEAN_BLUR_KERNEL;
    static const Matrix GAUSSIAN_BLUR_KERNEL;
    static const Matrix HORIZONTAL_SOBEL_KERNEL;
    static const Matrix VERTICAL_SOBEL_KERNEL;

    ScaleKernel m_scaler;

public:
    Convolution(ScaleKernel scaler);

    void process(const Image &src, Image &dst) override;

    void scale();

};

#endif
