#pragma once
#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include "imageProcessing.h"

class Brightness : public ImageProcessing {
private:
    unsigned int m_alpha;
    int m_bias;
public:
    Brightness();
    Brightness(unsigned int gain, int bias);
    void process(const Image &src, Image &dst) override;

};

#endif
