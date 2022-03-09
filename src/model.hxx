#pragma once

#include <ge211.hxx>
#include "ball.hxx"
#include "crosshair.hxx"
#include <cmath> // for sqrt

using dims = ge211::Dims<int>;

using Position = ge211::Posn<int>;

class Model
{
public:
    explicit Model(int width, int height);

    // Returns the dimensions of the screen
    dims get_model_dims() const
    { return model_dims_; }

    // Returns the list of balls in play
    std::vector<ball> get_balls() const
    { return balls_; }

    // Adds ball to the list of balls
    void add_ball(ball new_ball)
    { balls_.push_back(new_ball); }

    // checks if input position resides within a ball
    // if so, deletes the ball, returns true. returns false otherwise
    bool delete_ball(Position posn, Position displacement);

    // returns Euclidean distance between two positions
    float distance(Position pos1, Position pos2)
    {
        return std::sqrt(std::pow(pos1.x - pos2.x, 2)
                       + std::pow(pos1.y - pos2.y,2));
    }

    // shifts position according to perspective shift
    Position shift_pos(Position pos, Position shift)
    {
        return {pos.x + shift.x, pos.y + shift.y};
    }

private:
    std::vector<ball> balls_; // list of all the balls in play
    dims model_dims_;



};
