#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;



void custom_numbers(){
    int Play;
    int Wump;
    int Bats;
    int Pit;
    cout << "In which room should the player start?" << endl;
    while(true){
        cin.clear();
        cin>>Play;
        if(Play < 20 && Play > -1){
            ofstream custom_room;
            string filename = "Waardes.txt";
            custom_room.open(filename.c_str());
            if(custom_room.is_open()){
                custom_room << "P " << Play << endl;
            }
        }
        cout << "This is not a valid room, try again:" << endl;
    }
    
}

int main(){
    custom_numbers();
}