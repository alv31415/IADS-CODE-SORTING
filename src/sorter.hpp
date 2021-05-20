#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Sorter {
    private:
    public:
    vector<int> (*funct) (vector<int>);
    Sorter(string sortType= "q") {
        if (sortType == "i" || sortType == "insert" || sortType = "1") {

        }
    }
}