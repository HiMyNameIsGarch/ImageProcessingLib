#pragma once
#ifndef TESTS_H
#define TESTS_H

void generateConvolution();

void generateGamma();

void generateBrightness();

void generateDraw();

void generateAll();


inline void generateAll() {
    generateConvolution();
    generateGamma();
    generateBrightness();
    generateDraw();
}

#endif
