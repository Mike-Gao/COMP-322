//
// Created by Mike Gao on 2020-01-25.
//

#include "functions.h"
#include <iostream>
using namespace std;
void greetAndInstruct()
{
    char input;
    cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer." << endl;
    cout << "The board is numbered from 1 to 27 as per the following:\n" << endl;
    cout << "1|2|3 10|11|12 19|20|21" << endl;
    cout << "----- -------- --------" << endl;
    cout << "4|5|6 13|14|15 22|23|24" << endl;
    cout << "----- -------- --------" << endl;
    cout << "7|8|9 16|17|18 25|26|27\n" << endl;
    cout << "Player starts first. Simply input the number of the cell you want to occupy. "
            "Player’s move is marked with X. Computer’s move is marked with O." << endl;
    cout << "    y) Play\n    n) Exit\n" << "\n> ";
    cin >> input;
    while (true){
        switch (input){
            case 'y' :
                return;
            case 'n' :
                exit(0);
            default:
                cout << "Error, please enter either 'y' or 'n'" << endl;
                cin >> input;
        }
    }

}

void displayBoard (char board[])
{
    for (int i = 1 ; i < 22 ; i++){
        if ((i > 3 && i < 10) || (i > 12 && i < 19)) continue;
        cout << (board[i])
             << ((i%3!=0)? '|' : ' ');
    }
    cout << endl;
    cout << "----- ----- -----" << endl;
    for (int i = 4 ; i < 25 ; i++){
        if ((i > 6 && i < 13) || (i > 15 && i < 22)) continue;
        cout << (board[i])
             << ((i%3!=0)? '|' : ' ');
    }
    cout << endl;
    cout << "----- ----- -----" << endl;
    for (int i = 7 ; i < 28 ; i++){
        if ((i > 9 && i < 16) || (i > 18 && i < 25)) continue;
        cout << (board[i])
             << ((i%3!=0)? '|' : ' ');
    }
    cout << endl;
}

bool checkWinner(char board[])
{
    // Rows on single board
    // {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}, {13,14,15}, {16,17,18}, {19,20,21}, {22,23,24}, {25,26,27}
    for (int i = 1; i < 26; i++){
        int j = i+1;
        int k = i+2;
        if(board[i] == board[j] && board[i] == board[k] && board[i]!='?'){
            /* for debugging purposes */
//            cout << board[i] << endl;
//            cout << board[j] << endl;
//            cout << board[k] << endl;
            /* for debugging purposes */
            return true;
        }
    }

    // Columns on single board
    // {1,4,7}, {2,5,8}, {3,6,9}, {10,13,16}, {11,14,17}, {12,15,18}, {19,22,25}, {20,23,26}, {21,24,27}
    for (int i = 1; i < 22; i++){
        int j = i+3;
        int k = i+6;
        if(board[i] == board[j] && board[i] == board[k] && board[i]!='?'){
            return true;
        }
    }

    // Diagonals on single board
    // {1,5,9}, {3,5,7}, {10,14,18}, {12,14,16}, {19,23,27}, {21,23,25}
    for(int i = 1; i < 22; i++){
        if (i == 2 || (i > 3 && i < 10) || i == 11 || (i > 12 && i < 19) || i == 20 ) continue;
        if (i == 1 || i == 10 || i == 19) {
            int j = i+4;
            int k = i+8;
            if(board[i] == board[j] && board[i] == board[k] && board[i]!='?'){
                return true;
            }
        } else {
            int j = i+2;
            int k = i+4;
            if(board[i] == board[j] && board[i] == board[k] && board[i]!='?') {
                return true;
            }
        }
    }

    // Straight down through the board
    // {1,10,19}, {2,11,20}, {3,12,21}, {4,13,22}, {5,14,23}, {6,15,24}, {7,16,25}, {8,17,26}, {9,18,27}
    for (int i = 1; i < 10; i++){
        int j = i+9;
        int k = i+18;
        if (board[i] == board[j] && board[i] == board[k] && board[i]!='?'){
            return true;
        }
    }

    // Diagonals through boards
    // {1,13,25} (12), {2,14,26}(12), {3,15,27}(12),
    // {7,13,19}(6), {8,14,20}(6), {9,15,21}(6),
    // {1,11,21}(10), {4,14,24}(10), {7,17,27}(10),
    // {3,11,19}(8), {6,14,22}(8), {9,17,25}(8),
    // {1,14,27}(13), {3,14,25}(11),
    // {7,14,21}(7), {9,14,19}(5)
    for(int i = 1; i < 4; i++){
        int j = i+12;
        int k = i+24;
        if (board[i] == board[j] && board[i] == board[k] && board[i]!='?'){
            return true;
        }
    }
    for(int i = 7; i < 10; i++){
        int j = i+6;
        int k = i+12;
        if (board[i] == board[j] && board[i] == board[k] && board[i]!='?'){
            return true;
        }
    }
    for(int i = 1; i < 8; i+=3){
        int j = i+10;
        int k = i+20;
        if (board[i] == board[j] && board[i] == board[k] && board[i]!='?'){
            return true;
        }
    }
    for(int i = 3; i < 10; i+=3){
        int j = i+8;
        int k = i+16;
        if (board[i] == board[j] && board[i] == board[k] && board[i]!='?'){
            return true;
        }
    }

    if (board[14] != '?' && ((board[14] == board[3] && board[14] == board[25])
    || (board[14] == board[1] && board[14] == board[27])
    || (board[14] == board[7] && board[14] == board[21])
    || (board[14] == board[9] && board[14] == board[19]))){
        return true;
    }

    // Else, return false
    return false;

}

bool checkifLegal(int cellNbre, char board[])
{
    if (cellNbre < 1 || cellNbre > 27 ) return false;
    return (board[cellNbre] == '?') ? true : false;
}

void computerMove(char board[])
{
    for(int i = 1; i < 28; i++){
        if(checkifLegal(i,board)){
            board[i] = 'o';
            /* for debugging purposes */
            // cout << "testing iteration " << i << endl;
            // displayBoard(board);
            /* for debugging purposes */
            if (checkWinner(board)) return;
            board[i] = '?';
        }
    }
    for(int i = 1; i < 28; i++){
        if(checkifLegal(i,board)){
            board[i] = 'x';
            if (checkWinner(board)) {
                board[i] = 'o';
                return;
            }
            board[i] = '?';
        }
    }
    int i = rand() % 27 + 1;
    while (!checkifLegal(i, board)){
        i = rand() % 27 + 1;
    }
    board[i] = 'o';

}