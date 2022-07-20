#include "tic_tac_toe_4.h"
#include <iostream>
using std::cout;
using std::endl;

bool TicTacToe4::check_column_win() {
  bool win = false;
  if (pegs[0] == pegs[4] && pegs[4] == pegs[8] && pegs[8] == pegs[12]) {
    if (pegs[0] != " ")
      win = true;
  }
  if (pegs[1] == pegs[5] && pegs[5] == pegs[9] && pegs[9] == pegs[13]) {
    if (pegs[1] != " ") {
      win = true;
    }
  }
  if (pegs[2] == pegs[6] && pegs[6] == pegs[10] && pegs[10] == pegs[14]) {
    if (pegs[2] != " ") {
      win = true;
    }
  }
  if (pegs[3] == pegs[7] && pegs[7] == pegs[11] && pegs[11] == pegs[15]) {
    if (pegs[3] != " ") {
      win = true;
    }
  }
  return win;
}

bool TicTacToe4::check_row_win() {
  bool win = false;
  if (pegs[0] == pegs[1] && pegs[1] == pegs[2] && pegs[2] == pegs[3]) {
    if (pegs[0] != " ")
      win = true;
  }
  if (pegs[4] == pegs[5] && pegs[5] == pegs[6] && pegs[6] == pegs[7]) {
    if (pegs[4] != " ") {
      win = true;
    }
  }
  if (pegs[8] == pegs[9] && pegs[9] == pegs[10] && pegs[10] == pegs[11]) {
    if (pegs[8] != " ") {
      win = true;
    }
  }
  if (pegs[12] == pegs[13] && pegs[13] == pegs[14] && pegs[14] == pegs[15]) {
    if (pegs[12] != " ") {
      win = true;
    }
  }
  return win;
}

bool TicTacToe4::check_diagonal_win() {
  bool win = false;
  if (pegs[0] == pegs[5] && pegs[5] == pegs[10] && pegs[10] == pegs[15]) {
    if (pegs[0] != " ") {
      win = true;
    }
  }
  if (pegs[12] == pegs[9] && pegs[9] == pegs[6] && pegs[6] == pegs[3]) {
    if (pegs[12] != " ") {
      win = true;
    }
  }
  return win;
}

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15
else
false
*/

/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal
12,13,14, 15 are equal
*/

/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15

*/
