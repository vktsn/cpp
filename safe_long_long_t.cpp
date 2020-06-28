#include <iostream>
using namespace std;

class safe_long_long_t {
private:
    long long value;
public:
    explicit safe_long_long_t(long long x) {
        value = x;
    }

    safe_long_long_t operator=(const safe_long_long_t& a) {
        value = a.value;
        return *this;
    }

    safe_long_long_t& operator+=(const safe_long_long_t& a) {
        value += a.value;
        return *this;
    }

    safe_long_long_t& operator-=(const safe_long_long_t& a) {
        value -= a.value;
        return *this;
    }

    safe_long_long_t& operator*=(const safe_long_long_t& a) {
        value *= a.value;
        return *this;
    }

    safe_long_long_t& operator/=(const safe_long_long_t& a) {
        value /= a.value;
        return *this;
    }

    safe_long_long_t& operator%=(const safe_long_long_t& a) {
        value %= a.value;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const safe_long_long_t& a) {
        out << a.value;
        return out;
    };

    friend istream& operator>>(istream& in, safe_long_long_t& a) {
        in >> a.value;
        return in;
    };


    friend bool operator==(const safe_long_long_t& a, const safe_long_long_t& b);
    friend bool operator>(const safe_long_long_t& a, const safe_long_long_t& b);
    friend bool operator<(const safe_long_long_t& a, const safe_long_long_t& b);
};

safe_long_long_t operator+(safe_long_long_t a, const safe_long_long_t& b) {
    return (a += b);
}

safe_long_long_t operator-(safe_long_long_t a, const safe_long_long_t& b) {
    return (a -= b);
}

safe_long_long_t operator*(safe_long_long_t a, const safe_long_long_t& b) {
    return (a *= b);
}

safe_long_long_t operator/(safe_long_long_t a, const safe_long_long_t& b) {
    return (a /= b);
}

safe_long_long_t operator%(safe_long_long_t a, const safe_long_long_t& b) {
    return (a %= b);
}


bool operator==(const safe_long_long_t& a, const safe_long_long_t& b) {
    return (a.value == b.value);
}

bool operator!=(const safe_long_long_t& a, const safe_long_long_t& b) {
    return !(a == b);
}

bool operator>(const safe_long_long_t& a, const safe_long_long_t& b) {
    return (a.value > b.value);
}

bool operator<(const safe_long_long_t& a, const safe_long_long_t& b) {
    return (a.value < b.value);
}

int main() {
    safe_long_long_t a(12);
    safe_long_long_t b(3);
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    cout << "b % a = " << b % a << endl;
    cout << "a != b = " << (a != b) << endl;
    cout << "a == b = " << (a == b) << endl;
    cout << "a > b = " << (a > b) << endl;
    cout << "a < b = " << (a < b) << endl;
    return 0;
}
