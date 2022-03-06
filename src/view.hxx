#pragma once

#include "model.hxx"

class View
{
public:
    explicit View(Model const& model);
    void draw(ge211::Sprite_set& set);

    ge211::Posn<int> get_crosshair_pos()
    { return crosshair_posn_; }

private:
    Model const& model_;
    ge211::Circle_sprite ball_sprite_;
    ge211::Image_sprite crosshair_sprite_; // dimensions: 50px x 50px
    ge211::Dims<int> crosshair_dims_;
    ge211::Posn<int> crosshair_posn_;
};
