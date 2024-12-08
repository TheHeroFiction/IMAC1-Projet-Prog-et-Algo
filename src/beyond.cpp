#include "beyond.hpp"

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
    std::cout << "Choisis une colonne entre 1 et 7: ";
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
        if (tab[number + 34] == '.'){
            number = number + 34;
            break;  
        }
        if(tab[number-1 + i*7] != '.'){
            number = number-1 + (i-1)*7;
            break;
        }
    }
    tab[number] = player.symbol;
}

bool align_possibility(std::array<char,42> const & tab, char symbol, int index){
    if (index < 7){
        switch (index)
        {
        case 0:
            if (tab[1] == symbol || tab[7] == symbol || tab[8] == symbol ){
                return true;
            }
            break;
        case 6:
            if(tab[5] == symbol || tab[12] == symbol || tab[13] == symbol){
                return true;
            }
            break;
        default:
            if (tab[index-1] == symbol || tab[index+1] == symbol || tab[index+6] == symbol || tab[index+7] == symbol || tab[index+8] == symbol){
                return true;
            }
            break;
        }
    } else if (index > 34){
        switch (index)
        {
        case 35:
            if (tab[28] == symbol || tab[29] == symbol || tab[36] == symbol){
                return true;
            }
            break;
        case 41:
            if (tab[33] == symbol || tab[34] == symbol || tab[40] == symbol){
                return true;
            }
            break;
        default:
            if (tab[index-8] == symbol || tab[index-7] == symbol || tab[index-6] == symbol || tab[index-1] == symbol || tab[index+1] == symbol){
                return true;
            }
            break;
        }
    } else if (index % 7 == 0) {
        if (tab[index-7] == symbol || tab[index-6] == symbol || tab[index+1] == symbol || tab[index+7] == symbol || tab[index+8] == symbol){
            return true;
        }
    } else if (index % 7 == 6){
        if (tab[index-8] == symbol || tab[index-7] == symbol || tab[index-1] == symbol || tab[index+6] == symbol || tab[index+7] == symbol){
            return true;
        }
    } else {
        if (tab[index-8] == symbol || tab[index-7] == symbol || tab[index-6] == symbol || tab[index-1] == symbol || tab[index+1] == symbol || tab[index+6] == symbol || tab[index+7] == symbol || tab[index+8] == symbol){
            return true;
        }
    }
    return false;
} 

bool horizontal_win(std::array<char,42> const & tab, char symbol){
    for (int i {0}; i < 6 ; i++){
        if(tab[0 + i*7] == tab[1 + i*7] && tab [0 + i*7] == tab[2 + i*7] && tab[0 + i*7] == tab[3 + i*7]){
            return true;
        } else if (tab[1 + i*7] == tab[2 + i*7] && tab [1 + i*7] == tab[3 + i*7] && tab[1 + i*7] == tab[4 + i*7]){
            return true;
        } else if (tab[2 + i*7] == tab[3 + i*7] && tab [2 + i*7] == tab[4 + i*7] && tab[2 + i*7] == tab[5 + i*7]){
            return true; 
        } else if (tab[3 + i*7] == tab[4 + i*7] && tab [3 + i*7] == tab[5 + i*7] && tab[3 + i*7] == tab[6 + i*7]){
            return true;
        } else {
            return false;
        }
    }
}

bool vertical_win(std::array<char,42> const & tab, char symbol){
    
}

bool victory_detection(std::array<char,42> const & tab, char symbol){
    std::vector<int> indices{};
    for (int i {0} ; i < 42 ;i++){
        if (tab[i] == symbol){
            if (align_possibility(tab,symbol,i)){
                indices.push_back(i);
            }
        }
    }
}