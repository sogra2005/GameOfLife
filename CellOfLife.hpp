//
//  CellOfLife.hpp
//  GameOfLife
//
//  Created by A.Broslavsky on 06.08.2022.
//

#ifndef CellOfLife_hpp
#define CellOfLife_hpp

#include <iostream>

namespace CellOfLife {

    class Cell {
    public:
        Cell(bool status);
    public:
        bool GetLiving() const;
        void SetLiving(bool status);
        int GetGeneration() const;
        void SetGeneration(int val) { _generation = val; }
        void UpGeneration();
        void NotLive();
    private:
        bool _living;
        int _generation;
    };

}

#endif /* CellOfLife_hpp */
