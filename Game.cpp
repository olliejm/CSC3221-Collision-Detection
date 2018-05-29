#include <iostream>
#include "GameEngine.h"

using game::GameEngine;

// Configure game setup constants
const int GRID_WIDTH    = 420;
const int GRID_HEIGHT   = 210;
const int MAX_SHAPES    = 105;

int main()
{
    // Begin
    std::cout << "\n/*---------------------BEGIN GAME---------------------*/\n";
    std::cout << std::endl;

    // Initialise game engine
    auto engine = GameEngine(GRID_WIDTH, GRID_HEIGHT, MAX_SHAPES);

    // Initialise round count
    int rounds = 1;

    // Continue until one shape remains
    while (engine.shapes_remaining() > 1) {
        // Elimination round
        std::cout << "Round:\t" << rounds << std::endl;
        engine.resolve_overlaps();
        rounds++;

        // Print the total remaining
        std::cout << "\n\tShapes remaining:\t";
        std::cout << engine.shapes_remaining() << std::endl << std::endl;

        // Advance shape positions for next round if we aren't done already
        if (engine.shapes_remaining() > 1)
            engine.advance_positions();
    }

    std::cout << "\n/*---------------------GAME ENDED---------------------*/\n";
    std::cout << std::endl;

    // Print the final shape
    std::cout << "Final shape:\n\t" << engine.first() << std::endl;

    std::cout << "\n/*----------------------------------------------------*/\n";
    std::cout << std::endl;

    // End
    return 0;
}
