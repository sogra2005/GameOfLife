//
//  Randomizer.hpp
//  GameOfLife
//
//  Created by A.Broslavsky on 07.08.2022.
//

#ifndef Randomizer_hpp
#define Randomizer_hpp

#include <iostream>

namespace RandomizerSpace {

    class Randomizer {
    public:
        int GetRandomInt(int min, int max);
        bool GetRandomBool();
    };

}

#endif /* Randomizer_hpp */
