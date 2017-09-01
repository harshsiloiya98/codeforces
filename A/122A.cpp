/* Petya loves lucky numbers. Everybody knows that lucky numbers are positive 
integers whose decimal representation contains only the lucky digits 4 and 7. 
For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya calls a number almost lucky if it could be evenly divided by some lucky number. 
Help him find out if the given number n is almost lucky.

Input
The single line contains an integer n (1 ≤ n ≤ 1000) — the number that needs to be checked.

Output
In the only line print "YES" (without the quotes), if number n is almost lucky. 
Otherwise, print "NO" (without the quotes). */

#include <iostream>
#include <string>

using namespace std;

int checkset[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

int bSearch(int data) {
	int l = 0;
	int h = 14;
	int mid;
	while (l <= h) {
		mid = (l + h) / 2;
		if (checkset[mid] < data)
			l = mid + 1;
		else if (checkset[mid] > data)
			h = mid - 1;
		else
			return mid;
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	string flag = "NO";
	for (int i = 1; i <= n; i++) {
		if (bSearch(i) != -1)
			if (n % i == 0) {
				flag = "YES";
				break;
			}
	}
	cout << flag << endl;
	return 0;
}