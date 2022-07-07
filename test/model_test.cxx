#include "model.hxx"
#include "view.hxx"
#include <catch.hxx>

TEST_CASE("example test (TODO: replace this)")
{
    CHECK(1 + 1 == 2);
}

// TODO: ball disappears when clicked on by crosshair
TEST_CASE("no balls")
{
    Model model = Model(10, 10, 0, 2, 0);
    View view = View(model);
    model.delete_ball(view.get_crosshair_center_posn(), {0,0});
    CHECK(model.get_balls().empty() == false);
}

// TODO



//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate your functional requirements.
//
