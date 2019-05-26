#include <iostream>
using namespace std;
#define LEN 8

int arr[] = {4, 3, 2, 10, 12, 1, 5, 6};

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

void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[low + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    i = j = 0;
    k = low;

    while(i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(i < n2) {
        arr[k] = R[j];
        j++;
        k++;
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


int main() {
    insertionSort();

    return 0;
}
