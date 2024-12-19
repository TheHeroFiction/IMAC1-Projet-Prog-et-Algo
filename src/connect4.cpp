#include "connect4.hpp"

void draw_connect_4(std::array<char,42> const & tab){
    for (int i {0}; i < 6; i++){
        std::cout << "| " << tab[0 + i*7] << " | " << tab[1 + i*7] << " | " << tab[2 + i*7] << " | " << tab[3 + i*7] << " | " << tab[4 + i*7] << " | " << tab[5 + i*7] << " | " << tab[6 + i*7] << " |" << std::endl;
    }
}

void draw_connect_4_help(){
    std::array<char,42> tab 
    {'1','2','3','4','5','6','7',
    '0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0',
    '0','0','0','0','0','0','0'};
    draw_connect_4(tab);
}

void turn_connect_4(Player const & player,std::array<char,42> & tab, int & number){
    std::cout << player.name << " choisis une colonne entre 1 et 7: ";
    std::cin >> number;
    while(number > 7 || number < 1){
        std::cout << "Entre un chiffre valide entre 1 et 7: ";
        std::cin >> number;
    }
    while (tab[number-1] != '.'){
        std::cout << "Colonne pleine ! Choisis une autre colonne entre 1 et 7: ";
        std::cin >> number;
    }
    
    for (int i {1}; i < 6; i++){
        if (tab[number + 34] == '.'){ // regarde si la colonne est vide
            number = number + 34;
            break;  
        }
        if(tab[number-1 + i*7] != '.'){ //regarde jusqu'où la colonne est remplie
            number = number-1 + (i-1)*7;
            break;
        }
    }
    tab[number] = player.symbol;
}

bool horizontal_win_detection(std::array<char,42> const & tab, char symbol){
    for (int i {0}; i < 6 ; i++){
        if(tab[0 + i*7] == symbol && tab[0 + i*7] == tab[1 + i*7] && tab [0 + i*7] == tab[2 + i*7] && tab[0 + i*7] == tab[3 + i*7]){
            return true;
        } else if (tab[1 + i*7] == symbol && tab[1 + i*7] == tab[2 + i*7] && tab [1 + i*7] == tab[3 + i*7] && tab[1 + i*7] == tab[4 + i*7]){
            return true;
        } else if (tab[2 + i*7] == symbol &&tab[2 + i*7] == tab[3 + i*7] && tab [2 + i*7] == tab[4 + i*7] && tab[2 + i*7] == tab[5 + i*7]){
            return true; 
        } else if (tab[3 + i*7] == symbol && tab[3 + i*7] == tab[4 + i*7] && tab [3 + i*7] == tab[5 + i*7] && tab[3 + i*7] == tab[6 + i*7]){
            return true;
        }
    }
    return false;
}

bool vertical_win_detection(std::array<char,42> const & tab, char symbol){
    for (int i {0}; i < 7; i++){
        if (tab[0 + i] == symbol && tab[0 + i] == tab[7 + i] && tab[0 + i] == tab[14 + i] && tab[0 + i] == tab[21 + i]){
            return true;
        } else if (tab[7 + i] == symbol && tab[7 + i] == tab[14 + i] && tab[7 + i] == tab[21 + i] && tab[7 + i] == tab[28 + i]){
            return true;
        } else if (tab[14 + i] == symbol && tab[14 + i] == tab[21 + i] && tab[14 + i] == tab[28 + i] && tab[14 + i] == tab[35 + i]){
            return true;
        }
    }
    return false;
}

bool diagonale_win_detection(std::array<char,42> const & tab, char symbol){
    if (tab[38] == symbol && tab[38] == tab[32] && tab[38] == tab[26] && tab[38] == tab[20]){
        return true;
    } else if (tab[38] == symbol && tab[38] == tab[30] && tab[38] == tab[22] && tab[38] == tab[14]){
        return true;
    } else if (tab[37] == symbol && tab[37] == tab[31] && tab[37] == tab[25] && tab[37] == tab[19]){
        return true;
    } else if (tab[31] == symbol && tab[31] == tab[25] && tab[31] == tab[19] && tab[31] == tab[13]){
        return true;
    } else if (tab[36] == symbol && tab[36] == tab[30] && tab[36] == tab[24] && tab[36] == tab[18]){
        return true;
    } else if (tab[30] == symbol && tab[30] == tab[24] && tab[30] == tab[18] && tab[30] == tab[12]){
        return true;
    } else if (tab[24] == symbol && tab[24] == tab[18] && tab[24] == tab[12] && tab[24] == tab[6]){
        return true;
    } else if (tab[35] == symbol && tab[35] == tab[29] && tab[35] == tab[23] && tab[35] == tab[17]){
        return true;
    } else if (tab[29] == symbol && tab[29] == tab[23] && tab[29] == tab[17] && tab[29] == tab[11]){
        return true;
    } else if (tab[23] == symbol && tab[23] == tab[17] && tab[23] == tab[11] && tab[23] == tab[5]){
        return true;
    } else if (tab[28] == symbol && tab[28] == tab[22] && tab[28] == tab[16] && tab[28] == tab[10]){
        return true;
    } else if (tab[22] == symbol && tab[22] == tab[16] && tab[22] == tab[10] && tab[22] == tab[4]){
        return true;
    } else if (tab[21] == symbol && tab[21] == tab[15] && tab[21] == tab[9] && tab[21] == tab[3]){
        return true;
    } else if (tab[39] == symbol && tab[39] == tab[31] && tab[39] == tab[23] && tab[39] == tab[15]){
        return true;
    } else if (tab[31] == symbol && tab[31] == tab[23] && tab[31] == tab[15] && tab[31] == tab[7]){
        return true;
    } else if (tab[40] == symbol && tab[40] == tab[32] && tab[40] == tab[24] && tab[40] == tab[16]){
        return true;
    } else if (tab[32] == symbol && tab[32] == tab[24] && tab[32] == tab[16] && tab[32] == tab[8]){
        return true;
    } else if (tab[24] == symbol && tab[24] == tab[16] && tab[24] == tab[8] && tab[24] == tab[0]){
        return true;
    } else if (tab[41] == symbol && tab[41] == tab[33] && tab[41] == tab[25] && tab[41] == tab[17]){
        return true;
    } else if (tab[33] == symbol && tab[33] == tab[25] && tab[33] == tab[17] && tab[33] == tab[9]){
        return true;
    } else if (tab[25] == symbol && tab[25] == tab[17] && tab[25] == tab[9] && tab[25] == tab[1]){
        return true;
    } else if (tab[34] == symbol && tab[34] == tab[26] && tab[34] == tab[18] && tab[34] == tab[10]){
        return true;
    } else if (tab[26] == symbol && tab[26] == tab[18] && tab[26] == tab[10] && tab[26] == tab[2]){
        return true;
    } else if (tab[27] == symbol && tab[27] == tab[19] && tab[27] == tab[11] && tab[27] == tab[3]){
        return true;
    } else {
        return false;
    }
}

bool victory_detection(std::array<char,42> const & tab, char symbol){
    return (horizontal_win_detection(tab,symbol) || vertical_win_detection(tab,symbol) || diagonale_win_detection(tab,symbol));
}

void victory_declaration(std::array<char,42> const & tab, Player const & player_1, Player const & player_2){
    if(victory_detection(tab,player_1.symbol)){
            std::cout << player_1.name << " a gagné!"<< std::endl;
        } else if(victory_detection(tab,player_2.symbol)){
            std::cout << player_2.name << " a gagné!"<< std::endl;
        } else {
            std::cout << "Egalité !" << std::endl; 
        }
}

void two_players_connect_4_mode(Player const & player_1, Player const & player_2){
    std::array<char,42> tab 
    {'.','.','.','.','.','.','.',
    '.','.','.','.','.','.','.',
    '.','.','.','.','.','.','.',
    '.','.','.','.','.','.','.',
    '.','.','.','.','.','.','.',
    '.','.','.','.','.','.','.'};
    int number {0};
    bool is_finished {false};
    for (int i {0}; i < 42; i++){
        draw_connect_4(tab);
        std::cout << std::endl;
        draw_connect_4_help();
        if ( i%2 ==0){
            turn_connect_4(player_1,tab,number);
            if (victory_detection(tab,player_1.symbol)){
                is_finished = true;
                std::cout << player_1.name << " a gagne!"<< std::endl;
                break;
            }
        } else {
            turn_connect_4(player_2,tab,number);
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