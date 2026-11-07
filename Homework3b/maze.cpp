#include <iostream>
using std::cout, std::endl;
#include <string>
using std::string;
#include <fstream>
using std::ifstream, std::ofstream;
#include <sstream>
using std::stringstream;
#include <vector>
using std::vector;
#include "Grid.h"

void add_to_sol(const int& row, const int& col, const int& level, vector<string>& solution) {
  // all of this converts the ints into a string that I can print when I get my result
  stringstream checking;
  checking << row << " " << col << " " << level;
  string current_ans = checking.str();
  solution.push_back(current_ans);
}

bool find_path (Grid& maze, int row, int col, int level, vector<string>& solution){
    if (row == maze.height() - 1 && col == maze.width() - 1 && level == maze.depth() - 1){
      // ^^^ this is checking if I am at the exit
        add_to_sol(row, col, level, solution);
        return true;
    } else if (row < 0 || row >= maze.height() || col < 0 || col >=maze.width() || level < 0 || level >= maze.depth()) {
      // ^^^ this is checking if I am out of bounds
      return false;
    } else if (maze.at(row, col, level) == 2){
      // ^^^ this is checking if I have been at this spot before
      return false;
    } else if (maze.at(row, col, level) == 0) {
      // ^^^ this means that it isn't valid path
      return false;
    }
    // if all of this fails then I have to mark that I have been at the spot I am at and add it to my solution
    int og_val = maze.at(row, col, level); // this makes me able to backtrack whether its a one or a zero initially
    maze.at(row, col, level) = 2;
    add_to_sol(row, col, level, solution);
    // then I have to look for a new spot to go to
    if (find_path(maze, row + 1, col, level, solution)) {
      // ^^^ checking to the right
      return true;
    } else if (find_path(maze, row - 1, col, level, solution)) {
      // ^^ checking to the left
      return true;
    } else if (find_path(maze, row, col + 1, level, solution)) {
      // ^^ checking above
      return true;
    } else if (find_path(maze, row, col - 1, level, solution)) {
      // ^^ checking below
      return true;
    } else if (find_path(maze, row, col, level + 1, solution)) {
      //^^ checking deeper
      return true;
    } else if (find_path(maze, row, col, level - 1, solution)) {
      // ^^ checking less deep
      return true;
    }
    solution.pop_back();
    maze.at(row, col, level) = og_val;
    return false;
}

int main(int argc, char* argv[]) {
    // Write your code here
    ifstream file(argv[1]);
    if (!file.is_open()) {
      cout << "bad file" << endl;
      return 1;
    }
    stringstream ss;
    ss << file.rdbuf();
    Grid maze;
    ss >> maze;
    vector<string> solution;
    ofstream outfile(argv[2]);
    if (find_path(maze, 0, 0, 0, solution)) {
      outfile << "SOLUTION" << endl;
      for (size_t i = 0; i < solution.size(); i++) {
        outfile << solution[i] << endl;
      }
    } else {
      outfile << "NO SOLUTION" << endl;
    }
    return 0;
}
