#include "controller.hxx"

Controller::Controller()
        : model_(10, 10) // CHANGE THIS FROM MAGIC NUMBER LATER
        , view_(model_)
        , time_elapsed_(0)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);

    /********* make this a separate method later**********/
    rand_x_ = int(rand() % 100); // TODO: see below
    rand_y_ = int(rand() % 100); // TODO: make this dynamically change
    // with window size

    // keeps track of time passed
    time_elapsed_++;

    if (time_elapsed_ % 60 == 0) {
        // TODO: adds ball to playing field
        model_.add_ball(ball(5, {rand_x_, rand_y_}));

        // set.add_sprite(ball_sprite, {}); // TODO:
        // replace xy
        // with rand int x, rand int y
    }
}
