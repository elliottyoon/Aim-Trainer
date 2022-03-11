#include "controller.hxx"
#include <iostream>

Controller::Controller()
        : model_(500, 500, 0, 5, 0) // CHANGE THIS FROM MAGIC NUMBER LATER
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
int delete_time = 60;

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set, displacement_, score_, time_elapsed_);

    // gets random coordinate for ball to be placed
    Position rand_coord = get_rand_coord();
    // keeps track of time passed
    time_elapsed_++;
    int global_lifespan = -1;


    //when mode1 is engaged, set global_lifespan = to 300, so that each ball
    // made will have an intial lifespan of 5 seconds or so, then we will
    // call increment on each ball whenever that will happen

    if(model_.get_game_mode() == 1){
        global_lifespan = 60;
        model_.delete_expired();
    } else if (model_.get_game_mode() == 2){

        if(delete_time > 0){
            model_.clear_balls();
            delete_time--;
            model_.set_active_balls(0);
        } else if(model_.check_overload(model_.get_active_balls())){
            printf("you lose");
            quit();
        }
    }

    if (time_elapsed_ % ball_freq_ == 0) {
        model_.add_ball(ball(5, {rand_coord.x, rand_coord.y}, global_lifespan));
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
    } else {
        // plays (miss) sound when ball is not clicked
        mixer().play_effect(miss_sound_);
    }
}

void
Controller::on_key(ge211::Key key)
{
    if (key == ge211::Key::code('q')) {
        quit();
    }

    if (key == ge211::Key::code('1')) {
        model_.change_game_mode(1);
    }

    if (key == ge211::Key::code('2')) {
        model_.change_game_mode(2);
    }

    if (key == ge211::Key::code('3')) {
        model_.set_max_balls(3);
    }

    if (key == ge211::Key::code('4')) {
        model_.set_max_balls(4);
    }

    if (key == ge211::Key::code('5')) {
        model_.set_max_balls(5);
    }

    if (key == ge211::Key::code('6')) {
        model_.set_max_balls(6);
    }

    if (key == ge211::Key::code('7')) {
        model_.set_max_balls(7);
    }

    if (key == ge211::Key::code('8')) {
        model_.set_max_balls(8);
    }

    if (key == ge211::Key::code('9')) {
        model_.set_max_balls(9);
    }

    if (key == ge211::Key::code('0')) {
        model_.set_max_balls(10);
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
    return model_.get_model_dims();
}