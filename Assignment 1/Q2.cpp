#include<iostream>
using namespace std;
int unique(int A[],int n){
int i;
	int count =0;
for(i = 0; i < n; i++) {
        
        if(i == n-1 || A[i] != A[i+1]) {
            A[count] = A[i];  // store unique element at front
            count++;
        }
    }
    return count ;	
}
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
	int A[]={1,1,2,3,4,5,6,6,6,6,7,2,2,2};
	int n = sizeof(A)/sizeof(int);
	Sort(A,n);
	int s = unique(A,n);
int i;
// printing unique
	for(i=0;i<s;i++){
		cout<<A[i]<<endl;
	}
}
