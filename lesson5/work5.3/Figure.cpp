#include "Figure.h"
#include <iostream>

Figure::Figure(std::string n, int s) : name(n), sides_count(s) {}

std::string Figure::get_name() const {
    return name;
}

int Figure::get_sides_count() const {
    return sides_count;
}