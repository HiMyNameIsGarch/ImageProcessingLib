#include "../../include/imageProcessing/convolution.h"

static const int IDENTITY_KERNEL[ROWS][COLS] = {
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0}
};
static const int MEAN_BLUR_KERNEL[ROWS][COLS] = {
    {1, 1, 1},
    {1, 1, 1},
    {1, 1, 1}
};
static const int GAUSSIAN_BLUR_KERNEL[ROWS][COLS] = {
    {1, 2, 1},
    {2, 4, 2},
    {1, 2, 1}
};
static const int HORIZONTAL_SOBEL_KERNEL[ROWS][COLS] = {
    {1, 2, 1},
    {0, 0, 0},
    {-1, -2, -1}
};
static const int VERTICAL_SOBEL_KERNEL[ROWS][COLS] = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
};

Convolution::Convolution(ScaleKernel scaler) :
    m_scaler(scaler) {}

void Convolution::scale() {
    if(m_scaler != nullptr) {
        m_scaler();
    }
}

// F = output (filtered) image ( dst )
// K = kernel
// I = input image ( src )
//
// F = K * I
// The kernel has the shape (w, b) where w and b are odd numbers
// w = 2k + 1
// so k = (w - 1) / 2
//
// The formula for the convolution is:
// F(x, y) = ΣΣ K(i, j) * I(x - i + k, y - j + k)
void Convolution::process(const Image &src, Image &dst) {
    scale();
}
