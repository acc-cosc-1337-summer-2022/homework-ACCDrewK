// cpp
#include "tic_tac_toe.h"
#include <iostream>
using std::cout;
using std::string;

bool TicTacToe::game_over() { return check_board_full(); }

void TicTacToe::start_game(std::string first_player) {
  player = first_player;
  clear_board();
};

// private functions
void TicTacToe::clear_board() {
  for (auto &peg : pegs) {
    peg = " ";
  }
}

void TicTacToe::mark_board(int position) {
  pegs[position - 1] = player;
  set_next_player();
}

void TicTacToe::set_next_player() {
  if (player == "X") {
    player = "O";
  } else {
    player = "X";
  }
}

void TicTacToe::display_board() {
  for (int i = 0; i < pegs.size(); i += 3) {
    cout << pegs[i] << "|" << pegs[i + 1] << "|" << pegs[i + 2] << "\n";
  }
}

bool TicTacToe::check_board_full() {
  for (int i = 0; i < pegs.size(); i++) {
    if (pegs[i] == " ") {
      return false;
    }
  }
  return true;
}