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
    cout << "\nHunt the Wumpus" << endl;
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
    }
}
bool collision_death(vector<int> kamer){
    ifstream infile;
    string line;
    string filename = "Waardes.txt";
    infile.open(filename.c_str());
    if(infile.is_open()){
        while ( getline (infile, line) ){
            stringstream find;
            find << line;
            string temp;
            int found;
            while(!find.eof()) {
                find >> temp;
                if(stringstream(temp) >> found){
                    if (line[0] == 'W' || line[0] == 'G'){
                        if (found == kamer[0]){
                            infile.close();
                            return true;
                        }
                    }
                }
                temp = "";
            }
        }
    }
    else{
        cout << "ERROR: File unreachable \n";
        infile.close();
    }
    return false;
}
void sense(vector<int> kamer){
    ifstream infile;
    string line;
    string filename = "Waardes.txt";
    infile.open(filename.c_str());
    if(infile.is_open()){
        while ( getline (infile, line) ){
            stringstream find;
            find << line;
            string temp;
            int found;
            while(!find.eof()) {
                find >> temp;
                if(stringstream(temp) >> found){
                    for(unsigned int i=1;i<5;i++){
						if(found==kamer[i]){
							if(line[0]=='W'){
								cout << "You smell a disgusting beast" << endl;
							}
							else if(line[0]=='B'){
								cout << "You hear flapping nearby" << endl;
							}	
							else if(line[0]=='G'){
								cout << "You feel a cold breeze" << endl;
							}		
						}
					}
                }
                temp = "";
            }
        }
    }
    else{
        cout << "ERROR: File unreachable \n";
        infile.close();
    }
}

bool collision_bats(vector<int> kamer){
    ifstream infile;
    string line;
    string filename = "Waardes.txt";
    infile.open(filename.c_str());
    if(infile.is_open()){
        while ( getline (infile, line) ){
            stringstream find;
            find << line;
            string temp;
            int found;
            while(!find.eof()) {
                find >> temp;
                if(stringstream(temp) >> found){
                    if (line[0] == 'B'){
                        if (found == kamer[0]){
                            infile.close();
                            return true;
                        }
                    }
                }
                temp = "";
            }
        }
    }
    else{
        cout << "ERROR: File unreachable \n";
        infile.close();
        
    }
    return false;
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

void random_waardes_toewijzen(){
    ofstream waardes_infile;
	string filename = "Waardes.txt";
    waardes_infile.open(filename.c_str());
    if(waardes_infile.is_open()){
        int xyplayer = (rand()%19)+0;
        waardes_infile << "P " << xyplayer << endl;
        
        int xywump = (rand()%19)+0;
        while(xyplayer == xywump){
            xywump = (rand()%19)+0;
        }
        waardes_infile << "W " << xywump << endl;
        
        int xybats = (rand()%19)+0;
        while(xybats == xywump || xybats == xyplayer){
            xybats = (rand()%19)+0;
        }
        waardes_infile << "B " << xybats << endl;
        
        int xypit = (rand()%19)+0;
        while(xypit == xyplayer || xypit == xywump || xypit == xybats){
            xypit = (rand()%19)+0;
        }
        waardes_infile << "G" << xypit << endl;
    }
    else{
        cout << "ERROR: File unreachable \n";
    }
    waardes_infile.close();
    
}
int start_waarde_wumpus(){
    ifstream Start_waarde;
    string line;
    string filename = "Waardes.txt";
    Start_waarde.open(filename.c_str());
    if(Start_waarde.is_open()){
        while (true){
            getline(Start_waarde, line);
            if(line[0] == 'W'){
                stringstream find;
				find << line;
				string temp;
				int found;
				while(!find.eof()) {
					find >> temp;
					if(stringstream(temp) >> found){
                        Start_waarde.close();
						return found;
					}
					temp = "";
				}
            }
        }
    }
    else{
        cout << "ERROR: File unreachable \n";
        Start_waarde.close();
        return 0;
    }
}

bool raak_wumpus(int coords_wumpus,int schot_kamer)
{
	if (coords_wumpus == schot_kamer){
		return true;
	}
	return false;
}

int wumpus_lopen(int coords_wumpus)
{
	ifstream infile;
	string filename = "map.txt";
	string line;
	vector<int> cords;
	cords.push_back(coords_wumpus);
	infile.open(filename.c_str());
	if(infile.is_open()){
		for(int i=0;i<coords_wumpus+1;i++){
			getline(infile, line);
			if(i==coords_wumpus){
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

		int move_rand_wump = (rand()%3)+1;
		cords[move_rand_wump];
		return move_rand_wump;
	}
	else{
		infile.close();
		cout << "ERROR: File unreachable \n";
	}
}

bool schot_lopen_wumpus(int wumpus_coords, int schot_kamer){
	if(raak_wumpus(wumpus_coords,schot_kamer)){
		return true;
	}
	else{
		wumpus_coords = wumpus_lopen(wumpus_coords);
		return false;
	}
}

int schieten(){
    //vraag optie om te schieten
    //bij "yes" moet deze functie starten
    //vraag welke kamer je wilt schieten
    //check of die kamer aanliggend is
    //return kamer
    
}

int Begin_waarde_Speler()
{
    ifstream Start_waarde;
    string line;
    string filename = "Waardes.txt";
    Start_waarde.open(filename.c_str());
    if(Start_waarde.is_open()){
        while (true){
            getline(Start_waarde, line);
            if(line[0] == 'P'){
                stringstream find;
				find << line;
				string temp;
				int found;
				while(!find.eof()) {
					find >> temp;
					if(stringstream(temp) >> found){
                        Start_waarde.close();
						return found;
					}
					temp = "";
				}
            }
        }
    }
    else{
        cout << "ERROR: File unreachable \n";
        Start_waarde.close();
        return 0;
    }
}

int move(vector<int> cords){

    int side;
    cout << "---------------------------------------\n";
    cout << "You are in room: " << cords[0] << endl;
	cout << "Tunnels lead to room: " << cords[1] << ", " << cords[2] << " and " << cords[3] <<endl ;
    cout << "---------------------------------------\n";
	sense(cords);
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
		infile.close();
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
    
    vector<int> cords = directions(Begin_waarde_Speler());

    int schot_kamer = -1;

	int wumpus_coords = start_waarde_wumpus();

	// Er wordt gekeken of er is geschoten en of ie raak is dan wumpus locatie veranderen


    // Begin van het spel en de functies uitvoeren
	if(schot_kamer == -1){
		schot_lopen_wumpus(wumpus_coords, schot_kamer);
	}


	int side = move(cords);
    int finalDest = checkside(side, cords);


    // Loop: doorheen gaan van het spel.
    while(true){
        cords = directions(finalDest);
		if (collision_death(cords)){
            cout << "You are dead" << endl;
            break;
        }
        if (collision_bats(cords)){
            cout << "The bats carry you away" << endl;
            cords = directions((rand()%19)+0); 
        }
        side = move(cords);
        finalDest = checkside(side, cords);
    }
}
