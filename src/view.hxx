#pragma once

#include "model.hxx"

class View
{
public:
    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

private:
    Model const& model_;
    ge211::Text_sprite explanation_;
    ge211::Font sans28_{"sans.ttf", 28};
};
