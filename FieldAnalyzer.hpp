//
//  FieldAnalyzer.hpp
//  GameOfLife
//
//  Created by А.Broslavsky on 07.08.2022.
//

#ifndef FieldAnalyzer_hpp
#define FieldAnalyzer_hpp

#include <iostream>
#include <vector>

namespace CellOfLife { class Cell; }

namespace FieldAnalyzerSpace {

    class FieldAnalyzer {
    public:
        using CellPtr = std::shared_ptr<CellOfLife::Cell>;
        using MyVector = std::vector<std::vector<CellPtr> >;
    public:
        FieldAnalyzer();
    public:
        void Set(const MyVector data, const MyVector data2);
        MyVector Update();
        bool IsGameOver() const { return _gameOver; }
    private:
        void CenterAnalysis();
        void SwapData();
        std::size_t IndexConverter(int i, std::size_t max);
        int IsLiving(int k, int m);
    private:
        MyVector _data, _data2, _nullData;
        std::size_t _rows, _columns;
        bool _gameOver;
    };

}

#endif /* FieldAnalyzer_hpp */
