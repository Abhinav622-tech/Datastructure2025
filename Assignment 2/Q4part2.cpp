#include<iostream>
#include<string>
using namespace std;
void swap(string * X , string * Y ){
	 string temp = *X;
	*X = *Y;
	*Y= temp;
}
string reverse(string A){
	int n = A.length();
int i = 0 ; int j = n-1;;
while(i<j){
	swap(A[i],A[j]);
	i ++;
	j--;
}
return A;

}
int main(){
	string A ;
cout<<"enter the first string ";
getline(cin,A);
string B = reverse(A);


cout<<"the reverse strings are "<<B;
return 0; 
}

