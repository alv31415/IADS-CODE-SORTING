#include "helpers.h"

using namespace std;

// we use referencing throughout because we sort the vector in place

void swap (vector<int>&, int, int);

int partition (vector<int>&, int, int); 

void quickSortIdx(vector<int>&, int, int);

vector<int> quickSort(vector<int>);

void testQuickSort();