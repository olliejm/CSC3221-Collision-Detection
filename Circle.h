//******************************************************************************
//** A class to represent a circle of radius 'radius_'
//**
//** File: Circle.h
//** Author: Oliver McNally
//** Student Number: 130072007
//** Email: o.j.mcnally1@newcastle.ac.uk
//** Version: 0.2.1
//******************************************************************************

#ifndef CSC3221_PROJECT_2_CIRCLE_H
#define CSC3221_PROJECT_2_CIRCLE_H

#include "Shape.h"

namespace shapes {

class Circle : public Shape {

public:
    explicit Circle(double x = 0, double y = 0, double radius = 1);
    Circle(const Circle&);

    ~Circle() override;

    Circle& operator=(const Circle&);

    bool operator==(const Circle&) const;
    bool operator!=(const Circle&) const;

    friend std::ostream& operator<<(std::ostream&, const Circle&);

    // Implement pure virtual functions from base
    bool overlaps(const std::shared_ptr<Shape>&) const override;
    void print(std::ostream& to) const override;

    // Return the radius of the circle
    double radius() const;

private:
    double radius_;

};

}

#endif //CSC3221_PROJECT_2_CIRCLE_H
