#include "controller.hxx"

Controller::Controller()
        : model_(500, 500) // CHANGE THIS FROM MAGIC NUMBER LATER
        , view_(model_)
        , time_elapsed_(0)
        , mouse_posn_{0,0} // TODO: change this!
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);

    /********* TODO: make this a separate method later*********
     * TODO: if ball would overlap with already existing ball, generate new
     *       random value */
    rand_x_ = int(rand() % model_.get_model_dims().width);
    rand_y_ = int(rand() % model_.get_model_dims().height);

    // keeps track of time passed
    time_elapsed_++;

    if (time_elapsed_ % 60 == 0) {
        // TODO: adds ball to playing field
        model_.add_ball(ball(5, {rand_x_, rand_y_}));

    }
}

void
Controller::on_mouse_move(Position posn) {
    // calculate displacement and displace balls by the inverse displacement

    // set mouse_posn_ to whatever the new position is
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