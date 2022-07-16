// cpp
#include "tic_tac_toe.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// public functions
bool TicTacToe::game_over() {
  bool over_status{false};
  if (check_column_win()) {
    set_winner();
    over_status = true;
  } else if (check_row_win()) {
    set_winner();
    over_status = true;
  } else if (check_diagonal_win()) {
    set_winner();
    over_status = true;
  } else {
    over_status = check_board_full();
  }
  return over_status;
}

void TicTacToe::start_game(std::string first_player) {
  player = first_player;
  // cout << "Player 1 is now " << player << endl;
  winner = "C";  // reset the winner
  clear_board(); // clear board for first round
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
  // check board size, needs to be 9 or 16 cells
  if (pegs.size() == 16) {
    for (std::size_t i{0}; i < pegs.size(); i += 4) {
      cout << pegs[i] << "|" << pegs[i + 1] << "|" << pegs[i + 2] << "|" << pegs[i + 3] << endl;
    }
  } else if (pegs.size() == 9) {
    for (std::size_t i{0}; i < pegs.size(); i += 3) {
      cout << pegs[i] << "|" << pegs[i + 1] << "|" << pegs[i + 2] << endl;
    }
  } else {
    cout << "Warning: invalid size for board: " << pegs.size() << endl;
    // set length to 3, just to keep the program moving
    for (std::size_t i{0}; i < pegs.size(); i += 3) {
      cout << pegs[i] << "|" << pegs[i + 1] << "|" << pegs[i + 2] << endl;
    }
  }
}

bool TicTacToe::check_board_full() {
  for (std::size_t i{0}; i < pegs.size(); i++) {
    if (pegs[i] == " ") {
      return false; // an empty space found, board not full
    }
  }
  return true; // no empty spaces found, board full
}

void TicTacToe::set_winner() {
  if (player == "X") {
    winner = "O";
  } else if (player == "O") {
    winner = "X";
  } else {
    winner = "Invalid"; // In case player was not set correctly
  }
}

/* free functions */

bool already_played(int position, std::vector<int> &past_positions) {
  for (std::size_t i{0}; i < past_positions.size(); ++i) {
    if (past_positions[i] == position)
      return true;
  }
  return false;
}

int get_game_size() {
  int game_size{0};
  do {
    cout << "Do you wish to play a 3x3 game, or a 4x4 game? (enter 3 or 4): ";
    cin >> game_size;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Error: the program could not read your input, please try again." << endl;
    } else if (!(game_size == 3 || game_size == 4)) {
      cout << "Invalid input: you must enter either 3 or 4, please try again." << endl;
    } else {
      break;
    }
  } while (true);
  return game_size;
};

string select_player() {
  string first_player{""};
  do {
    do {
      if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
      }
      cout << "Choose 'X' or 'O' for the first player: ";
      cin >> first_player;
      if (cin.fail()) {
        cout << "Error: the program could not read your input, please try again." << endl;
      }
    } while (cin.fail());
    if (!(first_player == "X" || first_player == "O")) {
      cout << "Invalid player symbol; please choose \"X\" or \"O\"" << endl;
    }
  } while (!(first_player == "X" || first_player == "O"));
  return first_player;
}

void play_game(TicTacToe &game, int position, std::vector<int> &past_positions, int number_of_cells) {
  while (!(game.game_over())) {
    do {
      cout << "Enter a position: ";
      cin >> position;
      if (cin.fail()) {
        cout << "Error: you must enter a number for the position. Valid numbers are 1-" << number_of_cells << "."
             << endl;
        cin.clear();
        cin.ignore(100, '\n');
        continue;
      } else if (!(0 < position && position <= number_of_cells)) {
        cout << "Invalid position: you must choose a cell number between 1 and " << number_of_cells << endl;
        continue;
      } else if (already_played(position, past_positions)) {
        cout << "Invalid position: you must choose a cell that has not already been filled." << endl;
        continue;
      }
      break;
    } while (true);
    past_positions.push_back(position);
    game.mark_board(position);
    game.display_board();
  }
};
