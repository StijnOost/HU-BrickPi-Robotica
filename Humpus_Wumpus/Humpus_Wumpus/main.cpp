#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;


string getFileContents(ifstream& File)
{
    string Lines = "";
    if (File){
		while (File.good ()){
			string TempLine;
			getline (File , TempLine); 
			TempLine += "\n";  
			
			Lines += TempLine; 
		}
		return Lines;
	}
    else{
		return "ERROR File does not exist.";
    }
}


int ascii_art(string filename)
{
    string getFileContents(ifstream&); 
    ifstream infile(filename.c_str());
    string Art = getFileContents (infile);
    cout << Art << endl;
    infile.close ();

    return 0;
}


void leaderboard(){
	ascii_art("logo.txt");
}


void Instructies_uitlezen()
{
	string YorN_Instr;
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

bool collision_death(vector<int> kamer)
{
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


bool collision_bats(vector<int> kamer)
{
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


void ready_go()
{
    char Y_tostart;
    while(Y_tostart != 'Y' || Y_tostart != 'y'){
        cout << "\nAre you ready to start (Y)? ";
        cin >> Y_tostart;

        if(Y_tostart == 'Y' || Y_tostart == 'y'){
            break;
        }
    }
}

int location_wumpus()
{
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


bool wump_hit(int coords_wumpus,int schot_kamer)
{
	if (coords_wumpus == schot_kamer){
		return true;
	}
	return false;
}


bool wump_walk_shot(int wumpus_coords, int schot_kamer)
{
	if(wump_hit(wumpus_coords,schot_kamer)){
		return true;
	}
	else{
		return false;
	}
}



int player_start()
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
    cout << "---------------------------------------\n";
    cout << "You are in room: " << cords[0] << endl;
	cout << "There are tunnels that lead to room: " << cords[1] << ", " << cords[2] << " and " << cords[3] <<endl ;
    cout << "---------------------------------------\n";
	sense(cords);
    string SorM_Instr;
    while(true){
        cout << "Do you wanne shoot or move (S/M)? ";
		cin.ignore( 1000, '\n' );
        cin >> SorM_Instr;
        if(SorM_Instr[0] == 'S' || SorM_Instr[0] == 's' || SorM_Instr[0] == 'M' || SorM_Instr[0] == 'm'){
            return SorM_Instr;
        }
    }
}


int move(vector<int> cords)
{
    int side;
    cout << "To which room do you want to move to?: ";
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


vector<vector<int>> directions()
{
	ifstream infile;
	string filename = "map.txt";
	string line;
	vector<vector<int>> cords;
	vector<int> new_entry;
	infile.open(filename.c_str());
	if(infile.is_open()){
		for(int i=0;i<19;i++){
			cords.push_back(new_entry);
			cords[i].push_back(i);
			getline(infile, line);
			stringstream find;
			find << line;
			string temp;
			int found;
			while(!find.eof()) {
				find >> temp;
				if(stringstream(temp) >> found){
					cords[i].push_back(found);
				}
				temp = "";
			}
		}
		infile.close();
		return(cords);
	}
	else{
		infile.close();
		cout << "ERROR: File unreachable \n";
		return(cords);
	}
}


int wumpus_walky(int coords_wumpus, vector<vector<int>> way_to_go)
{
	ifstream infile;
	ofstream outfile;
	string filenameIn = "Waardes.txt";
	string filenameOut = "tmp.txt";
	string line;
    infile.open(filenameIn.c_str());
	outfile.open(filenameOut.c_str());
	
	vector<int> cords = way_to_go[coords_wumpus];
	int move_rand_wump = (rand()%3)+1;
	
	while(getline(infile, line)){
		if(line[0]=='W'){
			outfile << "W " << cords[move_rand_wump] << endl;
		}
		else{
			outfile << line << endl;
		}
	}
	
	infile.close();
	outfile.close();
	filenameIn = "tmp.txt";
	filenameOut = "Waardes.txt";
	infile.open(filenameIn.c_str());
	outfile.open(filenameOut.c_str());
	
	while(getline(infile, line)){
		outfile << line << endl;
	}
	
	return cords[move_rand_wump];
}


int aim(vector<int>cords){
    int shoot;
    cout << "To which room do you want to shoot?: ";
    cin >> shoot;
    int finalDest = checkside(shoot, cords);
    return finalDest;
}

int shoot(int arrows_amount, vector<int> cords, vector<vector<int>> way_to_go){
	if(arrows_amount>0){
		arrows_amount -=1;
		int wumpus_coords = location_wumpus();
		int schot_kamer = aim(cords);
		if(schot_kamer != -1){
			bool raak = wump_walk_shot(wumpus_coords, schot_kamer);
			if(raak){
				ascii_art("winner.txt");
				cout << "You win! You have slain the wumpus. You are MLG." << endl;
				return 999;
			}
			else{
				wumpus_coords = wumpus_walky(wumpus_coords, way_to_go);
				cout << endl << "You missed the shot and have lost the arrow, you have "  << arrows_amount << " left." << endl;
			}
		}
	}
	else{
		cout << endl << "You dont have any arrows left." << endl;
	}
	return arrows_amount;
}


int main()
{
	leaderboard();
	ready_go();  // Begint funcite om te vragen om mensen klaar zijn om te spelen.
	Instructies_uitlezen(); // Start functie die vraagt of mensen instructies wilt hebben.
	vector<vector<int>> way_to_go = directions();

	srand((unsigned)time(0));
	string username;
	while(true){
		cout << "Give a username: ";
		cin >> username;
		if(username.length()>3){
			cout << "Username exceeded the 3 character limit, try again." << endl;
		}
		else{
			cout << "Welcome, " << username << ". \n";
			break;
		}
	}

	vector<int> cords = way_to_go[player_start()];
	int arrows_amount = 5;
    int side;
    int finalDest;
    string Uitkomst_SPAO;  
	int score = 0;
	
	while(true){ // Loop: doorheen gaan van het spel.
		score+=1;
		Uitkomst_SPAO = Show_Position_And_Options(cords);
		if(Uitkomst_SPAO[0] == 'M' || Uitkomst_SPAO[0] == 'm'){
			side = move(cords);
			finalDest = checkside(side, cords);
			cords = way_to_go[finalDest];
			if (collision_bats(cords)){
				cout << "You've been carried away by bats!" << endl;
				cords = way_to_go[(rand()%19)+0];
			}
			if (collision_death(cords)){
				ascii_art("death.txt");
				cout << "You are dead, oh no!" << endl;
				break;
			}
			
		}
		else{
			arrows_amount = shoot(arrows_amount, cords, way_to_go);
			if(arrows_amount==999){
				break;
			}
		}
	}
}