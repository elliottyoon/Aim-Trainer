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
        , option_sprite_{{16, 16}, Color::white()}
        , option_sprite_active_{{15, 15}, Color::medium_red()}
        , debug_ball_sprite_{5, Color::medium_red()}
        , crosshair_sprite_("crosshair.png")
        , score_position_{10, 10}
        , time_position_{10, 40}
{
    ge211::Font sans30{"sans.ttf", 30};
}

void
View::draw(ge211::Sprite_set& set, Posn displacement, int score, int
time_elapsed)
{
    // draws crossshair. z-value: 10
    set.add_sprite(crosshair_sprite_, crosshair_.get_top_left_coords(),10);
    // draws score. z-value: 10
    ge211::Text_sprite::Builder current_score(sans18);
    current_score << "Score: " << score;
    score_sprite_.reconfigure(current_score);
    set.add_sprite(score_sprite_, score_position_, 10);
    // draws time elapsed. z-value: 10
    ge211::Text_sprite::Builder current_time(sans18);
    current_time << "Time: " << time_elapsed / 60;
    time_sprite_.reconfigure(current_time);
    set.add_sprite(time_sprite_, time_position_, 10);

    // draws the menu options
    for (Option option : model_.get_options()) {
        if (option.get_name() == "Reflex") {
            ge211::Text_sprite::Builder option_text1(sans18);
            option_text1 << option.get_name();
            mode1_text_sprite.reconfigure(option_text1);
            set.add_sprite(mode1_text_sprite, option.get_pos
            (option.get_text_pos_(), displacement),
                           15);
        } else {
            ge211::Text_sprite::Builder option_text2(sans18);
            option_text2 << option.get_name();
            mode2_text_sprite.reconfigure(option_text2);
            set.add_sprite(mode2_text_sprite, option.get_pos
            (option.get_text_pos_(), displacement), 15);
        }

        // add option sprite
        if (option.is_selected()) {
            set.add_sprite(option_sprite_active_, option.get_pos
            (option.get_box_pos_(), displacement),
                           20);
        } else {
            set.add_sprite(option_sprite_, option.get_pos(option
            .get_box_pos_(), displacement), 20);
        }

        if (model_.distance(crosshair_.get_center_coords(), option.get_center
        (option.get_box_pos_(), displacement)) < 8) {
            set.add_sprite(option_sprite_active_,
                           option.get_pos(option.get_box_pos_(), displacement),
                           25);
        }
    }

    // draws each ball in the balls vector. z-value: 1
    for (ball ball_individual: model_.get_balls()) {
        // TODO: this is for debugging
        if (model_.distance(crosshair_.get_center_coords(), ball_individual
        .get_view_center(displacement)) < 5) {
            set.add_sprite(debug_ball_sprite_,
                           ball_individual.get_view_position(displacement),
                           2);
        } else {
            set.add_sprite(ball_sprite_,
                       ball_individual.get_view_position(displacement),1);
        }
    }
}



