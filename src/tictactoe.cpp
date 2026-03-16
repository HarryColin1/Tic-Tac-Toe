#include "TicTacToe.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

TicTacToe::TicTacToe()
{
    resetBoard();
}

void TicTacToe::resetBoard()
{
    board.clear();
    for (short i = 1; i <= 9; ++i)
    {
        board.push_back(to_string(i));
    }
    currentPlayer = "X";
}

void TicTacToe::printBoard() const
{
    cout << "\n";
    cout << setw(3) << board[0] << " |" << setw(3) << board[1] << " |" << setw(3) << board[2] << "\n";
    cout << "----+----+----\n";
    cout << setw(3) << board[3] << " |" << setw(3) << board[4] << " |" << setw(3) << board[5] << "\n";
    cout << "----+----+----\n";
    cout << setw(3) << board[6] << " |" << setw(3) << board[7] << " |" << setw(3) << board[8] << "\n\n";
}

bool TicTacToe::makeMove(short cell)
{
    if (cell < 1 || cell > 9)
    {
        return false;
    }
    if (board[cell - 1] == "X" || board[cell - 1] == "O")
    {
        return false;
    }
    board[cell - 1] = currentPlayer;

    return true;
}

bool TicTacToe::checkWin() const
{
    short winConditions[8][3] =
    {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6}, {1,4,7},{2,5,8},
        {0,4,8}, {2,4,6}
    };

    for (short i = 0; i < 8; ++i)
    {
        short a = winConditions[i][0];
        short b = winConditions[i][1];
        short c = winConditions[i][2];

        if (board[a] == currentPlayer &&
            board[b] == currentPlayer &&
            board[c] == currentPlayer)
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe::checkDraw() const
{
    for (short i = 0; i < 9; ++i)
    {
        if (board[i] != "X" && board[i] != "O")
        {
            return false;
        }
    }
    return true;
}

void TicTacToe::switchPlayer()
{
    currentPlayer = (currentPlayer == "X") ? "O" : "X";
}

string TicTacToe::getCurrentPlayer() const
{
    return currentPlayer;
}