#include "Player.hpp"

Player create_player(){
    Player new_player{};
    std::cout << "Entrez votre nom: ";
    std::cin >> new_player.name;

    std::cout << std::endl;

    std::cout << "Entrez votre symbole (ex: 'X' ou 'O'): ";
    std::cin >> new_player.symbol;
    
    std::cout << std::endl;
    return new_player;
}

void detect_similarities(Player const & player_1, Player & player_2){
    while(player_1.name == player_2.name){
        std::cout << "Nom déjà pris ! Veuillez en choisir un autre: ";
        std::cin >> player_2.name;
        std::cout << std::endl;
    }
    while(player_1.symbol == player_2.symbol){
        std::cout << "Symbole déjà pris ! Veuillez en choisir un autre: ";
        std::cin >> player_2.symbol;
        std::cout << std::endl;
    }
}