#include "model.hxx"
#include <iostream>

using Position = ge211::Posn<int>;

Model::Model(int width, int height, int gamemode)
    : model_dims_{width, height}
    , game_mode(gamemode)
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

void Model::delete_expired()
{
    //iterates through the balls looking for expired balls, if in the
    // gamemode which requires this.


    for (std::vector<ball>::iterator it = balls_.begin(); it != balls_.end();)
    {

        //increments lifespan of each ball in the game each time draw is called
        (*it).increment_lifespan();

        //checks if any of the balls should be dead and removes them, also
        // should clear the screen when switching modes as lifespan is
        // typically intialized to -1

        if((*it).get_ball_lifespan() <= 0){
            it = balls_.erase(it);
            break;
        }
        ++it;

    }
}
