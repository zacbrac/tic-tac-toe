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


int check_for_win(char board_array[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << board_array[i][j];
        }
    }
    return 0;
}

int draw_board (int x, int y, char board_array[4][4]) {
    std::cout << std::string(50, '\n');
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            std::cout << board_array[i][j];
        }
        std::cout << "\n";
    }
    
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
    int x,y;
    std::string input;
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
    
    while (true) {
        std::cout << "Choose your point e.g. x y\n";
        std::getline(std::cin,input);
        std::stringstream ss(input);
        ss >> x >> y;
        
        if (plot_point(x,y,valid_points,marker,board)) {
            draw_board(4,4,board);
            toggle_turn(marker);
        } else {
            std::cout << "Invalid move, please try again\n";
        }


    }
    return 0;
}
