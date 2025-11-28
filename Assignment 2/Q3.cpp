#include<iostream>
using namespace std;
int linearSearch(int A[],int n){
	int i ;
	for(i=0;i<n-1;i++){
		if(A[i]!=i+1)
		return i+1;
	}
	return -1;
	
	}
int binarySearch(int a[], int n) {
    int l=0; int h =n-2; 
	while (l <= h) {
        int mid = (l + h) / 2;

        if (a[mid]==mid+1) {
            l = mid + 1;  
        } 
        
        else {
           h = mid - 1;  
        }
    }
    return l+1 ;
}	

int main(){
	int A[]={1,2,3,4,6};//range 1 to n-1 if n=6 5 element will be there in the array 
int result = linearSearch(A,6);
if(result!=-1){
	cout<<"the missing element is by using linear search"<<result<<endl;
}
else {
	cout<<"no element is missing ";
}
	cout << "Missing number (Binary Search): " << binarySearch(A, 6) << endl;
}
