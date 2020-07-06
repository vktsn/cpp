#include <iostream>
#include "int_list_t.h"
using namespace std;

int main() {
    int_list_t list_1;
    for (int i = 1; i < 11; ++i) {
        list_1.push_front(i);
    }
    cout << list_1 << endl;

    int_list_t list_2;
    for (int i = 1; i < 11; ++i) {
        list_2.push_back(i);
    }
    cout << list_2 << endl;

    return 0;
}
