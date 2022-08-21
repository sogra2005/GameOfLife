//
//  ConsoleMenu.hpp
//  GameOfLife
//
//  Created by A.Broslavsky on 07.08.2022.
//

#ifndef ConsoleMenu_hpp
#define ConsoleMenu_hpp

#include <iostream>

#include "GameController.hpp"

namespace ConsoleMenuSpace {

    class ConsoleMenu {
    public:
        using InitMethod = GameControllerSpace::InitMethod;
    public:
        ConsoleMenu();
    public:
        InitMethod OpenMenu();
        InitMethod SelectInit();
        InitMethod OpenSettings();
        std::pair<int, int> GetRowsAndColumns();
        bool IsColorMode() const { return _colorMod; }
        int LoadFile();
    private:
        bool _colorMod;
    };

}

#endif /* ConsoleMenu_hpp */
