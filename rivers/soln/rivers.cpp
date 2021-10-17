// ------------------------------
// Weekly Exercise 4 - Rivers
// CMPUT 275 Winter 2021
// Ashley Davis, 1616898
// ------------------------------

#include <iostream>

using namespace std;

// query() runs a single query to find the point
// betweeen two rivers where they first meet
// inputs: a - a pointer to the array rivers
//		   n - the number of rivers in the array
//         u - the first river's starting index
//         v - the second river's starting index
// return: connection - the point where the two meet
int query(int* a, int n, int u, int v);

int main() {
	// n - the number of rivers
	// q - the number of queries
	int n, q;
	cin >> n >> q;

	// rivers - an array of all the rivers' flows, set to
	//   		max length to remove varibale-length array
	int rivers[100000];
	for (int i = 0; i < n; i++) {
		cin >> rivers[i];
	}

	// u - the starting index of the first river
	// v - the starting index of the ssecond river
	// connection - the point where the two rivers meet
	int u, v, connection;

	// for each query:
	for (int j = 0; j < q; j++) {
		cin >> u >> v;  // input starting positions
		// a - a pointer to the array riverssss
		int *a = &rivers[0];
		connection = query(a, n, u, v);
		cout << connection << endl;
	}
	return 0;
}

// query() runs a single query to find the point
// betweeen two rivers where they first meet
// inputs: a - a pointer to the array rivers
//		   n - the number of rivers in the array
//         u - the first river's starting index
//         v - the second river's starting index
// return: connection - the point where the two meet
int query(int* a, int n, int u, int v) {
	// river1 - the current location along the first river (u)
	// river2 - the current location along the second river (v)
	// connection - the point where the two meet
	int river1, river2, connection;
	river1 = *(a + u - 1);  // index of rivers for u
	river2 = *(a + v - 1);  // index of rivers for v
	while (true) {
		if ( (u == 0) || (v == 0) ) {
			connection = 0;
			break;
		} else if (u == v) {
			connection = v;
			break;
		} else if (river1 == river2) {
			connection = river1;
			break;
		} else if (river1 < river2) {
			// move along the higher value of the two rivers
			v = river2;
			river2 = *(a + v - 1);
		} else {
			// move along the higher value of the two rivers
			u = river1;
			river1 = *(a + u - 1);
		}
		continue;
	}
	return connection;
}
