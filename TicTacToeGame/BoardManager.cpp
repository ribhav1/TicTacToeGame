#include "BoardManager.h"

void BoardManager::PrintBoard()
{
    std::cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "| ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n-------------\n";
    }
}

void BoardManager::MakeMove(std::string xo, int row, int col)
{
    board[row - 1][col - 1].replace(0, -1, xo);
}

bool BoardManager::CheckForWin(std::string xo, int rowMove, int colMove)
{
    int row = rowMove - 1;
    int col = colMove - 1;
    bool hasWon = false;

    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == xo && board[i][1] == xo && board[i][2] == xo)
        {
            hasWon = true;
        }
        if (board[0][i] == xo && board[1][i] == xo && board[2][i] == xo)
        {
            hasWon = true;
        }
    }
    if (board[0][0] == xo && board[1][1] == xo && board[2][2] == xo)
    {
        hasWon = true;
    }
    if (board[0][2] == xo && board[1][1] == xo && board[2][0] == xo)
    {
        hasWon = true;
    }

    return hasWon;
}

bool BoardManager::CheckValidMove(int rowMove, int colMove)
{

    return board[rowMove - 1][colMove - 1] == " ";
}
