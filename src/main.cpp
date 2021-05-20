#include "include/sorter.hpp"

void testSorting() {
    vector<int> testArray = {5,8,9,-1,2,4,64,2,7};
    cout << "Vector given: "<< vectorToString(testArray) << "\n";
    cout << "Vector sorted (insert): "<< vectorToString(insertSort(testArray)) << "\n";
    cout << "Vector sorted (merge): "<< vectorToString(mergeSort(testArray)) << "\n";
    cout << "Vector sorted (quick): "<< vectorToString(quickSort(testArray)) << "\n";
}

int main() {
    
    Sorter sortQuick("quick");
    vector<int> testArray = sortQuick.generateVector(-20,20,10);
    cout << "Vector Produced: "<< vectorToString(testArray) << "\n";
    cout << "Vector Sorted: "<< vectorToString(sortQuick.sort(testArray)) << "\n";
}