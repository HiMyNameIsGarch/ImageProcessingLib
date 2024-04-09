#include "../../include/imageProcessing/gammaCorrection.h"
#include <cmath>

GammaCorrection::GammaCorrection() :
    m_gamma(1) {}

GammaCorrection::GammaCorrection(double gamma) :
    m_gamma(gamma) {}

// If gamma < 1, the original image is darkened.
// If gamma > 1, the original image is lightened.
// If gamma = 1, the original image is unchanged (no-op).
void GammaCorrection::process(const Image &src, Image &dst) {
    if(m_gamma == 1) {
        std::cout << "No change in gamma." << std::endl;
        return;
    }
    for (uint i = 0; i < src.size().width(); i++) {
        for (uint j = 0; j < src.size().height(); j++) {
            uint val = pow(src.at(i, j), m_gamma);
            if(val > 255) {
                val = 255;
            } else if (val < 0) {
                val = 0;
            }
            dst.at(i, j) = val;
        }
    }
}
