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


    // overridden window methods
    std::string initial_window_title() const override;
    Dims initial_window_dimensions() const override;

private:
    Model model_;
    View view_;

    int rand_x_;
    int rand_y_;
    int time_elapsed_;
    int score_;

    Position displacement_;
    Position mouse_posn_;

    ge211::Sound_effect hit_sound_;
    ge211::Sound_effect miss_sound_;
};
