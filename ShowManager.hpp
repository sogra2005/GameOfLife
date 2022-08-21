//
//  ShowManager.hpp
//  GameOfLife
//
//  Created by A.Broslavsky on 06.08.2022.
//

#ifndef ShowManager_hpp
#define ShowManager_hpp

#include <iostream>
#include <vector>

namespace CellOfLife { class Cell; }

namespace ShowManagerSpace {

    class ShowManager {
    public:
        using CellPtr = std::shared_ptr<CellOfLife::Cell>;
        using MyVector = std::vector<std::vector<CellPtr> >;
    public:
        ShowManager(int colorMod);
    public:
        void Show(const MyVector &data);
    private:
        void ShowSeparator(std::size_t size);
    private:
        void GetColor(int generation);
    private:
        bool _colorMod;
    };

}

#endif /* ShowManager_hpp */
