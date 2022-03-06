#include "view.hxx"
using Color = ge211::Color;
int rand_x; // huhhhh
int rand_y;

View::View(Model const& model)
        : model_(model)
        , ball_sprite{5, Color::white()}
        , time_elapsed(0)
{ }

void
View::draw(ge211::Sprite_set& set)
{
    rand_x = int(rand() % 100); // TODO: see below
    rand_y = int(rand() % 100); // TODO: make this dynamically change
    // with window size

    // keeps track of time passed
    time_elapsed++;

    if (time_elapsed % 60 == 0) {
        // set.add_sprite(ball_sprite, {}); // TODO:
        // replace xy
        // with rand int x, rand int y
    }
}
