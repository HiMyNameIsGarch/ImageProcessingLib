#pragma once
#ifndef KERNEL_TYPE_H
#define KERNEL_TYPE_H

enum KernelType {
    identity,
    meanBlur,
    box,
    gaussianBlur,
    horizontalSobel,
    verticalSobel
};

#endif
