//******************************************************************************
//** Class to allow the instantiation and setup of a shape removal game,
//** and to then provide methods to perform the game logic in order to
//** advance it, and additionally offers methods to provide useful
//** information to the caller.
//** File: GameEngine.h
//** Author: Oliver McNally
//** Student Number: 130072007
//** Email: o.j.mcnally1@newcastle.ac.uk
//** Version: 0.2.3
//******************************************************************************
#ifndef CSC3221_PROJECT_2_ENGINE_H
#define CSC3221_PROJECT_2_ENGINE_H

#include <list>
#include "Square.h"
#include "Circle.h"

// Namespace for anything game engine related
namespace game {

using shapes::Shape;

class GameEngine {

public:
    // Initialise a game with the given parameters
    explicit GameEngine(
            int grid_width = 420,
            int grid_height = 210,
            int max_shapes = 105
    );

    // Destructor
    ~GameEngine();

    // Return first element of vector
    const Shape& first() const;

    // Return the number of shapes stored in the vector
    int shapes_remaining() const;

    // Return a random number between min and max
    static double random(double min, double max);

    // Resolve overlaps on the current grid
    void resolve_overlaps();

    // Advance positions of all shapes on the grid
    void advance_positions();

protected:
    // Game constants initialised in constructor
    const double grid_width_, grid_height_, max_shift_;

    // List to hold pointers to our shapes
    std::list<std::shared_ptr<Shape>> shapes_;

    // Determine if a given movement to a given shape is legal for the grid
    bool within_grid(const std::shared_ptr<Shape>&, double dx, double dy);

};

}

#endif //CSC3221_PROJECT_2_ENGINE_H
