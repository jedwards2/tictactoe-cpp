#include <vector>
#include <iterator>
#include "Board.hpp"

//forward declarations ------------------------------------------------
std::array<int, 2> getGuessArray(std::vector<std::array<int, 2>>& prevGuesses);
int getIndividualGuess();
int switchPlayer(int currentPlayer);
bool checkIfGuessIsValid(int guess1, int guess2, std::vector<std::array<int, 2>>& prevGuesses);

int main(int argc, const char * argv[]) {
  //initial multidimensional board array

  //array of 2 ints for previous guesses
  std::vector<std::array<int, 2>> prevGuesses;
  
  Board gameBoard {};
  int currentPlayer{0};

  
  while (!gameBoard.isGameWon()){
    gameBoard.printBoard();

    std::cout << "Current State of the Board" << "\n";
    
    //get array of 2 integers from player
    std::array<int, 2> guess {getGuessArray(prevGuesses)};
    prevGuesses.push_back(guess);
    
    //update the board with currentPlayer's mark
    gameBoard.setBoard(guess, currentPlayer);
    
    //update current state of game
    gameBoard.checkIfWon();
    
    //update the current Player
    currentPlayer = switchPlayer(currentPlayer);
  }
  
  //congratulate winner
  std::string_view message {currentPlayer ? "Congratulations X" : "Congratulations O"};
  std::cout << message << "\n";
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

bool checkIfGuessIsValid(int guess1, int guess2, std::vector<std::array<int, 2>>& prevGuesses){
  for (int i{0}; i<prevGuesses.size(); i++){
    if (prevGuesses[i][0] == guess1 && prevGuesses[i][1] == guess2){
      return false;
    }
  }
  return true;
}

std::array<int, 2> getGuessArray(std::vector<std::array<int, 2>>& prevGuesses){
  int guess1{ getIndividualGuess()};
  int guess2{ getIndividualGuess()};
  while (!checkIfGuessIsValid(guess1, guess2, prevGuesses)){
    guess1 = getIndividualGuess();
    guess2 = getIndividualGuess();
  }

  return std::array<int, 2>{ guess1, guess2};
}


int switchPlayer(int currentPlayer){
  return currentPlayer ? 0 : 1;
}

