//
//  FieldAnalyzer.cpp
//  GameOfLife
//
//  Created by A.Broslavsky on 07.08.2022.
//

#include "FieldAnalyzer.hpp"
#include "CellOfLife.hpp"

namespace FieldAnalyzerSpace {

    FieldAnalyzer::FieldAnalyzer()
    : _gameOver(false) {}

    void FieldAnalyzer::Set(const MyVector data, const MyVector data2) {
        _data = data;
        _data2 = data2;
        _rows = data.size();
        if (_rows > 0) _columns = data[0].size();
    }

    FieldAnalyzer::MyVector FieldAnalyzer::Update() {
        if (_data.size() > 0) {
            CenterAnalysis();
            SwapData();
            return _data;
        }
        return _nullData;
    }

    void FieldAnalyzer::CenterAnalysis() {
        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _columns; j++) {
                int count = 0;
                for (int k = i - 1; k <= i + 1; k++)
                    for (int m = j - 1; m <= j + 1; m++) {
                        if (!(k == i && m == j))
                            count += IsLiving(k, m);
                    }
                if (count < 2 || count > 3) {
                    _data2[i][j]->NotLive();
                } else if (count == 3 || count == 2) {
                    if (count == 3) _data2[i][j]->SetLiving(true);
                    _data2[i][j]->UpGeneration();
                }
            }
    }

    std::size_t FieldAnalyzer::IndexConverter(int i, std::size_t max) {
        (i < 0) ? i += max : (i >= max) ? i -= max : i = i;
        return (std::size_t) i;
    }

    int FieldAnalyzer::IsLiving(int k, int m) {
        return _data[IndexConverter(k, _rows)]
                    [IndexConverter(m, _columns)]->GetLiving() ? 1: 0;
    }

    void FieldAnalyzer::SwapData() {
        int count = 0;
        for (std::size_t i = 0; i < _rows; i++)
            for (std::size_t j = 0; j < _columns; j++) {
                if (_data[i][j]->GetLiving() == _data2[i][j]->GetLiving())
                    count++;
                _data[i][j]->SetLiving(_data2[i][j]->GetLiving());
                _data[i][j]->SetGeneration(_data2[i][j]->GetGeneration());
            }
        if (count == _rows * _columns)
            _gameOver = true;
    }
}
