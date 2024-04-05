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
            dst.at(i, j) = pow(src.at(i, j), m_gamma);
        }
    }
}
