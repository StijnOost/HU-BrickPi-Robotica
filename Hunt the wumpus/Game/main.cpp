#include <iostream>
#include <string>
using namespace std;

string reverse(string&orginalword){
	char temp;
	for(unsigned int i=0; i<orginalword.size()/2; i++){
		temp = orginalword[i];
		int last_num = orginalword.size()-i;
		orginalword.substr(i,1);
		orginalword.append(i,orginalword[last_num]);
		cout << orginalword << "\n";
		orginalword.substr(last_num,1);
		orginalword.append(last_num,temp);
		cout << orginalword << "\n";
		cout <<" "<<temp << "\n";
	}
	
	return orginalword;
}
bool isPalindroom(const string& word){
	string orginalWord = word;
	reverse(orginalWordsiacidc
	]['disxjdodc
	'p;.
	for(unsigned int i=0; i<word.size(); i++){ 
		if(word[i] != orginalWord[i]){
			return false;
		}
	}
	return true;
}

int main()
{
	string woord = "stekkerdoos";
	bool result = isPalindroom(woord);
	cout<< result;
}