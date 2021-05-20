#include "include/sorter.hpp"

void testSorting() {
    vector<int> testArray = {5,8,9,-1,2,4,64,2,7};
    cout << "Vector given: "<< vectorToString(testArray) << "\n";
    cout << "Vector sorted (insert): "<< vectorToString(insertSort(testArray)) << "\n";
    cout << "Vector sorted (merge): "<< vectorToString(mergeSort(testArray)) << "\n";
    cout << "Vector sorted (quick): "<< vectorToString(quickSort(testArray)) << "\n";
}

int main() {
    
    Sorter sortQuick("insert");
    
    //vector<int> testArray = sortQuick.generateVector(-20,20,10);
    //cout << "Vector Produced: "<< vectorToString(testArray) << "\n";
    //vector<int> sorted = sortQuick.sortShowRuntime(testArray);
    //cout << "Vector Sorted ("<< sortQuick.getSortType() << "): " << vectorToString(sorted) << "\n";

    for (int i = 1; i <= 10; i++) {
        tuple<vector<int>, vector<int>> results = sortQuick.sortShowRRuntime(-10000,10000, pow(2,i));
        cout << "Vector Produced: "<< vectorToString(get<0>(results)) << "\n";
        cout << "Vector Sorted ("<< sortQuick.getSortType() << "): " << vectorToString(get<1>(results)) << "\n";
    }
}