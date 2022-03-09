//
// Created by Elliott Yoon on 3/9/22.
//

#include "option.hxx"
Option::Option(Dims dimensions, Position pos, std::string name)
    : dimensions_(dimensions)
    , is_selected_(false)
    , name_(name)
    , text_pos_(pos)
    , box_pos_{text_pos_.x + 60, text_pos_.y + 20}
{

}