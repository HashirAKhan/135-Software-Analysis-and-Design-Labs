//Hashir Khan
//CSCI 133
//Lab 11A-D
//04-30-19

#include<iostream>
using namespace std;

class Profile{
  private:
    string username;
    string displayname;
  public:
    // Profile constructor for a user (initializing
    // private variables username=usrn, displayname=dspn)
    Profile(string user, string dspn){
      username = user;
      displayname = dspn;
    }

    // Default Profile constructor (username="", displayname="")
    Profile(){
      username = "";
      displayname = "";
    }

    // Default Profile constructor (username="", displayname="")
    string getUsername(){
      return username;
    }

    // Return name in the format: "displayname (@username)"
    string getFullName(){
      return displayname + " (@" + username + ")";
    }
    string getUserWithAt(){
      return "\"@"+username+"\"";
    }

    // Change display name
    void setDisplayName(string dspn){
      displayname = dspn;
    }
};


class Network{
  private:
    static const int MAX_USERS = 20;       // max number of user profiles
    int numUsers;                          // max number of user profiles
    Profile profiles[MAX_USERS];           // max number of user profiles
                                           // mapping integer ID -> Profile

    bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
    // following[id1][id2] == true when id1 is following id2


    // Returns user ID (index in the 'profiles' array) by their username
    // (or -1 if username is not found)
    int findID (string usrn){
      for (int i = 0; i < 20; i++){
        if(profiles[i].getUsername()==usrn){
          return i;
        }
      }
      return -1;
    }

  public:

    // Constructor, makes an empty network (numUsers = 0)
    Network(){
      numUsers = 0;
      for (int i = 0; i < MAX_USERS; i++){
        for (int k = 0; k < MAX_USERS; k++){
          following[i][k] = false;
        }
      }

    }

    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn){
      if(numUsers==MAX_USERS || usrn == ""){
        return false;
      }
      for (int i = 0; i < numUsers; i++){
        if(profiles[i].getUsername()==usrn){
          return false;
        }
      }
      for (int i = 0; i < usrn.length(); i++){
        if(!isalpha(usrn[i])&&!isdigit(usrn[i])){
          return false;
        }
      }
      Profile result= Profile(usrn, dspn);
      profiles[numUsers] = result;
      numUsers++;
      return true;
    }


    // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
    // return true if success (if both usernames exist), otherwise return false
    bool follow(string usrn1, string usrn2){
      bool check1 = false;
      bool check2 = false;
      int index1;
      int index2;
      for(int i = 0; i < numUsers; i++){
        if(profiles[i].getUsername() == usrn1){
          check1 = true;
          index1 = i;
        }
        if(profiles[i].getUsername() == usrn2){
          check2 = true;
          index2 = i;
        }
      }
      if(check1&&check2){
        following[index1][index2] = true;
        return true;
      }
      return false;
    }

    // Print Dot file (graphical representation of the network)
    void printDot(){
      cout<<"digraph {"<<endl;
      for(int i = 0; i < numUsers; i++){
        cout<<profiles[i].getUserWithAt()<<endl;
      }
  
      for(int i = 0; i < numUsers; i++){
        for(int k = 0; k <numUsers; k++){
          if(following[i][k]){
            cout<<profiles[i].getUserWithAt()<<" -> "<<profiles[k].getUserWithAt()<<endl;
          }
        }
      }
      cout<<"}";
    }

};

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");

    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}
