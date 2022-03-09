//
// Created by Elliott Yoon on 3/9/22.
//

#ifndef GAME_OPTION_HXX
#define GAME_OPTION_HXX
#include <ge211.hxx>
using Position = ge211::Posn<int>;
using Dims = ge211::Dims<int>;

class Option
{
public:
    explicit Option(Dims dimensions, Position pos, std::string name);

    // dimensions of options box
    Dims get_dimensions() const
    { return dimensions_; }

    // returns if option is selected
    bool is_selected() const
    { return is_selected_; }

    // returns name
    std::string get_name() const
    { return name_; }

    // returns (top-left) position of option box
    Position get_pos(Position pos_, Position displacement) const
    { return {pos_.x - displacement.x, pos_.y - displacement.y}; }

    // return center position of option box
    Position get_center(Position pos, Position displacement) const
    { return {get_pos(pos, displacement).x + (dimensions_.width / 2),
              get_pos(pos, displacement).y + (dimensions_.height / 2)}; }

    // sets is_selected_
    void set_selected(bool is_selected) {
        is_selected_ = is_selected;
    }

    Position get_text_pos_() const
    { return text_pos_; }
    Position get_box_pos_() const
    { return box_pos_; }

private:
    Dims dimensions_;
    Position text_pos_;
    Position box_pos_;
    bool is_selected_;
    std::string name_;
};


#endif //GAME_OPTION_HXX
