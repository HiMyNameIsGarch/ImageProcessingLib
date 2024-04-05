#pragma once
#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include "../image.h"

class ImageProcessing {
public:
    virtual void process(const Image &src, Image &dst);
};

#endif
