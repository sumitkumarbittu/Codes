#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int& comparisons, int& shifts) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            comparisons++; 
            arr[j + 1] = arr[j];
            shifts++; 
            j--;
        }
        if (j >= 0) {
            comparisons++; 
        }

        arr[j + 1] = key;
    }
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter the array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int comparisons = 0, shifts = 0;
        insertionSort(arr, comparisons, shifts);

        cout << "Sorted Array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Number of Comparisons: " << comparisons << endl;
        cout << "Number of Shifts: " << shifts << endl;
    }

    return 0;
}