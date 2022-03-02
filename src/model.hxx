#pragma once

#include <ge211.hxx>

#include "character.hxx"

class Model
{
public:
    // Constructor(s)
    Model();

    // Getters/Setters
    // Implemented in place if they're really simple (one liners)
    std::vector<Character> const& get_characters() const { return characters_; }

    // Public interface
    void on_frame(double dt);
    void on_click(ge211::Posn<float> position);

private:
    // Data members
    std::vector<Character> characters_;
};
