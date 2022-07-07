//
// Created by Elliott Yoon on 3/8/22.
//

#ifndef GAME_MENU_HXX
#define GAME_MENU_HXX
#pragma once

#include <ge211.hxx>

using Position = ge211::Posn<int>;
using Dims = ge211::Dims<int>;

class Menu
{
public:
    explicit Menu();
private:
    // top-left coordinate of menu box
    Position coords_;

};


#endif //GAME_MENU_HXX
