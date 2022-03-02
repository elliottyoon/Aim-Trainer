#include "character.hxx"

#include <string>
#include <cmath>

Character::Character(std::string const& image_filename,
                     ge211::Posn<float> const& initial_position)
    : sprite_(image_filename),
      position_(initial_position),
      velocity_(100.0),
      destination_(initial_position)
{ }

void Character::update(double dt) {
    // Get direction to destination
    // Displacement / magnitude = Unit direction vector
    ge211::Dims<float> unit_vector = (destination_ - position_) /
            distance_to_position_(destination_);

    // Update position to move towards destination
    // Only move if we're not already there!
    if (distance_to_position_(destination_) > 10) {
        // move to the destination
        position_ += unit_vector*velocity_*dt;
    } else {
        // we're at the destination
        if (!waypoints_.empty()) {
            destination_ = waypoints_.front();
            waypoints_.pop();
        }
    }
}

float
Character::distance_to_position_(ge211::Posn<float> target)
{
    float diffx = target.x - position_.x;
    float diffy = target.y - position_.y;
    return std::sqrt(diffx*diffx + diffy*diffy);
}

void
Character::add_destination(ge211::Posn<float> destination)
{
    waypoints_.push(destination);
}
