//Hashir Khan
//CSCI 133
//Lab 11A-D
//04-30-19

#include<iostream>
using namespace std;

class Profile{
  private:
    std::string username;
    std::string displayname;
  public:
    // Profile constructor for a user (initializing
    // private variables username=usrn, displayname=dspn)
    Profile(std::string user, std::string dspn){
      username = user;
      displayname = dspn;
    }

    // Default Profile constructor (username="", displayname="")
    Profile(){
      username = "";
      displayname = "";
    }

    // Default Profile constructor (username="", displayname="")
    std::string getUsername(){
      return username;
    }

    // Return name in the format: "displayname (@username)"
    std::string getFullName(){
      return displayname + " (@" + username + ")";
    }

    // Change display name
    void setDisplayName(std::string dspn){
      displayname = dspn;
    }
};

int main() {
    Profile p1("marco", "Marco");
    cout << p1.getUsername() << endl;
    cout << p1.getFullName() << endl;

    p1.setDisplayName("Marco Rossi");
    cout << p1.getUsername() << endl;
    cout << p1.getFullName() << endl;

    Profile p2("tarma1", "Tarma Roving");
    cout << p2.getUsername() << endl;
    cout << p2.getFullName() << endl;
}
