#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller();

protected:
    void draw(ge211::Sprite_set& set) override;

private:
    Model model_;
    View view_;

    int rand_x_;
    int rand_y_;
    int time_elapsed_;
};
