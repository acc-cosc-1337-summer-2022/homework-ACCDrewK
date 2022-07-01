// h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include <string>
#include <vector>

class TicTacToe {
public:
  bool game_over();
  void start_game(std::string first_player);
  void mark_board(int position);
  std::string get_player();
  void display_board();

private:
  std::string player{""};
  void clear_board();
  std::vector<std::string> pegs{9, " "};
  void set_next_player();
  bool check_board_full();
};

#endif // TIC_TAC_TOE_H