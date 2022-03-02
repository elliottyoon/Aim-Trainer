#include "model.hxx"
#include "character.hxx"

Model::Model()
    : characters_()
{
    Character eevee("eevee.png", {0, 0});
    //eevee.add_destination({300, 300});
    //eevee.add_destination({500, 500});
    //eevee.add_destination({500, 0});
    //eevee.add_destination({0, 0});

    Character wartortle("wartortle.png", {300, 0});
    wartortle.add_destination({0, 0});
    wartortle.add_destination({300, 0});
    wartortle.add_destination({0, 0});
    wartortle.add_destination({300, 0});

    characters_.push_back(eevee);
    characters_.push_back(wartortle);
}

void Model::on_frame(double dt)
{
    for (Character& character : characters_) {
        character.update(dt);
    }
}

void Model::on_click(ge211::Posn<float> position)
{
    characters_[0].add_destination(position);
}
