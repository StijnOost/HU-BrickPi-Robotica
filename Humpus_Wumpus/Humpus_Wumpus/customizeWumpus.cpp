#include "wumpHead.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


void clear_tmp_file(){ // Maak tmp file leeg  // Gemaakt door Jari
    ofstream tempfile;
    tempfile.open("tmp.txt");
    tempfile.close();
}


void setup(){ // Print de huidige waardes van het spel  // Gemaakt door Alexander
	cout << "---------------------------------" << endl;
	ifstream start_value;
    string line;
    string filename = "values.txt";
    start_value.open(filename.c_str());
    if(start_value.is_open()){
        while(getline(start_value, line)){
			stringstream find;
			find << line;
			string temp;
			int found;
			while(!find.eof()) {
				find >> temp;
				if(stringstream(temp) >> found){
					if(line[0]=='P'){
						cout << "Player starts at \t" << found << endl;
					}
					if(line[0]=='B'){
						cout << "There are bats at \t" << found << endl;
					}
					if(line[0]=='H'){
						cout << "There is a hole at \t" << found << endl;
					}
					if(line[0]=='W'){
						cout << "The Wumpus is at \t" << found << endl;
					}
				}
				temp = "";
			}
        }
    }
}


bool check_numbers(int number, vector<int> & list_int_objects){ // Controleert of een getal al gekozen is // Gemaakt door Jari
    for(unsigned int i=0; i<list_int_objects.size(); i++){
        if(number == list_int_objects[i]){
            return true;
        }
    }
    return false;
    
}


void New_value_in_tmp(int int_objects, string objects_chars, vector<string> tmp_values){ // Schrijft nieuwe waardes in de tmp  // Gemaakt door Jari
    ofstream outfile;
    string filename_out = "tmp.txt";
    outfile.open(filename_out.c_str(), ios_base::app);
    
    if(int_objects >= 0){
        for(unsigned int i=0; i<tmp_values.size(); i++){
            for(unsigned int j=0; j<tmp_values.size(); j++){
                if(tmp_values[i][j]==objects_chars[0]){
                    outfile << objects_chars[0] << " " << int_objects << endl;
                    break;
                }
            }
        }
    }
    else if(int_objects == -1){
        for(unsigned int i=0; i<tmp_values.size(); i++){
            for(unsigned int j=0; j<tmp_values.size(); j++){
                if(tmp_values[i][j]==objects_chars[0]){
                    outfile << objects_chars[0] << " " << int_objects << endl;
                    break;
                }
            }
        }
    }
    else{
        for(unsigned int i=0; i<tmp_values.size(); i++){
            for(unsigned int j=0; j<tmp_values.size(); j++){
                if(tmp_values[i][j]==objects_chars[0]){
                    outfile << tmp_values[i] << endl;
                    break;
                }
            }
        }
    }
    outfile.close();
}


void ask_for_custom_number(string objects_chars, vector<int> & list_int_objects){ // Vraag om random veranderen/ niet veranderen // Gemaakt door Tim/Jari
    ifstream infile;
    string filename_in = "values.txt";
    string line;
    infile.open(filename_in.c_str());
    int int_objects = -2;
    char YorN_change[2];
    vector<string> tmp_values;
 
    while(getline(infile, line)){
        tmp_values.push_back(line);
    }
	cout << "---------------------------------" << endl;
    cout << "Do you want to change the " << objects_chars << " start location? (y = Yes, n = No, r = Random value) ";
    cin>>YorN_change;
    if(YorN_change[0] == 'Y' || YorN_change[0] == 'y'){
        while(true){
            cout << "In which room should the " << objects_chars << " start? ";
            cin.clear();
            cin>>int_objects;
            while(!cin>>int_objects || int_objects > 19 || int_objects < 0 || check_numbers(int_objects, list_int_objects)){
                cout << "That room is already taken or invalid, try again: ";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cin>>int_objects;

            }
            list_int_objects.push_back(int_objects);
            cout << "Your chosen value is now: " << int_objects << endl;
            New_value_in_tmp(int_objects, objects_chars, tmp_values);
            break;
        }
    }
    else if(YorN_change[0] == 'R' || YorN_change[0] == 'r'){
		cout << objects_chars << " was randomized." << endl;
        while(true){
            int_objects = (rand()%20)+0;
            if(check_numbers(int_objects, list_int_objects) == false){
                list_int_objects.push_back(int_objects);
                New_value_in_tmp(int_objects, objects_chars, tmp_values);
                break;
            }
        }
    }
    else{
        New_value_in_tmp(int_objects, objects_chars, tmp_values);
		cout << objects_chars << " was not changed." << endl;
    }
    cout << endl;
    infile.close();
}


void save_data(){ // Zet alle waardes in tmp naar values // Gemaakt door Alexander
	ifstream infile;
    ofstream outfile;
    string filename_in = "tmp.txt";
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


bool reset_values_ask(bool reset_values){ // Vraag om waardes op te stlaan // Gemaakt door Jari
	cout << "---------------------------------" << endl;
    string Restart_Char;
	getline(cin, Restart_Char);
    while(true){
		if((Restart_Char[0] == 'Y' || Restart_Char[0] == 'y') && Restart_Char.size() < 2){
			save_data();
			break;
		}
		else if((Restart_Char[0] == 'N' || Restart_Char[0] == 'n') && Restart_Char.size() < 2){
			return true;
		}
        else{
            cout << "Do you want to keep these values? (Y/N) ";
			getline(cin, Restart_Char);
        }
	}
	return false;
}