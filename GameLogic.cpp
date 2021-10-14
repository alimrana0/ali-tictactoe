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
  // TODO
}

void game_display_board_and_input_next_move(Board & board) {
  error_exit(); // TODO
}
