#include "GameLogic.hpp"

#include "Board.hpp"
#include "Util.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;



const string PROMPT_BOARD_SIZE = "Input board size (2-5):";
const string PROMPT_MOVE_X = "Enter row and column for X:";
const string PROMPT_MOVE_O = "Enter row and column for O:";
const string PROMPT_TIE = "Tie game!";
const string PROMPT_WIN_X = "X wins!";
const string PROMPT_WIN_O = "O wins!";
const string MESSAGE_ERROR = "Invalid input.";



// exit with success.
void success_exit() {
  exit(0);
}

// print an error message and exit with error.
void error_exit() {
  cout << MESSAGE_ERROR << endl;
  exit(-1);
}



void game_input_board_size(Board & board) {
  
  cout << PROMPT_BOARD_SIZE << endl;
  unsigned int temp_board_size;
  if(!(cin >> temp_board_size) || temp_board_size < 2 || temp_board_size > 5) {
    error_exit();
  }
  else {
  board_reset_size(board, temp_board_size);
  }

}

void game_display_board_and_input_next_move(Board & board) {
  unsigned int row;
  unsigned int column;

    if(board_get_status(board) == (GameStatus::PLAYING_X_TURN)) {
    cout << PROMPT_MOVE_X << endl;
    if(!(cin >> row && cin >> column) || row >= board.size || column >= board.size) {
      error_exit();
    }
    else if(!(board_make_move(board, row, column))) {
      error_exit();
    }
    }
    if(board_get_status(board) == (GameStatus::PLAYING_O_TURN)) {
    cout << PROMPT_MOVE_O << endl;
    if(!(cin >> row && cin >> column) || row >= board.size || column >= board.size) {
      error_exit();
    }
    else if(!(board_make_move(board, row, column))) {
      error_exit();
    }
    }
  if(board_get_status(board) == (GameStatus::OVER_TIE)) {
    cout << PROMPT_TIE << endl;
    success_exit();
  }
  if(board_get_status(board) == (GameStatus::OVER_X_WON)) {
    cout << PROMPT_WIN_X << endl;
    success_exit();
  }
  if(board_get_status(board) == (GameStatus::OVER_O_WON)) {
    cout << PROMPT_WIN_O << endl;
    success_exit();
  }
}
