#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdlib.h>

using namespace std;

//initialize board by putting 1-9 in an 2D array.
void initalize_board (char board[3][3]) {

    int positionvalues =0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            positionvalues++;
            board[i][j] = '0'+ positionvalues;
        }
    }
}


//print board on the screen.
void print_board(char board[3][3]) {

    for (int i = 0; i < 3; i++) {
        cout << endl;
        for (int j = 0; j < 3; j++) {
            cout << "  ";
            cout << board[i][j];
        }
    }
    cout << endl << endl;
}


//Check if there is a winner.
char check_win(char board[3][3]) {

    // Check horizontal, vertical & diagonal through [0][0]
    if ((board[0][0] == 'X' || board[0][0] == 'O') && (board[0][0] == board[0][1] && board[0][0] == board[0][2] ||
                                                       board[0][0] == board[1][0] && board[0][0] == board[2][0] ||
                                                       board[0][0] == board[1][1] && board[0][0] == board[2][2]))
        return board[0][0];

        // Check horizontal, vertical & diagonal through [1][1]
    else if ((board[1][1] == 'X' || board[1][1] == 'O') && (board[1][1] == board[1][0] && board[1][1] == board[1][2] ||
                                                            board[1][1] == board[0][1] && board[1][1] == board[2][1] ||
                                                            board[1][1] == board[2][0] && board[1][1] == board[0][2]))
        return board[1][1];

        // Check horizontal, vertical & diagonal through [2][2]
    else if ((board[2][2] == 'X' || board[2][2] == 'O') && (board[2][2] == board[0][2] && board[2][2] == board[1][2] ||
                                                            board[2][2] == board[2][0] && board[2][2] == board[2][1]))
        return board[2][2];

    else
        return 'R';
}


//minimax logarithm for the AI to select best move based on AI turn or Player turn..
int minimax(char board[3][3], char player1, char player2)
{
    int bestmovescore = -10;
    int thismovescore = -10;

    if (check_win(board) == player1)
        return 5;
    if (check_win(board) == player2)
        return -5;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O')
            {
                char initialvalue = board[i][j];
                board[i][j] = player1;
                thismovescore = -(minimax(board,player2, player1));
                if(thismovescore>=bestmovescore)
                {
                    bestmovescore=thismovescore;
                }
                board[i][j] = initialvalue;
            }
        }
    }
    if (bestmovescore == -10)
        return 0;

    else if (bestmovescore < 0)
        return bestmovescore + 1;

    else
        return bestmovescore - 1;
}


//function to decide best move for AI.
int findbestmove (char board[3][3],char player1, char player2)
{
    int bestmovescore = -10;
    int thismovescore = -10;
    int bestmoverow = -10;
    int bestmovecol = -10;


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O')
            {
                char initialvalue = board[i][j];
                board[i][j] = player1;
                thismovescore = -(minimax(board,player2,player1));
                if(thismovescore>=bestmovescore)
                {
                    bestmovescore=thismovescore;
                    bestmoverow = i;
                    bestmovecol = j;
                }
                board[i][j] = initialvalue;
            }
        }
    }
    return (10*bestmoverow+bestmovecol);
}

//Function that determine AI input position and put take move.
void ai_placement(char board[3][3],int moves)
{
    cout << "Emon's turn:" <<endl;
    if (moves<=1)
    {
        if(board[1][1] != 'X')
            board[1][1] = 'O';
        else
            board[0][0]= 'O';
    }
    else
    {
        int aimove = findbestmove(board,'O','X');
        int row = aimove/10;
        int col = aimove%10;
        board[row][col] = 'O';
    }

}


//Function for player move on board.
void player_placement(char board[3][3]) {

    int row = 0, col = 0;
    int plotposition = 0;

    while (true) {

        while(true)
        {
            cout << "Your turn. Enter position value: ";
            cin >> plotposition;
            if(plotposition>=1 && plotposition<=9)
            {
                switch(plotposition){
                    case 1:
                        row=0;
                        col=0;
                        break;
                    case 2:
                        row=0;
                        col=1;
                        break;
                    case 3:
                        row=0;
                        col=2;
                        break;
                    case 4:
                        row=1;
                        col=0;
                        break;
                    case 5:
                        row=1;
                        col=1;
                        break;
                    case 6:
                        row=1;
                        col=2;
                        break;
                    case 7:
                        row=2;
                        col=0;
                        break;
                    case 8:
                        row=2;
                        col=1;
                        break;
                    case 9:
                        row=2;
                        col=2;
                        break;
                }
                break;
            }
            else
            {
                cout <<"Invalid input." << endl;
                cin.clear();
                cin.ignore(123,'\n');
            }
        }

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = 'X';
            break;
        }
        else
            cout << "Invalid move" << endl;
    }
}

//Function to decide who does the first move.
bool determineTosswinner() {
    string choice;
    while (true) {
        cout << "Do you want to go first?(Y/N):";
        cin >> choice;
        if (choice == "Y" || choice == "y") {
            return true;
        } else if (choice == "N" || choice == "n") {
            return false;
        } else
            cout << "Invalid input. Please press Y/N only." << endl;
    }
//this portion of code is to select the first move player at random
//--------------------------------------------------------------------------------
//    int choice;
//    int tossResult;
//    srand(time(NULL));
//    bool returnvalue;
//    cout << "Let's toss to determine who goes first." << endl;
//
//    while(true)
//    {
//        cout << "Head or Tail? (Press 1 for head, 2 for tail): ";
//        cin >> choice;
//        if(choice==1 || choice==2)
//            {
//                break;
//            }
//        else
//            {
//                cout << "Press only 1 or 2" << endl;
//                cin.clear();
//                cin.ignore(123,'\n');
//            }
//    }
//
//    int toss = 1+rand()%10;
//
//    if(toss%2 == 1)
//    {
//        cout << "Head" <<endl;
//        tossResult = 1;
//    }
//    else
//    {
//        cout << "Tail" <<endl;
//        tossResult = 2;
//    }
//
//    (choice==tossResult) ? (returnvalue=true) : (returnvalue=false);
//
//    return returnvalue;
}

//function that control the game and run the game.
void play_game(char board[3][3]){

    bool toss = determineTosswinner();
    int moves = 0;
    char winner;
    while (moves < 9) {
        if(toss)
        {
            player_placement(board);
            toss = false;
        }
        else
        {
            ai_placement(board,moves);
            toss = true;
        }

        print_board(board);

        winner =check_win(board);

        if(winner == 'X')
        {
            cout <<"You won!" <<endl;
            break;
        }
        else if(winner == 'O')
        {
            cout <<"AI won! Better luck next time." <<endl;
            break;
        }
        moves++;
    }
    if(moves==9)
    {
        cout << "It's a Draw!!" << endl;
    }
}


//main function
int main() {

    cout << "!!! TIC TAC TOE !!!" << endl;
    cout << "Welcome to Emon's Tic Tac Toe, where you never win." << endl;
    cout << "Hi, my name is Emon. I am the AI of this game." << endl;

    char board[3][3];

    while(true)
    {
        initalize_board(board);

        print_board(board);

        play_game(board);

        bool correctinput;
        string playAgain;

        do
        {
            cout <<"Play Again?(Press Y/N): ";
            cin >>playAgain;
            if(playAgain == "Y" || playAgain == "y")
            {
                correctinput=true;
            }
            else if(playAgain=="N" || playAgain=="n")
            {
                return 0;
            }
            else
            {
                cout <<"Not understood. Please press Y to play again and N to quit."<<endl;
                correctinput=false;
            }
        }while(!correctinput);
    }
}

//The minimax concept was used being inspired from the tic tac toe solution from "https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-3-tic-tac-toe-ai-finding-optimal-move/"
//This youtube video helped to understand the minimax concept "https://www.youtube.com/watch?v=l-hh51ncgDI"