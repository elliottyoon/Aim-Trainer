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
    explicit Option(Dims dimensions, std::string name);

    // dimensions of options box
    Dims get_dimensions() const
    { return dimensions_; }

    // returns if option is selected
    bool is_selected() const
    { return is_selected_; }

    // returns name
    std::string get_name() const
    { return name_; }
private:
    Dims dimensions_;
    bool is_selected_;
    std::string name_;
};


#endif //GAME_OPTION_HXX
