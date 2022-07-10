// cpp
#include "tic_tac_toe.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

bool TicTacToe::game_over()
{
    bool over_status{false};
    if (check_column_win())
    {
        set_winner();
        over_status = true;
    }
    else if (check_row_win())
    {
        set_winner();
        over_status = true;
    }
    else if (check_diagonal_win())
    {
        set_winner();
        over_status = true;
    }
    else
    {
        over_status = check_board_full();
    }
    return over_status;
}

void TicTacToe::start_game(std::string first_player)
{
    player = first_player;
    winner = "C";  // reset the winner
    clear_board(); // clear board for first round
};

// private functions
void TicTacToe::clear_board()
{
    for (auto &peg : pegs)
    {
        peg = " ";
    }
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::set_next_player()
{
    if (player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }
}

void TicTacToe::display_board()
{
    for (int i = 0; i < pegs.size(); i += 3)
    {
        cout << pegs[i] << "|" << pegs[i + 1] << "|" << pegs[i + 2] << "\n";
    }
}

bool TicTacToe::check_board_full()
{
    bool board_full{true};
    for (int i = 0; i < pegs.size(); i++)
    {
        if (pegs[i] == " ")
        {
            board_full = false;
        }
    }
    return board_full;
}

// set winner to O if player is X, otherwise winner is X
void TicTacToe::set_winner()
{
    if (player == "X")
    {
        winner = "O";
    }
    else if (player == "O")
    {
        winner = "X";
    }
    else
    {
        winner = "Invalid"; // In case player was not set correctly
    }
}

bool TicTacToe::check_column_win()
{
    bool win = false;
    if (pegs[0] == pegs[3] && pegs[3] == pegs[6])
    {
        if (pegs[0] != " ")
            win = true;
    }
    if (pegs[1] == pegs[4] && pegs[4] == pegs[7])
    {
        if (pegs[1] != " ")
        {
            win = true;
        }
    }
    if (pegs[2] == pegs[5] && pegs[5] == pegs[8])
    {
        if (pegs[2] != " ")
        {
            win = true;
        }
    }
    return win;
}

bool TicTacToe::check_row_win()
{
    bool win = false;
    if (pegs[0] == pegs[1] && pegs[1] == pegs[2])
    {
        if (pegs[0] != " ")
            win = true;
    }
    if (pegs[3] == pegs[4] && pegs[4] == pegs[5])
    {
        if (pegs[3] != " ")
        {
            win = true;
        }
    }
    if (pegs[6] == pegs[7] && pegs[7] == pegs[8])
    {
        if (pegs[6] != " ")
        {
            win = true;
        }
    }
    return win;
}

bool TicTacToe::check_diagonal_win()
{
    bool win = false;
    if (pegs[0] == pegs[4] && pegs[4] == pegs[8])
    {
        if (pegs[0] != " ")
            win = true;
    }
    if (pegs[2] == pegs[4] && pegs[4] == pegs[6])
    {
        if (pegs[2] != " ")
        {
            win = true;
        }
    }
    return win;
}

/* free functions */

bool already_played(int position, std::vector<int> &past_positions)
{
    for (int i{0}; i < past_positions.size(); ++i)
    {
        if (past_positions[i] == position)
            return true;
    }
    return false;
}