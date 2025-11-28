#include<iostream>
#include<string>
using namespace std;
string display(string*A , string*B){
string 	result = *A + *B ;
return result;
}
int main(){
	string A ;
cout<<"enter the first string ";
getline(cin,A);
string B ;
cout<<"enter the second string ";
getline(cin,B);
// STRING CONCATINATION

cout<<"the concatinated strings are "<<display(&A,&B);
return 0; 
}

