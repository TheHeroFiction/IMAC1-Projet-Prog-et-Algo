#pragma once
#include <iostream>
#include <string>

struct Player{
    std::string name{""};
    char symbol {'X'};
};

Player create_player();

void detect_similarities(Player const & player_1, Player & player_2);