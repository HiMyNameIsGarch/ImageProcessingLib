#include "../../include/imageProcessing/convolution.h"

Convolution::Convolution(KernelType kt) {
    m_kernelOpt = kt;
}

double Convolution::at(int i, int j) const {
    if(m_kernelOpt == KernelType::identity) {
        return Convolution::IDENTITY_KERNEL[i][j];
    }
    if(m_kernelOpt == KernelType::meanBlur) {
        return 1/9.0 * Convolution::MEAN_BLUR_KERNEL[i][j];
    }
    if(m_kernelOpt == KernelType::gaussianBlur) {
        return 1/16.0 * Convolution::GAUSSIAN_BLUR_KERNEL[i][j];
    }
    if(m_kernelOpt == KernelType::horizontalSobel) {
        return Convolution::HORIZONTAL_SOBEL_KERNEL[i][j];
    }
    if(m_kernelOpt == KernelType::verticalSobel) {
        return Convolution::VERTICAL_SOBEL_KERNEL[i][j];
    }
    if(m_kernelOpt == KernelType::box) {
        return Convolution::MEAN_BLUR_KERNEL[i][j];
    }
    std::cerr << "Error: Invalid option." << std::endl;
    return 1;
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
    if (src.size() != dst.size()) {
        std::cerr << "Error: Image sizes do not match." << std::endl;
        return;
    }

    uint ca[3][3];
    for (uint i = 0; i < src.size().height(); i++) {
        for (uint j = 0; j < src.size().width(); j++) {

            // Get the width and height of the image
            uint w = src.size().width() - 1;
            uint h = src.size().height() - 1;

            // Get the center pixel
            uint center = src.at(i, j);
            ca[1][1] = center;

            // // mindfuckery ifs
            if (i == 0) { // up
                ca[0][1] = center;
            } else { //
                ca[0][1] = src.at(i - 1, j);
            }
            if ( j == 0 ) { // left
                ca[1][0] = center;
            } else {
                ca[1][0] = src.at(i, j - 1);
            }
            if (i == h) { // down
                ca[2][1] = center;
            } else {
                ca[2][1] = src.at(i + 1, j);
            }
            if (j == w) { // right
                ca[1][2] = center;
            } else {
                ca[1][2] = src.at(i, j + 1);
            }

            if ( j == 0 && i == 0 ) { // left up
                ca[0][0] = center;
            } else if ( i == 0 ) {
                ca[0][0] = ca[1][0];
            } else if (j == 0) {
                ca[0][0] = ca[0][1];
            } else {
                ca[0][0] = src.at(i-1, j-1);
            }

            if (j == w && i == 0) // right up
                ca[0][2] = center;
            else if (j == w)
                ca[0][2] = ca[0][1];
            else if (i == 0)
                ca[0][2] = ca[1][2];
            else
                ca[0][2] = src.at(i-1,j+1);

            if ( i == h && j == 0 )  // left down
                ca[2][0] = center;
            else if (i == h)
                ca[2][0] = ca[1][0];
            else if (j == 0)
                ca[2][0] = ca[2][1];
            else
                ca[2][0] = src.at(i + 1, j - 1);


            if (i == h && j == w) // right down
                ca[2][2] = center;
            else if (i == h)
                ca[2][2] = ca[1][2];
            else if (j == w)
                ca[2][2] = ca[2][1];
            else
                ca[2][2] = src.at(i+1, j+1);

            double sum = 0;
            for(uint a = 0; a < K_ROWS; a++) {
                for(uint b = 0; b < K_COLS; b++) {
                    double conv = this->at(a, b);
                    double m = ca[a][b];
                    double product = m * conv;
                    sum += product;
                }
            }
            if(sum < 0)
                sum = 0;

            if (sum > 255)
                sum = 255;

            dst.at(i,j) = sum;
        }
    }
}
