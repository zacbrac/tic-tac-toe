//
//  main.cpp
//  tic-tac-toe
//
//  Created by Zachary Brachmanis on 4/28/15.
//  Copyright (c) 2015 Zac Brachmanis Developments. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>

bool winner_yet(char board[4][4] ,char symbol) {

    if (
        (board[1][1] == symbol && board[1][2] == symbol && board[1][3] == symbol ) ||
        (board[2][1] == symbol && board[2][2] == symbol && board[2][3] == symbol ) ||
        (board[3][1] == symbol && board[3][2] == symbol && board[3][3] == symbol ) ||
        (board[1][1] == symbol && board[2][1] == symbol && board[3][1] == symbol ) ||
        (board[1][2] == symbol && board[2][2] == symbol && board[3][2] == symbol ) ||
        (board[1][3] == symbol && board[2][3] == symbol && board[3][3] == symbol ) ||
        (board[1][1] == symbol && board[2][2] == symbol && board[3][3] == symbol ) ||
        (board[1][3] == symbol && board[2][2] == symbol && board[3][1] == symbol )
        ) {
        std::cout << symbol << " has won";
        return true;
        
    }

    return false;
    
}


bool game_finished(char board[4][4]) {
    
    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

            if (board[i][j] == '-') {
            
                return false;

            }

        }

    }

    std::cout << "GAME OVER / CAT SCRATCH OR WHATEVER IT'S CALLED\n";
    return true;
    
}

void draw_board (int x, int y, char board_array[4][4]) {
    
    std::cout << std::string(50, '\n');
    
    for (int i = 0; i < y; i++) {
    
        std::cout << "\t\t";
        
        for (int j = 0; j < x; j++) {
        
            std::cout << " " << board_array[i][j];

        }
        
        std::cout << "\n";

    }

    std::cout << std::string(4, '\n');
    
}

bool plot_point (int x, int y,char marker, char board_array[4][4]) {

    if (board_array[y][x] == '-') {
        
        std::cout << "here I am";
        board_array[y][x] = marker;
        return true;
        
    } else {

        std::cout << "actually im over here";
        return false;
        
    }
    
}

char toggle_turn(char marker) {
    return (marker == 'x') ? 'o' : 'x';
}

int main() {
    
    bool game_status = true;
    
    while (game_status) {
        
        int x,y;
        
        std::string input, general_input;
        
        char marker = 'x';

        char board[4][4] = {

            {' ','1','2','3'},
            {'1','-','-','-'},
            {'2','-','-','-'},
            {'3','-','-','-'}
            
        };

        draw_board(4,4,board);
        
        while (game_finished(board) == false && winner_yet(board, marker) == false) {

            std::cout << "Choose your point e.g. x y\n";
            std::cin >> x;
            std::cin >> y;
            
            if  (std::cin.fail()) {
                
                std::cout << "Invalid input, please start over\n";
                x = 0, y = 0;
                
                return 0;
                
            } else {

                if (plot_point(x,y,marker,board)) {

                    draw_board(4,4,board);
                    marker = toggle_turn(marker);

                } else {

                    draw_board(4,4,board);
                    std::cout << "Invalid move, please try again\n";

                }

            }

        }
        
        std::cout << "Player " << marker << " wins the round!\n";
        std::cout << "Would you like to play again?\n";
        std::cin >> general_input;
        
        if (general_input == "no" || general_input == "No") {
        
            game_status = false;

        }

    }

    return 0;
    
}
