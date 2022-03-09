//
// Created by Elliott Yoon on 3/8/22.
//

#include "crosshair.hxx"

Crosshair::Crosshair(Position coords, Position center_coords, std::string
filename,
                     ge211::Dims<int> dims)
    : coords_(coords)
    , center_coords_(center_coords)
    , filename_(filename)
    , dims_(dims)
{

}