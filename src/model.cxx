#include "model.hxx"
#include <iostream>

using Position = ge211::Posn<int>;

Model::Model(int width, int height)
    : model_dims_{width, height}
{
    menu_ = Menu();
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
            /*std::cout << "Crosshair: " << posn << "\n";
            std::cout << distance(posn, (*it).get_view_center(displacement)
            ) << "\n";
            std::cout << "Ball: " << (*it).get_view_center(displacement) <<
            "\n";*/
            ++it;
        }
    }
    return false;

}

bool
Model::select_option(Position posn, Position displacement)
{
    // iterates through options
    for (std::vector<Option>::iterator it = menu_.get_options().begin(); it
    != menu_.get_options().end();) {
        if (distance(posn, (*it).get_center((*it).get_box_pos_(),
                                            displacement)) < 5) {
            //TODO: fix magic # (5)
            std::cout << "Bool: " << (*it).is_selected() << "\n";
            (*it).set_selected(!(*it).is_selected());
            return true;
        } else {
            std::cout << "Pos: " << (*it).get_center((*it).get_box_pos_(),
                                          displacement) << "\n";
            std::cout << distance(posn, (*it).get_center((*it).get_box_pos_(),
                                                         displacement)) << "\n";
            ++it;
        }
    }
    return false;
}

/*
 *     // iterates through menu options
    for (std::vector<Option>::iterator it2 = menu_.get_options().begin(); it2 !=
    menu_.get_options().end();) {
        if (distance(posn, (*it2).get_center((*it2).get_box_pos_(),
                                             displacement)) < (*it2)
                                             .get_dimensions().width &&
                distance(posn, (*it2).get_center((*it2).get_box_pos_(),
                                                 displacement)) < (*it2)
                        .get_dimensions().height) {
            (*it2).set_selected(!(*it2).is_selected());
        }

        ++it2;
    }
 */