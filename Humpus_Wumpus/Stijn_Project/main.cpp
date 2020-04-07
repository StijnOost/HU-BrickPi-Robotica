#include <stdio.h>

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

void random_values_add(){
    ofstream waardes_infile;
	string filename = "Waardes.txt";
    waardes_infile.open(filename.c_str());
    if(waardes_infile.is_open()){
        int xyplayer = (rand()%19)+0;
        waardes_infile << "P " << xyplayer << endl;

        int xywump = (rand()%19)+0;
        while(xyplayer == xywump){
            xywump = (rand()%19)+0;
        }
        waardes_infile << "W " << xywump << endl;

        int xybats = (rand()%19)+0;
        while(xybats == xywump || xybats == xyplayer){
            xybats = (rand()%19)+0;
        }
        waardes_infile << "B " << xybats << endl;

        int xypit = (rand()%19)+0;
        while(xypit == xyplayer || xypit == xywump || xypit == xybats){
            xypit = (rand()%19)+0;
        }
        waardes_infile << "G " << xypit << endl;
    }
    else{
        cout << "ERROR: File unreachable \n";
    }
    waardes_infile.close();

}

int main(){
	srand((unsigned)time(0));
	random_values_add();
}
