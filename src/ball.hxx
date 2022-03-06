//
// Created by Elliott Yoon on 3/5/22.
//

#ifndef GAME_BALL_HXX
#define GAME_BALL_HXX
#pragma once


#include <ge211.hxx>
using Position = ge211::Posn<int>;

class ball
{
    // coordinates of ball
    // size of ball
public:
    explicit ball(int radius, Position pos);

    size_t ball_radius;
    Position ball_coords;


};


#endif //GAME_BALL_HXX
