#include "Board.hpp"

#include <iostream>
using namespace std;



void board_reset_size(Board & board, unsigned int size)
{
  board.size = size;
  for(unsigned int i = 0; i < board.size; i++) {
    vector<Space> tempVector;
      for(unsigned int j = 0; j < board.size; j++){
          tempVector.push_back(Space::BLANK);  
      }
     board.spaces.push_back(tempVector);
  }
  
}

bool board_make_move(Board & board, unsigned int row, unsigned int column)
{

  if(board.spaces[row][column] == Space::BLANK) {
    if(board.next_move == Space::X) {
    board.spaces[row][column] = Space::X;
    }
    else {
      board.spaces[row][column] = Space::O;
    }
    return true; 
  }
  else {return false;}

  if(board.next_move == Space::X) {
  board.next_move = Space::O;
  }
  else {board.next_move = Space::X;}
  
}

GameStatus board_get_status(const Board & board) {
  bool sameElementRow;
  bool sameElementCol;
  bool sameElementDiagonalL = true;
  bool sameElementDiagonalR = true;
  Space firstElementDiagonalL = board.spaces[0][0];
  Space firstElementDiagonalR = board.spaces[board.size - 1][board.size - 1];
  unsigned int boardFill = 0;

  // checks the status of horizontal and vertical sameness
  for (unsigned int i = 0; i < board.size; i++) {
    Space firstElement = board.spaces[i][i];
    sameElementRow = true;
    sameElementCol = true;
    if (firstElement != Space::BLANK) {
      ++boardFill;
    }
    for (unsigned int j = 0; i < board.size; j++) {
      sameElementRow = sameElementRow && board.spaces[i][j] == firstElement;
      if (board.spaces[i][j] != Space::BLANK) {
        ++boardFill;
      }
      sameElementCol = sameElementRow && board.spaces[j][i] == firstElement;
    }
    if (sameElementRow || sameElementCol) {
      if (firstElement == Space::X) {
        return GameStatus::OVER_X_WON;
      } else if (firstElement == Space::O) {
        return GameStatus::OVER_O_WON;
      }
    }
  }
  if (sameElementDiagonalL || sameElementDiagonalR) {
    if (sameElementRow || sameElementCol) {
      if (firstElementDiagonalL == Space::X || firstElementDiagonalR == Space::X ) {
        return GameStatus::OVER_X_WON;
      } else if (firstElementDiagonalL == Space::O || firstElementDiagonalR == Space::O) {
        return GameStatus::OVER_O_WON;
      }
    }
  }

  if (boardFill < board.size * board.size) {
    if (board.next_move == Space::X) {
    return GameStatus :: PLAYING_X_TURN;
    } else if (board.next_move == Space::O) {
    return GameStatus :: PLAYING_O_TURN;
    }
  }
  return GameStatus::OVER_TIE;
}


void board_print(const Board & board)
{
  for(unsigned int r = 0; r < board.spaces.size(); r++) {
    for(unsigned int c = 0; c < board.spaces[r].size(); c++) {
      if(c == board.spaces[r].size() - 1){
        if (board.spaces[r][c] == Space::X) {
        cout << "X" << endl;
        for(unsigned int i = 0; i <= board.spaces.size(); i++) {
          cout << "-";
        }
        cout << endl;
      }
      else if(board.spaces[r][c] == Space::O) {
        cout << "O" << endl;
        for(unsigned int i = 0; i <= board.spaces.size(); i++) {
          cout << "-";
        }
        cout << endl;
      }
      else if(board.spaces[r][c] == Space::BLANK) {
        cout << " " << endl;
        for(unsigned int i = 0; i <= board.spaces.size(); i++) {
          cout << "-";
        }
        cout << endl;
      }
      }
      else {
      if (board.spaces[r][c] == Space::X) {
        cout << "X|";
      }
      else if(board.spaces[r][c] == Space::O) {
        cout << "O|";
      }
      else if(board.spaces[r][c] == Space::BLANK) {
        cout << " |";
      }
      
    }
     
  }

  }
}
