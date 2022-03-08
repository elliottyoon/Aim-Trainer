#include "view.hxx"
using Color = ge211::Color;
#include <string>
#include <iostream>


View::View(Model& model)
        : model_(model)
        , ball_sprite_{5, Color::white()} // TODO: radius should be variable
        , debug_ball_sprite_{5, Color::medium_red()}
        , crosshair_sprite_("crosshair.png")
        , crosshair_dims_{50, 50}
        , sans30{"sans.ttf", 30}
        , crosshair_center_posn_{(int) (model_.get_model_dims().width / 2),
                                 (int) (model_.get_model_dims().height / 2)}
        , crosshair_posn_{(int) ((model_.get_model_dims().width / 2)
                                    - (crosshair_dims_.width / 2)),
                          (int) ((model_.get_model_dims().height / 2)
                                    - (crosshair_dims_.height/ 2))}
                                    // TODO: this is jank asf


{
    ge211::Font sans30{"sans.ttf", 30};
}

void
View::draw(ge211::Sprite_set& set, Posn displacement)
{

    // draws crossshair. z-value: 10
    set.add_sprite(crosshair_sprite_, crosshair_posn_,10);

    // draws each ball in the balls vector. z-value: 1
    for (ball ball_individual: model_.get_balls()) {
        // TODO: this is for debugging
        if (model_.distance(crosshair_center_posn_, ball_individual
        .get_view_center(displacement)) < 5) {
            set.add_sprite(debug_ball_sprite_,
                           ball_individual.get_view_position(displacement),
                           2);
        }
        else {
            set.add_sprite(ball_sprite_,
                       ball_individual.get_view_position(displacement),1);

            // TODO: adds position text next to ball




            }
    }

}
