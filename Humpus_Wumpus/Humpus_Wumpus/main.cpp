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
	ifstream infile;
	string filename_in = "score.txt";
	string line;
	infile.open(filename_in.c_str());
	int place = 0;
	
	cout << "Place | Name | Score | Time" << endl;
	cout << "---------------------------" << endl;
	while(getline(infile, line)){
		place+=1;
		if(place==1){
			cout << "1st: " << line << endl;
		}
		else if(place==2){
			cout << "2nd: " << line << endl;
		}
		else if(place==3){
			cout << "3rd: " << line << endl;
		}
		else{
			cout << place <<"th: " << line << endl;
		}
		
	}
	cout << "---------------------------" << endl;
}


void register_score(string username, time_t start_time, int score){
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
					outfile << username << " " << score << " " << diffrence << endl;
					amount_lines+=1;
					wrote=true;
				}
				else if(wrote==false && score == found){
					while(!find.eof()) {
						string temp;
						find >> temp;
						if(stringstream(temp) >> found){
							if(diffrence < found){
								outfile << username << " " << score << " " << diffrence << endl;
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
		outfile << username << " " << score << " " << diffrence << endl;
	}
	infile.close();
	outfile.close();
}

void read_instructions(){
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


int collision_death(vector<int> room){
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
					else if (line[0] == 'G'){
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


vector<vector<int>> directions(){
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


int wumpus_walky(int cords_wumpus, vector<vector<int>> way_to_go){
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


int aim(vector<int>cords){
    int shoot;
    cout << "To which room do you want to shoot?: ";
    cin >> shoot;
    int final_dest = checkside(shoot, cords);
    return final_dest;
}

vector<int> shoot(int arrows_amount, vector<int> cords, vector<vector<int>> way_to_go){
	vector<int> shoot_info;
	if(arrows_amount>0){
		shoot_info.push_back(arrows_amount-1);
		int wumpus_cords = location_wumpus();
		int shot_room = aim(cords);
		if(shot_room != -1){
			bool hit = wump_walk_shot(wumpus_cords, shot_room);
			if(hit){
				ascii_art("winner.txt");
				cout << "You win! You have slain the wumpus. You are a MLG gamer!" << endl;
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


int main(){
	leaderboard();
	ready_go();  // Begint funcite om te vragen om mensen klaar zijn om te spelen.
	read_instructions(); // Start functie die vraagt of mensen instructies wilt hebben.
	vector<vector<int>> way_to_go = directions();

	srand((unsigned)time(0));
	string username;
	while(true){
		cout << "Give a username: ";
		cin >> username;
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
}
