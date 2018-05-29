#include <cmath>
#include "CollisionManager.h"

namespace collisions {

// Direct a square-shape* collision
bool CollisionManager::collides(
        const Square& lhs,
        const std::shared_ptr<Shape>& rhs)
{
    // If we successfully cast rhs to square, perform square-square comparison
    if (auto square = std::dynamic_pointer_cast<Square>(rhs))
        return collides(lhs, *square);
    // If we successfully cast rhs to circle, perform circle-square comparison
    if (auto circle = std::dynamic_pointer_cast<Circle>(rhs))
        return collides(*circle, lhs);

    // Else there is no implementation yet for the given shape
    throw std::bad_cast();
}

// Direct a circle-shape* collision
bool CollisionManager::collides(
        const Circle& lhs,
        const std::shared_ptr<Shape>& rhs)
{
    // If we successfully cast rhs to square, perform circle-square comparison
    if (auto square = std::dynamic_pointer_cast<Square>(rhs))
        return collides(lhs, *square);
    // If we successfully cast rhs to circle, perform circle-circle comparison
    if (auto circle = std::dynamic_pointer_cast<Circle>(rhs))
        return collides(lhs, *circle);

    // Else there is no implementation yet for the given shape
    //TODO throw an exception instead?
    return false;
}

// Calculate a square-square collision
bool CollisionManager::collides(const Square& lhs, const Square& rhs)
{
    // If either corner clears the other, there's no collision
    return !(
            lhs.x_pos()+lhs.size()<rhs.x_pos() ||
                    lhs.x_pos()>rhs.x_pos()+rhs.size() ||
                    lhs.y_pos()+lhs.size()<rhs.y_pos() ||
                    lhs.y_pos()>rhs.y_pos()+rhs.size()
    );
}

// Calculate a circle-circle collision
bool CollisionManager::collides(const Circle& lhs, const Circle& rhs)
{
    // Determine if the distance between the centers is less than both radii
    return (pow(lhs.x_pos()-rhs.x_pos(), 2)+pow(lhs.y_pos()-rhs.y_pos(), 2))
            <=pow(lhs.radius()+rhs.radius(), 2);
}

// Calculate a square-circle collision
bool CollisionManager::collides(const Circle& lhs, const Square& rhs)
{
    // Find closest point on square to the circle
    double closest_x = clamp(lhs.x_pos(), rhs.x_pos(), rhs.x_pos()+rhs.size());
    double closest_y = clamp(lhs.y_pos(), rhs.y_pos(), rhs.y_pos()+rhs.size());

    // See if the point is closer than radius distance from the circle center
    // Use squared values to avoid slower sqrt calculations
    return pow(lhs.x_pos()-closest_x, 2)+pow(lhs.y_pos()-closest_y, 2)
            <=pow(lhs.radius(), 2);
}

// Clamp function to restrict value to given range
double CollisionManager::clamp(double p, const double min, const double max)
{
    if (p<min) p = min;
    else if (p>max) p = max;
    return p;
}

}
