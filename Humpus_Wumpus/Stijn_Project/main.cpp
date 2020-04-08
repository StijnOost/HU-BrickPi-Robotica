#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;


string get_file_contents(ifstream& File){
    string Lines = "";
    if (File){
		while (File.good ()){
			string Templine;
			getline (File , Templine);
			Templine += "\n";

			Lines += Templine;
		}
		return Lines;
	}
    else{
		return "ERROR File does not exist.";
    }
}


int ascii_art(string filename){
    string get_file_contents(ifstream&);
    ifstream infile(filename.c_str());
    string Art = get_file_contents (infile);
    cout << Art << endl;
    infile.close ();

    return 0;
}


void leaderboard(){
	ascii_art("logo.txt");
}


void read_instructions(){
	string YorN_instr;
    cout << "Do you need instructions: (Y/N)? ";
    getline(cin, YorN_instr);

    if(YorN_instr[0] == 'Y' || YorN_instr[0] == 'y'){
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


void sense(vector<int> room){
    ifstream infile;
    string line;
    string filename = "values.txt";
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
                        if(found==room[i]){
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




bool collision_death(vector<int> room){
    ifstream infile;
    string line;
    string filename = "values.txt";
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
                        if (found == room[0]){
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


bool collision_bats(vector<int> room){
    ifstream infile;
    string line;
    string filename = "values.txt";
    infile.open(filename.c_str());
    if(infile.is_open()){
        while ( getline (infile, line) ){
            stringstream find;
            find << line;
            int found;
            while(!find.eof()) {
                string temp;
                find >> temp;
                if(stringstream(temp) >> found){
                    if (line[0] == 'B'){
                        if (found == room[0]){
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


void ready_go(){
    string Y_tostart;
    cout << "\nAre you ready to start (Y)? ";
    while(true){
        getline(cin, Y_tostart);
        if (Y_tostart.size() < 2){
            if(Y_tostart[0] == 'Y' || Y_tostart[0] == 'y'){
				break;
            }
        }
        else{
            cout << "\nAre you ready to start (Y)? ";
        }
    }
}


void assign_values(){
    ofstream values_infile;
	string filename = "values.txt";
    values_infile.open(filename.c_str());
    if(values_infile.is_open()){
        int xyplayer = (rand()%20)+0;
        values_infile << "P " << xyplayer << endl;
        int xywump = (rand()%20)+0;
        while(xyplayer == xywump){
            xywump = (rand()%20)+0;
        }
        values_infile << "W " << xywump << endl;

        int xybats = (rand()%20)+0;
        while(xybats == xywump || xybats == xyplayer){
            xybats = (rand()%20)+0;
        }
        values_infile << "B " << xybats << endl;

        int xypit = (rand()%20)+0;
        while(xypit == xyplayer || xypit == xywump || xypit == xybats){
            xypit = (rand()%20)+0;
        }
        values_infile << "G " << xypit << endl;
    }
    else{
        cout << "ERROR: File unreachable \n";
    }
    values_infile.close();
}


int location_wumpus(){
    ifstream start_value;
    string line;
    string filename = "values.txt";
    start_value.open(filename.c_str());
    if(start_value.is_open()){
        while (true){
            getline(start_value, line);
            if(line[0] == 'W'){
                stringstream find;
				find << line;
				string temp;
				int found;
				while(!find.eof()) {
					find >> temp;
					if(stringstream(temp) >> found){
                        start_value.close();
						return found;
					}
					temp = "";
				}
            }
        }
    }
    else{
        cout << "ERROR: File unreachable \n";
        start_value.close();
        return 0;
    }
}


bool wump_hit(int cords_wumpus,int shot_room){
	if (cords_wumpus == shot_room){
		return true;
	}
	return false;
}


bool wump_walk_shot(int wumpus_cords, int shot_room){
	if(wump_hit(wumpus_cords,shot_room)){
		return true;
	}
	else{
		return false;
	}
}



int player_start(){
    ifstream start_value;
    string line;
    string filename = "values.txt";
    start_value.open(filename.c_str());
    if(start_value.is_open()){
        while (true){
            getline(start_value, line);
            if(line[0] == 'P'){
                stringstream find;
				find << line;
				string temp;
				int found;
				while(!find.eof()) {
					find >> temp;
					if(stringstream(temp) >> found){
                        start_value.close();
						return found;
					}
					temp = "";
				}
            }
        }
    }
    else{
        cout << "ERROR: File unreachable \n";
        start_value.close();
        return 0;
    }
}


string show_position_and_options(vector<int> cords){
    cout << "---------------------------------------\n";
    cout << "You are in room: " << cords[0] << endl;
	cout << "There are tunnels that lead to room: " << cords[1] << ", " << cords[2] << " and " << cords[3] <<endl ;
    cout << "---------------------------------------\n";
	sense(cords);
    string SorM_instr = "";
    cout << "Do you want to shoot or move (S/M)? ";
    while(true){
            getline(cin,SorM_instr);
            if(SorM_instr.size() < 2){
                if(SorM_instr[0] == 'S' || SorM_instr[0] == 's' || SorM_instr[0] == 'M' || SorM_instr[0] == 'm'){
                    return SorM_instr;
                }

            }
            else{
                cout << "Do you want to shoot or move (S/M)? ";
            }

    }
}


int move(vector<int> cords){
    int side;
    cout << "To which room do you want to move to?: ";
    cin >> side;
    return side;
}


int checkside(int side, vector<int> cords){
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


vector<vector<int> > directions(){
	ifstream infile;
	string filename = "map.txt";
	string line;
	vector<vector<int> > cords;
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


int wumpus_walky(int cords_wumpus, vector<vector<int> > way_to_go){
	ifstream infile;
	ofstream outfile;
	string filename_in = "values.txt";
	string filename_out = "tmp.txt";
	string line;
    infile.open(filename_in.c_str());
	outfile.open(filename_out.c_str());

	vector<int> cords = way_to_go[cords_wumpus];

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
	filename_in = "tmp.txt";
	filename_out = "values.txt";
	infile.open(filename_in.c_str());
	outfile.open(filename_out.c_str());

	while(getline(infile, line)){
		outfile << line << endl;
	}


	return cords[move_rand_wump];
}


int aim(vector<int>cords){
    int shoot;
    cout << "To which room do you want to shoot?: ";
    cin >> shoot;
    int final_dest = checkside(shoot, cords);
    return final_dest;
}

int shoot(int arrows_amount, vector<int> cords, vector<vector<int> > way_to_go){
	if(arrows_amount>0){
		arrows_amount -=1;
		int wumpus_cords = location_wumpus();
		int shot_room = aim(cords);
		if(shot_room != -1){
			bool hit = wump_walk_shot(wumpus_cords, shot_room);
			if(hit){
				ascii_art("winner.txt");
				cout << "You win! You have slain the wumpus!" << endl;
				return 999;
			}
			else{
				wumpus_cords = wumpus_walky(wumpus_cords, way_to_go);
				cout << endl << "You missed the shot and have lost the arrow, you have "  << arrows_amount << " left." << endl;
			}
		}
	}
	else{
		cout << endl << "You don't have any arrows left." << endl;
	}
	return arrows_amount;
}

bool restart_game_question(bool restart_game)
{
    string Restart_Char;
    cout << "Would you like to restart the same game? (Y/N) ";
    while(true){
        getline(cin, Restart_Char);
        if (Restart_Char.size() < 2){
            if(Restart_Char[0] == 'Y' || Restart_Char[0] == 'y'){
                return true;
            }
            else if(Restart_Char[0] == 'N' || Restart_Char[0] == 'n'){
                return false;
            }
        }
        else{
            cout << "Would you like to restart the same game? (Y/N) ";
        }
    }
}

char AI_sense(vector<int> room){
    ifstream infile;
    string line;
	vector<char> dangers;
    string filename = "values.txt";
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
                        if(found==room[i]){
                            if(line[0]=='W'){
                                cout << "AI smells a disgusting beast" << endl;
								dangers.append('w')
                            }
                            if(line[0]=='B'){
                                cout << "AI hears flapping nearby" << endl;
								dangers.append('b')
                            }
                            if(line[0]=='G'){
                                cout << "AI feels a cold breeze" << endl;
								dangers.append('g')
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
vector<int> ai_avoid(pit_rooms,wump_rooms,cords){
	if (pit_rooms.size()>wump_rooms.size())
		for(i=0; i>pit_rooms.size();i++;){
			for
			if(pit_rooms[i] == cords[i+1] || wump_rooms[i] == cords[i+1]){
				
			}
		}
}


vector<string> algorithm_way_to_go(cords)
{
	vector<int> pit_rooms;
	vector<int> wump_rooms;
	vector<int> visited;
	vector<string> S_M_and_room;
	
	char str[2];
	
	visited.append(cords[0]); //Kamer waar die staat toewijzen dat ie daar is geweest
	vector<char> danger = AI_sense(cords); //als er iets in de buurt is
	for (int i = 1; i > cords.size(); i++){
		if (danger[0] == 'w'){ 					//voeg alle kamers eromheen toe aan de gevaarlijke vector
			for(int j=0; j>visited.size(); j++){		//verwijder de kamers waar je al bent geweest of nog nergens geweest random
				if (visited[j] != cords[i]){
					wump_rooms.append(cords[i]);
				}
			}
		}
		if(danger[0] == 'p'||danger[1] == 'p'){
			for(int j=0; j>visited.size(); j++){		//verwijder de kamers waar je al bent geweest of nog nergens geweest random
				if (visited[j] != cords[i]){
					pit_rooms.append(cords[i]);
				}
				
			}
		}
		vector<int> directions = ai_avoid(pit_rooms,wump_rooms,cords)
	}
	if (wump.size() == 1){
		S_M_and_room.append("s");
		sprintf(str, "%d", wump_rooms[0]);
		S_M_and_room.append(str);
		return S_M_and_room;
	}
	else{
		S_M_and_room.append('m');
		int start_value_ran = directions.size;
		int direction_to_go = (rand()%start_value_ran)+0;
		sprintf(str, "%d", direction_to_go);
		S_M_and_room.append(str);
		return S_M_and_room
	}
	
		
}

int main(){
  bool restart_game = true;
  while(restart_game){
  	leaderboard();
  	ready_go();  // Begint funcite om te vragen om mensen klaar zijn om te spelen.
  	read_instructions(); // Start functie die vraagt of mensen instructies wilt hebben.
  	vector<vector<int> > way_to_go = directions();

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
      int final_dest;
      string outcome_SPAO;
	  char ai_outcomeSPAO;
  	int score = 0;
	
	int aiside = 0;
	ai_outcomeSPAO = algorithm_way_to_go(cords);
	char a = '4';
	int ia = a - '0';
	ai_side = ai_move();
	
  	while(true){ // Loop: doorheen gaan van het spel.
  		score+=1;
  		//outcome_SPAO = show_position_and_options(cords);
  		if(ai_outcome_SPAO[0] == 'M' || ai_outcome_SPAO[0] == 'm'){
  			side = move(cords);
  			final_dest = checkside(side, cords);
  			cords = way_to_go[final_dest];
  			if (collision_bats(cords)){
  				cout << "You've been carried away by bats!" << endl;
  				cords = way_to_go[(rand()%20)+0];
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
    restart_game = restart_game_question(restart_game);
}
}
