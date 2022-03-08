#include "model.hxx"
#include <iostream>

using Position = ge211::Posn<int>;

Model::Model(int width, int height)
    : model_dims_{width, height}
{

}

bool
Model::delete_ball(Position posn, Position displacment)
{
    // iterates through balls.
    for (std::vector<ball>::iterator it = balls_.begin(); it != balls_.end();) {
        // if position is within the circumference of ball
        if (distance(posn, (*it).get_ball_position())
        <= (*it).get_ball_radius()) {
            // deletes ball
            it = balls_.erase(it);
            return true;
        }
        else {
            std::cout << (*it).get_ball_position() << "\n";
            ++it;
        }
    }
    return false;

}
