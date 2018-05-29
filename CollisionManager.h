//******************************************************************************
//** Class providing static methods to compute whether or not an overlap
//** occurs between two shapes, and will also determine the true type of a
//** passed pointer to the base class
//** File: CollisionManager.h
//** Author: Oliver McNally
//** Student Number: 130072007
//** Email: o.j.mcnally1@newcastle.ac.uk
//** Version: 0.2.2
//******************************************************************************

#ifndef CSC3221_PROJECT_2_OVERLAPMANAGER_H
#define CSC3221_PROJECT_2_OVERLAPMANAGER_H

#include "Square.h"
#include "Circle.h"

// Namespace for anything collision related
namespace collisions {

using shapes::Shape;
using shapes::Square;
using shapes::Circle;

class CollisionManager {

public:
    // Determine the type of a pointer to base before sending for calculation
    static bool collides(const Square&, const std::shared_ptr<Shape>&);
    static bool collides(const Circle&, const std::shared_ptr<Shape>&);

    // Calculate a square-square, circle-circle, or circle-square collision
    static bool collides(const Square&, const Square&);
    static bool collides(const Circle&, const Circle&);
    static bool collides(const Circle&, const Square&);

    // Helper method to limit a value p to within min and max range
    static double clamp(double p, double min, double max);

};

}

#endif //CSC3221_PROJECT_2_OVERLAPMANAGER_H
