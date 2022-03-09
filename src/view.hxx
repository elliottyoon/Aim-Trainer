#pragma once

#include "model.hxx"
using Posn = ge211::Posn<int>;

class View
{
public:
    explicit View(Model& model);
    void draw(ge211::Sprite_set& set, Posn displacement);

    Posn get_crosshair_center_posn()
    { return crosshair_.get_center_coords(); }


private:
    Model& model_;
    Crosshair crosshair_;
    ge211::Circle_sprite ball_sprite_;
    ge211::Circle_sprite debug_ball_sprite_;
    ge211::Image_sprite crosshair_sprite_; // dimensions: 50px x 50px
    ge211::Font sans30;


};
