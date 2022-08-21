//
//  GameController.cpp
//  GameOfLife
//
//  Created by A.Broslavsky on 07.08.2022.
//

#include "GameController.hpp"

#include "CellOfLife.hpp"
#include "ConsoleMenu.hpp"
#include "ShowManager.hpp"
#include "FieldAnalyzer.hpp"
#include "FieldLoader.hpp"

#include <fstream>

namespace GameControllerSpace {

    using namespace std;

    GameController::GameController(std::string pwd) :
    _menu(make_shared<ConsoleMenuSpace::ConsoleMenu>()),
    _analyzer(make_shared<FieldAnalyzerSpace::FieldAnalyzer>()),
    _loaderData(make_shared<FieldLoaderSpace::FieldLoader>(_menu, pwd)),
    _gameOver(false), _pwd(pwd) {
        switch (_menu->OpenMenu()) {
            case InitMethod::File: InitFromFile();
                break;
            case InitMethod::Random: InitFromRandom();
                break;
            case InitMethod::Keyboard: InitFromKeyboard();
                break;
            default: _gameOver = true;
                break;
        }
        if (!_gameOver) {
            auto colorMode = _menu->IsColorMode();
            _showManager = make_shared<ShowManagerSpace::ShowManager>(colorMode);
            _analyzer->Set(_data, _data2);
            _showManager->Show(_data);
        }
    }
    
    void GameController::InitFromRandom() {
        LoadDatasFromLoader(_loaderData->LoadFromRandom());
    }

    void GameController::InitFromKeyboard() {
        LoadDatasFromLoader(_loaderData->LoadFromKeyboard());
    }

    void GameController::InitFromFile() {
        auto num = _menu->LoadFile();
        if (num > 0)
            LoadDatasFromLoader(_loaderData->LoadFromFile(num));
        else
            _gameOver = true;
    }

    void GameController::LoadDatasFromLoader(PairMyVectors Pair) {
        _data = Pair.first;
        _data2 = Pair.second;
        if(_data.size() == 0 && _data2.size() == 0)
            _gameOver = true;
        _rows = _loaderData->GetRows();
        _columns = _loaderData->GetColumns();
    }

    void GameController::Update() {
        _data = _analyzer->Update();
        _showManager->Show(_data);
        _gameOver = _analyzer->IsGameOver();
    }

    bool GameController::IsGameOver() {
        return _gameOver;
    }

}
