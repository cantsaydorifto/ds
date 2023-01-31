#include <iostream>
using namespace std;
void inputArray(int arr[], int n) {
    cout << "Enter data:";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}
int linearSearch(int array[], int n, int key, int pos) {
    // Base Case
    if (n == 0) {
        return -1;
    }
    if (array[0] == key) {
        return pos;
    } else {
        return linearSearch(array + 1, n - 1, key, pos + 1);
    }
}
int binarySearch(int arr[], int n, int key) {
    int s = 0, e = n;
    while (s <= e) {
        int mid = (s + e) / 2;

        if (arr[mid] == key) {
            return mid + 1;
        }
        if (arr[mid] < key) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return -1;
}
void printResult(int pos) {
    if (pos == -1) {
        cout << "ELEMENT NOT FOUND" << endl;
    } else {
        cout << "ELEMENT FOUND" << endl;
        cout << "Position:" << pos << endl;
    }
}
int main() {
    int n;
    cout << "Enter size of array:";
    cin >> n;
    int arr[n];
    inputArray(arr, n);

    // LINEAR SEARCH
    int key;
    cout << "LINEAR SEARCH" << endl;
    cout << "Enter key to find:";
    cin >> key;
    int pos = linearSearch(arr, n, key, 1);
    printResult(pos);

    // BINARY SEARCH
    cout << "BINARY SEARCH" << endl;
    cout << "Enter key to find:";
    cin >> key;
    pos = binarySearch(arr, n, key);
    printResult(pos);
    return 0;
}
