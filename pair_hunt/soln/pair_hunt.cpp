// -----------------------------------
// Weekly Exercise 3: Pair Hunt
// CMPUT 275 Winter 2021
// Ashley Davis, 1616898
// -----------------------------------

#include <iostream>
#include <algorithm>  // for sort()
#include <cmath>  // for abs()

using namespace std;

int main() {
	// n - the number of items to be compared
	// T - the target price
	// index - used to iterate through list of items
	int n, T, index = 0;
	cin >> n >> T;

	// items - the list of item prices to be compared
	int items[250000];

	// for loop to add prices to the items list
	for (; index < n; index++) {
		cin >> items[index];
	}

	// sort prices
	sort(items, items + n);

	// i - the lower index
	// j - the upper index
	// I - the price of the item at index i
	// J - the price of the item at index j
	// isPair - true if there is a pair, false otherwise
	int i = 0, j = (n - 1), I, J;
	bool isPair = false;

	while (i < j) {
		I = items[i];
		J = items[j];

		// if (I + J - T) == 0 within error...
		if (abs(I + J - T) < 0.0001) {
			isPair = true;
			break;
		} else if (I + J < T) {
			i++;  // increase lower bound
		} else if (I + J > T) {
			j--;  // decrease upper bound
		}
	}

	if (isPair) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
