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
    explicit ball(int radius, Position pos, int id);

    // Returns ball radius
    int get_ball_radius() const
    { return ball_radius_; }

    // Returns (model) ball position
    Position get_ball_position() const
    { return ball_coords_; }

    // Returns (view) ball position
    Position get_view_position(Position displacement) const
    { return {ball_coords_.x - displacement.x, ball_coords_.y - displacement
    .y}; }

    // Returns ball ID number
    int get_ball_id() const
    { return id_num_; }

    // Returns ball center_coords_
    Position get_view_center(Position displacement) const
    { return {get_view_position(displacement).x + ball_radius_,
              get_view_position(displacement).y + ball_radius_}; }


private:
    int ball_radius_;
    int id_num_;
    Position ball_coords_;

};


#endif //GAME_BALL_HXX
