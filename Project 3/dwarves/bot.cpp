
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "bot.h"

using namespace std;

const int MAX_ROWS = 40;
const int MAX_COLS = 40;
const int MAX_NUM = 10;

int ROWS;  // global variables
int COLS;
int NUM;

/* onStart:
An Initialization procedure called at the start of the game.
You can use it to initialize certain global variables, or do
something else before the actual simulation starts.
Parameters:
    rows: number of rows
    cols: number of columns
    num:  number of dwarfs
    log:  a cout-like log */


//Coord object stores both a row and col
struct Coord{
    int row;
    int col;
};

void onStart(int rows, int cols, int num, std::ostream &log) {
  log << "Start!" << endl; // Print a greeting message

  ROWS = rows; // Save values in global variables
  COLS = cols;
  NUM = num;
}

/* onAction:
A procedure called each time an idle dwarf is choosing
their next action.
Parameters:
    dwarf:   dwarf choosing an action
    day:     day (1+)
    hours:   number of hours in 24-hour format (0-23)
    minutes: number of minutes (0-59)
    log:     a cout-like log  */


//Checks to see if the dwarf is next to a tree
bool isNextToTree(Dwarf &dwarf, int r, int c){
  if (dwarf.look(r, c+1)==PINE_TREE){
    return true;
  }
  else if(dwarf.look(r, c-1)==PINE_TREE){
    return true;
  }
  else if(dwarf.look(r+1, c)==PINE_TREE){
    return true;
  }
  else if(dwarf.look(r-1, c)==PINE_TREE){
    return true;
  }
  return false;
}

//Gets the direction of the tree near a dwarf
Dir getTree(Dwarf &dwarf, int r, int c){
  if (dwarf.look(r, c+1)==PINE_TREE){
    return EAST;
  }
  else if(dwarf.look(r, c-1)==PINE_TREE){
    return WEST;
  }
  else if(dwarf.look(r+1, c)==PINE_TREE){
    return SOUTH;
  }
  else if(dwarf.look(r-1, c)==PINE_TREE){
    return NORTH;
  }
}


//Finds the closest tree that has an empty spot next to it
Coord findNearestTree(Dwarf &dwarf, int r, int c){
  for (int i = 1; i < 40; i++){
    if (isNextToTree(dwarf,r, c+i)&&dwarf.look(r,c+i)==EMPTY){
      return {r,c+i};
    }
    else if (isNextToTree(dwarf,r, c-i)&&dwarf.look(r,c-i)==EMPTY){
      return {r,c-i};
    }
    else if (isNextToTree(dwarf,r+i, c)&&dwarf.look(r+i,c)==EMPTY){
      return {r+i,c};
    }
    else if (isNextToTree(dwarf,r-i, c)&&dwarf.look(r-i,c)==EMPTY){
      return {r-i,c};
    }
    else if (isNextToTree(dwarf,r+i, c+i)&&dwarf.look(r+i,c+i)==EMPTY){
      return {r+i,c+i};
    }
    else if (isNextToTree(dwarf,r+i, c-i)&&dwarf.look(r+i,c-i)==EMPTY){
      return {r+i,c-i};
    }
    else if (isNextToTree(dwarf,r-i, c+i)&&dwarf.look(r-i,c+i)==EMPTY){
      return {r-i,c+i};
    }
    else if (isNextToTree(dwarf,r-i, c-i)&&dwarf.look(r-i,c-i)==EMPTY){
      return {r-i,c-i};
    }
  }
}

void onAction(Dwarf &dwarf, int day, int hours, int minutes, ostream &log) {
  // Get current position of the dwarf
  int r = dwarf.row();
  int c = dwarf.col();


  // Look if there is a tree on the right from the dwarf
  if (isNextToTree(dwarf, r, c)) {
    // If there is a pine tree, chop it
    log << "Found a tree -- chop" << endl;
    dwarf.start_chop(getTree(dwarf,r, c));
    return;
  }
  else {
    // Otherwise, move to a random location
    Coord temp = findNearestTree(dwarf, r, c);
    dwarf.start_walk(temp.row, temp.col);
    return;
  }
}
