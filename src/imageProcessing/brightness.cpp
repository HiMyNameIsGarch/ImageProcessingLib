#include "../../include/imageProcessing/brightness.h"

Brightness::Brightness() :
    m_alpha(1), m_bias(0) {}

Brightness::Brightness(unsigned int gain, int bias) {
    if (gain < 1) {
        m_alpha = 1;
    }
    else {
        m_alpha = gain;
    }
    m_bias = bias;
}

// dst(x, y) = α⋅src(x, y) + β
// α = m_alpha
// β = m_bias
void Brightness::process(const Image &src, Image &dst) {
    if (src.size() != dst.size()) {
        std::cerr << "Error: Image sizes do not match." << std::endl;
        return;
    }
    if(m_alpha == 1 && m_bias == 0) {
        std::cout << "No change in brightness." << std::endl;
        return;
    }
    for (uint i = 0; i < src.size().width(); i++) {
        for (uint j = 0; j < src.size().height(); j++) {
            dst.at(i, j) = m_alpha * src.at(i, j) + m_bias;
        }
    }
}
