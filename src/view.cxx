#include "view.hxx"
using Color = ge211::Color;


View::View(Model const& model)
        : model_(model)
        , ball_sprite{5, Color::white()} // TODO: radius should be variable
{ }

void
View::draw(ge211::Sprite_set& set)
{
    // draws each ball in the balls vector
    for (ball ball_individual: model_.get_balls()) {
        set.add_sprite(ball_sprite, ball_individual.get_ball_position());
    }
}
