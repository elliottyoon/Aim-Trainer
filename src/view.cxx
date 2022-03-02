#include "view.hxx"
#include "character.hxx"

View::View(Model const& model)
        : model_(model),
          explanation_()
{ }

void
View::draw(ge211::Sprite_set& set)
{
    // Get the character from the model and draw it
    for (auto& character : model_.get_characters()) {
        set.add_sprite(character.get_sprite(),
                       character.get_position().into<int>());
    }

    // Build explanation text
    ge211::Text_sprite::Builder explain_builder(sans28_);
    explain_builder.color(ge211::Color(0, 0, 255));

    Character first = model_.get_characters()[0];
    explain_builder << "First character: at {"
                    << (int)first.get_position().x
                    << ", "
                    << (int)first.get_position().y
                    << "} going to {"
                    << first.get_destination().x
                    << ", "
                    << first.get_destination().y
                    << "}";

    explanation_.reconfigure(explain_builder);
    set.add_sprite(explanation_, {0, 500});
}

