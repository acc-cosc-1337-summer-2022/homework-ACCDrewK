// h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include <memory>
#include <string>
#include <vector>

class TicTacToe {
public:
  TicTacToe(int n) : pegs(n * n, " "){};
  bool game_over();
  void start_game(std::string first_player);
  void mark_board(int position);
  std::string get_player() { return player; };
  void display_board();
  std::string get_winner() { return winner; };
  virtual ~TicTacToe(){};

protected:
  std::vector<std::string> pegs{""};
  virtual bool check_column_win() = 0;
  virtual bool check_row_win() = 0;
  virtual bool check_diagonal_win() = 0;

private:
  std::string player{""};
  std::string winner{"C"};
  void clear_board();
  void set_next_player();
  bool check_board_full();
  void set_winner();
};

/* free functions */

// Returns true if the position chosen by the player is already filled
bool already_played(int position, std::vector<int> &past_positions);

// Returns the game size the user chooses
int get_game_size();

// Returns the symbol the first player chooses
std::string select_player();

/* Starts the playing loop. Players will enter a postion to mark, then the board will be marked with their symbol.
Returns to main when a player wins the game, or when the board is full. */
void play_game(TicTacToe &game, int position, std::vector<int> &past_positions, int number_of_cells);

#endif // TIC_TAC_TOE_H