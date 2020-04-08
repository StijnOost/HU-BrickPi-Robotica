#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    int getal;
    vector<int> getallen;
    int count = 0;
    while(count <= 5){
        cout << "geef getal: ";
        cin >> getal;
        getallen.push_back(getal);
        count++;
    }
    for(int i=0; i<getallen.size(); i++){
        cout << "HANS: " << getallen[i] << endl;
    }
}