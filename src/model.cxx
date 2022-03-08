#include "model.hxx"
#include <iostream>

using Position = ge211::Posn<int>;

Model::Model(int width, int height)
    : model_dims_{width, height}
{

}

bool
Model::delete_ball(Position posn, Position displacement)
{
    // iterates through balls.
    for (std::vector<ball>::iterator it = balls_.begin(); it != balls_.end();) {
        // if position is within the circumference of ball
        if (distance(posn, (*it).get_view_center(displacement))
        < (*it).get_ball_radius()) {
            // deletes ball
            it = balls_.erase(it);
            return true;
        }
        else {
            std::cout << "Crosshair: " << posn << "\n";
            std::cout << distance(posn, (*it).get_view_center(displacement)
            ) << "\n";
            std::cout << "Ball: " << (*it).get_view_center(displacement) <<
            "\n";
            ++it;
        }
    }
    return false;

}
