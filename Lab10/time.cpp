//Hashir Khan
//Lab 10 A-F
//CSCI 135
//4/15/19

#include <iostream>

//Stores the genre of a movie
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

//creates a Time object
class Time {
public:
    int h; //hours
    int m; //minutes
};

//creates a movie object
class Movie{
  public:
    std::string title;
    Genre genre;
    int duration; //in minutes
};

//creates a TimeSlot
//stores the movie and when it will be playing
class TimeSlot{
  public:
    Movie movie;
    Time startTime;
};

//converts the time from h:m format to just minutes
int minutesSinceMidnight(Time time){
  return time.h*60 + time.m;
}

//measures distance between two times in minutes
int minutesUntil(Time earlier, Time later){
  return minutesSinceMidnight(later)- minutesSinceMidnight(earlier);
}

//creates a new Time object by adding minutes to a time object
Time addMinutes(Time time, int minutes){
  Time newTime = {time.h, time.m};
  newTime.m = (time.m + minutes) % 60;
  newTime.h = (time.h+ (time.m + minutes)/60)%24;
  return newTime;
}

//prints out the movie info
void printMovie(Movie mv){
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

//Prints out the time in hh:mm format
void printTime(Time time){
  std::cout<<time.h<<":"<<time.m;
}

//Prints out the Timeslot information
void printTimeSlot(TimeSlot ts){
  printMovie(ts.movie);
  std::cout<<"[starts at ";
  printTime(ts.startTime);
  std::cout<<", ends by ";
  printTime(addMinutes(ts.startTime, ts.movie.duration));
  std::cout<<"]";
}

//Scheduals a movie directly after a movie
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
  TimeSlot result;
  result.movie = nextMovie;
  result.startTime = addMinutes(ts.startTime, ts.movie.duration);
  return result;
}

//Checks to see if two timeslots overlap
bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
  if(minutesSinceMidnight(ts1.startTime)>minutesSinceMidnight(ts2.startTime)){
    if(minutesSinceMidnight(addMinutes(ts2.startTime, ts2.movie.duration))>minutesSinceMidnight(ts1.startTime)){
      return true;
    }
    else{
      return false;
    }
  }
  else{
    if(minutesSinceMidnight(addMinutes(ts1.startTime, ts1.movie.duration))>minutesSinceMidnight(ts2.startTime)){
      return true;
    }
    else{
      return false;
    }
  }
}

int main(){
  Time one = {5,30};
  Time two = {6,30};
  std::cout<<std::to_string(minutesUntil(one, two));
  return 0;
}
