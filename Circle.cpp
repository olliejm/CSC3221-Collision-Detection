#include "Circle.h"
#include "CollisionManager.h"

namespace shapes {

Circle::Circle(double x, double y, double radius)
        :Shape(x, y), radius_(radius) { }

Circle::Circle(const Circle& copy)
        :Shape(copy.x_, copy.y_), radius_(copy.radius_) { }

Circle::~Circle() = default;

Circle& Circle::operator=(const Circle& rhs)
{
    x_ = rhs.x_;
    y_ = rhs.y_;
    radius_ = rhs.radius_;
    return *this;
}

bool Circle::operator==(const Circle& rhs) const
{
    return (x_ == rhs.x_) && (y_ == rhs.y_) && (radius_ == rhs.radius_);
}

bool Circle::operator!=(const Circle& rhs) const
{
    return !(*this==rhs);
}

std::ostream& operator<<(std::ostream& os, const Circle& circle)
{
    os << "Circle(x:" << circle.x_
       << ", y:" << circle.y_
       << ", radius:" << circle.radius_ << ")";
    return os;
}

using collisions::CollisionManager;
// Send self and rhs to collision manager for evaluation
bool Circle::overlaps(const std::shared_ptr<Shape>& rhs) const
{
    return CollisionManager::collides(*this, rhs);
}

// Define print operation for base class
void Circle::print(std::ostream& to) const
{
    to << *this;
}

double Circle::radius() const
{
    return radius_;
}

}
