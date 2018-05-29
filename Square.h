//******************************************************************************
//** A class to represent a square of side length 'size_'
//**
//** File: Square.h
//** Author: Oliver McNally
//** Student Number: 130072007
//** Email: o.j.mcnally1@newcastle.ac.uk
//** Version: 0.2.1
//******************************************************************************

#ifndef CSC3221_PROJECT_2_SQUARE_H
#define CSC3221_PROJECT_2_SQUARE_H

#include "Shape.h"

namespace shapes {

class Square : public Shape {

public:
    explicit Square(double x = 0, double y = 0, double size = 1);
    Square(const Square&);

    ~Square() override;

    Square& operator=(const Square&);

    bool operator==(const Square&) const;
    bool operator!=(const Square&) const;

    friend std::ostream& operator<<(std::ostream&, const Square&);

    // Implement pure virtual functions from base
    bool overlaps(const std::shared_ptr<Shape>&) const override;
    void print(std::ostream& to) const override;

    // Return size of the square
    double size() const;

private:
    double size_;

};

}

#endif //CSC3221_PROJECT_2_SQUARE_H
