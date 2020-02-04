#include <iostream>
#include "functions.h"
using namespace std;
int main() {
    bool playerTurn;
    int location;
    greetAndInstruct();
    char * board = new char[28];
    /* initialize board */
    for (int i = 1; i < 28; i++){
        board[i] = '?';
    }
    cout << "Current Board:" << endl;
    displayBoard(board);
    while (!checkWinner(board))
    {
        playerTurn = true;
        cout << "Please enter the location you want to place your x:" << endl;
        cin >> location;
        while (!checkifLegal(location,board)){
            cout << "Invalid move! Please enter the location again:" << endl;
            cin >> location;
        }
        board[location] = 'x';
        cout << "Your Move:" << endl;
        displayBoard(board);
        if (!checkWinner(board)){
            cout << "Computer Move:" << endl;
            playerTurn = false;
            computerMove(board);
            displayBoard(board);
        }
    }
    // It has been mathematically proved that TicTacToe 3D does not have a tie condition. So we do not worry about it.
    if (playerTurn == true){
        cout << "Congrats! You WIN!" << endl;
        cout << "Final Board:" << endl;
        displayBoard(board);
    } else {
        cout << "CPU WIN!" << endl;
        cout << "Final Board:" << endl;
        displayBoard(board);
    }
}
