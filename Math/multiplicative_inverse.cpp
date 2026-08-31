// ## Modular Multiplicative Inverse using Extended Euclidean Algorithm


#include <bits/stdc++.h>
using namespace std;

int x, y, g;

void extendedEuclidean(int a, int b) {
    if (b == 0) {
        x = 1;
        y = 0;
        g = a;
        return;
    }

    extendedEuclidean(b, a % b);

    int cx = y;
    int cy = x - (a / b) * y;

    x = cx;
    y = cy;
}

void inverse(int a, int m) {
    if (gcd(a, m) == 1) {
        extendedEuclidean(a, m);

        x = (x % m + m) % m;

        cout << "Modular Inverse = " << x << '\n';
    } else {
        cout << "Modular inverse does not exist\n";
    }
}

int main() {
    int a = 2;
    int m = 7;

    inverse(a, m);

    return 0;
}
