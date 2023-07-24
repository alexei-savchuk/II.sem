#include <iostream>
#include <cmath>

using namespace std;

double sum_cos(int n, double x) {
	if (n == 1) {
	 return	cos(x);
	}
	else {
		return (cos(n * x) + sum_cos(n - 1, x));
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	double x;
	cout << "ֲגוההטעו x ט n" << endl;
	cin >> x >> n;
	cout << "y =" << sum_cos(n,x) << endl;
	return 0;
}