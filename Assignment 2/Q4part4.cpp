#include<iostream>
using namespace std;
#include<string>
void swap(char * X , char * Y ){
	char temp = *X;
	*X = *Y;
	*Y= temp;
	
}
void AlphabeticalSort(string &A){
	int i , j;
	int n = A.length();
	for(i=0;i<n-1;i++){ //for no of passes 
		for(j=0;j<n-i-1;j++){
			if(A[j]>A[j+1]){ // no of comparison
			swap(A[j],A[j+1]);
			}
		}
	}
	}

int main(){
string str;
string 	result;
	cout<<"enter the name of string";
	getline(cin,str);
AlphabeticalSort(str);
	
	cout<<"the string without vowel"<<str;
}

