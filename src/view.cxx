#include "view.hxx"
using Color = ge211::Color;


View::View(Model const& model)
        : model_(model)
        , ball_sprite_{5, Color::white()} // TODO: radius should be variable
        , crosshair_sprite_("crosshair.png")
        , crosshair_dims_{50, 50}
        , crosshair_posn_{(int) ((model_.get_model_dims().width / 2)
                                    - (crosshair_dims_.width / 2)),
                          (int) ((model_.get_model_dims().height / 2)
                                    - (crosshair_dims_.height/ 2))}
                                    // TODO: this is jank asf
{ }

void
View::draw(ge211::Sprite_set& set)
{
    // draws crossshair. z-value: 10
    set.add_sprite(crosshair_sprite_, crosshair_posn_, 10);

    // draws each ball in the balls vector. z-value: 1
    for (ball ball_individual: model_.get_balls()) {
        set.add_sprite(ball_sprite_, ball_individual.get_ball_position(), 1);
    }
}
