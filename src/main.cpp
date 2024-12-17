#include "main.hpp"

void draw_game_board(std::array<char,9> const & tab){
    std::cout << "| " << tab[0] << " | " << tab[1] << " | " << tab[2] << " |" << std::endl;
    std::cout << "| " << tab[3] << " | " << tab[4] << " | " << tab[5] << " |" << std::endl;
    std::cout << "| " << tab[6] << " | " << tab[7] << " | " << tab[8] << " |" << std::endl;
}

void draw_help_board(){
    std::array<char,9> tab {'1','2','3','4','5','6','7','8','9'};
    draw_game_board(tab);
}

void turn(Player const & player, int & number, std::array<char,9> & tab){
    std::cout << player.name << " à toi de jouer! Entre un nombre entre 1 et 9: ";
        std::cin >> number;
    while (tab[number-1] != '.'){
        std::cout << "Ce n'est pas un emplacement valide ! Entre un nouveau nombre entre 1 et 9: ";
        std::cin >> number;
    }
    tab[number-1] = player.symbol;
}

bool victory_detection(std::array<char,9> const & tab, char symbol){
    for (int i {0}; i < 2; i++){
        if (tab[i] == symbol && tab[i] == tab[i+3] && tab[i] == tab[i+6]){
            return true;
        } else if (tab[i] == symbol && tab[i] == tab[i+1] && tab[i] == tab[i+2]){
            return true;
        }
    }
    if (tab[0] == symbol && tab[0] == tab [4] && tab[0] == tab[8]){
        return true;
    } else if (tab[2] == symbol && tab[2] == tab[4] && tab[2] == tab[6]){
        return true;
    }
    return false;
}

void victory_declaration(std::array<char,9> const & tab, Player const & player_1, Player const & player_2){
    if(victory_detection(tab,player_1.symbol)){
            std::cout << player_1.name << " a gagné!"<< std::endl;
        } else if(victory_detection(tab,player_2.symbol)){
            std::cout << player_2.name << " a gagné!"<< std::endl;
        } else {
            std::cout << "Egalité !" << std::endl; 
        }
}

void two_players_mode(Player const & player_1, Player const & player_2){
    std::array<char,9> tab {'.','.','.','.','.','.','.','.','.'};
    int number {0};
    bool is_finished {false};
    for (int i {0}; i < 9; i++){
        draw_game_board(tab);
        std::cout << std::endl;
        draw_help_board();
        if ( i%2 ==0){
            turn(player_1,number,tab);
            if (victory_detection(tab,player_1.symbol)){
                is_finished = true;
                std::cout << player_1.name << " a gagne!"<< std::endl;
                break;
            }
        } else {
            turn(player_2,number,tab);
            if (victory_detection(tab,player_2.symbol)){
                is_finished = true;
                std::cout << player_2.name << " a gagne!"<< std::endl;
                break;
            }
        }
        std::cout << std::endl;
    }
    if (!is_finished){
        victory_declaration(tab,player_1,player_2);
    }
}

void IA_play(std::array<char,9> & tab){
    std::vector<int> empty {};
    for (int i {0}; i < 9 ; i++){
        if (tab[i] == '.'){
            empty.push_back(i);
        }
    }
    std::cout << "L' IA a joué !" << std::endl;
    tab[empty[rand()%empty.size()]] = IA.symbol;
}

void one_player_mode(Player const & player){
    std::array<char,9> tab {'.','.','.','.','.','.','.','.','.'};
    int number {0};
    bool is_finished {false};
    for (int i {0}; i < 9; i++){
        draw_game_board(tab);
        std::cout << std::endl;
        draw_help_board();
        if ( i%2 ==0){
            turn(player,number,tab);
            if (victory_detection(tab,player.symbol)){
                is_finished = true;
                std::cout << player.name << " a gagne!"<< std::endl;
                break;
            }
        } else {
            IA_play(tab);
            if (victory_detection(tab,IA.symbol)){
                is_finished = true;
                std::cout << IA.name << " a gagne!"<< std::endl;
                break;
            }
        }
        std::cout << std::endl;
    }
    if (!is_finished){
        victory_declaration(tab,player,IA);
    }
}

void boot_menu(){
    int number {0};
    std::cout << "Bienvenue dans le jeu de TicTacToe" << std::endl;
    std::cout << "Veuillez choisir un mode de jeu :" << std::endl;
    std::cout << "1. Deux joueurs" << std::endl;
    std::cout << "2. Un joueur contre l'IA" << std::endl;
    std::cin >> number;
    if (number == 1){
        Player player_1 {create_player()};
        Player player_2 {create_player()};
        detect_similarities(player_1,player_2);
        two_players_mode(player_1,player_2);
    } else if (number == 2){
        Player player {create_player()};
        detect_similarities(IA,player);
        one_player_mode(player);
    } else {
        std::cout << "Aucun mode associé à ce nombre" << std::endl;
    }
}

void boot_menu_with_connect4(){
    int number {0};
    std::cout << "Bienvenue !" << std::endl;
    std::cout << "Veuillez choisir un mode de jeu :" << std::endl;
    std::cout << "1. Tictactoe: Deux joueurs" << std::endl;
    std::cout << "2. Tictactoe: Un joueur contre l'IA" << std::endl;
    std::cout << "3. Puissance4: Deux joueurs" << std::endl;
    std::cin >> number;
    if (number == 1){
        Player player_1 {create_player()};
        Player player_2 {create_player()};
        detect_similarities(player_1,player_2);
        two_players_mode(player_1,player_2);
    } else if (number == 2){
        Player player {create_player()};
        detect_similarities(IA,player);
        one_player_mode(player);
    } else if (number == 3){
        Player player_1 {create_player()};
        Player player_2 {create_player()};
        detect_similarities(player_1,player_2);
        two_players_connect_4_mode(player_1,player_2);
    } else {
        std::cout << "Aucun mode associé à ce nombre! Fin du programme!" << std::endl;
    }
}


int main(){
    std::setlocale(LC_ALL, ".65001");
    //boot_menu(); // Projet de base: morpion avec un mode 1 joueur et un mode 2 joueurs 
    boot_menu_with_connect4();
    return 0;
}