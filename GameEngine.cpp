#include <iostream>
#include <cmath>
#include <random>
#include "GameEngine.h"

namespace game {

using shapes::Square;
using shapes::Circle;

// Create a game with the given parameters
// Constant value max_shift_ will be determined from them
GameEngine::GameEngine(
        const int grid_width,
        const int grid_height,
        const int max_shapes)
        :
        grid_width_(grid_width),
        grid_height_(grid_height),
        // Don't shift by more than 10% of the smallest dimension
        max_shift_(std::min(grid_width, grid_height)*0.1)
{
    // Don't make shapes bigger than roughly 20% of the smallest dimension
    const double max_scale = std::min(grid_width, grid_height)*0.2;

    // Make each shape max_shapes_ times
    for (int i = 0; i<max_shapes; i++) {
        // First a random square
        double size = random(0, max_scale);
        auto square =
                std::make_shared<Square>(
                        // Make sure it's within the grid
                        random(0, grid_width_-size),
                        random(0, grid_height_-size),
                        size
                );
        // Insert it
        shapes_.push_back(square);

        // Now a random circle
        double radius = random(0, max_scale);
        auto circle =
                std::make_shared<Circle>(
                        // Make sure it's within the grid
                        random(0+radius, grid_width_-radius),
                        random(0+radius, grid_height_-radius),
                        radius
                );
        // Insert it
        shapes_.push_back(circle);
    }
}

// Destructor simply clears the array, smart pointers should do the rest
GameEngine::~GameEngine()
{
    shapes_.clear();
}
// Return first element in vector
const Shape& GameEngine::first() const
{
    return *shapes_.front();
}

// Return current size of vector (no. shapes on grid)
int GameEngine::shapes_remaining() const
{
    return static_cast<int>(shapes_.size());
}

// Generate a random number between the given values
double GameEngine::random(double min, double max)
{
    // Random device to seed Mersenne twister
    std::random_device rd;
    // Mersenne twister (seed it with rd)
    std::mt19937 mt(rd());
    // Get a real distribution between min and max
    std::uniform_real_distribution<double> dist(min, max);
    // Return a random number from the distribution using Mersenne twister
    return dist(mt);
}

// Resolve all overlaps on the current grid, printing to std:cout
void GameEngine::resolve_overlaps()
{
    // Declare iterators
    auto it = shapes_.begin();
    auto end = shapes_.end();

    // While end of the vector isn't reached
    while (std::distance(it, end)>1) {
        // Declare shape for capture
        auto shape = *it;
        // Define lambda condition
        auto condition = [shape](const std::shared_ptr<Shape>& other) {
          // See if the shape overlaps with the one being checked
          bool overlaps = shape->overlaps(other);

          // If it does, print details to our output
          if (overlaps) {
              std::cout << "\tColliding:\n\t\t" << *shape;
              std::cout << "\n\t\t" << *other;
              std::cout << "\n\tRemoving:\n\t\t" << *other << std::endl;
          }

          // Return whether or not an overlap occurred
          return overlaps;
        };

        // Identify the overlapping shapes
        end = std::remove_if(++it, end, condition);
    }

    // Remove the overlapping shapes
    shapes_.erase(end, shapes_.end());
}

void GameEngine::advance_positions()
{
    // For every shape
    for (auto& shape : shapes_) {
        // Declare dx and dy for movement
        double dx, dy;

        // Until the movement would be legal, test random shifts
        do {
            dx = random(-max_shift_, max_shift_);
            dy = random(-max_shift_, max_shift_);
        }
        while (!within_grid(shape, dx, dy));

        // Apply the movement
        shape->move(dx, dy);
    }
}

bool GameEngine::within_grid(const std::shared_ptr<Shape>& shape, const double dx, const double dy)
{
    // The potential new x and y co-ordinates
    double x, y;

    // If we have a square, determine if the movement is legal
    if (auto square = std::dynamic_pointer_cast<Square>(shape)) {
        x = square->x_pos()+dx+square->size();
        y = square->y_pos()+dy+square->size();
        return x>0 && x<grid_width_ && y>0 && y<grid_height_;
    }

    // If we have a circle, determine if the movement is legal
    if (auto circle = std::dynamic_pointer_cast<Circle>(shape)) {
        x = circle->x_pos()+dx+circle->radius();
        y = circle->y_pos()+dy+circle->radius();
        return x>0 && x<grid_width_ && y>0 && y<grid_height_;
    }

    // It's an unknown type and we don't know how to deal with it
    throw std::bad_cast();
}

}
