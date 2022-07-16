#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <string>
#include <vector>

TEST_CASE("Verify Test Configuration") { REQUIRE(true == true); }

//! BEGIN TESTS FOR 3x3 GAME
TEST_CASE("Verify game_over function") {
  TicTacToe3 game;
  REQUIRE(game.game_over() == false);
}

TEST_CASE("Test 3x3 start_game, player X") {
  TicTacToe3 game;
  std::string player{"X"};
  game.start_game(player);
  REQUIRE(game.get_player() == player);
}

TEST_CASE("Test 3x3 start_game, Player O") {
  TicTacToe3 game;
  std::string player{"O"};
  game.start_game(player);
  REQUIRE(game.get_player() == player);
}

TEST_CASE("Test if the board is full") {
  TicTacToe3 game;
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

/**
 * Tests for a 3x3 draw game
 * Final board after all moves (for "X"):
 * X|O|X
 * X|O|O
 * O|X|X
 * Opposite board will result for player "O"
 */
TEST_CASE("Test get_winner, draw") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe3 game;
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
TEST_CASE("Test get_winner, First column win") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe3 game;
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
TEST_CASE("Test get_winner, Second column win") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe3 game;
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
TEST_CASE("Test get_winner, Third column win") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe3 game;
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
TEST_CASE("Test get_winner, First row win") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe3 game;
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
TEST_CASE("Test get_winner, Second row win") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe3 game;
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
TEST_CASE("Test get_winner, Third row win") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe3 game;
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
TEST_CASE("Test get_winner, Forward diagonal win") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe3 game;
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
TEST_CASE("Test get_winner, Backward diagonal win") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe3 game;
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
// * END 3x3 GAME TESTS

// ! BEGIN 4x4 GAME TESTS

// Board used for draw:
// --------------------
// X|O|X|O
// X|O|X|O
// X|O|X|O
// O|X|O|X
TEST_CASE("Test get_winner, draw 4") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe4 game;
    game.start_game(p);
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
    game.mark_board(6);
    REQUIRE(game.game_over() == false);
    game.mark_board(7);
    REQUIRE(game.game_over() == false);
    game.mark_board(8);
    REQUIRE(game.game_over() == false);
    game.mark_board(9);
    REQUIRE(game.game_over() == false);
    game.mark_board(10);
    REQUIRE(game.game_over() == false);
    game.mark_board(11);
    REQUIRE(game.game_over() == false);
    game.mark_board(12);
    REQUIRE(game.game_over() == false);
    game.mark_board(14);
    REQUIRE(game.game_over() == false);
    game.mark_board(15);
    REQUIRE(game.game_over() == false);
    game.mark_board(16);
    REQUIRE(game.game_over() == false);
    game.mark_board(13);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");
  }
}

TEST_CASE("Test get_winner, First column win 4") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe4 game;
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
    REQUIRE(game.game_over() == false);
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(13);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == p);
  }
}

TEST_CASE("Test get_winner, Second column win 4") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe4 game;
    game.start_game(p);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(6);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(10);
    REQUIRE(game.game_over() == false);
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(14);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == p);
  }
}

TEST_CASE("Test get_winner, Third column win 4") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe4 game;
    game.start_game(p);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(7);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(11);
    REQUIRE(game.game_over() == false);
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(15);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == p);
  }
}

TEST_CASE("Test get_winner, fourth column win 4") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe4 game;
    game.start_game(p);
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(8);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(12);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(16);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == p);
  }
}

TEST_CASE("Test get_winner, first row win 4") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe4 game;
    game.start_game(p);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(6);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(7);
    REQUIRE(game.game_over() == false);
    game.mark_board(4);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == p);
  }
}

TEST_CASE("Test get_winner, second row win 4") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe4 game;
    game.start_game(p);
    game.mark_board(5);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(6);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(7);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(8);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == p);
  }
}

TEST_CASE("Test get_winner, third row win 4") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe4 game;
    game.start_game(p);
    game.mark_board(9);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(10);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(11);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(12);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == p);
  }
}

TEST_CASE("Test get_winner, fourth row win 4") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe4 game;
    game.start_game(p);
    game.mark_board(13);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(14);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(15);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(16);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == p);
  }
}

/**
 * X|O|O|O
 *  |X| |
 *  | |X|
 *  | | |x
 */
TEST_CASE("Test get_winner, backward diagonal win 4") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe4 game;
    game.start_game(p);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(6);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(11);
    REQUIRE(game.game_over() == false);
    game.mark_board(4);
    REQUIRE(game.game_over() == false);
    game.mark_board(16);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == p);
  }
}

/**
 * O|O|O|X
 *  | |X|
 *  |X| |
 * X| | |
 */
TEST_CASE("Test get_winner, forward diagonal win 4") {
  std::string players[2]{"X", "O"};
  for (auto &p : players) {
    TicTacToe4 game;
    game.start_game(p);
    game.mark_board(13);
    REQUIRE(game.game_over() == false);
    game.mark_board(1);
    REQUIRE(game.game_over() == false);
    game.mark_board(10);
    REQUIRE(game.game_over() == false);
    game.mark_board(2);
    REQUIRE(game.game_over() == false);
    game.mark_board(7);
    REQUIRE(game.game_over() == false);
    game.mark_board(3);
    REQUIRE(game.game_over() == false);
    game.mark_board(4);
    game.game_over();
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == p);
  }
}
//* END 4x4 GAME TESTS

// Test already_played function
TEST_CASE("Test already_played function") {
  TicTacToe3 game;
  std::vector<int> past_positions{0};
  int position{1};
  std::string player{"X"};
  game.start_game(player);
  game.mark_board(position);
  REQUIRE(already_played(position, past_positions) == false);
  past_positions.push_back(position);
  REQUIRE(already_played(position, past_positions) == true);
}

TEST_CASE("Test already_played function 4") {
  TicTacToe4 game;
  std::vector<int> past_positions{0};
  int position{1};
  std::string player{"X"};
  game.start_game(player);
  game.mark_board(position);
  REQUIRE(already_played(position, past_positions) == false);
  past_positions.push_back(position);
  REQUIRE(already_played(position, past_positions) == true);
}
