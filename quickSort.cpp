#include "helpers.h"

using namespace std;

// we use referencing throughout because we sort the vector in place

void swap (vector<int>& A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int partition (vector<int>& A, int startIndex, int pivotIndex) {
    /*
    Given a vector A, performs partition. 
    Going from startIndex to pivotIndex-1, keeps track of 2 indices i,j. 
    A[i] and A[j] are switched at each iteration.
    If A[j] <= A[pivotIndex], i and j are both incremented.
    Otherwise, j increments but i remains in place.
    At the end, swap A[i+1] and A[pivotIndex]
    This partitions the subarray of A from startIndex to pivotIndex,
    such that anything smaller than the pivot is to its left, and anything bigger is to its right
    */

    int pivot = A[pivotIndex];
    int i = startIndex - 1;

    for (int j = startIndex; j < pivotIndex; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A, i, j);
        }
    }

    i++;

    swap(A, i, pivotIndex);

   return i;
};

void quickSortIdx(vector<int> &A, int startIndex, int endIndex) {
    /*
    Sorts all elements of A between startIndex and endIndex, 
    by recursively applying itself, and using partition to find the pivot
    */

    if (startIndex < endIndex) {
        int splitIndex = partition(A, startIndex, endIndex);
        quickSortIdx(A, startIndex, splitIndex - 1);
        quickSortIdx(A, splitIndex, endIndex);
    }
}

void quickSort(vector<int> A) {
    quickSortIdx(A, 0, A.size()-1);
}

int main() {
    vector<int> testArray = {5,8,9,-1,2,4,64,2,7};
    cout << "Vector given: "<< vectorToString(testArray) << "\n";
    quickSortIdx(testArray,0,8);
    cout << "Vector sorted: "<< vectorToString(testArray) << "\n";
};