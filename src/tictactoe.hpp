
#pragma once
#include <string>
#include <vector>

class TicTacToe
{
private:
    std::vector<std::string> board;
    std::string currentPlayer;

public:
    TicTacToe();
    void printBoard() const;
    bool makeMove(short cell);
    bool checkWin() const;
    bool checkDraw() const;
    void switchPlayer();
    std::string getCurrentPlayer() const;
    void resetBoard();
};