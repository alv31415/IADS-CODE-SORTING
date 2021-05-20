#include <functional>
#include <stdlib.h>
#include <time.h>
#include "insertSort.h"
#include "mergeSort.h"
#include "quickSort.h"

using namespace std;

class Sorter {
    /*
    Class which unifies all sorting algorithms.
    Contains functionality to test performance of insertSort, mergeSort and quickSort.
    */ 
    private:
        function<vector<int>(vector<int>)> sorter; //sorting algorithm used by class instance

        int seed = time(0); // seed to generate random vectors of numbers

        string strToSortType(string str);
        string sortType;
    public:
        Sorter(); // default Sorter uses quickSort
        Sorter(string sortType); // sortType to define sorting

        string getSortType();
        string printRuntime(vector<int> input, long runtime);
        string printRuntimes(vector<vector<int>> inputs, vector<long> runtimes);

        vector<int> sort(vector<int>); // for sorting arrays
        vector<int> generateVector(int lower, int upper, int len); // for generating random arrays
        vector<int> sortShowRuntime(vector<int>); // sort array & display information on performance
        tuple<vector<int>, vector<int>> sortShowRRuntime(int lower, int upper, int len); // sort random array & display information on performance
};