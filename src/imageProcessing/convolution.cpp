#include "../../include/imageProcessing/convolution.h"

Convolution::Convolution(ScaleKernel scaler) :
    m_scaler(scaler) {}

double Convolution::at(short opt, int i, int j) {
    if(opt == 1) {
        return Convolution::IDENTITY_KERNEL[i][j];
    }
    if(opt == 2) {
        return 1/9.0 * Convolution::MEAN_BLUR_KERNEL[i][j];
    }
    if(opt == 3) {
        return 1/16.0 * Convolution::GAUSSIAN_BLUR_KERNEL[i][j];
    }
    if(opt == 4) {
        return Convolution::HORIZONTAL_SOBEL_KERNEL[i][j];
    }
    if(opt == 5) {
        return Convolution::VERTICAL_SOBEL_KERNEL[i][j];
    }
    if(opt == 6) {
        return Convolution::MEAN_BLUR_KERNEL[i][j];
    }
    std::cerr << "Error: Invalid option." << std::endl;
    return INVALID_KERNEL;
}

void Convolution::kernel_scaler(short opt) {
    if(opt > MAX_OPT || opt < 1) {
        std::cerr << "Error: Invalid option." << std::endl;
        return;
    }
    scaler_opt = opt;
}

void Convolution::set_scaler(short opt) {
    if(m_scaler != nullptr) {
        m_scaler(opt);
    } else {
        kernel_scaler(opt);
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
    // if(scaler_opt > MAX_OPT || scaler_opt < 1) {
    //     std::cerr << "Error: Invalid option." << std::endl;
    //     return;
    // }

    uint ca[3][3];
    for (uint i = 0; i < src.size().height(); i++) {
        for (uint j = 0; j < src.size().width(); j++) {
            uint w = src.size().width() - 1;
            uint h = src.size().height() - 1;

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
                    double conv = Convolution::at(6, a, b);
                    double m = ca[a][b];
                    double product = m * conv;
                    sum += product;
                }
            }
            if(sum < 0)
                sum = 0;

            if (sum > 255)
                sum = 255;

            dst.at(i,j) = (uint)sum;

        }
}
}
