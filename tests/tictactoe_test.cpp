#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include "../src/tictactoe.hpp"

using namespace std;

TEST_CASE("TicTacToe basic functionality")
{
    TicTacToe game;

    SECTION("The initial board is empty and not won")
    {
        REQUIRE_FALSE(game.checkWin());
        REQUIRE_FALSE(game.checkDraw());
    }

    SECTION("Valid moves and player switch")
    {
        REQUIRE(game.makeMove(1));
        REQUIRE_FALSE(game.makeMove(1));
        game.switchPlayer();

        REQUIRE(game.getCurrentPlayer() == "O");
        REQUIRE(game.makeMove(2));
    }

    SECTION("Winning conditions")
    {
        game.makeMove(1);
        game.makeMove(4);
        game.makeMove(2);
        game.makeMove(5);
        game.makeMove(3);
        REQUIRE(game.checkWin() == true);
    }

    SECTION("Draw conditions")
    {
        short moves[] = {1, 2, 3, 5, 4, 6, 8, 7, 9};
        for (short move : moves)
        {
            game.makeMove(move);
            game.switchPlayer();
        }
        REQUIRE(game.checkDraw() == true);
        REQUIRE(game.checkWin() == false);
    }
}


TEST_CASE("TicTacToe Z.O.M.B.E or edge cases")
{
    TicTacToe game;

    SECTION("Invalid moves")
    {
        REQUIRE_FALSE(game.makeMove(0));
        REQUIRE_FALSE(game.makeMove(10));
        REQUIRE_FALSE(game.makeMove(-5));
    }

    SECTION("Move on occupied cells")
    {
        REQUIRE(game.makeMove(1));
        REQUIRE_FALSE(game.makeMove(1));
    }

    SECTION("Switch player consistently")
    {
        REQUIRE(game.getCurrentPlayer() == "X");
        game.switchPlayer();
        REQUIRE(game.getCurrentPlayer() == "O");
        game.switchPlayer();
        REQUIRE(game.getCurrentPlayer() == "X");
    }

    SECTION("Board reset clears cells")
    {
        game.makeMove(1);
        game.resetBoard();

        REQUIRE(game.getCurrentPlayer() == "X");
        REQUIRE(game.makeMove(1));
    }
}