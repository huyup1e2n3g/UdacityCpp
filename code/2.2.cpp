#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State {kEmpty, kObstacle};

vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    State curstate;
    while (sline >> n >> c && c == ',') {
      // a State::kEmpty if n is 0, and push_back
      // a State::kObstacle otherwise.
      if (n == 0) {
        curstate = State::kEmpty;
      }
      else if (n == 1) {
        curstate = State::kObstacle;
      }
      row.push_back(curstate);
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

// Cell to string
// "⛰️   "
// "0   "
string CellString(State cell) {
    switch(cell){
        case State::kEmpty:
                return "0   ";
        case State::kObstacle:
                return "⛰️   ";
    }
}

void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}

int main() {
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);
}
