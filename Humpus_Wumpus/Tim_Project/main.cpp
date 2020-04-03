#include <iostream>
#include <fstream>
using namespace std;

#include <string>

           //Gets file contents

int death()
{
    string getFileContents (ifstream&); 
    ifstream Reader ("death.txt");             //Open file

    string Art = getFileContents (Reader);       //Get file
    
    cout << Art << endl;               //Print it to the screen

    Reader.close ();                           //Close file

    return 0;
}

string getFileContents (ifstream& File)
{
    string Lines = "";        //All lines
    
    if (File)                      //Check if everything is good
    {
	while (File.good ())
	{
	    string TempLine;                  //Temp line
	    getline (File , TempLine);        //Get temp line
	    TempLine += "\n";                      //Add newline character
	    
	    Lines += TempLine;                     //Add newline
	}
	return Lines;
    }
    else                           //Return error
    {
	return "ERROR File does not exist.";
    }
}

int text2()
{
    string getFileContents (ifstream&); 
    ifstream Reader ("winner.txt");             //Open file

    string Art = getFileContents (Reader);       //Get file
    
    cout << Art << endl;               //Print it to the screen

    Reader.close ();                           //Close file

    return 0;
}

int main(){
    text();
    text2();
}