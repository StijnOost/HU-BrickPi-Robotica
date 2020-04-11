#include "wumpHead.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <Windows.h>
using namespace std;
// Meeste code hier is een copy van de main.cpp, alle functies die nieuw zijn is bijgezet wie het heeft gemaakt

string get_file_contents_AI(ifstream& File){
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


int ascii_art_AI(string filename){
    string get_file_contents_AI(ifstream&);
    ifstream infile(filename.c_str());
    string Art = get_file_contents_AI(infile);
    cout << Art << endl;
    infile.close ();

    return 0;
}


void leaderboard_AI(){
	ascii_art_AI("logo.txt");
}


void read_instructions_AI(){
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


void sense_AI(vector<int> room){
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




bool collision_death_AI(vector<int> room){
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


bool collision_bats_AI(vector<int> room){
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


void ready_go_AI(){
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


int location_wumpus_AI(){
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


bool wump_hit_AI(int cords_wumpus,int shot_room){
	if (cords_wumpus == shot_room){
		return true;
	}
	return false;
}


bool wump_walk_shot_AI(int wumpus_cords, int shot_room){
	if(wump_hit_AI(wumpus_cords,shot_room)){
		return true;
	}
	else{
		return false;
	}
}



int player_start_AI(){
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


string show_position_and_options_AI(vector<int> cords){
    cout << "---------------------------------------\n";
    cout << "You are in room: " << cords[0] << endl;
	cout << "There are tunnels that lead to room: " << cords[1] << ", " << cords[2] << " and " << cords[3] <<endl ;
    cout << "---------------------------------------\n";
	sense_AI(cords);
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


int move_AI(vector<int> cords){
    int side;
    cout << "To which room do you want to move to?: ";
    cin >> side;
    return side;
}


int checkside_AI(int side, vector<int> cords){
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


vector<vector<int> > directions_AI(){
	ifstream infile;
	string filename = "map.txt";
	string line;
	vector<vector<int> > cords;
	vector<int> new_entry;
	infile.open(filename.c_str());
	if(infile.is_open()){
		for(int i=0;i<20;i++){
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


int wumpus_walky_AI(int cords_wumpus, vector<vector<int> > way_to_go){
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


int aim_AI(vector<int>cords){
    int shoot;
    cout << "To which room do you want to shoot?: ";
    cin >> shoot;
    int final_dest = checkside_AI(shoot, cords);
    return final_dest;
}

int shoot_AI(int arrows_amount, vector<int> cords, vector<vector<int> > way_to_go){
	if(arrows_amount>0){
		arrows_amount -=1;
		int wumpus_cords = location_wumpus_AI();
		int shot_room = aim_AI(cords);
		if(shot_room != -1){
			bool hit = wump_walk_shot_AI(wumpus_cords, shot_room);
			if(hit){
				ascii_art_AI("winner.txt");
				cout << "You win! You have slain the wumpus!" << endl;
				return 999;
			}
			else{
				wumpus_cords = wumpus_walky_AI(wumpus_cords, way_to_go);
				cout << endl << "You missed the shot and have lost the arrow, you have "  << arrows_amount << " left." << endl;
			}
		}
	}
	else{
		cout << endl << "You don't have any arrows left." << endl;
	}
	return arrows_amount;
}

bool restart_game_question_AI(bool restart_game){
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

vector<char> AI_sense(vector<int> room){// Bekijkt waar het gevaar is returned dit in een vec  // Gemaakt door Stijn
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
								dangers.push_back('w');
                            }
                            if(line[0]=='B'){
                                cout << "AI hears flapping nearby" << endl;
								dangers.push_back('b');
                            }
                            if(line[0]=='G'){
                                cout << "AI feels a cold breeze" << endl;
								dangers.push_back('g');
                            }
							
                        }
			
                    }
				}
			temp = "";
			}
		
        }
		if (dangers.size()==0){
			dangers.push_back('n'); //no dangers
		}
		return dangers;
		
    }
    else{
        cout << "ERROR: File unreachable \n";
        infile.close();
    }
}
vector<int> ai_avoid(vector<int>pit_rooms,vector<int>wump_rooms,vector<int>cords){ //Kijken waar hij niet naartoe moet  // Gemaakt door Stijn
	vector<int> temp;
	bool room_hazard = false;
	int count;
	for(unsigned int i=1;i<4;i++){
	count = 0;
		for(unsigned int j=0;j<wump_rooms.size();j++){
			room_hazard == false;
			if(cords[i]==wump_rooms[j]&& count==0){
				count += 1;
				room_hazard = true;
				cout<<cords[i]<<"same dus HAZARD"<<wump_rooms[j]<<endl;
				Sleep(100);
			}
		}
		cout << cords[i]<< room_hazard<<"False safe"<<endl;
		if(room_hazard == false){
			temp.push_back(cords[i]);
		}
	}
	cout<<temp.size()<< "temp"<<endl;
	Sleep(500);
	return temp;
}


vector<string> algorithm_way_to_go(vector<int>cords,vector<int> & visited,vector<int> & wump_rooms,vector<int> & pit_rooms){ //Algorithm van het ai  // Gemaakt door Stijn
	vector<string> S_M_and_room;
	vector<int>wump_rooms_safe;
	vector<int> directions;
	char str[2];
	int count;
	int count_safe;
	
	visited.push_back(cords[0]); //Kamer waar die staat toewijzen dat ie daar is geweest
	cout<<visited.size()<<"size visited"<<endl;
	vector<char> danger = AI_sense(cords); //als er iets in de buurt is
	for (int i=0; i<3; i++){
	count_safe =0;
	count = 0;
		if (danger[0] == 'w'){ 					//voeg alle kamers eromheen toe aan de gevaarlijke vector
		cout << cords[0]<<"i am here and scared"<<endl;
			for(int j=0; j<visited.size(); j++){		//verwijder de kamers waar je al bent geweest of nog nergens geweest random
				cout<<visited[j] << " " << cords[i+1]<<endl;
				cout<<count<<"count"<<endl;
				cout<<count_safe<<"safe"<<endl;
				Sleep(100);
				if (visited[j] == cords[i+1]){
					if(count_safe == 1){ 
						count_safe +=1;
						wump_rooms_safe.push_back(cords[i+1]);
						cout << visited[j] << "vistited" << endl; 
						cout << cords[i+1] << "cords" << endl; 
						Sleep(300);
						
					}
				}
				else if(count==0){
					count=+1;
					wump_rooms.push_back(cords[i+1]);
				}
				cout<<endl;
			}
		}
		
		if(danger[0] == 'p'||danger[1] == 'p'){
			for(int j=0; j>visited.size(); j++){		//verwijder de kamers waar je al bent geweest of nog nergens geweest random
				if (visited[j] != cords[i]){
					pit_rooms.push_back(cords[i]);
				}
			}
		}
		Sleep(300);
	}
	cout<<wump_rooms_safe.size()<<"safe rooms"<<endl;
	if (wump_rooms_safe.size()==0){
		directions = ai_avoid(pit_rooms,wump_rooms,cords);
	}
	else{
		cout<<directions[0]<<"safe"<<endl;
		directions = wump_rooms_safe;
	}
	
	cout<<wump_rooms.size() << "Wump rooms"<< endl;
	for(int i=0; i<wump_rooms.size(); i++){
		cout<<wump_rooms[i]<<" wump_rooms"<<endl;
	}
	if (wump_rooms.size() == 1){
		cout<<"paniek"<<endl;
		S_M_and_room.push_back("s");
		sprintf(str, "%d", wump_rooms[0]);
		S_M_and_room.push_back(str);
		Sleep(100);
		return S_M_and_room;
	}
	else{
		int direction_to_go;
		bool same = true;
		S_M_and_room.push_back("m");
		int start_value_ran = directions.size();
		cout<< start_value_ran <<"start"<<endl;
		while(same){
			direction_to_go = (rand()%start_value_ran)+1;
			for(int i; i<visited.size(); i++){
				cout<< visited[i]<<" been there" <<endl;
				if(visited[i]!=cords[direction_to_go]){
					same = false; 
					continue;
				}
				
			}
			same = false;
		}
		cout<< "after random val"<<endl;
		sprintf(str, "%d", cords[direction_to_go]);
		S_M_and_room.push_back(str);
		cout<< cords[direction_to_go] << "moving too"<<endl;
		cout<< S_M_and_room[0] << S_M_and_room[0] << "move too room return"<<endl;
		return S_M_and_room;
	}
	
		
}

int start(){//Vernieuwde main() // Gemaakt door Stijn
  bool restart_game = true;
  while(restart_game){
  	leaderboard_AI();
  	ready_go_AI();  // Begint funcite om te vragen om mensen klaar zijn om te spelen.
  	read_instructions_AI(); // Start functie die vraagt of mensen instructies wilt hebben.
  	vector<vector<int> > way_to_go = directions_AI();

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

  	vector<int> cords = way_to_go[player_start_AI()];
	cout<< cords[0]<<cords[1]<<cords[2]<<cords[3];
  	int arrows_amount = 5;
	int side;
	int final_dest;
	string outcome_SPAO;
	vector<string> ai_outcome_SPAO;
  	int score = 0;
	int aiside = 0;
	string ai_SPAO; 
	vector<int> visited;
	vector<int> wump_rooms;
	vector<int> pit_rooms;
	
	
	while(true){ // Loop: doorheen gaan van het spel.
		score+=1;
		ai_outcome_SPAO = algorithm_way_to_go(cords,visited,wump_rooms,pit_rooms);
		
		ai_SPAO	= ai_outcome_SPAO[0];
		
		cout<< endl<< ai_outcome_SPAO[1] << " room" << endl;
  		//outcome_SPAO = show_position_and_options_AI(cords);
  		if(ai_SPAO[0] == 'M' || ai_SPAO[0] == 'm'){
			cout<<"after move"<<endl;
			istringstream(ai_outcome_SPAO[1]) >> side;
			
  			final_dest = checkside_AI(side, cords);
			cout<<"after checkside"<<endl;
			cout<< final_dest<<"final dest"<<endl;
			cout<< way_to_go.size()<<"go size"<<endl;
  			cords = way_to_go[final_dest];
			cout<<"after way to go"<<endl;
  			if (collision_bats_AI(cords)){
  				cout << "You've been carried away by bats!" << endl;
  				cords = way_to_go[(rand()%20)+0];
  			}
  			if (collision_death_AI(cords)){
  				ascii_art_AI("death.txt");
  				cout << "You are dead, oh no!" << endl;
  				break;
  			}

  		}
  		else{
  			arrows_amount = shoot_AI(arrows_amount, cords, way_to_go);
  			if(arrows_amount==999){
  				break;
  			}
  		}
  	}
    restart_game = restart_game_question_AI(restart_game);
}
}
