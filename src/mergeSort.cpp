#include "include/mergeSort.h"

using namespace std;

vector<int> merge (vector<int> B, vector<int> C) {
    /*
    Given 2 vectors B and C, assumed to be ordered, 
    merges them such that the resulting vector is also ordered
    */
    vector<int> combined;

    int i = 0;
    int j = 0;

    // while the indices haven't overflown, add the smallest element out of B or C, accroding to i and j
    while (i < B.size() && j < C.size()) {
        if (B[i] < C[j]) {
            combined.push_back(B[i]);
            i++;
        }
        else {
            combined.push_back(C[j]);
            j++;
        }
    }

    // add remaining elements of B or C, depending on which one has been terminated first
    if (i >= B.size()) {
        combined.insert(combined.end(), &C[j], &C[C.size()]);
    }
    else {
        combined.insert(combined.end(), &B[i], &B[B.size()]);
    }

    return combined;

};


vector<int> mergeSortIdx (vector<int> array, int low, int high) {
    /*
    Performs mergesort for the elements of array between indices low and high
    */
    
    // one element vector
    if ((high - low) == 1) {
        return vector <int> {array[low]};
    }
    // otherwise recursively call mergeSortIdx and combine the resulting vectors
    else {
        int mid = floor((high + low)/2);

        vector<int> leftArr = mergeSortIdx(array, low, mid);
        vector<int> rightArr = mergeSortIdx(array, mid, high);
        vector<int> merged = merge(leftArr, rightArr);

        return merged;
    }
};

// mergeSort on whole array
vector<int> mergeSort(vector<int> array) {
    return mergeSortIdx(array, 0, array.size());
};

void testMergeSort() {
    vector<int> testArray = {5,8,9,-1,2,4,64,2,7};
    cout << "Vector given: "<< vectorToString(testArray) << "\n";
    cout << "Vector sorted: "<< vectorToString(mergeSort(testArray)) << "\n";
};