//
//  main.cpp
//  GameOfLife
//
//  Created by A.Broslavsky on 06.08.2022.
//

#include <iostream>
#include <vector>

#include "GameController.hpp"

#include <stdio.h>
namespace GameControllerSpace { class GameController; }

int main(int argc, char *argv[]) {
    
    std::string pwd = argv[0];
    
    auto pos = pwd.find_last_of('/');
    if (pos != std::string::npos)
        pwd.erase(pos, std::numeric_limits<std::string::size_type>::max());
    
    GameControllerSpace::GameController gameController(pwd + "/");
    
    bool gameOver = false;
    
    while (!gameOver) {
        gameOver = gameController.IsGameOver();
        if (!gameOver) gameController.Update();
    }
    
    return 0;
}
