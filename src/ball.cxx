//
// Created by Elliott Yoon on 3/5/22.
//

#include "ball.hxx"

using Position = ge211::Posn<int>;

ball::ball(int radius, Position pos, int id)
    : ball_radius_(radius)
    , ball_coords_(pos)
    , id_num_(id)
    {

}
