#include <iostream>
using namespace std;
#define LEN 8

int arr[] = {4, 3, 2, 10, 12, 1, 5, 6};

// Insertion Sort

void insertionSort() {
    int tmp;
    for (int i = 1; i < LEN; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (arr[j+1] < arr[j]) {
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

// Bubble Sort

void bubbleSort() {
    int tmp;
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN-1; j++) {
            if (arr[i] > arr[j+1]) {
                tmp = arr[i];
                arr[i] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

// Selection Sort

void selectionSort() {
    int tmp, min_idx;
    for (int i = 0; i < LEN-1; i++) {
        min_idx = i;
        for (int j = i; j < LEN; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}

// Merge Sort

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int k, i, j;

    i = j = 0;
    k = low;
    
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[low + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
    
        merge(arr, low, mid, high);
    }
}

// Quick Sort

int partition(int arr[], int low, int high) {
    int ind = low-1, tmp;
    int pivot = arr[high];
    for (int i = low; i < high; i++) {
        if (arr[i] < pivot) {
            ind++;
            tmp = arr[i];
            arr[i] = arr[ind];
            arr[ind] = tmp;
        }
    }

    tmp = arr[ind + 1];
    arr[ind + 1] = arr[high];
    arr[high] = tmp;

    return (ind + 1);  

}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



int main() {
    insertionSort();

    return 0;
}
