#include "include/helpers.h"

using namespace std;

string vectorToString (vector<int> array) {
    string str = "[";
    for (int n = 0; n < array.size(); n++) {

        string element = to_string(array[n]);

        if (n == array.size() - 1){
            str += (element+ "]");
        }
        else {
            str += (element+ ", ");
        }
    };

    return str;
};