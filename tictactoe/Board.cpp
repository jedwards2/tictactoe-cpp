#include "Board.hpp"

Board::Board(){
  //set all squares to _ state
  for (int i{0}; i<m_board.size(); i++){
    for (int q{0}; q<m_board.size(); q++){
      m_board[i][q] = '_';
    }
  }
}

void Board::printBoard(){
  for (int i{0}; i<m_board.size(); i++){
    for (int q{0}; q<m_board.size(); q++){
      std::cout << m_board[i][q] << " ";
    }
    std::cout << "\n";
  }
}

void Board::setBoard(std::array<int, 2>& guessArray, int currentPlayer){
  if (currentPlayer){
    m_board[guessArray[0]][guessArray[1]] = 'O';
  } else {
    m_board[guessArray[0]][guessArray[1]] = 'X';
  }
}

bool Board::checkRow(const std::array<char, BOARD_SIZE>& row){
  const char check{row[0]};
  if (check == '_'){
    return false;
  }
  for (int i{0}; i<row.size(); i++){
    if (row[i] != check){
      return false;
    }
  }
  return true;
}

bool Board::checkColumn(int colNum){
  const char check{m_board[colNum][0]};
  if (check == '_'){
    return false;
  }
  for (int i{0}; i<m_board.size(); i++){
    if (m_board[i][colNum] != check){
      return false;
    }
  }
  return true;
}

bool Board::checkLeftDiagonal(){
  const char check{m_board[0][0]};
  if (check == '_'){
    return false;
  }
  for (int i{0}; i<m_board.size(); i++){
    if (m_board[i][i] != check){
      return false;
    }
  }
  return true;
}

bool Board::checkRightDiagonal(){
  const char check { m_board[m_board.size() - 1][0] };
  if (check == '_'){
    return false;
  }
  for (int i{0}; i<m_board.size(); i++){
    if (m_board[(m_board.size() - 1) - i][i] != check){
      return false;
    }
  }
  return true;
}

void Board::checkIfWon(){
  for (int i{0}; i<BOARD_SIZE; i++){
    if (checkRow(m_board[i]) || checkColumn(i) || checkLeftDiagonal() || checkRightDiagonal()){
      gameWon = true;
      return;
    }
  }
  gameWon = false;
}

