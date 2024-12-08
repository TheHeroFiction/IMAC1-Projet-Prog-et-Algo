#pragma once
#include <array>
#include <vector>
#include <random>
#include "Player.hpp"
#include "beyond.hpp"

void draw_game_board(std::array<char,9> const & tab);

void draw_help_board();

void turn(Player const & player, int & number, std::array<char,9> & tab);

bool victory_detection(std::array<char,9> const & tab,char symbol);

void victory_declaration(std::array<char,9> const & tab, Player const & player_1, Player const & player_2);

void two_players_mode(Player const & player_1, Player const & player_2);

Player IA {"IA",'I'};

void IA_play(std::array<char,9> & tab);

void one_player_mode(Player const & player_1);

void boot_menu();