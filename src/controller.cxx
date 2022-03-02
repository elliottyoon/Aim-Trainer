#include "controller.hxx"

Controller::Controller()
        : view_(model_)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

void
Controller::on_frame(double dt)
{
    model_.on_frame(dt);
}

void Controller::on_mouse_down(ge211::Mouse_button button,
                               ge211::Posn<int> position)
{
    model_.on_click(position.into<float>());
}
