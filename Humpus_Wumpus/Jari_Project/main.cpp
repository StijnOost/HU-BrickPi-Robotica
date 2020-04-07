#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int count = 0;
    string SorM_Instr;
    while(true){
        cout << "Do you wanne shoot or move (S/M)? ";
        getline(cin,SorM_Instr);
        if(SorM_Instr.size() < 2){
            if(SorM_Instr == "S" || SorM_Instr == "s" || SorM_Instr == "M" || SorM_Instr == "m"){
                cout << SorM_Instr << endl;
                break;
            }

        }
        count++;
        if(count == 10){
            break;
        }
    }
}
