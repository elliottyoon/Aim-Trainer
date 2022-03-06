#pragma once

#include <ge211.hxx>
#include "ball.hxx"
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

private:
    std::vector<ball> balls_; // list of all the balls in play
    dims model_dims_;



};
