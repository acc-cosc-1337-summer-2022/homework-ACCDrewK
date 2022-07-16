#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::make_unique;
using std::string;
using std::unique_ptr;
using std::vector;

int main() {
  unique_ptr<TicTacToe> game{nullptr};
  string first_player{""};
  char user_choice{'Y'};
  vector<int> past_positions{0};
  int game_size{3}, number_of_cells{9};

  cout << "Welcome to TicTacToe!" << endl;
  cout << "\nThe first player should choose a symbol first, the other player will take the other symbol. The first "
          "player to fill in a row, a column, or a diagonal line from corner to corner with their symbol wins. Good "
          "luck!\n"
       << endl;

  // main program loop
  do {
    // game setup phase
    game_size = get_game_size();
    number_of_cells = game_size * game_size;
    if (game_size == 3) {
      game = make_unique<TicTacToe3>();
    } else if (game_size == 4) {
      game = make_unique<TicTacToe4>();
    }
    past_positions.clear();         // clear previous positions
    first_player = select_player(); // reset player symbol for each game
    game->start_game(first_player);
    int position{0};

    // playing loop
    play_game(*game, position, past_positions, number_of_cells);

    // game end
    if (game->get_winner() != "C") {
      cout << "The winner is..." << game->get_winner() << "!!\n";
    } else {
      cout << "The game is a draw." << endl;
    }
    cout << "Game over!\nDo you want to play again? (y/n): ";
    cin >> user_choice;
  } while (user_choice == 'y' || user_choice == 'Y');
  cout << "Thanks for playing!" << endl;
  return 0;
}