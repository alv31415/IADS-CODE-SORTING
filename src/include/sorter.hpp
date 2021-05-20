#include <functional>
#include <stdlib.h>
#include <time.h>
#include "insertSort.h"
#include "mergeSort.h"
#include "quickSort.h"

using namespace std;

class Sorter {
    private:
        function<vector<int>(vector<int>)> sorter;
        int seed = time(0);
    public:
        Sorter();
        Sorter(string sortType);
        vector<int> sort(vector<int>);
        vector<int> generateVector(int lower, int upper, int len);
};