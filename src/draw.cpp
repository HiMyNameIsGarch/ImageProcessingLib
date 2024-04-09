#include "../include/draw.h"

void drawCircle(Image& img, Point center, int radius, unsigned char color) {
    // Check if the circle is contained in the image
    if (center.x() - radius < 0 || center.x() + radius >= img.size().width() ||
        center.y() - radius < 0 || center.y() + radius >= img.size().height()) {
      std::cerr << "Circle is out of the image" << std::endl;
      return;
    }

    // Draw the circle
    int x = radius;
    int y = 0;
    int err = 0;
    while (x >= y) {
        img.at(center.x() + x, center.y() + y) = color;
        img.at(center.x() + y, center.y() + x) = color;
        img.at(center.x() - y, center.y() + x) = color;
        img.at(center.x() - x, center.y() + y) = color;
        img.at(center.x() - x, center.y() - y) = color;
        img.at(center.x() - y, center.y() - x) = color;
        img.at(center.x() + y, center.y() - x) = color;
        img.at(center.x() + x, center.y() - y) = color;
        if (err <= 0) {
            y += 1;
            err += 2*y + 1;
        }
        if (err > 0) {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

void drawLine(Image &img, Point p1, Point p2, unsigned char color) {
    // check if the line is contained in the image
    if (p1.x() < 0 || p1.x() >= img.size().width() || p1.y() < 0 || p1.y() >= img.size().height()) {
        std::cerr << "Point p1 is out of the image" << std::endl;
        return;
    }
    if (p2.x() < 0 || p2.x() >= img.size().width() || p2.y() < 0 || p2.y() >= img.size().height()) {
        std::cerr << "Point p2 is out of the image" << std::endl;
        return;
    }
    // Draw the line from p1 to p2
    int dx = p2.x() - p1.x();
    int dy = p2.y() - p1.y();
    int steps = std::max(std::abs(dx), std::abs(dy));
    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;
    float x = p1.x();
    float y = p1.y();
    for (int i = 0; i < steps; i++) {
        img.at(x, y) = color;
        x += xInc;
        y += yInc;
    }
}

void drawRectangle(Image &img, Rectangle r, unsigned char color) {
    // Check if the rectangle is contained in the image
    if (r.topLeft().x() < 0 || r.topLeft().x() >= img.size().width() ||
        r.topLeft().y() < 0 || r.topLeft().y() >= img.size().height()) {
      std::cerr << "Rectangle is out of the image" << std::endl;
      return;
    }

    // Prepare the point to draw
    Point tl = r.topLeft();
    Point tr = Point(r.topLeft().x() + r.size().width(), r.topLeft().y());
    Point bl = Point(r.topLeft().x(), r.topLeft().y() + r.size().height());
    Point br = Point(r.topLeft().x() + r.size().width(), r.topLeft().y() + r.size().height());

    // Draw the rectangle using the drawLine function
    drawLine(img, tl, tr, color);
    drawLine(img, tr, br, color);
    drawLine(img, br, bl, color);
    drawLine(img, bl, tl, color);
}

void drawRectangle(Image &img, Point tl, Point br, unsigned char color) {
    // Check if the rectangle is contained in the image
    if (tl.x() < 0 || tl.x() >= img.size().width() ||
        tl.y() < 0 || tl.y() >= img.size().height()) {
      std::cerr << "Point tl is out of the image" << std::endl;
      return;
    }
    if (br.x() < 0 || br.x() >= img.size().width() ||
        br.y() < 0 || br.y() >= img.size().height()) {
      std::cerr << "Point br is out of the image" << std::endl;
      return;
    }

    // Prepare the point to draw
    Point tr = Point(br.x(), tl.y());
    Point bl = Point(tl.x(), br.y());

    // Draw the rectangle using the drawLine function
    drawLine(img, tl, tr, color);
    drawLine(img, tr, br, color);
    drawLine(img, br, bl, color);
    drawLine(img, bl, tl, color);
}
