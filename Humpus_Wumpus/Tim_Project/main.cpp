#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> a = {1,5,6,8};

int move(){
    int side;
    cout << "---------------------------------------\n";
    cout << "You are in room: " << a[0] << endl;
	cout << "Tunnels lead to room: " << a[1] << ", " << a[2] << " and " << a[3] <<endl ;
    cout << "---------------------------------------\n";
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

int main(){
    int side = move();
    checkside(side);
}

