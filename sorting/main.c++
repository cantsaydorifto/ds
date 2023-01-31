#include <iostream>
using namespace std;
void inputArray(int arr[], int n) {
    cout << "Enter data:";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void printArray(int arr[], int n) {
    cout << "Sorted array:";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void selectionSort() {
    cout << "SELECTION SORT" << endl;
    int n;
    cout << "Enter array size:";
    cin >> n;
    int arr[n];
    inputArray(arr, n);
    int counter = 1;
    while (counter < n) {
        for (int i = 0; i < n - counter; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
        counter++;
    }
    printArray(arr, n);
}
void bubbleSort() {
    cout << "BUBBLE SORT" << endl;
    int n;
    cout << "Enter array size:";
    cin >> n;
    int arr[n];
    inputArray(arr, n);
    for (int j = 0; j < n - 1; j++) {
        for (int k = j; k < n; k++) {
            if (arr[k] < arr[j]) {
                int temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
            }
        }
    }
    printArray(arr, n);
}

void insertionSort() {
    cout << "INSERTION SORT" << endl;
    int n;
    cout << "Enter array size:";
    cin >> n;
    int arr[n];

    inputArray(arr, n);
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            if (arr[j] > temp) {
                arr[j + 1] = arr[j];
            } else {
                break;
            }
        }
        arr[j + 1] = temp;
    }

    printArray(arr, n);
}
void Merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;  // Length of array 1
    int n2 = r - mid;
    int a[n1];
    int b[n2];
    // Copying elements
    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + i + 1];
    }
    // Sorting array by making pointers to each array
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            k++;
            i++;
        } else {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    // Copying leftover elements
    while (i < n1) {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2) {
        arr[k] = b[j];
        k++;
        j++;
    }
}
void callMergeSort(int* arr, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        callMergeSort(arr, l, mid);
        callMergeSort(arr, mid + 1, r);
        Merge(arr, l, mid, r);
    }
}

void mergeSort() {
    cout << "MERGE SORT" << endl;
    int n;
    cout << "Enter array size:";
    cin >> n;
    int arr[n];
    inputArray(arr, n);
    callMergeSort(arr, 0, n - 1);
    printArray(arr, n);
}

int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            cnt++;
        }
    }
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void callQuickSort(int arr[], int s, int e) {
    // base case
    if (s >= e)
        return;
    int p = partition(arr, s, e);
    callQuickSort(arr, s, p - 1);
    callQuickSort(arr, p + 1, e);
}
void quickSort() {
    cout << "QUICK SORT" << endl;
    int n;
    cout << "Enter array size:";
    cin >> n;
    int arr[n];
    inputArray(arr, n);
    callQuickSort(arr, 0, n - 1);
    printArray(arr, n);
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void callHeapSort(int* arr, int n) {
    int size = n;
    while (size > 1) {
        // Step 1 : Swap last element
        swap(arr[1], arr[size]);
        // Step 2 : remove last element
        size--;
        // Step 3 : Move to its correct position
        heapify(arr, size, 1);
    }
}
void heapSort() {
    cout << "HEAP SORT" << endl;
    int n;
    cout << "Enter array size:";
    cin >> n;
    int arr[n + 1];
    arr[0] = -1;
    cout << "Enter data:";
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    // Creating heap
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }
    // Calling heap sort
    callHeapSort(arr, n);
    cout << "Sorted array:";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    bubbleSort();
    cout << endl;
    insertionSort();
    cout << endl;
    mergeSort();
    cout << endl;
    selectionSort();
    cout << endl;
    heapSort();
    cout << endl;
    quickSort();
    cout << endl;
    return 0;
}
