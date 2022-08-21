//
//  ConsoleMenu.cpp
//  GameOfLife
//
//  Created by A.Broslavsky on 07.08.2022.
//

#include "ConsoleMenu.hpp"

#include "GameController.hpp"

namespace ConsoleMenuSpace {

using namespace std;

    ConsoleMenu::ConsoleMenu() :
    _colorMod(false) {}

    ConsoleMenu::InitMethod ConsoleMenu::OpenMenu() {
        cout << "================== M E N U ==================" << endl << endl;
        cout << "   > ENTER 1 : Start" << endl << endl;
        cout << "   > ENTER 2 : OPEN SETTINGS" << endl << endl;
        cout << "   > ENTER 0 : Exit" << endl << endl;
        cout << "   > ENTER NUMBER : ";
        int i;
        cin >> i;
        if (i < 1 || i > 4) {
            cout << "   ...EROR" << endl << endl;
            return OpenMenu();
        } else if (i == 1)
            return SelectInit();
        else if (i == 2)
            return OpenSettings();
        return InitMethod::End;
    }

    ConsoleMenu::InitMethod ConsoleMenu::SelectInit() {
        cout << "====== Choose how to fill in the field ======" << endl;
        cout << endl;
        cout << "   > ENTER 1 : Load from file." << endl << endl;
        cout << "   > ENTER 2 : Load random." << endl << endl;
        cout << "   > ENTER 3 : Load from Keyboard." << endl << endl;
        cout << "   > ENTER 0 : Exit" << endl << endl;
        cout << "   > ENTER NUMBER : ";
        int i;
        cin >> i;
        if (i < 0 || i > 4) {
            cout << "   ...EROR" << endl << endl;
            return SelectInit();
        }
        return  i == 1 ? InitMethod::File : i == 2 ? InitMethod::Random :
                i == 3 ? InitMethod::Keyboard : InitMethod::End;
    }

    std::pair<int, int> ConsoleMenu::GetRowsAndColumns() {
        int i = 0, j = 0;
        cout << "====== Enter field size (rows and columns) ======" << endl << endl;
        cout << "   > ENTER ROWS : ";
        cin >> i;
        cout << "   > ENTER COLUMNS : ";
        cin >> j;
        return {i, j};
    }

    ConsoleMenu::InitMethod ConsoleMenu::OpenSettings() {
        cout << "============ S E T T I N G S ============" << endl << endl;
        if (_colorMod)
            cout << "   > ENTER 1 : Disabled color mode" << endl << endl;
        else
            cout << "   > ENTER 1 : Enabled color mode" << endl << endl;
        cout << "   > ENTER 2 : Open main menu" << endl << endl;
        cout << "   > ENTER 0 : Exit" << endl << endl;
        cout << "   > ENTER NUMBER : ";
        int i;
        cin >> i;
        if (i < 0 || i > 2) {
            cout << "   ...EROR" << endl << endl;
            return OpenSettings();
        } else if (i == 1) {
            _colorMod = !_colorMod;
            return OpenSettings();
        } else if (i == 2)
            return OpenMenu();
        return InitMethod::End;
    }

    int ConsoleMenu::LoadFile() {
        cout << "============ Load file ============" << endl << endl;
        cout << "   > Enter file number from 1 to 10" << endl << endl;
        cout << "   > ENTER 0 : Exit" << endl << endl;
        cout << "   > ENTER NUMBER : ";
        int i;
        cin >> i;
        if (i < 0 || i > 10) {
            cout << "   ...EROR" << endl << endl;
            return LoadFile();
        } else
            return i;
    }

}
