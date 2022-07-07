#include "model.hxx"
#include <iostream>
#include <catch.hxx>

TEST_CASE("Ball not deleted when crosshair not over it and mouse clicked")
{
    Model model = Model(100, 100, 0, 10, 0);
    model.add_ball(ball(5, {10, 10}, -1));
    model.delete_ball({0,0}, {0,0});
    CHECK(!model.get_balls().empty());
}

TEST_CASE("Ball deleted when crosshair over it and mouse clicked")
{
    Model model = Model(100, 100, 0, 10, 0);
    model.add_ball(ball(5, {10, 10}, -1));
    model.delete_ball({10,10}, {0,0});
    model.delete_expired();
    CHECK(model.get_balls().empty());
}

TEST_CASE("Ball not deleted when user misses")
{
    Model model = Model(100, 100, 0, 10, 0);
    model.add_ball(ball(5, {10, 10}, -1));
    //model.add_ball(ball(5, {90, 90}, -1));
    CHECK(!model.delete_ball({50, 50}, {0,0}));
}

TEST_CASE("Ball displacement with mouse movement")
{
    Model model = Model(100, 100, 0, 10, 0);
    model.add_ball(ball(5, {10, 10}, -1));
    Position p = {5,5};
    CHECK(model.get_balls().front().get_view_position({5,5}) == p);
}

TEST_CASE("User doesn't miss with mouse movement")
{
    Model model = Model(100, 100, 0, 10, 0);
    model.add_ball(ball(5, {10, 10}, -1));
    model.delete_ball({0,0}, {5,5});
    model.delete_expired();
    CHECK(model.get_balls().empty());
}