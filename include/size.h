#pragma once
#ifndef SIZE_H
#define SIZE_H

typedef unsigned int uint;

class Size {

private:
    uint m_width;
    uint m_height;
    uint m_area;

public:
    Size();
    Size(uint width, uint height);

    // Getters
    uint width() const { return m_width; };
    uint height() const { return m_height; };
    uint area() const { return m_area; };

    // Setters
    void setWidth(uint width);
    void setHeight(uint height);

    // Operators
    bool operator==(const Size &size) const;
    bool operator!=(const Size &size) const;

    bool operator<(const Size &size) const;
    bool operator<=(const Size &size) const;

    bool operator>(const Size &size) const;
    bool operator>=(const Size &size) const;

};

#endif
