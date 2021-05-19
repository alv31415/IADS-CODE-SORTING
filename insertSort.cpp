#include <iostream>
#include <vector>
#include <string>
#include "helpers.h"

using namespace std;

vector<int> insertSort (vector<int> array) {
    int n = array.size();
    for (int i = 0; i < n; i++) {
        int x = array[i];
        int j = i - 1;
        // until we find an element which is smaller than x, iterate
        // switching x and the element to its left
        while (j >= 0 && array[j] > x) {
            array[j+1] = array[j];
            j -= 1;
        }
        // once an element smaller than x is found, we insert x in front of it
        array[j+1] = x;

    };

    return array;

};

int testInsertSort() {
    vector<int> testArray = {5,8,9,-1,2,4,64,2,7};
    cout << "Vector given: "<< vectorToString(testArray) << "\n";
    cout << "Vector sorted: "<< vectorToString(insertSort(testArray)) << "\n";
};