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
    while (!checkWinner(board))
    {
        displayBoard(board);
        cout << "Please enter the location you want to place your x:" << endl;
        cin >> location;
        while (!checkifLegal(location,board)){
            cout << "Invalid move! Please enter the location again:" << endl;
            cin >> location;
        }
        board[location] = 'x';
        cout << "Your Move:" << endl;
        displayBoard(board);
        cout << "Computer Move:" << endl;
        computerMove(board);
        displayBoard(board);
    }
}
