//
//  Randomizer.cpp
//  GameOfLife
//
//  Created by A.Broslavsky on 07.08.2022.
//

#include "Randomizer.hpp"

#include <random>

namespace RandomizerSpace {

    bool Randomizer::GetRandomBool() {
        return GetRandomInt(0, 1) == 0 ? false : true;
    }

    int Randomizer::GetRandomInt(int min, int max) {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distribution(min, max);
        int x = distribution(generator);
        return x;
    }

}
