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
    void on_mouse_move(Position) override;

    // overridden window methods
    std::string initial_window_title() const override;
    Dims initial_window_dimensions() const override;

private:
    Model model_;
    View view_;

    int rand_x_;
    int rand_y_;
    int time_elapsed_;
    Position mouse_posn_;
};
