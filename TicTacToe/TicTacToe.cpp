#include <iostream>
#include <string>

std::string spacer = " | ";
bool someoneWon = false;
char board[10];
bool player1turn = true;

void setPieces() {
    board[1] = '1';
    board[2] = '2';
    board[3] = '3';
    board[4] = '4';
    board[5] = '5';
    board[6] = '6';
    board[7] = '7';
    board[8] = '8';
    board[9] = '9';
}
void updateBoard() {
    for (int i = 1; i <= 9; i++) {
        std::cout << spacer << board[i];
        if (i % 3 == 0) {
            std::cout << spacer << "\n";
        }
    }
}

void makeMove() {
    char playedPiece;
    int userinput;
    if (player1turn == true) {
        playedPiece = 'X';
        std::cout << "It's Player 1's turn! 'X' ";
    }
    else {
        playedPiece = 'O';
        std::cout << "It's player 2's turn! 'O'";
    }
    std::cout << "Please write a number between 1 and 9.\n";
    std::cin >> userinput;
    while (userinput < 1 || userinput > 9 || board[userinput] == 'X' || board[userinput] == 'O') {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Please enter a valid selection.\n";
        std::cin >> userinput;
    }
    board[userinput] = playedPiece;
    
}

bool checkForWinners() {
    if (board[1] == board[2] && board[2] == board[3]) {
        return true;
    }
    else if (board[4] == board[5] && board[5] == board[6]) {
        return true;
    }
    else if (board[7] == board[8] && board[8] == board[9]) {
        return true;
    } //Checks all horizontal places

    else if (board[1] == board[4] && board[4] == board[7]) {
        return true;
    }
    else if (board[2] == board[5] && board[5] == board[8]) {
        return true;
    }
    else if (board[3] == board[6] && board[6] == board[9]) {
        return true;
    } //Checks all vertical spaces

    else if (board[1] == board[5] && board[5] == board[9]) {
        return true;
    }
    else if (board[3] == board[5] && board[5] == board[7]) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    setPieces();
    while (someoneWon == false)
    {
        system("cls");
        std::cout << "Welcome to TicTacToe!\n";
        updateBoard();
        makeMove();
        if (checkForWinners() == true) {
            system("cls");
            std::cout << "Welcome to TicTacToe!\n";
            updateBoard();
            if (player1turn == true) {
                std::cout << "Player 1 has won!";
            }
            else {
                std::cout << "Player 2 has won!";
            }
            someoneWon = true;
        }
        player1turn = !player1turn;
    }
}

