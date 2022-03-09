#include "view.hxx"
using Color = ge211::Color;
#include <string>
#include <iostream>


View::View(Model& model)
        : model_(model)
        , crosshair_({(int) ((model_.get_model_dims().width / 2)
                             - (50 / 2)),
                      (int) ((model_.get_model_dims().height / 2)
                             - (50 / 2))},
                     // TODO: change magic number 50 to crosshair_dims
                     //  .width/height
                     {(int) (model_.get_model_dims().width / 2),
                      (int) (model_.get_model_dims().height / 2)},
                     "crosshair.png",
                     {50, 50}) // TODO: magic number
        , ball_sprite_{5, Color::white()} // TODO: radius should be variable
        , debug_ball_sprite_{5, Color::medium_red()}
        , crosshair_sprite_("crosshair.png")
        , score_position_{10, 10}
{
    ge211::Font sans30{"sans.ttf", 30};
}

void
View::draw(ge211::Sprite_set& set, Posn displacement, int score)
{
    // draws crossshair. z-value: 10
    set.add_sprite(crosshair_sprite_, crosshair_.get_top_left_coords(),10);
    // draws score. z-value: 20
    ge211::Text_sprite::Builder current_score(sans18);
    current_score << score;
    score_sprite_.reconfigure(current_score);
    set.add_sprite(score_sprite_, score_position_);

    // draws each ball in the balls vector. z-value: 1
    for (ball ball_individual: model_.get_balls()) {
        // TODO: this is for debugging
        if (model_.distance(crosshair_.get_center_coords(), ball_individual
        .get_view_center(displacement)) < 5) {
            set.add_sprite(debug_ball_sprite_,
                           ball_individual.get_view_position(displacement),
                           2);
        }
        else {
            set.add_sprite(ball_sprite_,
                       ball_individual.get_view_position(displacement),1);
            }
    }
}



