//Implement the Binary search algorithm regarded as a fast search algorithm with 
//run-time complexity of ?(log n) in comparison to the Linear Search. 
#include<iostream>
using namespace std;
int binarySearch(int a[], int l, int h, int key) {
    while (l <= h) {
        int mid = (l + h) / 2;

        if (a[mid] == key) {
            return mid;  // found 
        } 
        else if (a[mid] > key) {
            l = mid + 1;  
        } 
        else {
           h = mid - 1;  
        }
    }
    return -1; // not found
}
void input(int A[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<"enter the number";
		cin>>A[i];
	}
}
int main(){
	int i;
	int A[6];
	input(A,6);
	cout << "Array elements: ";
    for (int i = 0; i < 6; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    int key = 7 ;
  int result = binarySearch(A,0,5,key);
if(result!=-1){
	cout << "Target " << key << " found at index " << result << endl;
}
else{
	cout << "Target " << key << " not found" << endl;
}
return 0;	
}
