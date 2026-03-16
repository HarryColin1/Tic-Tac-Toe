#include <iostream>
#include "src/tictactoe.hpp"
#include <sstream>
#include <string>


using namespace std;

int main()
{
  TicTacToe game;
  string playAgain = "yes";

  while (playAgain == "yes")
  {
    game.resetBoard();
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!\n";

    while (!gameOver)
    {
      game.printBoard();
      string input;
      short move = 0;
      bool validMove = false;

      while (!validMove)
      {
        cout << "Player " << game.getCurrentPlayer() << ", enter your move: ";
        getline(cin, input);
        stringstream ss(input);

        if ((ss >> move) && ss.eof() && game.makeMove(move))
        {
          validMove = true;
        }
        else
        {
          cout << "Invalid move! Try again.\n";
        }
      }

      if (game.checkWin())
      {
        game.printBoard();
        cout << "Player " << game.getCurrentPlayer() << " wins!\n";
        gameOver = true;
      }
      else if (game.checkDraw())
      {
        game.printBoard();
        cout << "The game is a draw!\n";
        gameOver = true;
      }
      else
      {
        game.switchPlayer();
      }
    }

    bool validResponse = false;
    while (!validResponse)
    {
      cout << "Would you like to play again (yes/no)? ";
      getline(cin, playAgain);

      if (playAgain == "yes" || playAgain == "no")
      {
        validResponse = true;
      }
      else
      {
        cout << "That is not a valid entry!\n";
      }
    }
  }

  cout << "Goodbye!\n";
  return 0;
}