#include<iostream>

using namespace std;

void duplicateTwos(int arr[], int n) {
    int count = 0;
int i;
    // Step 1: Count number of 2s to duplicate (may exceed array length)
    for ( i = 0; i < n; i++) {
        if (arr[i] == 2)
            count++;
    }

    // Step 2: Work backwards from end
    for ( i = n - 1; i >= 0; i--) {
        int pos = i + count; // new position after duplication
        if (pos < n)
            arr[pos] = arr[i]; // copy element

        if (arr[i] == 2) {
            count--;           // one duplication accounted
            pos = i + count;
            if (pos < n)
                arr[pos] = 2; // duplicate 2
        }
    }
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
int i;
    int arr[n];
    cout << "Enter array elements: ";
    for ( i = 0; i < n; i++)
        cin >> arr[i];

    duplicateTwos(arr, n);

    cout << "Modified array: ";
    for ( i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
