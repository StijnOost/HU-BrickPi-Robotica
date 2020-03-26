#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int Instructies_uitlezen(){
    cout << "1. There are 3 hazards: \n";
        cout << "\t1.1 A bottomless pit (you will feel a breeze nearby).\n";
        cout << "\t1.2 A colony of bats that will pick you up and drop you in a random space (you will hear flapping nearby).\n";
        cout << "\t1.3 A fearsome, hungry, and unbathed wumpus (you will smell it nearby).\n";
    cout << "2. The wumpus is heavy; bats cannot lift him.\n";
    cout << "3. The wumpus is covered in suckers; he won't fall down the bottomless pit.\n";
    cout << "4. Firing an arrow that misses the wumpus may cause it to move.\n";
    cout << "5. You have 5 wumpus-piercing arrows.\n";
    cout << "6. You may find an arrow dropped by a previous hunter.\n";

    return 0;
}

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
		return(cords);
	}
	else{
		cout << "ERROR: File unreachable \n";
	}
}

int random_rand_waarde_player()
{
	int xyplayer = (rand()%19)+0;
	cout << xyplayer;
}

int random_rand_waarde_wump()
{
	int xywump = (rand()%19)+0;
	cout << xywump;
}

char Begin_Met_Spelen(){
    char Y_tostart;
    while(Y_tostart != 'Y' || Y_tostart != 'y'){
        cout << "\nDo you wanne start (Y)? ";
        cin >> Y_tostart;

        if(Y_tostart == 'Y' || Y_tostart == 'y'){
            return 'Y';
        }
    }
}

int move(){
	vector<int> a = {1,5,6,8};
    int side;
    cout << "---------------------------------------\n";
    cout << "You are in room: " << a[0] << endl;
	cout << "Tunnels lead to room: " << a[1] << ", " << a[2] << " and " << a[3] <<endl ;
    cout << "---------------------------------------\n";
    cout << "To which room do you want to go?" << endl;
    cin >> side;
    return side;
}

int checkside(int side){
    if (side == a[1] || side == a[2] || side == a[3]){
        //fucntie
        return 0;
    }
    else{
        cout << "No such room nearby, try again:" << endl;
        cin >> side;
        checkside(side);
    }

}

int main()
{
	srand((unsigned)time(0));
	int positie_speler = random_rand_waarde_player();
	int positie_wump = random_rand_waarde_wump();
	directions(location);
	char YorN_Instr;
    cout << "Hunt the Wumpus" << endl;
    cout << "Do you need instructions: (Y/N)? ";
    cin >> YorN_Instr;

    if(YorN_Instr == 'Y' || YorN_Instr == 'y'){
        int Instructies = Instructies_uitlezen();
    }
    char Begin_met_Spelen_Uitkomst = Begin_Met_Spelen();
	int side = move();
    checkside(side);
    // Return Y om volgende functie te starten die het spel laat starten:


}
