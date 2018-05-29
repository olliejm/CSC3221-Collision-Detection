#include "Square.h"
#include "CollisionManager.h"

namespace shapes {

Square::Square(double x, double y, double size)
        :Shape(x, y), size_(size) { }

Square::Square(const Square& copy)
        :Shape(copy.x_, copy.y_), size_(copy.size_) { }

Square::~Square() = default;

Square& Square::operator=(const Square& rhs)
{
    x_ = rhs.x_;
    y_ = rhs.y_;
    size_ = rhs.size_;
    return *this;
}

bool Square::operator==(const Square& rhs) const
{
    return (x_ == rhs.x_) && (y_ == rhs.y_) && (size_ == rhs.size_);
}

bool Square::operator!=(const Square& rhs) const
{
    return !(*this==rhs);
}

std::ostream& operator<<(std::ostream& os, const Square& square)
{
    os << "Square(x:" << square.x_
       << ", y:" << square.y_
       << ", size:" << square.size_ << ")";
    return os;
}

using collisions::CollisionManager;
// Send self and rhs to collision manager for evaluation
bool Square::overlaps(const std::shared_ptr<Shape>& rhs) const
{
    return CollisionManager::collides(*this, rhs);
}

// Define print operation for base class
void Square::print(std::ostream& to) const
{
    to << *this;
}

double Square::size() const
{
    return size_;
}

}
