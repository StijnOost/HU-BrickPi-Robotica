#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

void clear_tmp_file()
{
    ofstream tempfile;
    tempfile.open("tmp.txt");
}

void New_value_in_tmp(int int_objects, string objects_chars, vector<string> tmp_values)
{
    ofstream outfile;
    string filename_out = "tmp.txt";
    outfile.open(filename_out.c_str(), ios_base::app);
    cout << objects_chars << endl;
    if(int_objects != -1 && int_objects != -2){
        for(int i=0; i<tmp_values.size(); i++){
            for(int j=0; j<tmp_values.size(); j++){
                if(tmp_values[i][j]==objects_chars[0]){
                    outfile << objects_chars[0] << " " << int_objects << endl;
                    break;
                }
            }
        }
    }
    else if(int_objects == -1){
        for(int i=0; i<tmp_values.size(); i++){
            for(int j=0; j<tmp_values.size(); j++){
                if(tmp_values[i][j]==objects_chars[0]){
                    outfile << objects_chars[0] << " " << (rand()%20)+0 << endl;
                    break;
                }
            }
        }
    }
    else{
        for(int i=0; i<tmp_values.size(); i++){
            for(int j=0; j<tmp_values.size(); j++){
                if(tmp_values[i][j]==objects_chars[0]){
                    outfile << tmp_values[i] << endl;
                    break;
                }
            }
        }
    }
    outfile.close();
}


void ask_for_custom_number(string objects_chars)
{
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
    cout << "Do you want to change the " << objects_chars << " start location? (y/n/r) ";
    cin>>YorN_change;
    if(YorN_change[0] == 'Y' || YorN_change[0] == 'y'){
        while(true){
            cout << "In which room should the " << objects_chars << " start? ";
            cin.clear();
            cin>>int_objects;
            while(!cin>>int_objects || int_objects > 19 || int_objects < 0){
                cout << "This is not a valid room, try again: ";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cin>>int_objects;
            }
            cout << "Your chosen value is now: " << int_objects << endl;
            New_value_in_tmp(int_objects, objects_chars, tmp_values);
            break;
        }
    }
    else if(YorN_change[0] == 'R' || YorN_change[0] == 'r'){
        int_objects = -1;
        New_value_in_tmp(int_objects, objects_chars, tmp_values);
    }
    else{
        New_value_in_tmp(int_objects, objects_chars, tmp_values);
    }
    cout << endl;
    infile.close();
}

int main()
{
    clear_tmp_file();
    srand((unsigned)time(0));
    vector<string> objects_chars = {"Hole", "Wombat", "Bat", "Player"};
    for(int i=0; i<4; i++){
        cout << objects_chars[i][0] << endl;
        ask_for_custom_number(objects_chars[i]);
    }    
}