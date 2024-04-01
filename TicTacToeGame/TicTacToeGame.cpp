#include <iostream>;
#include <string>;
#include "BoardManager.h";

BoardManager board;
bool playing = true;
bool xMove = true;
bool winner = false;

int col;
int row;

int main()
{
    std::cout << "Welcome" << std::endl << "Player 1 will be X, and Player 2 will be O" << std::endl;
    std::cout << "To make your move, please enter the row (1-3) and the column (1-3) where you would like to make your move with a space in between" << std::endl;

    while (playing)
    {
        bool isValidMove = false;

       board.PrintBoard();

       std::cout << (xMove ? "Player 1" : "Player2") << ", please make your move" << std::endl;
       std::cin >> row >> col;

       if (!board.CheckValidMove(row, col))
       {
           while (isValidMove == false)
           {
               std::cout << "Invalid move, please make a new move" << std::endl;
               std::cin >> row >> col;
               isValidMove = board.CheckValidMove(row, col);
           }
       }
       else
       {
           isValidMove = true;
       }

       if (xMove)
       {   
           board.MakeMove("X", row, col);
       }
       else
       {
           board.MakeMove("O", row, col);
       }

       if (board.CheckForWin((xMove ? "X" : "O"), row, col))
       {
           playing = false;
       }

       xMove = !xMove;

    }

    board.PrintBoard();
    std::cout << "Congratulations " << (!xMove ? "Player 1" : "Player 2") << " has won!";

    return 0;
}