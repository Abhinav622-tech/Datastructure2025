#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int A[]={1,2,3,5,6,7,8,9,10};
	int n= sizeof(A)/sizeof(int);
	int k;
	cout<<"enter the value of the k ";
	cin>>k;
	int count =0;
	int i ;
	int j;
for(i=0;i<n;i++){
	for(j=i+1;j<n;j++){
		if((abs(A[i] - A[j]) == k)){ 
		cout << "(" << A[i] << ", " << A[j] << ")" << endl;
			count ++;
		}
	}
}
cout<<"the number of such pair are "<<count;
}
