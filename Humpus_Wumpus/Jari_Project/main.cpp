#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void custom_numbers(){
    ifstream infile;
    ofstream outfile;
    string filename_in = "values.txt";
	string filename_out = "tmp.txt";
    string line;
    infile.open(filename_in.c_str());
	outfile.open(filename_out.c_str());
    int Play = 0;
    int Wump = 0;
    int Bats = 0;
    int Pit = 0;
    char YorN_change[2];
    
    cout << "Do you want to change the player start location? (y/n) ";
    //getline(cin, YorN_change);
    cin>>YorN_change;
    if(YorN_change[0] == 'Y' || YorN_change[0] == 'y'){
        
        while(true){
            cout << "In which room should the player start? ";
            cin.clear();
            cin>>Play;
            while(!cin>>Play || Play > 19 || Play < 0){
                cout << "This is not a valid room, try again:" << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cin>>Play;
            }
            while(getline(infile, line)){
                if(line[0]=='P'){
                    outfile << "P " << Play << endl;
                    break;
                }
                else{
                    outfile << line << endl;
                }
            }
            cout << "De gekozen waarde is: " << Play << endl;
            break;
        }
    }

    
    cout << "Do you want to change the Wumpus start location? (y/n)" << endl;
    cin.clear();
    //getline(cin, YorN_change);
    cin>>YorN_change;
    
    if(YorN_change[0] == 'Y' || YorN_change[0] == 'y'){
        while(true){
            cout << "In which room should the Wumpus start?" << endl;
            cin.clear();
            cin>>Wump;
            while(!cin>>Wump || Wump > 19 || Wump < 0){
                cout << "This is not a valid room, try again:" << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cin>>Wump;
            }
            while(getline(infile, line)){
                if(line[0]=='W'){
                    outfile << "W " << Wump << endl;
                    break;
                }
                else{
                    outfile << line << endl;
                }
            }
            cout << "De gekozen waarde is: " << Wump << endl;
            break;
        }
    }
    
    cout << "Do you want to change the Bats start location? (y/n)" << endl;
    cin.clear();
    //getline(cin, YorN_change);
    cin>>YorN_change;
    if(YorN_change[0] == 'Y' || YorN_change[0] == 'y'){
        while(true){
            cout << "In which room should the Bats start?" << endl;
            cin.clear();
            cin>>Bats;
            while(!cin>>Bats || Bats > 19 || Bats < 0){
                cout << "This is not a valid room, try again:" << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cin>>Bats;
            }
            while(getline(infile, line)){
                if(line[0]=='B'){
                    outfile << "B " << Bats << endl;
                    break;
                }
                else{
                    cout << "Hoertje" << endl;
                    outfile << line << endl;
                }
            }
            cout << "De gekozen waarde is: " << Bats << endl;
            break;
        }
    }
    
    cout << "Do you want to change the Pit location? (y/n)" << endl;
    cin.clear();
    //getline(cin, YorN_change);
    cin>>YorN_change;
    if(YorN_change[0] == 'Y' || YorN_change[0] == 'y'){
        while(true){
            cout << "In which room should the Pit be?" << endl;
            cin.clear();
            cin>>Pit;
            while(!cin>>Pit || Pit > 19 || Pit < 0){
                cout << "This is not a valid room, try again:" << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cin>>Pit;
            }
            while(getline(infile, line)){
                if(line[0]=='G'){
                    outfile << "G " << Pit << endl;
                    break;
                }
                else{
                    outfile << line << endl;
                    cout << "Hoertje" << endl;
                }
            }
            cout << "De gekozen waarde is: " << Pit << endl;
            break;
        }
    }
    
    infile.close();
	outfile.close();


	//while(getline(infile, line)){
		//outfile << line << endl;
	//}

    
}
    
    


int main(){
    custom_numbers();
    cout << "Test" << endl;
    
}
