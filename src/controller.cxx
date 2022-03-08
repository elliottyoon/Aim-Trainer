#include "controller.hxx"
#include <iostream>

Controller::Controller()
        : model_(500, 500) // CHANGE THIS FROM MAGIC NUMBER LATER
        , view_(model_)
        , time_elapsed_(0)
        , mouse_posn_(view_.get_crosshair_pos())
        , displacement_{0,0}
        , id_count_(0)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set, displacement_);

    /********* TODO: make this a separate method later*********
     *  */
    rand_x_ = int(rand() % model_.get_model_dims().width);
    rand_y_ = int(rand() % model_.get_model_dims().height);
    // keeps track of time passed
    time_elapsed_++;

    if (time_elapsed_ % 60 == 0) {
        model_.add_ball(ball(5, {rand_x_, rand_y_}, id_count_));
        id_count_++; // new id number for new ball
    }
}

void
Controller::on_mouse_move(Position posn)
{
    // calculate displacement and displace balls by the inverse displacement
    displacement_ += {posn.x - mouse_posn_.x, posn.y - mouse_posn_.y};

    // set mouse_posn_ to whatever the new position is
    mouse_posn_ = posn;
}

void
Controller::on_mouse_down(ge211::Mouse_button button, Position posn)
{
    // TODO: delete ball from model
    if (model_.delete_ball(view_.get_crosshair_pos(), displacement_)) {
        std::cout << "true\n";
        // TODO: play sound
        // TODO: increment score
    }
}

std::string
Controller::initial_window_title() const
{
    return "Aim Trainer";
}

Dims
Controller::initial_window_dimensions() const
{
    return model_.get_model_dims(); // TODO: Change magic number
}