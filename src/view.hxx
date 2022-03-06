#pragma once

#include "model.hxx"

class View
{
public:
    explicit View(Model const& model);
    void draw(ge211::Sprite_set& set);

private:
    Model const& model_;
    ge211::Circle_sprite ball_sprite;

};
