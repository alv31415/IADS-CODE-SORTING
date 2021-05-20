#include "include/sorter.hpp"
#include <iomanip>
#include <sstream>
#include <chrono>

// Helper String Method

// used to print out table rows for sortShowRuntime and sortShowRRuntime
string printRow(string col1, string col2, string col3) {
    int rightPad = 10;
    int leftPad = floor(1.7*rightPad);
    int fullPad = floor(8.1*rightPad) + 1;

    ostringstream table;
    table << setfill('-') << setw(fullPad) << "\n"
          << setfill(' ') << "|"
          << setw(leftPad) << col1 
          << setw(rightPad) << "|"
          << setw(leftPad) << col2
          << setw(rightPad) << "|" 
          << setw(leftPad) << col3 
          << setw(rightPad) << "|\n"
          << setfill('-') << setw(fullPad) << "\n";

    return table.str();
}

// String methods

string Sorter::strToSortType(string str) {
    if (str == "i" || str == "insert" || str == "1") {
        return "insertSort";
    }
    else if (str == "m" || str == "merge" || str == "2") {
        return "mergeSort";
    }
    else if (str == "q" || str == "quick" || str == "3") {
        return "quickSort";
    }
    else {
        return "INVALID_SORT";
    }
}

string Sorter::getSortType() {
    return Sorter::sortType;
}

// prints runtime table given input and runtime
string Sorter::printRuntime(vector<int> input, long runtime) {
    string headerRow = printRow("Algorithm", "Array Size", "Runtime (ms)");
    string runtimeRow = printRow(Sorter::sortType, to_string(input.size()), to_string(runtime)) + "\n";

    return (headerRow + runtimeRow);
}

// prints runtime table given a number of inputs and their runtimes
string Sorter::printRuntimes(vector<vector<int>> inputs, vector<long> runtimes) {
    string rows = printRow("Algorithm", "Array Size", "Runtime (ms)");

    for (int i = 0; i < inputs.size(); i++) {
        rows += printRow(Sorter::sortType, to_string(inputs[i].size()), to_string(runtimes[i]));   
    }

    return rows + "\n";
    
}

// -----------------------------------------------------------------------

// Constructors

Sorter::Sorter() {
    this->sortType = "quickSort";
    sorter = quickSort;
}

Sorter::Sorter(string sortType) {
    /*
    Initialise the type of sorter to use, depending on String or number.
    Default is quickSort
    */

    this->sortType = Sorter::strToSortType(sortType);

    if (Sorter::sortType == "insertSort") {
        sorter = insertSort;
    }
    else if (Sorter::sortType == "mergeSort"){
        sorter = mergeSort;
    }
    else {
        if (Sorter::sortType == "INVALID_SORT") {
            this->sortType = "quickSort";
            cout << "\033[1;31mInvalid sort string provided when constructing Sorter.\nOptions include: insertSort ('i', 'insert', '1'), mergeSort ('m', 'merge', '1'), or quickSort ('q', 'quick', '3').\nUsing quickSort as default.\033[0m\n"; 
        }
        sorter = quickSort;
    }
}

// -----------------------------------------------------------------------

// Functionality Methods

// sort array based on sorter algorithm
vector<int> Sorter::sort(vector<int> array) { return sorter(array); }

            
// generate random vector of length len using integers between lower, and upper
vector<int> Sorter::generateVector(int lower, int upper, int len) {
    vector<int> randVector(len);

    srand(seed);

    for (int i = 0; i < len; i++) {
        randVector[i] = rand() % (upper - lower + 1) + lower;
    }

    // update seed to prevent repeating vectors if method is used repeatedly
    seed += len + 1; 

    return randVector;
}

// shows runtime for Sorter instance (on given array) on a table. Returns sorted array.
vector<int> Sorter::sortShowRuntime(vector<int> array) {

    auto start = chrono::high_resolution_clock::now();

    vector<int> sorted = sorter(array);

    auto stop = chrono::high_resolution_clock::now();

    auto duration = duration_cast<chrono::microseconds>(stop - start);

    cout << Sorter::printRuntime(array, duration.count());

    return sorted;
}

// shows runtime for Sorter instance (on random array) on a table. Returns a tuple of random array, and its sorted version. 
tuple<vector<int>, vector<int>> Sorter::sortShowRRuntime(int lower, int upper, int len) {
    vector<int> randArray = Sorter::generateVector(lower, upper, len);

    vector<int> sorted = Sorter::sortShowRuntime(randArray);

    return make_tuple(randArray, sorted);
}