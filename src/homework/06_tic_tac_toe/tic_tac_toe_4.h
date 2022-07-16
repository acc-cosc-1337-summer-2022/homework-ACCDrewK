//h// h
#ifndef TIC_TAC_TOE_4_H
#define TIC_TAC_TOE_4_H
#include "tic_tac_toe.h"

// A 4x4 tic tac toe matrix
class TicTacToe4 : public TicTacToe {
public:
  TicTacToe4() : TicTacToe(4){};

private:
  bool check_column_win() override;
  bool check_row_win() override;
  bool check_diagonal_win() override;
};

#endif // TIC_TAC_TOE_4_H