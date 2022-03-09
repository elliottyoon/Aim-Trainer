//
// Created by Elliott Yoon on 3/8/22.
//

#include "menu.hxx"
Menu::Menu()
    : options_{}
{
    // Mode 1: ball will pop up on the screen and disappear after a short amount of time if not clicked by user
    Option mode1 = Option({10, 10}, {10, 70}, "Reflex");//TODO: change magic #
    // Mode 2: balls will pop up on the screen and if too many balls on screen, user loses.
    Option mode2 = Option({10, 10}, {10, 100}, "Frenzy"); //TODO: change magic #

    // adds modes to options vector
    options_.push_back(mode1);
    options_.push_back(mode2);
}