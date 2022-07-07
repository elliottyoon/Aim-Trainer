//
// Created by Elliott Yoon on 3/8/22.
//

#ifndef GAME_CROSSHAIR_HXX
#define GAME_CROSSHAIR_HXX
#pragma once

#include <ge211.hxx>
using Position = ge211::Posn<int>;

class Crosshair
{
public:
    // constructor
    explicit Crosshair(Position coords, Position center_coords, std::string
    filename,ge211::Dims<int> dims);

    // (top-left) coordinates of crosshair picture
    Position get_top_left_coords() const
    { return coords_; }

    // (center) coordinates of crosshair picture
    Position get_center_coords() const
    { return center_coords_;}

    // filename of crosshair image
    std::string get_filename() const
    { return filename_; }

    // dimensions of crosshair image
    ge211::Dims<int> get_dims() const
    { return dims_; }

private:
    Position coords_;
    Position center_coords_;
    std::string filename_;
    ge211::Dims<int> dims_;

};


#endif //GAME_CROSSHAIR_HXX
