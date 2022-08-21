//
//  GameController.hpp
//  GameOfLife
//
//  Created by A.Broslavsky on 07.08.2022.
//

#ifndef GameController_hpp
#define GameController_hpp

#include <iostream>

#include <vector>

namespace CellOfLife { class Cell; }

namespace ConsoleMenuSpace { class ConsoleMenu; }

namespace ShowManagerSpace { class ShowManager; }

namespace FieldAnalyzerSpace { class FieldAnalyzer; }

namespace FieldLoaderSpace { class FieldLoader; }

namespace GameControllerSpace {

    enum class InitMethod {
        Keyboard,
        Random,
        File,
        //..
        End
    };

    class GameController {
    public:
        using CellPtr = std::shared_ptr<CellOfLife::Cell>;
        using MyVector = std::vector<std::vector<CellPtr> >;
    public:
        using ConsoleMenuPtr = std::shared_ptr<ConsoleMenuSpace::ConsoleMenu>;
        using ShowManagerPtr = std::shared_ptr<ShowManagerSpace::ShowManager>;
        using AnalyzerPtr = std::shared_ptr<FieldAnalyzerSpace::FieldAnalyzer>;
        using FieldLoaderPtr = std::shared_ptr<FieldLoaderSpace::FieldLoader>;
    public:
        GameController(std::string pwd);
    private:
        void InitFromRandom();
        void InitFromFile();
        void InitFromKeyboard();
    private:
        using PairMyVectors = std::pair<MyVector, MyVector>;
        void LoadDatasFromLoader(PairMyVectors Pair);
    public:
        void Update();
        bool IsGameOver();
    private:
        ConsoleMenuPtr _menu;
        ShowManagerPtr _showManager;
        AnalyzerPtr _analyzer;
        FieldLoaderPtr _loaderData;
    private:
        MyVector _data, _data2;
        int _rows, _columns;
        bool _gameOver;
        std::string _pwd;
    };

}

#endif /* GameController_hpp */
