#ifndef BOARD_H
#define BOARD_H
#include <array>
#include <stdio.h>
#include <iostream>

constexpr int BOARD_SIZE {2};

class Board
{
  private:
    std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE> m_board {};
    bool gameWon {false};
  public:
    Board();
    void printBoard();
    void setBoard(std::array<int, 2>& guessArray, int currentPlayer);
    void checkIfWon();
    bool checkColumn(int colNum);
    bool checkRow(const std::array<char, BOARD_SIZE>& row);
    bool checkRightDiagonal();
    bool checkLeftDiagonal();
    int size(){
      return static_cast<int>(m_board.size());
    }
    bool isGameWon(){
      return gameWon;
    }
};

#endif
