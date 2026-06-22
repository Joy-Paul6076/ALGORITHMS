#include <iostream>
using namespace std;

void Merge_Sort(int arr[], int n) {
    if (n <= 1) return;

    int mid = n / 2;
    int *left = new int[mid];
    int *right = new int[n - mid];

    for (int i = 0; i < mid; ++i) left[i] = arr[i];
    for (int i = mid; i < n; ++i) right[i - mid] = arr[i];

    Merge_Sort(left, mid);
    Merge_Sort(right, n - mid);

    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid) {
        if (left[i] < right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < mid) arr[k++] = left[i++];
    while (j < n - mid) arr[k++] = right[j++];

    delete[] left;
    delete[] right;
}

int main() {
    int n;
    cout << "Enter no of elements of the array: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid number of elements.\n";
        return 1;
    }

    int *arr = new int[n];
    cout << "Enter the Elements of the array:";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Merge_Sort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << '\n';

    delete[] arr;
    return 0;
}