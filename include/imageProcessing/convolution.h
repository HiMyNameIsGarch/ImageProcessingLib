#pragma once
#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include "imageProcessing.h"
#include <array>

constexpr size_t ROWS = 3;
constexpr size_t COLS = 3;

using ScaleKernel = void(*)(int opt, Image &kernel);

using Matrix = const std::array<std::array<const int, COLS>, ROWS>;

class Convolution : public ImageProcessing {

private:
    constexpr static const Matrix IDENTITY_KERNEL = {{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    }};
    constexpr static const Matrix MEAN_BLUR_KERNEL = {{
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    }};
    constexpr static const Matrix GAUSSIAN_BLUR_KERNEL = {{
        {1, 2, 1},
        {2, 4, 2},
        {1, 2, 1}
    }};
    constexpr static const Matrix HORIZONTAL_SOBEL_KERNEL {{
        {1, 2, 1},
        {0, 0, 0},
        {-1, -2, -1}
    }};
    constexpr static const Matrix VERTICAL_SOBEL_KERNEL = {{
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    }};

    ScaleKernel m_scaler;

    void apply_scale(Image &kernel, const Matrix m);

    void kernel_scaler(int opt, Image &img);

public:
    Convolution(ScaleKernel scaler);

    void process(const Image &src, Image &dst) override;

    void scale(int opt, Image &kernel);

};

#endif
