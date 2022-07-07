#pragma once

#include <ge211.hxx>
#include "ball.hxx"
#include "crosshair.hxx"
#include <cmath> // for sqrt

using dims = ge211::Dims<int>;

using Position = ge211::Posn<int>;

class Model
{
public:
    explicit Model(int width, int height, int gamemode, int maxballs, int
    currentballs);

    //sets max balls
    void set_max_balls(int balls){
        max_balls = balls;
    }

    //get active balls
    int get_active_balls(){
        return active_balls;
    }

    //set active balls directly
    void set_active_balls(int io){
        active_balls = io;
    }

    // Change game mode
    void change_game_mode(int gm)
    {game_mode = gm;}

    // Return game mode
    int get_game_mode() const
    {return game_mode;}

    // Returns the dimensions of the screen
    dims get_model_dims() const
    { return model_dims_; }

    // Returns the list of balls in play
    std::vector<ball> get_balls() const
    { return balls_; }

    // Adds ball to the list of balls
    void add_ball(ball new_ball)
    { balls_.push_back(new_ball);
        active_balls++;}

    // checks if input position resides within a ball
    // if so, deletes the ball, returns true. returns false otherwise
    bool delete_ball(Position posn, Position displacement);

    void delete_expired();

    void clear_balls();

    bool check_overload(int num);

    // returns Euclidean distance between two positions
    float distance(Position pos1, Position pos2)
    {
        return std::sqrt(std::pow(pos1.x - pos2.x, 2)
                         + std::pow(pos1.y - pos2.y,2));
    }

    // shifts position according to perspective shift
    Position shift_pos(Position pos, Position shift)
    {
        return {pos.x + shift.x, pos.y + shift.y};
    }

private:
    std::vector<ball> balls_; // list of all the balls in play
    dims model_dims_;
    int game_mode;
    int max_balls;
    int active_balls;



};
