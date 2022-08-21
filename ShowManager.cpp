//
//  ShowManager.cpp
//  GameOfLife
//
//  Created by A.Broslavsky on 06.08.2022.
//

#include "ShowManager.hpp"

#include "CellOfLife.hpp"

#include "unistd.h"

#include "termcolor.hpp"

#include <stdio.h>

namespace ShowManagerSpace {

    using namespace std;

    ShowManager::ShowManager(int colorMod)
    : _colorMod(colorMod){}

    void ShowManager::Show(const MyVector &data) {
        std::size_t rows, columns;
        rows = data.size(); columns = data[0].size();
        for (std::size_t i = 0; i < rows; i++, std::cout << '\n')
            for (std::size_t j = 0; j < columns; j++) {
                if (_colorMod) GetColor(data[i][j].get()->GetGeneration());
                std::cout << (data[i][j].get()->GetLiving() ? "*" : " ");
            }
        ShowSeparator(columns);
        usleep(200000);
    }

    void ShowManager::ShowSeparator(std::size_t size) {
        if (_colorMod) std::cout << termcolor::red;
        for (;size > 0; size--, std::cout << '-');
        std::cout << '\n';
    }

    void ShowManager::GetColor(int generation) {
        if (generation < 2)
            std::cout << termcolor::white;
        else if (generation >= 2 && generation < 4)
            std::cout << termcolor::blue;
        else if (generation >= 4 && generation < 6)
            std::cout << termcolor::green;
        else if (generation >= 6 && generation < 8)
            std::cout << termcolor::yellow;
        else
            std::cout << termcolor::red;
    }
}
