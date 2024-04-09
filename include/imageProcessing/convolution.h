#pragma once
#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include "imageProcessing.h"
#include <array>
#include "kernel_type.h"

constexpr size_t K_ROWS = 3;
constexpr size_t K_COLS = 3;

using Matrix = std::array<std::array<const int, K_COLS>, K_ROWS>;

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

    double at(int i, int j) const;
    KernelType m_kernelOpt;

public:
    Convolution(KernelType kernelOpt);

    void process(const Image &src, Image &dst) override;
};

#endif
