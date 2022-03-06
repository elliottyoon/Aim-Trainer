#include "controller.hxx"

Controller::Controller()
        : model_(10, 10) // CHANGE THIS FROM MAGIC NUMBER LATER
        , view_(model_)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}
