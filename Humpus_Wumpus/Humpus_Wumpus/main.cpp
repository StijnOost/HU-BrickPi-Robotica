#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime> 
using namespace std;

int random_rand_waarde_player()
{	
	srand((unsigned)time(0));
	int xyplayer = (rand()%19)+0;
	cout << xyplayer;
}

int random_rand_waarde_wump()
{	
	srand((unsigned)time(0));
	int xywump = (rand()%19)+0;
	cout << xywump;
}

int main()
{
	int positie_speler = random_rand_waarde_player();
	int positie_wump =random_rand_waarde_wump()
}
