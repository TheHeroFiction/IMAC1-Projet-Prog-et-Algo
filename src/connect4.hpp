#pragma once
#include <array>
#include <vector>
#include "Player.hpp"

void draw_connect_4(std::array<char,42> const & tab);

void draw_connect_4_help();

void turn_connect_4(Player const & player,std::array<char,42> & tab, int & number);

bool horizontal_win_detection(std::array<char,42> const & tab, char symbol);

bool vertical_win_detection(std::array<char,42> const & tab, char symbol);

bool diagonale_win_detection(std::array<char,42> const & tab, char symbol);

bool victory_detection(std::array<char,42> const & tab, char symbol);

void victory_declaration(std::array<char,42> const & tab, Player const & player_1, Player const & player_2);

void two_players_connect_4_mode(Player const & player1, Player const & player2);