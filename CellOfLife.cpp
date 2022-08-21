//
//  CellOfLife.cpp
//  GameOfLife
//
//  Created by A.Broslavsky on 06.08.2022.
//

#include "CellOfLife.hpp"

namespace CellOfLife {

    Cell::Cell(bool status)
    : _living(status), _generation(0) {}

    bool Cell::GetLiving() const {
        return _living;
    }

    void Cell::SetLiving(bool status) {
        _living = status;
    }

    int Cell::GetGeneration() const {
        return _generation;
    }

    void Cell::UpGeneration() {
        _generation++;
    }

    void Cell::NotLive() {
        _living = false;
        _generation = 0;
    }

}
