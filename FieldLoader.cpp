//
//  FieldLosder.cpp
//  GameOfLife
//
//  Created by А.Broslavsky on 08.08.2022.
//

#include "FieldLoader.hpp"

#include "CellOfLife.hpp"
#include "Randomizer.hpp"
#include "ConsoleMenu.hpp"

#include <fstream>

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

namespace FieldLoaderSpace {

    using namespace std;

    FieldLoader::FieldLoader(const ConsoleMenuPtr &menu, std::string pwd)
    : _randomizer(make_shared<RandomizerSpace::Randomizer>()),
    _rows(0), _columns(0), _menu(menu), _pwd(pwd) {
        DIR * dir;
         struct dirent * de;
         
        if ( ( dir = opendir(pwd.c_str()) ) == NULL ){}
         
        while ( (de = readdir(dir)) )
             printf("%s\n", de->d_name);
         
         closedir(dir);
    }

    FieldLoader::PairMyVectors FieldLoader::LoadFromRandom() {
        LoadFieldSize();
        for (int i = 0; i < _rows; i++) {
            std::vector<CellPtr> _cells, _cells2;
            for (int j = 0; j < _columns; j++) {
                auto c = _randomizer->GetRandomBool();
                _cells.push_back(CreateCell(c));
                _cells2.push_back(CreateCell(c));
            }
            loadLine({_cells, _cells2});
        }
        return {_data, _data2};
    }

    FieldLoader::PairMyVectors FieldLoader::LoadFromFile(int number) {
        std::vector<int> line;
        
        std::ifstream in(_pwd + "txt/FieldLoadFile_" + std::to_string(number) +".txt");
        if (in.is_open()) {
            in >> _rows >> _columns;
            for (int i = 0; i < _rows; i++) {
                std::vector<CellPtr> _cells, _cells2;
                for (int j = 0, c = 0; j < _columns; j++, c = 0) {
                    in >> c;
                    _cells.push_back(CreateCell(c));
                    _cells2.push_back(CreateCell(c));
                }
                loadLine({_cells, _cells2});
            }
        }
        in.close();
        return {_data, _data2};
    }

    FieldLoader::PairMyVectors FieldLoader::LoadFromKeyboard() {
        LoadFieldSize();
        for (int i = 0; i < _rows; i++) {
            std::vector<CellPtr> _cells, _cells2;
            for (int j = 0; j < _columns; j++) {
                int c = 0;
                std::cin >> c;
                _cells.push_back(CreateCell(c));
                _cells2.push_back(CreateCell(c));
            }
            loadLine({_cells, _cells2});
        }
        return {_data, _data2};
    }

    void FieldLoader::loadLine(std::pair<VectorCellPtr, VectorCellPtr> Pair) {
        _data. push_back(Pair.first);
        _data2.push_back(Pair.second);
    }

    FieldLoader::CellPtr FieldLoader::CreateCell(int status) {
        return make_shared<CellOfLife::Cell>(status == 0 ? false : true);
    }

    void FieldLoader::LoadFieldSize() {
        auto size = _menu->GetRowsAndColumns();
        _rows = size.first;
        _columns = size.second;
    }


}
