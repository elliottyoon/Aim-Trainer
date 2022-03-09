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
public:
    explicit ball(int radius, Position pos);

    // Returns ball radius
    int get_ball_radius() const
    { return ball_radius_; }

    // Returns (model) ball position (top-left corner)
    Position get_ball_position() const
    { return ball_coords_; }

    // Returns (view) ball position (top-left corner)
    Position get_view_position(Position displacement) const
    { return {ball_coords_.x - displacement.x, ball_coords_.y - displacement
    .y}; }



    // Returns the coordinates of the (viewed) center of the ball
    Position get_view_center(Position displacement) const
    { return {get_view_position(displacement).x + ball_radius_,
              get_view_position(displacement).y + ball_radius_}; }


private:
    // radius of the ball
    int ball_radius_;
    // coordinates of the ball (on the model)
    Position ball_coords_;

};


#endif //GAME_BALL_HXX
