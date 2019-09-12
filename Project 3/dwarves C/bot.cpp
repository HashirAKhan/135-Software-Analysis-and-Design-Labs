//Hashir Khan
//CSCI 135
//Project 3C
//5-12-19


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

bool GET_LUMBER;
bool ROW_CLEAR;
bool ASSIGNED_TO_TREES;
int STATUS[MAX_NUM];
bool COVER;
bool PICKING_APPLES;
bool BREAK_FREE;
bool GET_PUMPKINS;
bool HOME;
bool CLEAR_START_ROW;
bool BUILD_FORT;
int FORT_ROW;
bool CLOSE_FORT;
bool BREAK;
bool CLEAR_FINAL;
bool BUILD_FINAL;
bool GO_IN;
bool PROTECT;
//1 is if next to apple trees
//2 if it has broken free
//3 if its at home row

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
Coord SAFE = {0,0};


void onStart(int rows, int cols, int num, std::ostream &log) {
  log << "Start!" << endl; // Print a greeting message

  ROWS = rows; // Save values in global variables
  COLS = cols;
  NUM = num;

//setting all my bools to work
  GET_LUMBER = true;
  ROW_CLEAR = false;
  COVER = false;
  PICKING_APPLES = true;
  BREAK_FREE = false;
  GET_PUMPKINS = true;
  HOME = false;
  BUILD_FORT = true;
  FORT_ROW = 1;
  CLEAR_START_ROW = false;
  BREAK = false;
  CLOSE_FORT = false;
  CLEAR_FINAL= false;
  BUILD_FINAL = false;
  GO_IN=false;
  PROTECT = false;

  for(int i = 0; i < num; i++){
    STATUS[i] = 0;
  }
  ASSIGNED_TO_TREES = false;
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
bool isNextToObject(Dwarf &dwarf, int r, int c, Place place){
  if (dwarf.look(r, c+1)==place||dwarf.look(r, c-1)==place||dwarf.look(r+1, c)==place||dwarf.look(r-1, c)==place){
    return true;
  }
  return false;
}

//Gets the direction of the tree near a dwarf
Dir getObject(Dwarf &dwarf, int r, int c, Place place){
  if (dwarf.look(r, c+1)==place){
    return EAST;
  }
  else if(dwarf.look(r, c-1)==place){
    return WEST;
  }
  else if(dwarf.look(r+1, c)==place){
    return SOUTH;
  }
  else if(dwarf.look(r-1, c)==place){
    return NORTH;
  }
}


//Finds the closest tree that has an empty spot next to it
Coord findNearestObject(Dwarf &dwarf, int r, int c, Place place){
  for (int i = 1; i < 200; i++){
    if (dwarf.look(r,c+i)==EMPTY&&isNextToObject(dwarf,r, c+i,place)){
      return {r,c+i};
    }
    else if (dwarf.look(r,c-i)==EMPTY&&isNextToObject(dwarf,r, c-i,place)){
      return {r,c-i};
    }
    else if (dwarf.look(r+i,c)==EMPTY&&isNextToObject(dwarf,r+i, c,place)){
      return {r+i,c};
    }
    else if (dwarf.look(r-i,c)==EMPTY&&isNextToObject(dwarf,r-i, c,place)){
      return {r-i,c};
    }
    int j = 1;
    for(int k = i-1; k > 0; k--){
      if (dwarf.look(r+j,c+k)==EMPTY&&isNextToObject(dwarf,r+j, c+k,place)){
        return {r+j,c+k};
      }
      j++;
    }
    j = 1;
    for(int k = i-1; k > 0; k--){
      if (dwarf.look(r+j,c-k)==EMPTY&&isNextToObject(dwarf,r+j, c-k,place)){
        return {r+j,c-k};
      }
      j++;
    }
    j = 1;
    for(int k = i-1; k > 0; k--){
      if (dwarf.look(r-j,c-k)==EMPTY&&isNextToObject(dwarf,r-j, c-k,place)){
        return {r-j,c-k};
      }
      j++;
    }
    for(int k = i-1; k > 0; k--){
      if (dwarf.look(r-j,c+k)==EMPTY&&isNextToObject(dwarf,r-j, c+k,place)){
        return {r-j,c+k};
      }
      j++;
    }
  }
  return {-1, -1};
}


bool getLumber(Dwarf &dwarf, int r, int c){
  // Look if there is a tree on the right from the dwarf
  if (isNextToObject(dwarf, r, c, PINE_TREE)) {
    // If there is a pine tree, chop it

    dwarf.start_chop(getObject(dwarf,r, c, PINE_TREE));
    return true;
  }
  else {
    // Otherwise, move to a random location
    Coord temp = findNearestObject(dwarf, r, c, PINE_TREE);
    if(temp.row==-1){
      return false;
    }

    dwarf.start_walk(temp.row, temp.col);
    return true;
  }
}

bool isAreaClear(Dwarf &dwarf){
  for(int i = 0; i < NUM; i++){
    for(int k = 0; k < 6; k++){
      if(dwarf.look(i, k) != EMPTY && dwarf.look(i,k) != DWARF){
        return false;
      }
    }
  }
  return true;
}

void clearRow(Dwarf &dwarf){
  return;
}

bool checkStatus(int step){
  for(int i = 0; i < NUM; i++){
    if(STATUS[i] != step){
      return false;
    }
  }
  return true;
}

void goToAppleTrees(Dwarf &dwarf, int r, int c){
  if(checkStatus(1)){
    ASSIGNED_TO_TREES = true;
    return;
  }
  if(isNextToObject(dwarf, r, c, APPLE_TREE)){
    STATUS[dwarf.name()]=1;
    return;
  }

  Coord appleTree = findNearestObject(dwarf, r, c, APPLE_TREE);
  dwarf.start_walk(appleTree.row, appleTree.col);
  return;
}

bool getPumpkins(Dwarf &dwarf, int r, int c){

  if (isNextToObject(dwarf, r, c, PUMPKIN)) {


    dwarf.start_pick(getObject(dwarf,r, c, PUMPKIN));
    return true;
  }
  else {

    Coord temp = findNearestObject(dwarf, r, c, PUMPKIN);
    if(temp.row==-1){
      return false;
    }

    dwarf.start_walk(temp.row, temp.col);
    return true;
  }
}


Coord findEmptySpace(Dwarf &dwarf, int r, int c){
  if (dwarf.look(r, c+1)==EMPTY){
    return {r,c+1};
  }
  else if(dwarf.look(r, c-1)==EMPTY){
    return {r,c-1};
  }
  else if(dwarf.look(r+1, c)==EMPTY){
    return {r+1,c};
  }
  else if(dwarf.look(r-1, c)==EMPTY){
    return {r-1,c};
  }
}


void goToHomeRow(Dwarf &dwarf, int r , int c){
  if(isNextToObject(dwarf, r, c, APPLE_TREE)){
    dwarf.start_chop(getObject(dwarf, r, c, APPLE_TREE));
    return;
  }
  if(isNextToObject(dwarf, r, c, PUMPKIN)){
    dwarf.start_pick(getObject(dwarf, r, c, PUMPKIN));
    return;
  }

  if(dwarf.look(dwarf.name(), 1) != EMPTY && dwarf.look(dwarf.name(), 1) != DWARF){
    Coord temp = findEmptySpace(dwarf, dwarf.name(), 1);
    dwarf.start_walk(temp.row, temp.col);
    return;
  }
  else{
    dwarf.start_walk(dwarf.name(), 1);
    return;
  }
  return;
}

bool clearSpace(Dwarf &dwarf, int r, int c, Dir direction){
  if (direction == WEST){
    if(dwarf.look(r,c-1) == PINE_TREE || dwarf.look(r,c-1) == APPLE_TREE){
      dwarf.start_chop(WEST);
      return true;
    }
    if(dwarf.look(r,c-1) == PUMPKIN){
      dwarf.start_pick(WEST);
      return true;
    }
  }
  else if (direction == EAST){
    if(dwarf.look(r,c+1) == PINE_TREE || dwarf.look(r,c+1) == APPLE_TREE || dwarf.look(r,c+1) == FENCE){
      dwarf.start_chop(EAST);
      return true;
    }
    if(dwarf.look(r,c+1) == PUMPKIN){
      dwarf.start_pick(EAST);
      return true;
    }
  }
  return false;
}

bool isRowClear(Dwarf &dwarf, int col){
  for(int i = 0; i < NUM; i++){
    if(dwarf.look(i, col)!=EMPTY){
      return false;
    }
  }
  return true;
}

bool isRowFort(Dwarf dwarf, int c){
  for(int i = 0; i < NUM; i++){
    if(dwarf.look(i, c)!=FENCE){
      return false;
    }
  }
  return true;
}




void buildFort(Dwarf &dwarf, int r, int c){


  while(dwarf.lumber()>(NUM*20+23)){
    if(c!=FORT_ROW){
      dwarf.start_walk(dwarf.name(), FORT_ROW);
      return;
    }

    if(dwarf.look(r,c-1)==EMPTY){
      dwarf.start_build(WEST);
      return;
    }

    if(!isRowClear(dwarf, FORT_ROW+1)){
      clearSpace(dwarf, r, c, EAST);
      return;
    }

    if(isRowClear(dwarf, FORT_ROW+1)&&isRowFort(dwarf, FORT_ROW-1)){
      FORT_ROW++;
      return;
    }
    return;
  }

  while(!CLEAR_FINAL){
    if(isRowClear(dwarf, FORT_ROW+1)){
      CLEAR_FINAL = true;
      return;
    }
    clearSpace(dwarf,r,c,EAST);
    return;
  }

  while(!BUILD_FINAL){
    if(dwarf.name()==NUM-1){
      if(r != dwarf.name()+1){
        if(dwarf.look(r+1,c)==EMPTY){
          dwarf.start_walk(r+1,c);
          BUILD_FINAL = true;
          return;
        }
        else{
          dwarf.start_chop(SOUTH);
          return;
        }

      }
      BUILD_FINAL = true;
    }
    return;
  }

  while(!CLOSE_FORT){
    if(dwarf.name()==NUM-1){
      if(dwarf.look(r, c+1)!=EMPTY&&dwarf.look(r,c+1)!=FENCE){
        clearSpace(dwarf,r,c,EAST);
        return;
      }
      if(dwarf.look(r, c-1)!=EMPTY&&dwarf.look(r,c-1)!=FENCE){
        clearSpace(dwarf,r,c,WEST);
        return;
      }
      if(dwarf.look(r, c-1)==EMPTY){
        dwarf.start_build(WEST);
        return;
      }
      if(dwarf.look(r, c+1)==EMPTY){
        dwarf.start_build(EAST);
        return;
      }
      CLOSE_FORT = true;
      return;
    }
    return;
  }

  while(!GO_IN){
    if(dwarf.name()==NUM-1){
      if(r!=dwarf.name()){
        dwarf.start_walk(dwarf.name(),c);
        return;
      }
      GO_IN = true;
    }
    return;
  }
  if(isNextToObject(dwarf, r, c,EMPTY)){
    dwarf.start_build(getObject(dwarf,r,c,EMPTY));
    return;
  }

  return;
}

/*
  while(!GO_IN){
    if(dwarf.name()==NUM-1){
      if(r!=dwarf.name()){
        dwarf.start_walk(dwarf.name(),c);
        return;
      }
      GO_IN = true;
    }
    return;
  }
  if(isNextToObject(dwarf, r, c,EMPTY)){
    dwarf.start_build(getObject(dwarf,r,c,EMPTY));
    return;
  }

  return;
}
*/



void onAction(Dwarf &dwarf, int day, int hours, int minutes, ostream &log) {
  // Get current position of the dwarf
  int r = dwarf.row();
  int c = dwarf.col();

  while(PROTECT){
    if(isNextToObject(dwarf, r, c, EMPTY)){
      dwarf.start_build(getObject(dwarf, r, c, EMPTY));
      return;
    }
    return;
  }
  if(day == 7 && hours == 19 && minutes > 56){
    PROTECT = true;
    return;
  }

  //Incase a dwarf get stuck, run this
  if(!COVER && !isNextToObject(dwarf, r, c,EMPTY)){
    dwarf.start_chop(getObject(dwarf, r, c, PINE_TREE));
  }

  //Start with collecting some wood
  while(GET_LUMBER && dwarf.lumber() < 500){
    if(!getLumber(dwarf, r, c)){
      GET_LUMBER = false;
    }
    return;
  }
  //To stop collecting wood
  GET_LUMBER = false;


  //To get Every Dwarf Next to an Apple Tree
  while(!ASSIGNED_TO_TREES){
    goToAppleTrees(dwarf, r, c);
    return;
  }

  while(PICKING_APPLES){
    COVER = true;
    if(isNextToObject(dwarf, r, c, EMPTY)){
      dwarf.start_build(getObject(dwarf, r, c, EMPTY));
      return;
    }
    while(day < 7 || (day == 7 && hours < 6)|| (day ==7 && hours == 6 && minutes < 30)){
      dwarf.start_pick(getObject(dwarf, r, c, APPLE_TREE));
      return;
    }
    PICKING_APPLES = false;
    return;
  }


  while(!BREAK_FREE){
    if(isNextToObject(dwarf,r,c,FENCE)){
      dwarf.start_chop(getObject(dwarf, r, c, FENCE));
    }
    else{
      STATUS[dwarf.name()]=2;
    }
    if(checkStatus(2)){
      BREAK_FREE = true;
    }
    return;
  }



  while(GET_PUMPKINS){
    if(!getPumpkins(dwarf, r, c)){
      GET_PUMPKINS = false;
    }
    return;
  }

//places them at home
  while(!HOME){
    goToHomeRow(dwarf, r,c);

    if(dwarf.look(dwarf.name(), 1)==DWARF){
      STATUS[dwarf.name()]=3;
    }

    if (checkStatus(3)){
      HOME = true;
      return;
    }

    return;
  }

//clears start ROW_CLEAR
  while(!CLEAR_START_ROW){
    if(isRowClear(dwarf, 0)){
      CLEAR_START_ROW = true;
      return;
    }
    dwarf.start_chop(WEST);
    return;

  }


//builds a fort
  while(BUILD_FORT){
    buildFort(dwarf,r,c);
    return;
  }






}
