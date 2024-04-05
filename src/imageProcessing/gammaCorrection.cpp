#include "../../include/imageProcessing/gammaCorrection.h"

GammaCorrection::GammaCorrection() :
    m_gamma(1) {}

GammaCorrection::GammaCorrection(double gamma) :
    m_gamma(gamma) {}

// If gamma < 1, the original image is darkened.
// If gamma > 1, the original image is lightened.
// If gamma = 1, the original image is unchanged (no-op).
void GammaCorrection::process(const Image &src, Image &dst) {
}
