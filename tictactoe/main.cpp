#include <array>
#include <iostream>
#include <iterator>

//set compile-time const for board size, does not work due to check conditions
constexpr int BOARD_SIZE {3};

//forward declarations ------------------------------------------------
void printBoard(const std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board);
void setBoard(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, std::array<int, 2>& guessArray, int currentPlayer);
std::array<int, 2> getGuessArray();
int getIndividualGuess();
int switchPlayer(int currentPlayer);
bool checkIfWon(const std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, bool gameWon);
bool checkColumn(const std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, int colNum);
bool checkRow(const std::array<char, BOARD_SIZE>& row);
bool checkRightDiagonal(const std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board);
bool checkLeftDiagonal(const std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board);

int main(int argc, const char * argv[]) {
  //build initial multidimensional board array
  std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE> board {};
  
  bool gameWon {false};
  int currentPlayer{0};
  
  //set all squares to _ state
  for (int i{0}; i<board.size(); i++){
    for (int q{0}; q<board.size(); q++){
      board[i][q] = '_';
    }
  }
  
  while (!gameWon){
    printBoard(board);
    std::cout << "Current State of the Board" << "\n";
    
    //get array of 2 integers from player
    std::array<int, 2> guess {getGuessArray()};
    
    //update the board with currentPlayer's mark
    setBoard(board, guess, currentPlayer);
    
    //update current state of game
    gameWon = checkIfWon(board, gameWon);
    
    //update the current Player
    currentPlayer = switchPlayer(currentPlayer);
  }
  
  return 0;
}

int getIndividualGuess(){
  int guess {-1};
  
  //check that guess is within board size
  while (guess > BOARD_SIZE || guess < 0){
    std::cout << "Please Input an Integer: ";
    std::cin >> guess;
  }
  
  return guess;
}

std::array<int, 2> getGuessArray(){
  int guess1{ getIndividualGuess()};
  int guess2{ getIndividualGuess()};
  return std::array<int, 2>{ guess1, guess2};
}

void printBoard(const std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board){
  for (int i{0}; i<board.size(); i++){
    for (int q{0}; q<board.size(); q++){
      std::cout << board[i][q] << " ";
    }
    std::cout << "\n";
  }
}

void setBoard(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, std::array<int, 2>& guessArray, int currentPlayer){
  if (currentPlayer){
    board[guessArray[0]][guessArray[1]] = 'O';
  } else {
    board[guessArray[0]][guessArray[1]] = 'X';
  }
}

int switchPlayer(int currentPlayer){
  return currentPlayer ? 0 : 1;
}

bool checkIfWon(const std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, bool gameWon){
  for (int i{0}; i<BOARD_SIZE; i++){
    if (checkRow(board[i]) || checkColumn(board, i) || checkLeftDiagonal(board) || checkRightDiagonal(board)){
      return true;
    }
  }
  return false;
}

bool checkRow(const std::array<char, BOARD_SIZE>& row){
  char check{row[0]};
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

bool checkColumn(const std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, int colNum){
  char check{board[colNum][0]};
  if (check == '_'){
    return false;
  }
  for (int i{0}; i<board.size(); i++){
    if (board[i][colNum] != check){
      return false;
    }
  }
  return true;
}

bool checkLeftDiagonal(const std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board){
  char check{board[0][0]};
  if (check == '_'){
    return false;
  }
  for (int i{0}; i<board.size(); i++){
    if (board[i][i] != check){
      return false;
    }
  }
  return true;
}

bool checkRightDiagonal(const std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board){
  char check { board[board.size() - 1][0] };
  if (check == '_'){
    return false;
  }
  for (int i{0}; i<board.size(); i++){
    if (board[(board.size() - 1) - i][i] != check){
      return false;
    }
  }
  return true;
}
