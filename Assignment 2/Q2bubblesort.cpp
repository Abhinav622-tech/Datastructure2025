#include<iostream>
using namespace std;
void swap(int * X , int * Y ){
	int temp = *X;
	*X = *Y;
	*Y= temp;
	
}
void bubbleSort(int A[], int n){
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
	int A []={64,34,25,12,22,11,90};
	int i;
	bubbleSort(A,7);
	for(i=0;i<7;i++){
		cout<<A[i]<<endl;
	}
	
}

