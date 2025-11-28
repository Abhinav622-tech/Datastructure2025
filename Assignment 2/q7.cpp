#include<iostream>
using namespace std;
int inversion(int A[],int n){
	int i;
	int j;
	int count=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(A[i]>A[j]){
				count ++;
				cout << "Inversion pair: (" << A[i] << ", " << A[j] << ")"<<endl;
			}
		}
	}
	return count;
}
int main(){
	int A[]={1,2,3,5,4};
	int n =sizeof(A)/sizeof(int);
	int count = inversion(A,n);
	cout<<"the number of unorderd pair are "<<count;
}
