#include "../../include/imageProcessing/convolution.h"

Convolution::Convolution(ScaleKernel scaler) :
    m_scaler(scaler) {}

void Convolution::apply_scale(Image &kernel, Matrix matrix) {
    for (uint i = 0; i < kernel.size().width(); i++) {
        for (uint j = 0; j < kernel.size().height(); j++) {
            kernel.at(i, j) = matrix[i][j];
        }
    }
}

void Convolution::kernel_scaler(int opt, Image &kernel) {
    if (opt == 1) {
        apply_scale(kernel, Convolution::IDENTITY_KERNEL);
        return;
    }
    if(opt == 2) {
        apply_scale(kernel, Convolution::MEAN_BLUR_KERNEL);
        return;
    }
    if(opt == 3) {
        apply_scale(kernel, Convolution::GAUSSIAN_BLUR_KERNEL);
        return;
    }
    if(opt == 4) {
        apply_scale(kernel, Convolution::HORIZONTAL_SOBEL_KERNEL);
        return;
    }
    if(opt == 5) {
        apply_scale(kernel, Convolution::VERTICAL_SOBEL_KERNEL);
        return;
    }
    std::cerr << "Error: Invalid option." << std::endl;
}

void Convolution::scale(int opt, Image &kernel) {
    if(m_scaler != nullptr) {
        m_scaler(opt, kernel);
    } else {
        kernel_scaler(opt, kernel);
    }
}
//
// // F = output (filtered) image ( dst )
// // K = kernel
// // I = input image ( src )
// //
// // F = K * I
// // The kernel has the shape (w, b) where w and b are odd numbers
// // w = 2k + 1
// // so k = (w - 1) / 2
// //
// // The formula for the convolution is:
// // F(x, y) = ΣΣ K(i, j) * I(x - i + k, y - j + k)
void Convolution::process(const Image &src, Image &dst) {
    if (src.size() != dst.size()) {
        std::cerr << "Error: Image sizes do not match." << std::endl;
        return;
    }
    Image kernel(Size(3,3));
    scale(5, kernel);
    for (uint i = 0; i < src.size().width(); i++) {
        for (uint j = 0; j < src.size().height(); j++) {
            int sum = 0;
            for (uint k = 0; k < kernel.size().width(); k++) {
                for (uint l = 0; l < kernel.size().height(); l++) {
                    sum += kernel.at(k, l) * src.at(i, j);
                }
            }
            dst.at(i,j) = sum;
        }
    }
}
