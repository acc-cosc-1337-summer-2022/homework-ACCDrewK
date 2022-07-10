#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include <string>
#include <vector>

TEST_CASE("Verify Test Configuration", "verification")
{
    REQUIRE(true == true);
}

TEST_CASE("Verify game_over functions", "game_over")
{
    TicTacToe game;
    REQUIRE(game.game_over() == false);
}

TEST_CASE("Test if the board is full")
{
    TicTacToe game;
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(7);
    REQUIRE(game.game_over() == false);
    game.mark_board(6);
    REQUIRE(game.game_over() == false);
    game.mark_board(9);
    REQUIRE(game.game_over() == false);
    game.mark_board(8);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test start_game, player X")
{
    TicTacToe game;
    std::string player{"X"};
    game.start_game(player);
    REQUIRE(game.get_player() == player);
}

TEST_CASE("Test start_game, Player O")
{
    TicTacToe game;
    std::string player{"O"};
    game.start_game(player);
    REQUIRE(game.get_player() == player);
}

/**
 * Tests for a draw game
 * Final board after all moves (for "X"):
 * X|O|X
 * X|O|O
 * O|X|X
 * Opposite board will result for player "O"
 */
TEST_CASE("Test get_winner, Draw")
{
    std::string players[2]{"X", "O"};
    for (auto &p : players)
    {
        TicTacToe game;
        game.start_game(p);
        game.mark_board(1);
        REQUIRE(game.game_over() == false);
        game.mark_board(5);
        REQUIRE(game.game_over() == false);
        game.mark_board(9);
        REQUIRE(game.game_over() == false);
        game.mark_board(2);
        REQUIRE(game.game_over() == false);
        game.mark_board(8);
        REQUIRE(game.game_over() == false);
        game.mark_board(7);
        REQUIRE(game.game_over() == false);
        game.mark_board(3);
        REQUIRE(game.game_over() == false);
        game.mark_board(6);
        REQUIRE(game.game_over() == false);
        game.mark_board(4);
        REQUIRE(game.game_over() == true);
        REQUIRE(game.get_winner() == "C");
    }
}

/* Player wins through first column */
TEST_CASE("Test get_winner, First column win")
{
    std::string players[2]{"X", "O"};
    for (auto &p : players)
    {
        TicTacToe game;
        game.start_game(p);
        game.mark_board(1);
        REQUIRE(game.game_over() == false);
        game.mark_board(2);
        REQUIRE(game.game_over() == false);
        game.mark_board(4);
        REQUIRE(game.game_over() == false);
        game.mark_board(3);
        REQUIRE(game.game_over() == false);
        game.mark_board(7);
        REQUIRE(game.game_over() == true);
        REQUIRE(game.get_winner() == p);
    }
}

/* Player wins through second column */
TEST_CASE("Test get_winner, Second column win")
{
    std::string players[2]{"X", "O"};
    for (auto &p : players)
    {
        TicTacToe game;
        game.start_game(p);
        game.mark_board(2);
        REQUIRE(game.game_over() == false);
        game.mark_board(1);
        REQUIRE(game.game_over() == false);
        game.mark_board(5);
        REQUIRE(game.game_over() == false);
        game.mark_board(3);
        REQUIRE(game.game_over() == false);
        game.mark_board(8);
        REQUIRE(game.game_over() == true);
        REQUIRE(game.get_winner() == p);
    }
}

/* Player wins through third column */
TEST_CASE("Test get_winner, Third column win")
{
    std::string players[2]{"X", "O"};
    for (auto &p : players)
    {
        TicTacToe game;
        game.start_game(p);
        game.mark_board(3);
        REQUIRE(game.game_over() == false);
        game.mark_board(1);
        REQUIRE(game.game_over() == false);
        game.mark_board(6);
        REQUIRE(game.game_over() == false);
        game.mark_board(2);
        REQUIRE(game.game_over() == false);
        game.mark_board(9);
        REQUIRE(game.game_over() == true);
        REQUIRE(game.get_winner() == p);
    }
}

/* Player wins through first row */
TEST_CASE("Test get_winner, First row win")
{
    std::string players[2]{"X", "O"};
    for (auto &p : players)
    {
        TicTacToe game;
        game.start_game(p);
        game.mark_board(1);
        REQUIRE(game.game_over() == false);
        game.mark_board(4);
        REQUIRE(game.game_over() == false);
        game.mark_board(2);
        REQUIRE(game.game_over() == false);
        game.mark_board(5);
        REQUIRE(game.game_over() == false);
        game.mark_board(3);
        REQUIRE(game.game_over() == true);
        REQUIRE(game.get_winner() == p);
    }
}

/* Player wins through second row */
TEST_CASE("Test get_winner, Second row win")
{
    std::string players[2]{"X", "O"};
    for (auto &p : players)
    {
        TicTacToe game;
        game.start_game(p);
        game.mark_board(4);
        REQUIRE(game.game_over() == false);
        game.mark_board(1);
        REQUIRE(game.game_over() == false);
        game.mark_board(5);
        REQUIRE(game.game_over() == false);
        game.mark_board(2);
        REQUIRE(game.game_over() == false);
        game.mark_board(6);
        REQUIRE(game.game_over() == true);
        REQUIRE(game.get_winner() == p);
    }
}

/* Player wins through third row */
TEST_CASE("Test get_winner, Third row win")
{
    std::string players[2]{"X", "O"};
    for (auto &p : players)
    {
        TicTacToe game;
        game.start_game(p);
        game.mark_board(7);
        REQUIRE(game.game_over() == false);
        game.mark_board(1);
        REQUIRE(game.game_over() == false);
        game.mark_board(8);
        REQUIRE(game.game_over() == false);
        game.mark_board(2);
        REQUIRE(game.game_over() == false);
        game.mark_board(9);
        REQUIRE(game.game_over() == true);
        REQUIRE(game.get_winner() == p);
    }
}

/* Player wins through 7-5-3 diagonal */
TEST_CASE("Test get_winner, Forward diagonal win")
{
    std::string players[2]{"X", "O"};
    for (auto &p : players)
    {
        TicTacToe game;
        game.start_game(p);
        game.mark_board(7);
        REQUIRE(game.game_over() == false);
        game.mark_board(1);
        REQUIRE(game.game_over() == false);
        game.mark_board(5);
        REQUIRE(game.game_over() == false);
        game.mark_board(2);
        REQUIRE(game.game_over() == false);
        game.mark_board(3);
        REQUIRE(game.game_over() == true);
        REQUIRE(game.get_winner() == p);
    }
}

/* Player wins through 1-5-9 diagonal */
TEST_CASE("Test get_winner, Backward diagonal win")
{
    std::string players[2]{"X", "O"};
    for (auto &p : players)
    {
        TicTacToe game;
        game.start_game(p);
        game.mark_board(1);
        REQUIRE(game.game_over() == false);
        game.mark_board(2);
        REQUIRE(game.game_over() == false);
        game.mark_board(5);
        REQUIRE(game.game_over() == false);
        game.mark_board(3);
        REQUIRE(game.game_over() == false);
        game.mark_board(9);
        REQUIRE(game.game_over() == true);
        REQUIRE(game.get_winner() == p);
    }
}

/* Test already_played function */
TEST_CASE("Test already_played function")
{
    TicTacToe game;
    std::vector<int> past_positions{0};
    int position{1};
    std::string player{"X"};
    game.start_game(player);
    game.mark_board(position);
    REQUIRE(already_played(position, past_positions) == false);
    past_positions.push_back(position);
    REQUIRE(already_played(position, past_positions) == true);
}