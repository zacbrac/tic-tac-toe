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

bool plot_point (int x, int y, int valid_points[3][3], char board_array[4][4]) {
    int board_num_x = x-1;
    int board_num_y = y-1;
    if (valid_points[board_num_y][board_num_x] == 1) {
        std::cout << "If statement was triggered";
        valid_points[board_num_x][board_num_y] = 0;
        board_array[x][y] = 'x';
        return true;
    } else {
        std::cout << "Else statement was triggered";
        return false;
    }
}

int main(int argc, const char * argv[]) {
    int x,y;
    std::string input;
    
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
        
        plot_point(x,y,valid_points,board);
        draw_board(4,4,board);

    }
    
    return 0;
}
