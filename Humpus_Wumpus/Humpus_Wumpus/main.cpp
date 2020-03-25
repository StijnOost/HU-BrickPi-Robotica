#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{   
    char YorN;
    while(YorN != 'Y' || YorN != 'y'){
        cout << "Hunt the Wumpus" << endl;
        cout << "Do you wanne play (Y/N)? ";
        cin >> YorN;
        
        if(YorN == 'N' || YorN == 'n'){
            cout << "Doei" << endl;
            return 0;
        }
        else if(YorN == 'Y' || YorN == 'y'){
            cout << "1. There are 3 hazards: \n"; 
                cout << "\t1.1 A bottomless pit (you will feel a breeze nearby).\n";
                cout << "\t1.2 A colony of bats that will pick you up and drop you in a random space (you will hear flapping nearby).\n";
                cout << "\t1.3 A fearsome, hungry, and unbathed wumpus (you will smell it nearby).\n";
            cout << "2. The wumpus is heavy; bats cannot lift him.\n";
            cout << "3. The wumpus is covered in suckers; he won't fall down the bottomless pit.\n";
            cout << "4. Firing an arrow that misses the wumpus may cause it to move.\n";
            cout << "5. You have 5 wumpus-piercing arrows.\n";
            cout << "6. You may find an arrow dropped by a previous hunter.\n";
        }
    }
}
