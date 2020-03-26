#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

void Instructies_uitlezen()
{
	string YorN_Instr;
    cout << "Hunt the Wumpus" << endl;
    cout << "Do you need instructions: (Y/N)? ";
    cin >> YorN_Instr;
    
    if(YorN_Instr == "Y" || YorN_Instr == "y"){
        cout << "1. There are 3 hazards: \n";
            cout << "\t1.1 A bottomless pit (you will feel a breeze nearby).\n";
            cout << "\t1.2 A colony of bats that will pick you up and drop you in a random space (you will hear flapping nearby).\n";
            cout << "\t1.3 A fearsome, hungry, and unbathed wumpus (you will smell it nearby).\n";
        cout << "2. The wumpus is heavy; bats cannot lift him.\n";
        cout << "3. The wumpus is covered in suckers; he won't fall down the bottomless pit.\n";
        cout << "4. Firing an arrow that misses the wumpus may cause it to move.\n";
        cout << "5. You have 5 wumpus-piercing arrows.\n";
        cout << "6. You may find an arrow dropped by a previous hunter.\n";
    }
}

void Klaar_Om_Te_Spelen()
{
    string Y_tostart;
    while(Y_tostart != "Y" || Y_tostart != "y"){
        cout << "\nAre you ready to start (Y)? ";
        cin >> Y_tostart;

        if(Y_tostart == "Y" || Y_tostart == "y"){
            break;
        }
    }
}

int random_rand_waarde_player()
{
	int xyplayer = (rand()%19)+0;
	return xyplayer;
}

int random_rand_waarde_wump()
{
	int xywump = (rand()%19)+0;
	return xywump;
}

// HIER GRAAG RANDOM WAARDE VAN PIT EN BATS

int move(vector<int> cords)
{
	
    int side;
    cout << "---------------------------------------\n";
    cout << "You are in room: " << cords[0] << endl;
	cout << "Tunnels lead to room: " << cords[1] << ", " << cords[2] << " and " << cords[3] <<endl ;
    cout << "---------------------------------------\n";
    cout << "To which room do you want to go?" << endl;
    cin >> side;
    return side;
}

int checkside(int side, vector<int> cords)
{
    while(true){
        if (side == cords[1] || side == cords[2] || side == cords[3]){
        //fucntie
        return side;
        }
        else{
            cout << "No such room nearby, try again:" << endl;
            cin >> side;
        }
    }
}

vector<int> directions(int local)
{
	ifstream infile;
	string filename = "map.txt";
	string line;
	vector<int> cords;
	cords.push_back(local);
	infile.open(filename.c_str());
	if(infile.is_open()){
		for(int i=0;i<local+1;i++){
			getline(infile, line);
			if(i==local){
				stringstream find;
				find << line;
				string temp;
				int found;
				while(!find.eof()) {
					find >> temp;
					if(stringstream(temp) >> found){
						cords.push_back(found);
					}
					temp = "";
				}
			}
		}
		infile.close();
		return(cords);
	}
	else{
		cout << "ERROR: File unreachable \n";
	}
}

int main()
{
    // Start functie die vraagt of mensen instructies wilt hebben.
    Instructies_uitlezen();
    
    // Begint funcite om te vragen om mensen klaar zijn om te spelen.
    Klaar_Om_Te_Spelen();
    
    // Random waardes geven voor spawn points voor Wumpus en de spelers ( Moet nog bats en pit zijn. )
    srand((unsigned)time(0));
	int positie_wump = random_rand_waarde_wump();
	vector<int> cords = directions(random_rand_waarde_player());
    
    // Begin van het spel en de functies uitvoeren
	int side = move(cords);
    int finalDest = checkside(side, cords);
    
    // Loop: doorheen gaan van het spel.
    while(true){
        cords = directions(finalDest);
        side = move(cords);
        finalDest = checkside(side, cords);
    }
}
