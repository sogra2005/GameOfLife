//
//  FieldLoader.hpp
//  GameOfLife
//
//  Created by А.Broslavsky on 08.08.2022.
//

#ifndef FieldLoader_hpp
#define FieldLoader_hpp

#include <iostream>
#include <vector>

namespace RandomizerSpace { class Randomizer; }

namespace ConsoleMenuSpace { class ConsoleMenu; }

namespace CellOfLife { class Cell; }

namespace FieldLoaderSpace {

    class FieldLoader {
    public:
        using CellPtr = std::shared_ptr<CellOfLife::Cell>;
        using MyVector = std::vector<std::vector<CellPtr> >;
    public:
        using RandomizerPtr = std::shared_ptr<RandomizerSpace::Randomizer>;
        using ConsoleMenuPtr = std::shared_ptr<ConsoleMenuSpace::ConsoleMenu>;
    public:
        FieldLoader(const ConsoleMenuPtr &menu, std::string pwd);
    public:
        using PairMyVectors = std::pair<MyVector, MyVector>;
        PairMyVectors LoadFromRandom();
        PairMyVectors LoadFromFile(int number);
        PairMyVectors LoadFromKeyboard();
    public:
        int GetRows() const { return _rows; }
        int GetColumns() const { return _columns; }
    private:
        CellPtr CreateCell(int status);
    private:
        void LoadFieldSize();
    private:
        using VectorCellPtr = std::vector<CellPtr>;
        void loadLine(std::pair<VectorCellPtr, VectorCellPtr> Pair);
    private:
        ConsoleMenuPtr _menu;
        RandomizerPtr _randomizer;
    private:
        MyVector _data, _data2;
        int _rows, _columns;
        std::string _pwd;
    };

}

#endif /* FieldLoader_hpp */
