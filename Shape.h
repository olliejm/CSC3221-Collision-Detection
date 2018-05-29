//******************************************************************************
//** An abstract base class representing all the shared aspects of a shape.
//** Cannot be instantiated, derived classes must provide meaningful
//** implementations of shape comparison and print to ostream
//** File: Shape.h
//** Author: Oliver McNally
//** Student Number: 130072007
//** Email: o.j.mcnally1@newcastle.ac.uk
//** Version: 0.2.1
//******************************************************************************
#ifndef CSC3221_PROJECT_2_SHAPE_H
#define CSC3221_PROJECT_2_SHAPE_H

#include <ostream>

// Namespace for all shapes
namespace shapes {

class Shape {

public:
    Shape(double x, double y);

    // Virtual destructor for abstract class
    virtual ~Shape() = 0;

    // Allow us to print a shape when dealing with pointers to the base class
    friend std::ostream& operator<<(std::ostream&, const Shape&);

    // Pure virtual function to determine overlap of shape with another
    virtual bool overlaps(const std::shared_ptr<Shape>&) const = 0;

    // Derived must implement to allow meaningful output operator functioning
    virtual void print(std::ostream& to) const = 0;

    // Move the shape by dx,dy
    void move(double dx, double dy);

    // Return the current x and y pos of the shape
    double x_pos() const;
    double y_pos() const;

protected:
    // The x,y co-ordinates of the shape
    double x_, y_;

};

}

#endif //CSC3221_PROJECT_2_SHAPE_H
