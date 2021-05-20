#include "include/sorter.hpp"

Sorter::Sorter() {
    sorter = quickSort;
}

Sorter:: Sorter(string sortType) {
            if (sortType == "i" || sortType == "insert" || sortType == "1") {
                sorter = insertSort;
            }
            else if (sortType == "m" || sortType == "merge" || sortType == "2"){
                sorter = mergeSort;
            }
            else {
                sorter = quickSort;
            }
}

vector<int> Sorter::sort(vector<int> array) {
            return sorter(array);
        }

vector<int> Sorter::generateVector(int lower, int upper, int len) {
    vector<int> randVector(len);

    srand(seed);

    for (int i = 0; i < len; i++) {
        randVector[i] = rand() % (upper - lower + 1) + lower;
    }

    seed += len + 1;

    return randVector;
}