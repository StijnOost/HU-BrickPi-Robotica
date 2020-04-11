#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

vector<int> directions(int local){
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
	}
	else{
		cout << "ERROR: File unreachable \n";
	}
	cout << cords[0] << endl;
	cout << cords[1] << endl;
	cout << cords[2] << endl;
	cout << cords[3] << endl;
	return(cords);
}
int main(){
	int location = 9;
	directions(location);
}