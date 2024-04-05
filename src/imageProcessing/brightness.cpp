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
}
