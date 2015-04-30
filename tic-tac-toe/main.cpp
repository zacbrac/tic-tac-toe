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

int winner_yet(char board[4][4]) {
    if (
        (board[1][1] == 'x' && board[1][2] == 'x' && board[1][3] == 'x' ) ||
        (board[2][1] == 'x' && board[2][2] == 'x' && board[2][3] == 'x' ) ||
        (board[3][1] == 'x' && board[3][2] == 'x' && board[3][3] == 'x' ) ||
        (board[1][1] == 'x' && board[2][1] == 'x' && board[3][1] == 'x' ) ||
        (board[1][2] == 'x' && board[2][2] == 'x' && board[3][2] == 'x' ) ||
        (board[1][3] == 'x' && board[2][3] == 'x' && board[3][3] == 'x' ) ||
        (board[1][1] == 'x' && board[2][2] == 'x' && board[3][3] == 'x' ) ||
        (board[1][3] == 'x' && board[2][2] == 'x' && board[3][1] == 'x' )
        ) {
        return 1;
    } else if (
        (board[1][1] == 'o' && board[1][2] == 'o' && board[1][3] == 'o' ) ||
        (board[2][1] == 'o' && board[2][2] == 'o' && board[2][3] == 'o' ) ||
        (board[3][1] == 'o' && board[3][2] == 'o' && board[3][3] == 'o' ) ||
        (board[1][1] == 'o' && board[2][1] == 'o' && board[3][1] == 'o' ) ||
        (board[1][2] == 'o' && board[2][2] == 'o' && board[3][2] == 'o' ) ||
        (board[1][3] == 'o' && board[2][3] == 'o' && board[3][3] == 'o' ) ||
        (board[1][1] == 'o' && board[2][2] == 'o' && board[3][3] == 'o' ) ||
        (board[1][3] == 'o' && board[2][2] == 'o' && board[3][1] == 'o' )
        ) {
        return 2;
    }

    return 0;
}


bool game_finished(int valid_points[3][3]) {
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (valid_points[i][j] == 1) {
                return false;
            }
        }
    }
    std::cout << "GAME OVER / CAT SCRATCH OR WHATEVER IT'S CALLED\n";

    return true;
}

int draw_board (int x, int y, char board_array[4][4]) {
    std::cout << std::string(50, '\n');
    for (int i = 0; i < y; i++) {
        std::cout << "\t\t";
        for (int j = 0; j < x; j++) {
            std::cout << " " << board_array[i][j];
        }
        std::cout << "\n";
    }
    std::cout << std::string(4, '\n');
    return 0;
}

bool plot_point (int x, int y, int valid_points[3][3],char marker, char board_array[4][4]) {
    int board_num_x = x-1;
    int board_num_y = y-1;
    if (valid_points[board_num_x][board_num_y] == 1) {
        valid_points[board_num_x][board_num_y] = 0;
        board_array[y][x] = marker;
        return true;
    } else {
        return false;
    }
}

int toggle_turn(char &marker) {
    if (marker == 'x') {
        marker = 'o';
    } else {
        marker = 'x';
    }
    return 0;
}

int main(int argc, const char * argv[]) {
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
        int valid_points[3][3] = {
            {1,1,1},
            {1,1,1},
            {1,1,1}
        };
        
        draw_board(4,4,board);
        
        while (game_finished(valid_points) == false && winner_yet(board) == 0) {
            std::cout << "Choose your point e.g. x y\n";

            std::cin >> x;
            std::cin >> y;
            
            if  (std::cin.fail()) {
                std::cout << "Invalid input, please start over\n";
                x = 0, y = 0;
                exit(0);
            } else {
                if (plot_point(x,y,valid_points,marker,board)) {
                    draw_board(4,4,board);
                    toggle_turn(marker);
                } else {
                    draw_board(4,4,board);
                    std::cout << "Invalid move, please try again\n";
                }

            }
            
        }
        std::cout << "Player " << winner_yet(board) << " wins the round!\n";
        std::cout << "Would you like to play again?\n";
        std::cin >> general_input;
        if (general_input == "no" || general_input == "No") {
            game_status = false;
        }
    }
    return 0;
}