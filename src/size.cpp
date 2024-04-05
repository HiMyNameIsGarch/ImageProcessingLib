#include "../include/size.h"

Size::Size() {
    m_width = 0;
    m_height = 0;
    m_area = 0;
}
Size::Size(uint width, uint height) {
    m_width = width;
    m_height = height;
    m_area = width * height;
}
void Size::setWidth(uint width) {
    m_width = width;
    m_area = m_width * m_height;
}
void Size::setHeight(uint height) {
    m_height = height;
    m_area = m_width * m_height;
}
bool Size::operator==(const Size &size) const {
    return m_width == size.m_width && m_height == size.m_height;
}
bool Size::operator!=(const Size &size) const {
    return m_width != size.m_width || m_height != size.m_height;
}
bool Size::operator<(const Size &size) const {
    return m_area < size.m_area;
}
bool Size::operator<=(const Size &size) const {
    return m_area <= size.m_area;
}
bool Size::operator>(const Size &size) const {
    return m_area > size.m_area;
}
bool Size::operator>=(const Size &size) const {
    return m_area >= size.m_area;
}
