#include "headers/insertSort.h"
#include "headers/mergeSort.h"
#include "headers/quickSort.h"

int main() {
    vector<int> testArray = {5,8,9,-1,2,4,64,2,7};
    cout << "Vector given: "<< vectorToString(testArray) << "\n";
    cout << "Vector sorted (insert): "<< vectorToString(insertSort(testArray)) << "\n";
    cout << "Vector sorted (merge): "<< vectorToString(mergeSort(testArray)) << "\n";
    cout << "Vector sorted (quick): "<< vectorToString(quickSort(testArray)) << "\n";
}