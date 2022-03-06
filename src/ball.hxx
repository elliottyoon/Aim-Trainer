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

    // Returns ball radius
    int get_ball_radius() const
    { return ball_radius_; }

    // Returns ball position
    Position get_ball_position() const
    { return ball_coords_; }

private:
    int ball_radius_;
    Position ball_coords_;

};


#endif //GAME_BALL_HXX
