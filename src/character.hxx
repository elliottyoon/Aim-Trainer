#pragma once

#include <ge211.hxx>

#include <string>
#include <queue>

class Character
{
public:
    // Constructor(s)
    Character(std::string const& image_filename,
              ge211::Posn<float> const& initial_position);

    // Getters/Setters
    // Implemented in place if they're really simple (one liners)
    //void set_position(ge211::Posn<float> position) {
    //    position_ = position;
    //}
    ge211::Posn<float> const& get_position() const {
        return position_;
    }
    ge211::Image_sprite const& get_sprite() const {
        return sprite_;
    }
    //void set_destination(ge211::Posn<float> destination) {
    //    destination_ = destination;
    //}
    ge211::Posn<float> const& get_destination() const {
        return destination_;
    }

    // Public interface
    void update(double dt);
    void add_destination(ge211::Posn<float> destination);

private:

    // Private helpers
    float distance_to_position_(ge211::Posn<float> target);
    
    // Data members
    ge211::Image_sprite sprite_;
    ge211::Posn<float> position_;
    float velocity_;
    ge211::Posn<float> destination_;
    std::queue<ge211::Posn<float>> waypoints_;

};
