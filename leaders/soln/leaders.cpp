// -------------------------------------
// Weekly Exercise #2 - Leaders
// CmMPUT 275, Winter 2021
// Ashley Davis
// -------------------------------------

// NOTE TO THE MARKER: The style guide indicates improper indentation on line
//  34 regardless of what is on that line. I'm not sure if this is a glitch, but
//  in my code I made sure it's lined up with lines 33 and 35.

#include <iostream>
using namespace std;

// void() takes two pointers to the values of the array numbers to reverse
// inputs: begin - the first value's pointer
//         end   - the second value's pointer
// output: void
void reverse(int* begin, int* end);

// main() reads input, finds the leaders, and calls reverse()
int main() {
	// n - the number of values
	int n;
	cin >> n;

	// numbers - the array of length n values as inputted
	// input - the amount out of 'n' values that have been inputted
	int numbers[n], input = 0;
	for (; input < n; input++) {
		cin >> numbers[input];
	}

	// FIND THE LEADERS HERE
	// leaders_ind - an array holding the indexes of the leaders in numbers
	//               note: indexes listed in reverse order and know the last
    //                     number in the array will be a leader
	// index - used to iterate backwards through numbers to find the leaders
	// high_value - the largest value in the array, initially the last value
	// count = the number of leaders found
	int leaders_ind[n], index = n-2, high_value = numbers[n-1], count = 1;
	leaders_ind[0] = (n-1);
	for (; index >= 0; index--) {
		if (numbers[index] > high_value) {
			leaders_ind[count] = index;
			count += 1;
			high_value = numbers[index];
		}
	}
	// num_leaders - holds the value of count while count is used to iterate
	int num_leaders = count;

	count -= 1;  // count needs - 1 in order to iterate through numbers
	// this for loop prints the leader values using leaders_ind
	for (; count >= 0; count--) {
		cout << numbers[leaders_ind[count]];
		// prints a space between values
		if (count != 0) {
			cout << " ";
		}
	}
	cout << endl;

	// REVERSE THE VALUES OF NUMBERS HERE
	// upperbound - the value to the left of the leader, upperbound to be reversed
	// lowerbound - value to right of the previous leader, lowerbound to reverse
	// new_index - the new index to iterate through the for loop, using num_leaders
	// upper - temporary holder for the value of upper value to reverse
	// lower - temporary holder for the value of lower value to reverse
	// begin - pointer to the lower value to be reverse in numbers
	// end - pointer to the upper value to be reverse in numbers
	int upperbound, lowerbound = 0, new_index = num_leaders - 1, upper, lower;
	for (; new_index >= 0; new_index--) {
		upperbound = leaders_ind[new_index] - 1;
		// If there are only two numberss next to each other to reverse
		// Ex) 9 1 2 8 -> 9 2 1 8
		if ((upperbound - lowerbound) == 1) {
			int * begin = &numbers[lowerbound], * end = &numbers[upperbound];
				reverse(begin, end);

		// If there are odd number of values to reverse
		// Ex) 9 1 2 3 8 -> 9 3 2 1 8
		} else if (((upperbound - lowerbound) % 2) == 1) {
			upper = upperbound;
			lower = lowerbound;
			// while loop until all numbers have been reversed
			while (upper - lower >= 1) {
				int * begin = &numbers[lower], * end = &numbers[upper];
				reverse(begin, end);
				upper -= 1;
				lower += 1;
			}
		// If there are an even number of values to reverse
		// Ex) 9 1 2 3 4 8 -> 9 4 3 2 1 8
		} else if (((upperbound - lowerbound) % 2) == 0) {
			upper = upperbound;
			lower = lowerbound;
			// while loop until all numberss have been reversed
			while (upper - lower >= 0) {
				int * begin = &numbers[lower], * end = &numbers[upper];
				reverse(begin, end);
				upper -= 1;
				lower += 1;
			}
		// resets lowerbound to the right of the leader
		} lowerbound = upperbound + 2;
	}

	// resets the index value to 0, prints all the values of numbers
	index = 0;
	for (; index < n; index++) {
		cout << numbers[index];
		if (index != n-1) {
			cout << " ";
		}
	}

	cout << endl;
	return 0;
}

// void() takes two pointers to the values of the array numbers to reverse
// inputs: begin - the first value's pointer
//         end   - the second value's pointer
// output: void
void reverse(int* begin, int* end) {
	// temp_num - a temporary number to hold the value of pointer end
	int temp_num;
	temp_num = *end;
	*end = *begin;
	*begin = temp_num;
	return;
}
