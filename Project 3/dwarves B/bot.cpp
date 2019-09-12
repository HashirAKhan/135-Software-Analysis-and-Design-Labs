
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

int STEP;
int STATUS[6];
Dir TARGET[6];


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

  STEP = 0;
  for(int i = 0; i < 6; i++){
    STATUS[i]=0;
    TARGET[i]=NORTH;
  }
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
  if (dwarf.look(r, c+1)==PINE_TREE||dwarf.look(r, c-1)==PINE_TREE||dwarf.look(r+1, c)==PINE_TREE||dwarf.look(r-1, c)==PINE_TREE){
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

void getLumber(Dwarf &dwarf, int r, int c){
  if (isNextToTree(dwarf, r, c)) {
    // If there is a pine tree, chop it
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

bool isRowEmpty(Dwarf &dwarf){
  for(int i = 0; i < 6; i++){
    if(dwarf.look(dwarf.name(),i)!=EMPTY&&dwarf.look(dwarf.name(),i)!=DWARF){
      return false;
    }
  }
  return true;
}

Coord findEmptySpot(Dwarf &dwarf, int r, int c){
  if (dwarf.look(r+1, c)==EMPTY){
    TARGET[dwarf.name()]=NORTH;
    return {r+1,c};
  }
  else if(dwarf.look(r-1, c)==EMPTY){
    TARGET[dwarf.name()]=SOUTH;
    return {r-1,c};
  }
  else if(dwarf.look(r, c+1)==EMPTY){
    TARGET[dwarf.name()]=WEST;
    return {r,c+1};
  }
  else if(dwarf.look(r, c-1)==EMPTY){
    TARGET[dwarf.name()]=EAST;
    return {r,c-1};
  }
}



Coord goToClearRow(Dwarf &dwarf){
  for(int i = 0; i < 6; i++){
    if(dwarf.look(dwarf.name(),i)!=EMPTY){
      Coord temp = findEmptySpot(dwarf, dwarf.name(), i);
      return temp;
    }
  }
  return {0,0};
}



void onAction(Dwarf &dwarf, int day, int hours, int minutes, ostream &log) {
  // Get current position of the dwarf
  int r = dwarf.row();
  int c = dwarf.col();

  bool test;


  if(STEP==0){
      if(isRowEmpty(dwarf)){
        dwarf.start_walk(dwarf.name(), 5);
        STATUS[dwarf.name()]=2;
      }
      else{
        if(STATUS[dwarf.name()]==0){
          Coord walk = goToClearRow(dwarf);
          dwarf.start_walk(walk.row, walk.col);
          STATUS[dwarf.name()]=1;
          return;
        }
        else if(STATUS[dwarf.name()]==1){
          dwarf.start_chop(TARGET[dwarf.name()]);
          STATUS[dwarf.name()]=0;
        }
      }


      test = true;
      for(int i = 0; i < 6; i++){
        if(dwarf.look(i,5)!=DWARF){
          test = false;
        }
      }

      if(test){
        log << "TEST"<< endl;
        STEP = 1;
      }
  }

  else if(STEP==1){

    int rr = rand() % ROWS;
    int cc = rand() % COLS;

    if(STATUS[dwarf.name()]==2){
      dwarf.start_walk(rr, cc);
      STATUS[dwarf.name()]=3;
      return;
    }


    test = true;

    for (int i = 0; i < 6; i++){
      if(STATUS[i]!=3){
        test = false;
      }
    }

    if(test){
      log<<"RUN"<<endl;
      STEP = 2;
    }

  }

  else if(STEP == 2){
    if(dwarf.lumber()<330){
      getLumber(dwarf, r,c);
      return;
    }
    else{
      STEP = 3;
    }
  }

  else if(STEP == 3){
    dwarf.start_walk(dwarf.name(), 1);
    STATUS[dwarf.name()]=4;


    test = true;

    for(int i = 0; i < 6; i++){
      if (dwarf.look(i,1)!=DWARF){
        test = false;
      }
    }

    if(test){
      STEP = 4;
    }

  }


  else if(STEP == 4){
    if(STATUS[dwarf.name()]==4){
      dwarf.start_build(WEST);
      STATUS[dwarf.name()]=5;
      return;
    }
    else{
      dwarf.start_walk(r, c+1);
      STATUS[dwarf.name()]=4;
      return;

    }
  }
//  else if(STEP = 3){


//  }





}
