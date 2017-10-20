/* Kefa decided to make some money doing business on the Internet for exactly n days. 
He knows that on the i-th day (1 ≤ i ≤ n) he makes ai money. Kefa loves progress, that's 
why he wants to know the length of the maximum non-decreasing subsegment in sequence ai. 
Let us remind you that the subsegment of the sequence is its continuous fragment. A subsegment 
of numbers is called non-decreasing if all numbers in it follow in the non-decreasing order.

Help Kefa cope with this task!

Input
The first line contains integer n (1 ≤ n ≤ 10^5).

The second line contains n integers a1,  a2,  ...,  an (1 ≤ ai ≤ 10^9).

Output
Print a single integer — the length of the maximum non-decreasing subsegment of sequence a. */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	priority_queue<int> length;
	int x = 1;
	for (int j = 0; j < n - 1; j++) {
		if (num[j] <= num[j + 1])
			x++;
		else {
			length.push(x);
			x = 1;
		}
	}
	length.push(x);
	cout << length.top() << endl;
	return 0;
}