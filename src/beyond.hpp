#pragma once
#include <array>
#include <vector>
#include "Player.hpp"

void draw_connect_4(std::array<char,42> const & tab);

void draw_connect_4_help();

void turn_connect_4(Player const & player,std::array<char,42> tab, int & number);

bool align_possibility(std::array<char,42> const & tab, char symbol, int index);

bool horizontal_win(std::array<char,42> const & tab, char symbol);

bool vertical_win(std::array<char,42> const & tab, char symbol);

bool victory_detection(std::array<char,42> & tab, char symbol);