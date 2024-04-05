#ifndef GAMMACORRECTION_H
#define GAMMACORRECTION_H

#include "imageProcessing.h"

class GammaCorrection :public ImageProcessing {
private:
    double m_gamma;
public:
    GammaCorrection();
    GammaCorrection(double gamma);
    void process(const Image &src, Image &dst) override;

};

#endif
