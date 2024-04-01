#pragma once
#include <iostream>;
#include <string>;


class BoardManager
{
private:
    std::string board[3][3] = 
    {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "} 
    };

public:
    void PrintBoard();
    void MakeMove(std::string xo, int row, int col);
    bool CheckForWin(std::string xo, int rowMove, int colMove);
    bool CheckValidMove(int rowMove, int colMove);
};

