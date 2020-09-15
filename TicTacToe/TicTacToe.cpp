#include <iostream>
#include <string>

std::string spacer = " | ";
bool someoneWon = false;
char board[10];
bool player1turn = true;
bool player2exists = true;
int turn = 1;
char winLines[24] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '1', '4', '7', '2', '5', '8', '3', '6', '9', '1', '5', '9', '3', '5', '7' };

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
    for (int i = 1; i <= (sizeof(board)/sizeof(board[0]))-1; i++) {
        std::cout << spacer << board[i];
        if (i % 3 == 0) {
            std::cout << spacer << "\n";
        }
    }
}

int aiMoves() {
    int counter = 0;
    char searchfor = 'O';
    char selection = '0';
    char obtainedSpaces[3] = {'0','0','0'};
    //for (int i = 0; i < sizeof(winLines); i++) {
    //    if (i % 3 == 0) {
    //        std::cout << "inside for loop, looking for " << winLines[i]-'0' << winLines[i+1]-'0' << winLines[i+2]-'0' << "\n";
    //        if (counter == 2) {
    //            std::cout << "Board[winlines[i]] == " << board[winLines[i]-'0'] << " and winlines[i] == " << winLines[i] << "\n";
    //            if (board[winLines[i] -'0']-'0' == winLines[i] - '0') {
    //                selection = winLines[i];
    //                return selection - '0';
    //                std::cout << "Returning " << selection - '0' << "\n";
    //            }
    //            else if (board[winLines[i-1]-'0'] == winLines[i-1] - '0') {
    //                selection = winLines[i-1];
    //                return selection - '0';
    //                std::cout << "Returning " << selection - '0' << "\n";
    //            }
    //            else if (board[winLines[i-2]-'0'] == winLines[i-3 - '0']) {
    //                selection = winLines[i-2];
    //                return selection - '0';
    //                std::cout << "Returning " << selection - '0' << "\n";
    //            }
    //        }
    //        counter = 0;
    //    }
    //    if (board[winLines[i]-'0'] != winLines[i]) {
    //        counter++;
    //        std::cout << board[winLines[i]-'0'] << " != " << winLines[i] << ", counter = " << counter << "\n";
    //    }
    //    
    //}

    for (int i = 0; i < sizeof(winLines); i++) {
        if (board[winLines[i] - '0'] == searchfor) {
            obtainedSpaces[counter] = board[winLines[i]-'0'];
            counter++;

            //std::cout << board[winLines[i] - '0'] << "\nCounter er nå " << counter << "\n";
        }
        if ((i) % 3 == 0) {
            if (counter == 2) {
                if (obtainedSpaces[0] != searchfor) {
                    selection = obtainedSpaces[0];
                    std::cout << "returning " << obtainedSpaces[0] << "\n";
                }
                else if (obtainedSpaces[1] != searchfor) {
                    selection = obtainedSpaces[1];
                    std::cout << "returning " << obtainedSpaces[1] << "\n";
                }
                else if (obtainedSpaces[2] != searchfor) {
                    selection = obtainedSpaces[2];
                    std::cout << "returning " << obtainedSpaces[2] << "\n";
                }
            }
            counter = 0;
            obtainedSpaces[0] = {'0'};
            obtainedSpaces[1] = {'0'};
            obtainedSpaces[2] = {'0'};
        }
        
    }

    if (selection != '0') {
        return selection-'0';
        std::cout << "Returning " << selection - '0' << "\n";
    }
    
    
    /*if (turn == 1 && board[7] == '7') { //If the AI starts, it will play bottom left.
        return 7;
    }
    else if (turn == 3) {
        if (board[5] == 'X' && board[3] == '3') { //If the player selects the middle, AI will play top right.
            return 3;
        }
        else if (board[5] == '5') { //If the player doesn't select the middle, we play an adjacent corner
            if (board[4] == '4' && board[1] == '1') {
                return 1;
            }
            else if (board[8] == '8' && board[9] == '9') {
                return 9;
            }
        }
    }
    else if (turn == 5) {
        if (board[7] == 'O' && board[5] == 'X' && board[3] == 'O' && board[9] == 'X' && board[1] == '1') //If the player plays a corner for turn 4, the ai will select the remaining corner
        {
            return 1;
        }
        else if (board[7] == 'O' && board[5] == 'X' && board[3] == 'O' && board[1] == 'X' && board[9] == '9') //If the player plays a corner for turn 4, the ai will select the remaining corner
        {
            return 9;
        }
        else if (board[2] == 'X' && board[5] == 'X' && board[8] == '8') { //Block the player
            return 8;
        }
        else if (board[8] == 'X' && board[5] == 'X' && board[2] == '2') { //Block the player
            return 2;
        }
        else if (board[4] == 'X' && board[5] == 'X' && board[6] == '6') { //Block the player
            return 6;
        }
        else if (board[6] == 'X' && board[5] == 'X' && board[4] == '4') { //Block the player
            return 4;
        }

        else if (board[1] == 'O' && board[7] == 'O' && board[4] == '4') { //Win the game
            return 4;
        }
        else if (board[1] == 'O' && board[3] == 'O' && board[2] == '2') { //Block the player
            return 2;
        }
        else if (board[3] == 'O' && board[9] == 'O' && board[6] == '6') { //Block the player
            return 6;
        }
        else if (board[7] == 'O' && board[9] == 'O' && board[8] == '8') { //Block the player
            return 8;
        }
    }
    else if (turn == 7) {
        if (board[1] == board[3] && board[3] == 'O' && board[2] == '2') { //If the player falls in my trap the game is won right here in either of these
            return 2;
        }
        else if (board[3] == board[9] && board[9] == 'O' && board[6] == '6') {
            return 6;
        }
        else if (board[7] == board[9] && board[9] == 'O' && board[8] == '8') {
            return 8;
        }
        else if (board[1] == board[7] && board[7] == 'O' && board[4] == '4') {
            return 4;
        }
    }*/

    else {
        for (int i = 1; i <= 9; i++) {
            if (board[i] != 'X' && board[i] != 'O') { //failsafe to make sure it plays anything in case none of the above happen.
                return i;
                std::cout << "Checking " << i;
                break;
                
            }
        }
    }
}

void makeMove() {
    char playedPiece;
    int userinput;
    if (player2exists == true) {
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
    else if (player2exists == false) {
        if (player1turn == true) {
            playedPiece = 'X';
            std::cout << "It's Player 1's turn! 'X' ";

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
        else {
            playedPiece = 'O';
            board[aiMoves()] = playedPiece;
        }
    }
    
    
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
void oneOrTwoPlayers() {
    int answer = 0;
    std::cout << "Would you like to play against an AI or against someone locally?\n1. AI and you start\n2. AI and the AI starts\n3. Local multiplayer. 'splitscreen' if you can call it that.\n";
    std::cin >> answer;
    while (answer < 1 || answer > 3) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Please enter a valid number.\n";
        std::cin >> answer;
    }
    if (answer == 1) {
        player2exists = false;
    }
    else if (answer == 2) {
        player2exists = false;
        player1turn = false;
    }
    else if (answer == 3) {
        player2exists = true;
    }
}

int main()
{
    setPieces();
    oneOrTwoPlayers();
    while (someoneWon == false)
    {
        //system("cls");  
        std::cout << "Welcome to TicTacToe!\n";
        updateBoard();
        makeMove();
        if (checkForWinners() == true) {
            //system("cls");
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
        turn++;
        player1turn = !player1turn;
    }

    

}

