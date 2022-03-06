#pragma once

#include "model.hxx"

class View
{
public:
    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

private:
    Model const& model_;
    size_t time_elapsed; /* time elapsed since game starts (might change this
     to be part of the model) 1 = 1/60th of a second  */
    ge211::Circle_sprite ball_sprite;

};
