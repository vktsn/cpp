#include <iostream>
using namespace std;

class safe_c_array_t {
private:
    int size;
    int* arr;

public:
    safe_c_array_t(int n) {
        size = n;
        arr = new int[size];
    }

    safe_c_array_t& operator=(const safe_c_array_t& original) {
            size = original.size;
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = original.arr[i];
        }
        return *this;
    }

    safe_c_array_t(const safe_c_array_t& origin) {
        size = origin.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = origin.arr[i];
        }
    }

    void fill() {
        for (int i = 0; i < size; i++) {
            arr[i] = i;
        }
    }

    int& operator[](int k) {
        return arr[k];
    }
    ~safe_c_array_t() {
        delete[]arr;
    }
};

int main() {
    safe_c_array_t arr = safe_c_array_t(10);
    safe_c_array_t copy = safe_c_array_t(arr);
    arr.fill();
    copy.fill();
    safe_c_array_t arr2 = copy;
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " " << copy[i] << " " << arr2[i] << endl;
    }
    return 0;
}
