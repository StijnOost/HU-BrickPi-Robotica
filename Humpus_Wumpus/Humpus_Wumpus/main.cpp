#include "wumpHead.hpp"
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;


string get_file_contents(ifstream& File){ //Opent de ascii file en returned 1 lange string aan tekens // Gemaakt door Tim
    string Lines = "";
    if (File){
		while (File.good()){
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


int ascii_art(const string filename){ //Openen van een text file met een ascii plaatje. parameter is de text file naam. // Gemaakt door Tim
    string get_file_contents(ifstream&);
    ifstream infile(filename.c_str());
    string Art = get_file_contents (infile);
    cout << Art << endl;
    infile.close ();

    return 0;
}


void leaderboard(){ //Laat het leaderboard zien met de beste 9 tijden voor het verslaan van Wumpus // Gemaakt door Alexander
	ascii_art("logo.txt");
	ifstream infile;
	string filename_in = "score.txt";
	string line;
	infile.open(filename_in.c_str());
	int place = 0;
	
	cout << "Place | Name | Score | Time" << endl;
	cout << "---------------------------" << endl;
	for(unsigned int i=1;i<10;i++){
        getline(infile, line);
		place+=1;
		if(place==1){
			cout << "1st:    " << line << endl;
		}
		else if(place==2){
			cout << "2nd:    " << line << endl;
		}
		else if(place==3){
			cout << "3rd:    " << line << endl;
		}
		else{
			cout << place <<"th:    " << line << endl;
		}
	}
	cout << "---------------------------" << endl;
}


void register_score(const string username, const time_t start_time, const int score){ //Registreert je score in een file als je hebt gewonnen met de naam score en tijd // Gemaakt door Alexander
	double diffrence = difftime( time(0), start_time);
	cout << "You won with a score of " << score << " whithin " << diffrence << " seconds." << endl;
	
	ifstream infile;
	ofstream outfile;
	string filename_in = "score.txt";
	string filename_out = "tmp.txt";
	string line;
	bool wrote = false;
    infile.open(filename_in.c_str());
	outfile.open(filename_out.c_str());
    
	while(getline(infile, line)){
		outfile << line << endl;
	}

	infile.close();
	outfile.close();
	filename_in = "tmp.txt";
	filename_out = "score.txt";
	infile.open(filename_in.c_str());
	outfile.open(filename_out.c_str());
	
	int amount_lines = 0;
	while(getline(infile, line)){
		if(amount_lines==9){
			break;
		}
		stringstream find;
		find << line;
		int found;
		while(!find.eof()) {
			string temp;
			find >> temp;
			if(stringstream(temp) >> found){
				if(wrote==false && score < found){
					if(score>9){
                        outfile << username << "      " << score << "     " << diffrence << endl;
                    }
                    else{
                        outfile << username << "      " << score << "      " << diffrence << endl;
                    }
					amount_lines+=1;
					wrote=true;
				}
				else if(wrote==false && score == found){
					while(!find.eof()) {
						string temp;
						find >> temp;
						if(stringstream(temp) >> found){
							if(diffrence < found){
                                if(score>9){
                                    outfile << username << "      " << score << "     " << diffrence << endl;
                                }
								else{
                                    outfile << username << "      " << score << "      " << diffrence << endl;
                                }
								amount_lines+=1;
								wrote=true;
							}
						}
					}
				}
				outfile << line << endl;
				if(amount_lines==9){
					break;
				}
				amount_lines+=1;
				break;
			}
			temp = "";
		}
		
	}
	if(amount_lines==0 || (amount_lines<9 && wrote == false)){
        if(score>9){
            outfile << username << "      " << score << "     " << diffrence << endl;
        }
        else{
            outfile << username << "      " << score << "      " << diffrence << endl;
        }
	}
	infile.close();
	outfile.close();
}


void read_instructions(){ //Vraagt om instructies van het spel  // Gemaakt door Jari
	string YorN_instr;
    cout << "Do you need instructions: (Y/N)? ";
    getline(cin, YorN_instr);

    if(YorN_instr[0] == 'Y' || YorN_instr[0] == 'y'){
		cout << "1. Your goal is to kill The Wumpus \n";
        cout << "2. There are 3 hazards, you will sense them if you get too close: \n";
            cout << "\t1.1 A bottomless pit (you will feel a breeze nearby).\n";
            cout << "\t1.2 A colony of bats that will pick you up and drop you in a random space (you will hear flapping nearby).\n";
            cout << "\t1.3 A fearsome, hungry, and unbathed wumpus (you will smell it nearby).\n";
        cout << "3. The wumpus is heavy; bats cannot lift him.\n";
        cout << "4. The wumpus is covered in suction cups; he won't fall down the bottomless pit.\n";
        cout << "5. Firing an arrow that misses the wumpus may cause it to move.\n";
        cout << "6. You have 5 wumpus-piercing arrows, if you run out you better start running.\n";
    }
}


void sense(const vector<int> room){ //Laat de messages zien als je dichtbij een Wumpus, Bats of Pit bent // Gemaakt door Alexander
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
                            if(line[0]=='H'){
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


int collision_death(const vector<int> room){ //Checkt of je op de Wumpus loopt // Gemaakt door Iedereen
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
                    if (line[0] == 'W'){
                        if (found == room[0]){
                            infile.close();
                            return 2;
                        }
                    }
					else if (line[0] == 'H'){
                        if (found == room[0]){
                            infile.close();
                            return 1;
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
    return 0;
}


bool collision_bats(const vector<int> room){ //Checkt of je op de Bats loopt // Gemaakt door Iedereen
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


void ready_go(){ //Vraagt of je het spel wilt spelen // Gemaakt door Jari
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


int location_wumpus(){ //Zoekt de locatie van de Wumpus // Gemaakt door Stijn
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


bool wump_hit(const int cords_wumpus, const int shot_room){ //Check of de pijl de Wumpus raakt // Gemaakt door Stijn
	if (cords_wumpus == shot_room){
		return true;
	}
	return false;
}


bool wump_walk_shot(const int wumpus_cords, const int shot_room){ //Check of de Wumpus moet lopen (true is gewonnen, false is lopen) // Gemaakt door Stijn
	if(wump_hit(wumpus_cords,shot_room)){
		return true;
	}
	else{
		return false;
	}
}


int player_start(){ //Startwaarde van de speler // Gemaakt door Alexander
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


string show_position_and_options(const vector<int> cords){ //Laat de speler zien in welke kamer hij/zij is en vraagt om te schieten of lopen // Gemaakt door Jari/Tim
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


int move(const vector<int> cords){ //Vragen naar welke kamer de speler wilt lopen // Gemaakt door Tim
    int side;
    cout << "To which room do you want to move to?: ";
    cin >> side;
    return side;
}


int checkside(int side, const vector<int> cords){ //Check of de opgegeven kamer van move() aanliggend is aan de kamer waar de speler is // Gemaakt door Tim
    while(true){
        if (side == cords[1] || side == cords[2] || side == cords[3]){
        return side;
        }
        else{
            cout << "No such room nearby, try again: ";
			cin.clear();
            cin.ignore(INT_MAX, '\n');
            cin >> side;
        }
    }
}


vector<vector<int>> directions(){ //Maakt een vector met de kamer en de aanliggende 3 kamers // Gemaakt door Alexander
	ifstream infile;
	string filename = "map.txt";
	string line;
	vector<vector<int>> cords;
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


int wumpus_walky(const int cords_wumpus, const vector<vector<int>> way_to_go){ //Laat de wumpus naar een random kamer om zich heen lopen // Gemaakt door Stijn
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

	infile.close();
	outfile.close();
	return cords[move_rand_wump];
}


int aim(const vector<int> cords){ // Gemaakt door Stijn
    int shoot;
    cout << "To which room do you want to shoot?: ";
    cin >> shoot;
    int final_dest = checkside(shoot, cords);
    return final_dest;
}


vector<int> shoot(int arrows_amount, const vector<int> cords, const vector<vector<int>> way_to_go){ //Check of de speler nog pijlen heeft, zo ja: laat de speler weten of hij/zij de wumpus heeft geraakt // Gemaakt door Stijn/Tim
	vector<int> shoot_info;
	if(arrows_amount>0){
		shoot_info.push_back(arrows_amount-1);
		int wumpus_cords = location_wumpus();
		int shot_room = aim(cords);
		if(shot_room != -1){
			bool hit = wump_walk_shot(wumpus_cords, shot_room);
			if(hit){
				ascii_art("winner.txt");
				cout << "You win! You have slain the wumpus!" << endl;
				shoot_info.push_back(1);
				return shoot_info;
			}
			else if(shoot_info[0]==0){
				ascii_art("death wump.txt");
				cout << "You have shot your last shot, The Wumpus noticed this and charged you down." << endl;
				shoot_info.push_back(2);
				return shoot_info;
			}
			else{
				wumpus_cords = wumpus_walky(wumpus_cords, way_to_go);
				cout << endl << "You missed the shot and have lost the arrow, you have "  << shoot_info[0] << " left." << endl;
			}
		}
	}
	shoot_info.push_back(0);
	return shoot_info;
}


bool restart_game_question(){ //Vraagt de speler om het spel opnieuw te spelen // Gemaakt door Jari
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


void save_loadout(){ //Slaat de waarde van de speler, Wumpus, Bats en Pit op in een text file // Gemaakt door Alexander
	ifstream infile;
	ofstream outfile;
	string filename_in = "values.txt";
	string filename_out = "values begin.txt";
	string line;
    infile.open(filename_in.c_str());
	outfile.open(filename_out.c_str());
    
	while(getline(infile, line)){
		outfile << line << endl;
	}
	infile.close();
	outfile.close();
}


void paste_loadout(){ //Zet waarde in de value text file // Gemaakt door Alexander
	ifstream infile;
	ofstream outfile;
	string filename_in = "values begin.txt";
	string filename_out = "values.txt";
	string line;
    infile.open(filename_in.c_str());
	outfile.open(filename_out.c_str());
    
	while(getline(infile, line)){
		outfile << line << endl;
	}
	infile.close();
	outfile.close();
}


int main(){ // Gemaakt door Iedereen
	cout << endl;
	cout << "What mode do you want to play?" << endl;
	cout << "(Play = P, Custom = C, AI = A): ";
    string SorP;
	getline(cin, SorP);
    while(true){
        if((SorP[0] == 'p' || SorP[0] == 'P') && SorP.size() < 2){
            break;
        }
        else if((SorP[0] == 'c' || SorP[0] == 'C') && SorP.size() < 2){
			bool reset_values = true;
            while(reset_values){
				setup();
                clear_tmp_file();
                srand((unsigned)time(0));
                vector<int> list_int_objects;
                vector<string> objects_chars = {"Hole", "Wumpus", "Bat", "Player"};
                for(int i=0; i<4; i++){
                    ask_for_custom_number(objects_chars[i], list_int_objects);
                }
                reset_values = reset_values_ask(reset_values);
            }
        }
		if((SorP[0] == 'A' || SorP[0] == 'a') && SorP.size() < 2){
            start();
        }
		cout << "(Play = P, Custom = C, AI = A): ";
		getline(cin, SorP);
    }
    bool restart_game = true;
	save_loadout();
	while(restart_game){ //Als de speler kiest voor herstarten (of standaard bij eerste ronde)
		paste_loadout();
		leaderboard();
		ready_go();  
		read_instructions(); 
		const vector<vector<int>> way_to_go = directions();

		srand((unsigned)time(0));
		string username;
		while(true){ //Vraag om de naam van de speler totdat de speler een naam van 3 karakters geeft
			cout << "Give a username: ";
			getline(cin, username);
			if(username.length()!=3){
				cout << "Your username should be 3 characters, try again." << endl;
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
		vector<int> shoot_info;
		int score = 0;
		time_t start_time = time(0);
		
		while(true){ // Loop: doorheen gaan van het spel.
			score+=1;
			outcome_SPAO = show_position_and_options(cords);
			if(outcome_SPAO[0] == 'M' || outcome_SPAO[0] == 'm'){
				side = move(cords);
				final_dest = checkside(side, cords);
				cords = way_to_go[final_dest];
				if (collision_bats(cords)){
					cout << "You've been carried away by bats!" << endl;
					cords = way_to_go[(rand()%20)+0];
				}
				if(collision_death(cords)==1){
					ascii_art("death cliff.txt");
					cout << "You have fallen down a botemless pit!" << endl;
					break;
				}
				if(collision_death(cords)==2){
					ascii_art("death wump.txt");
					cout << "You have been killed by the wumpus!" << endl;
					break;
				}

			}
			else{
				shoot_info = shoot(arrows_amount, cords, way_to_go);
				arrows_amount = shoot_info[0];
				if(shoot_info[1]==1){
					register_score(username, start_time, score);
					break;
				}
				if(shoot_info[1]==2){
					break;
				}
			}
		}
		restart_game = restart_game_question();
	}
}
