#include "Shape.h"

namespace shapes {

Shape::Shape(double x, double y)
        :x_(x), y_(y) { }

Shape::~Shape() = default;

// Call the print method of the derived class, output to os and return
std::ostream& operator<<(std::ostream& os, const Shape& rhs)
{
    rhs.print(os);
    return os;
}

// Add the movement to the current position
void Shape::move(double dx, double dy)
{
    x_+=dx;
    y_+=dy;
}

double Shape::x_pos() const
{
    return x_;
}

double Shape::y_pos() const
{
    return y_;
}

}
