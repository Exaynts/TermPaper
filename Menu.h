#pragma once
#include "Shape.h"
#include "Typefigure.h"
#include <fstream> // Äëÿ çàãðóçêè ôàéëà â ôóíêöèè Load()
#include <vector>

using namespace std;

class Menu {
private:
    vector<Shape*> ptype;
    int Select_Item(int) const;
protected:
    // Ñòàòè÷åñêèé óêàçàòåëü íà äàííûå, îáùèå äëÿ âñåõ ôèãóð
    static Data* data;
public:
    // Âõîä â ïðîãðàììó
    static Data* Entrance();
    // Çàãðóçèòü äàííûå ôèãóð ñ ôàéëà
    static bool Load(string& file_path);
    // Ãëàâíîå ìåíþ
    static bool Main_Menu();

    // Ñîçäàòü ôèãóðó
    static void Create_figure();
    // Âûáðàòü ôèãóðó (ïî èíäåêñó)
    static int Select_figure();
    // Èçìåíèòü ôèãóðó
    static void Change_figure(int figure_index);
    Menu(vector<Shape*> _ptype) : ptype(_ptype) {}
    Shape* Select_Type() const;
};
