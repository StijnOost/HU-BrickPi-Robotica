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
    tempfile.close();
}

bool check_numbers(int number, vector<int> & list_int_objects)
{
    for(int i=0; i<list_int_objects.size(); i++){
        if(number == list_int_objects[i]){
            return true;
        }
    }
    return false;
    
}

void New_value_in_tmp(int int_objects, string objects_chars, vector<string> tmp_values)
{
    ofstream outfile;
    string filename_out = "tmp.txt";
    outfile.open(filename_out.c_str(), ios_base::app);
    
    if(int_objects >= 0){
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
                    outfile << objects_chars[0] << " " << int_objects << endl;
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


void ask_for_custom_number(string objects_chars, vector<int> & list_int_objects)
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
            while(!cin>>int_objects || int_objects > 19 || int_objects < 0 || check_numbers(int_objects, list_int_objects)){
                cout << "This is not a valid room, try again: ";
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
    }
    cout << endl;
    infile.close();
}

bool reset_values_ask(bool reset_values){
    string Restart_Char;
    cout << "Do you want to keep these values? (Y/N) ";
    while(true){
        getline(cin, Restart_Char);
        if (Restart_Char.size() < 2){
            if(Restart_Char[0] == 'Y' || Restart_Char[0] == 'y'){
                return false;
            }
            else if(Restart_Char[0] == 'N' || Restart_Char[0] == 'n'){
                return true;
            }
        }
        else{
            cout << "Do you want to keep these values? (Y/N) ";
        }
    }
}

int main()
{
    bool reset_values = true;
    while(reset_values){
        cout << "Standard values of the objects are: " << endl;
        cout << "Hole is: \t16 " << endl;
        cout << "Wombat is: \t9 " << endl;
        cout << "Bat is: \t14 " << endl;
        cout << "Player is: \t6 " << endl;
        clear_tmp_file();
        srand((unsigned)time(0));
        vector<int> list_int_objects;
        vector<string> objects_chars = {"Hole", "Wombat", "Bat", "Player"};
        for(int i=0; i<4; i++){
            ask_for_custom_number(objects_chars[i], list_int_objects);
        }
        reset_values = reset_values_ask(reset_values);
    }
}