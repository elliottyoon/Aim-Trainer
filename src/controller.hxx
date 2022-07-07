#pragma once

#include "model.hxx"
#include "view.hxx"
#include <ge211.hxx>

using Dims = ge211::Dims<int>;

class Controller : public ge211::Abstract_game
{
public:
    Controller();

protected:
    void draw(ge211::Sprite_set& set) override;
    //  - on_mouse_move for mouse tracking
    //  - on_mouse_down for the whole aim trainer thingy
    void on_mouse_move(Position) override;
    void on_mouse_down(ge211::Mouse_button button, Position) override;
    void on_key(ge211::Key) override;


    // overridden window methods
    std::string initial_window_title() const override;
    Dims initial_window_dimensions() const override;

private:
    Model model_;
    View view_;
    int time_elapsed_;
    Position mouse_posn_;
    Position displacement_;
    int ball_freq_; // how many 1/60th seconds in between balls being placed
    int score_;



    ge211::Sound_effect hit_sound_;
    ge211::Sound_effect miss_sound_;

    // gets random x and y coordinate.
    // TODO: keep balls from spawning under menu screen
    Position get_rand_coord()
    { return {int(rand() % model_.get_model_dims().width),
              int(rand() % model_.get_model_dims().height)}; }
};
