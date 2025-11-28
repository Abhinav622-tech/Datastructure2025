#include <iostream>
using namespace std;

// Function to create array
void createArray(int arr[], int &n) {
    cout << "How many elements do you want to create? ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// Function to display array
void displayArray(int arr[], int n) {
    if(n == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    cout << "Array elements: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to insert element
void insertElement(int arr[], int &n, int pos, int value) {
    if(n == 100) {
        cout << "Array is full! Cannot insert." << endl;
        return;
    }
    if(pos < 1 || pos > n+1) {
        cout << "Invalid position!" << endl;
        return;
    }
    for(int i = n; i >= pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos-1] = value;
    n++;
    cout << "Element inserted successfully." << endl;
}

// Function to delete element
void deleteElement(int arr[], int &n, int pos) {
    if(n == 0) {
        cout << "Array is empty! Cannot delete." << endl;
        return;
    }
    if(pos < 1 || pos > n) {
        cout << "Invalid position!" << endl;
        return;
    }
    for(int i = pos-1; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
    cout << "Element deleted successfully." << endl;
}

// Function to perform linear search
void linearSearch(int arr[], int n, int key) {
    if(n == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    int found = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = i;
            break;
        }
    }
    if(found != -1) {
        cout << "Element found at position " << found+1 << endl;
    } else {
        cout << "Element not found!" << endl;
    }
}

int main() {
    int arr[100]; // maximum array size
    int n = 0;    // current size of array
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                createArray(arr, n);
                break;
            case 2:
                displayArray(arr, n);
                break;
            case 3: {
                int pos, value;
                cout << "Enter position to insert: ";
                cin >> pos;
                cout << "Enter value to insert: ";
                cin >> value;
                insertElement(arr, n, pos, value);
                break;
            }
            case 4: {
                int pos;
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteElement(arr, n, pos);
                break;
            }
            case 5: {
                int key;
                cout << "Enter element to search: ";
                cin >> key;
                linearSearch(arr, n, key);
                break;
            }
            case 6:
                cout << "Exiting program. Bye!" << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while(choice != 6);

    return 0;
}
