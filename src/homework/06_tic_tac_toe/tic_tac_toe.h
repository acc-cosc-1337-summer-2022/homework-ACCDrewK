// h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include <string>
#include <vector>

class TicTacToe
{
  public:
    bool game_over();
    void start_game(std::string first_player);
    void mark_board(int position);
    std::string get_player()
    {
        return player;
    }
    void display_board();
    std::string get_winner()
    {
        return winner;
    }

  private:
    std::string player{""};
    std::string winner{"C"};
    void clear_board();
    std::vector<std::string> pegs{9, " "};
    void set_next_player();
    bool check_board_full();
    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win();
    void set_winner();
};

/* free functions */
bool already_played(int position, std::vector<int> &past_positions);

#endif // TIC_TAC_TOE_H