#include "controller.hxx"
#include <iostream>

Controller::Controller()
        : model_(500, 500) // CHANGE THIS FROM MAGIC NUMBER LATER
        , view_(model_)
        , time_elapsed_(0)
        , mouse_posn_(view_.get_crosshair_center_posn())
        , displacement_{0,0}
        , ball_freq_(60)
        , score_(0)
        , hit_sound_("hitsound_soft.ogg", mixer())
        , miss_sound_("ABMiss.ogg", mixer())
{
}

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set, displacement_, score_, time_elapsed_);

    // gets random coordinate for ball to be placed
    Position rand_coord = get_rand_coord();
    // keeps track of time passed
    time_elapsed_++;

    if (time_elapsed_ % ball_freq_ == 0) {
        model_.add_ball(ball(5, {rand_coord.x, rand_coord.y}));
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
    if (model_.delete_ball(view_.get_crosshair_center_posn(), displacement_)) {
        // plays (hit) sound when ball is clicked
        mixer().play_effect(hit_sound_);
        // increments score
        score_++;
    }
    // plays (miss) sound when ball is not clicked
    mixer().play_effect(miss_sound_);
}

std::string
Controller::initial_window_title() const
{
    return "Aim Trainer";
}

Dims
Controller::initial_window_dimensions() const
{
    return model_.get_model_dims();
}