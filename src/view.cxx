#include "view.hxx"
using Color = ge211::Color;
int rand_x; // huhhhh
int rand_y;

View::View(Model const& model)
        : model_(model)
        , ball_sprite{5, Color::white()}
{ }

void
View::draw(ge211::Sprite_set& set)
{

}
