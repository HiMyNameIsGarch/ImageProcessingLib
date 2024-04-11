#pragma once
#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#define setPixel(val) val > 255 ? 255 : val < 0 ? 0 : val

#include "../image.h"

class ImageProcessing {
public:
    virtual void process(const Image &src, Image &dst);
};

#endif
