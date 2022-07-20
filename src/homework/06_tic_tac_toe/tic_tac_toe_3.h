// h
#ifndef TIC_TAC_TOE_3_H
#define TIC_TAC_TOE_3_H
#include "tic_tac_toe.h"

// A 3x3 tic tac toe matrix
class TicTacToe3 : public TicTacToe {
public:
  TicTacToe3() : TicTacToe(3){};

private:
  bool check_column_win() override;
  bool check_row_win() override;
  bool check_diagonal_win() override;
};

#endif // TIC_TAC_TOE_3_H