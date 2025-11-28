#include<iostream>
using namespace std;
 void swap(int * X , int * Y ){
	int temp = *X;
	*X = *Y;
	*Y= temp;
	
}
void Sort(int A[], int n){
	int i , j;
	for(i=0;i<n-1;i++){ //for no of passes 
		for(j=0;j<n-i-1;j++){
			if(A[j]>A[j+1]){ // no of comparison
			swap(A[j],A[j+1]);
			}
		}
}
	}
int main(){
	int i;
	int A[] = {6,5,4,4,7,8,2,2};
	int n =sizeof(A)/sizeof(int);
	Sort(A,n);
	int count = 0;
	for(i=0;i<n;i++){
		if(A[i]!=A[i+1]){
			count ++;
		}
	}
	cout<<"the number of the unique element is "<<count;
}
