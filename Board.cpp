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
  board.next_move = Space::X;
  board_print(board);
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

    if(board.next_move == Space::X) {
      board.next_move = Space::O;
    } else {
      board.next_move = Space::X;
    }
    board_print(board);
    return true; 
  }
  else {return false;}


  
}

GameStatus board_get_status(const Board & board) {
  bool sameElementRow;
  bool sameElementCol;
  bool sameElementDiagonalL = true;
  bool sameElementDiagonalR = true;
  Space firstElementDiagonalL = board.spaces[0][0];
  Space firstElementDiagonalR = board.spaces[0][board.size - 1];
  unsigned int boardFill = 0;

  // checks the status of horizontal and vertical sameness
  for (unsigned int i = 0; i < board.size; i++) {
    Space firstElement = board.spaces[i][i];
    sameElementRow = true;
    sameElementCol = true;
    if (firstElement != Space::BLANK) {
      ++boardFill;
    }
    for (unsigned int j = 0; j < board.size; j++) {
      if (board.spaces[i][j] != Space::BLANK) {
        sameElementRow = sameElementRow && board.spaces[i][j] == firstElement;
        ++boardFill;
      } else {
        sameElementRow = false;
      }
      if (board.spaces[j][i] != Space::BLANK) {
        sameElementCol = sameElementCol && board.spaces[j][i] == firstElement;
      } else {
        sameElementCol = false;
      }
      if (board.spaces[i][i] != Space::BLANK) {
        sameElementDiagonalL = sameElementDiagonalL && board.spaces[i][i] == firstElement;
      } else {
        sameElementDiagonalL = false;
      }
    }
    if (sameElementRow || sameElementCol) {
      if (firstElement == Space::X) {
        return GameStatus::OVER_X_WON;
      } else if (firstElement == Space::O) {
        return GameStatus::OVER_O_WON;
      }
    }
  }
  unsigned int row = 0;
  unsigned int col = board.size -1;
  while (row < board.size) {
    if (board.spaces[row][col] != Space::BLANK) {
      sameElementDiagonalR = sameElementDiagonalR && board.spaces[row][col] == firstElementDiagonalR;
    } else {
      sameElementDiagonalR = false;
    }
    --col;
    ++row;
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
      if(r < board.spaces.size() && c == board.spaces[r].size() - 1){
        if (board.spaces[r][c] == Space::X) {
        cout << "X" << endl;
        if(r < board.spaces.size() -1) {
        for(unsigned int i = 0; i < board.spaces.size() + board.spaces.size() - 1; i++) {
          cout << "-";
        }
        cout << endl;
        }
      }
      else if(board.spaces[r][c] == Space::O) {
        cout << "O" << endl;
        if(r < board.spaces.size() -1) {
        for(unsigned int i = 0; i < board.spaces.size() + board.spaces.size() - 1; i++) {
          cout << "-";
        }
        cout << endl;
        }
      }
      else if(board.spaces[r][c] == Space::BLANK) {
        cout << " " << endl;
        if(r < board.spaces.size() -1) {
        for(unsigned int i = 0; i < board.spaces.size() + board.spaces.size() - 1; i++) {
          cout << "-";
        }
        cout << endl;
      }
      }
      }
      else {
        if(r == board.spaces.size() - 1 && c == board.spaces.size() - 1) {
          if (board.spaces[r][c] == Space::X) {
        cout << "X|" << endl;
      }
      else if(board.spaces[r][c] == Space::O) {
        cout << "O|" << endl;
      }
      else if(board.spaces[r][c] == Space::BLANK) {
        cout << " |" << endl;
      }
      

        }
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
