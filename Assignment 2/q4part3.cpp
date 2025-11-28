#include<iostream>
using namespace std;
#include<string>
bool vowel(char ch ){
	ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'); // checking each character of the string and return true or false 
}
int main(){
string str;
string 	result;
	cout<<"enter the name of string";
	getline(cin,str);
	int i;
	for(i=0;i<str.length();i++){
		if(!vowel(str[i])){
			result+=str[i];
		}
	}
	cout<<"the string without vowel"<<result;
}

