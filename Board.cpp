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
  if(board.spaces[row][column] == Space::X || board.spaces[row][column] == Space::O) {
    return false;
  }
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

bool x_won(const Board & board) {
  int size = board.size;
  //Row fill
		for(int i = 0; i < size; ++i){
			for(int j = 0; j < size; ++j){
				if(board.spaces[i][j] != Space::X)
					break;
				if(j == (size-1))
					return true;
			}
		}

		//Column fill
		for(int i = 0; i < size; ++i)
			for(int j = 0; j < size; ++j){
				if(board.spaces[j][i] != Space::X)
					break;
				if(j == (size-1))
					return true;
			}
		
		//left down diagonal fill
		for(int i = 0; i < size; ++i){
			if(board.spaces[i][i] != Space::X)
				break;
			if(i == (size-1))
				return true;
		}
 
		//left up diagonal fill
		for(int i = 0; i < size; ++i){
			if(board.spaces[size - 1 - i][i] != Space::X)
				break;
			if(i == (size-1))
				return true;
		}
		return false;
}

bool o_won(const Board & board) {
  int size = board.size;
  //Row fill
		for(int i = 0; i < size; ++i){
			for(int j = 0; j < size; ++j){
				if(board.spaces[i][j] != Space::O)
					break;
				if(j == (size-1))
					return true;
			}
		}

		//Column fill
		for(int i = 0; i < size; ++i)
			for(int j = 0; j < size; ++j){
				if(board.spaces[j][i] != Space::O)
					break;
				if(j == (size-1))
					return true;
			}
		
		//left down diagonal fill
		for(int i = 0; i < size; ++i){
			if(board.spaces[i][i] != Space::O)
				break;
			if(i == (size-1))
				return true;
		}
 
		//left up diagonal fill
		for(int i = 0; i < size; ++i){
			if(board.spaces[size - 1 - i][i] != Space::O)
				break;
			if(i == (size-1))
				return true;
		}

		return false;
	}


GameStatus board_get_status(const Board & board) {
  if(x_won(board)) {
    return GameStatus::OVER_X_WON;
  }
  if(o_won(board)) {
    return GameStatus::OVER_O_WON;
  }
  unsigned int boardFill = 0;

  // checks the status of horizontal and vertical sameness
  for (unsigned int i = 0; i < board.size; i++) {
    for (unsigned int j = 0; j < board.size; j++) {
      if (board.spaces[i][j] != Space::BLANK) {
        ++boardFill;
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
