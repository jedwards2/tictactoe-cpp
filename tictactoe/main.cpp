#include <array>
#include <iostream>
#include <iterator>

//set compile-time const for board size, does not work due to check conditions
constexpr int BOARD_SIZE {3};

void printBoard(const std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board);
void setBoard(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, std::array<int, 2>& guessArray, int currentPlayer);
std::array<int, 2> getGuessArray();
int getIndividualGuess();
int switchPlayer(int currentPlayer);
bool checkIfWon(const std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE>& board, bool gameWon);

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
  int guess {};
  std::cout << "Please Input an Integer: ";
  std::cin >> guess;
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
  //checks all rows and columns, making sure they are equal, and not "_"
  if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == board[0][2] && board[0][0] != '_'){
    return true;
  } else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == board[1][2] && board[1][0] != '_'){
    return true;
  } else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == board[2][2] && board[2][0] != '_'){
    return true;
  } else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == board[2][0] && board[0][0] != '_'){
    return true;
  } else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == board[1][2] && board[1][0] != '_'){
    return true;
  } else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == board[2][2] && board[2][0] != '_'){
    return true;
  } else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == board[2][2] && board[0][0] != '_'){
    return true;
  } else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] == board[0][2] && board[2][0] != '_'){
    return true;
  }
  return false;
}
