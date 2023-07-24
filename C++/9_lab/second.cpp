#include <iostream>

using namespace std;

double f(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    else if (n == 1) {
        return x;
    }
    else {
        return (x * x / (n * (n - 1))) * f(x, n - 2);
    }
}

int main() {
    double x;
    int n;

    cout << "������� x � n: ";
    cin >> x >> n;

    double result = f(x, n);

    cout << "���������: " << result << endl;

    return 0;
}
