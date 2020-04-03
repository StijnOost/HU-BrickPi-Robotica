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
                            if(line[0]=='B'){
                                cout << "You hear flapping nearby" << endl;
                            }    
                            if(line[0]=='G'){
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

int death()
{
    string getFileContents (ifstream&); 
    ifstream Reader ("death.txt");             //Open file

    string Art = getFileContents (Reader);       //Get file
    
    cout << Art << endl;               //Print it to the screen

    Reader.close ();                           //Close file

    return 0;
}

string getFileContents (ifstream& File)
{
    string Lines = "";        //All lines
    
    if (File)                      //Check if everything is good
    {
    while (File.good ())
    {
        string TempLine;                  //Temp line
        getline (File , TempLine);        //Get temp line
        TempLine += "\n";                      //Add newline character
        
        Lines += TempLine;                     //Add newline
    }
    return Lines;
    }
    else                           //Return error
    {
    return "ERROR File does not exist.";
    }
}

int win()
{
    string getFileContents (ifstream&); 
    ifstream Reader ("winner.txt");             //Open file

    string Art = getFileContents (Reader);       //Get file
    
    cout << Art << endl;               //Print it to the screen

    Reader.close ();                           //Close file

    return 0;
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

char Klaar_Om_Te_Spelen()
{
    char Y_tostart;
    while(Y_tostart != 'Y' || Y_tostart != 'y'){
        cout << "\nAre you ready to start (Y)? ";
        cin >> Y_tostart;

        if(Y_tostart == 'Y' || Y_tostart == 'y'){
            return Y_tostart;
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
        waardes_infile << "G " << xypit << endl;
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
		return cords[move_rand_wump];
	}
	else{
		infile.close();
		cout << "ERROR: File unreachable \n";
	}
}

bool raak_wumpus(int coords_wumpus,int schot_kamer)
{
	if (coords_wumpus == schot_kamer){
		return true;
	}
	return false;
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
string Show_Position_And_Options(vector<int> cords)
{
    int side;
    cout << "---------------------------------------\n";
    cout << "You are in room: " << cords[0] << endl;
	cout << "Tunnels lead to room: " << cords[1] << ", " << cords[2] << " and " << cords[3] <<endl ;
    cout << "---------------------------------------\n";
	sense(cords);
    while(true){
		cout << "Do you wanne shoot or move (S/M)? ";
        string SorM_Instr = "";
		cin.ignore( 1000, '\n' );
        cin >> SorM_Instr;
		cout << SorM_Instr << endl;
		cout << SorM_Instr[0] << endl;
            if(SorM_Instr[0] == 'S' || SorM_Instr[0] == 's' || SorM_Instr[0] == 'M' || SorM_Instr[0] == 'm'){
                return SorM_Instr;
            }
    }
        
        
}


int move(vector<int> cords)
{
    int side;
    cout << "Which direction do you move to?: ";
    cin >> side;
    return side;
}

int checkside(int side, vector<int> cords)
{
    while(true){
        if (side == cords[1] || side == cords[2] || side == cords[3]){
        return side;
        }
        else{
            cout << "No such room nearby, try again:" << endl;
			cin.clear();
            cin.ignore(INT_MAX, '\n');
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

int schieten(vector<int>cords){
    int shoot;
    cout << "To which room do you want to shoot?: ";
    cin >> shoot;
    int finalDest = checkside(shoot, cords);
    return finalDest;
}

int main()
{
    // Start functie die vraagt of mensen instructies wilt hebben.
    Instructies_uitlezen();

    // Begint funcite om te vragen om mensen klaar zijn om te spelen.
		char Klaar_Om_to_Spelen_Uitkomst = Klaar_Om_Te_Spelen();

	 // Random waardes geven voor spawn points voor Wumpus en de spelers ( Moet nog bats en pit zijn. )
	 srand((unsigned)time(0));
	 if(Klaar_Om_to_Spelen_Uitkomst != 'Y' || Klaar_Om_to_Spelen_Uitkomst != 'y'){
			 random_waardes_toewijzen();
	 }
    // Random waardes geven voor spawn points voor Wumpus en de spelers ( Moet nog bats en pit zijn. )

	vector<int> cords = directions(Begin_waarde_Speler());
	int wumpus_coords = start_waarde_wumpus();

	// Er wordt gekeken of er is geschoten en of ie raak is dan wumpus locatie veranderen
	bool finish = true;
	int schot_kamer = -1;
	int arrows_amount = 5;
    // Begint funcite om te vragen om mensen klaar zijn om te spelen.

    // Random waardes geven voor spawn points voor Wumpus en de spelers ( Moet nog bats en pit zijn. )

    // Begin van het spel en de functies uitvoeren
    int side;
    int finalDest;
    string Uitkomst_SPAO = Show_Position_And_Options(cords);
    if(Uitkomst_SPAO[0] == 'M' || Uitkomst_SPAO[0] == 'm'){
        side = move(cords);
        finalDest = checkside(+side, cords);
		cords = directions(finalDest);
		if (collision_bats(cords)){
			cout << "The bats carry you away" << endl;
			cords = directions((rand()%19)+0);
		}
		if (collision_death(cords)){
			death();
			cout << "You are dead, oh noh!" << endl;
			finish = false;
		}

    }
    else{
		if(arrows_amount>0){
			arrows_amount -=1;
			schot_kamer = schieten(cords);
			if(schot_kamer != -1){
				bool raak = schot_lopen_wumpus(wumpus_coords, schot_kamer);
				if(raak){
					win();
					cout << "You win! You have killed the wumpus. You are MLG." << endl;
					finish = false;
				}else{
					cout << endl <<"You missed the shot you have " << arrows_amount << " left." << endl;
				}
			}
		}
		else{
			cout << endl <<"You dont have any arrows left, you cant shoot."<< endl;
		}
	}
	if(finish == true){    // Loop: doorheen gaan van het spel.
		while(true){
			Uitkomst_SPAO = Show_Position_And_Options(cords);
			if(Uitkomst_SPAO[0] == 'M' || Uitkomst_SPAO[0] == 'm'){
				side = move(cords);
				finalDest = checkside(side, cords);
				cords = directions(finalDest);// Loop: doorheen gaan van het spel
				if (collision_bats(cords)){
					cout << "The bats carry you away" << endl;
					cords = directions((rand()%19)+0);
				}
				if (collision_death(cords)){
					death();
					cout << "You are dead, oh noh!" << endl;
					break;
				}
				
			}
			else{
				if(arrows_amount>0){// HIER MOET CODE VOOR SCHIETEN
					arrows_amount -=1;
					schot_kamer = schieten(cords);
					if(schot_kamer != -1){
						bool raak = schot_lopen_wumpus(wumpus_coords, schot_kamer);
						if(raak){
							win();
							cout << "You win! You have killed the wumpus. You are MLG." << endl;
							break;
						}
						else{
							cout << endl << "You missed the shot you have "  <<arrows_amount<< " left." << endl;
						}
					}
					
				}
				else{
					cout << endl << "You dont have any arrows left, you cant shoot." << endl;
					}
				
			}

		}
	}
}

