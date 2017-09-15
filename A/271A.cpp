/* It seems like the year of 2013 came only yesterday. Do you know a curious fact? The 
year of 2013 is the first year after the old 1987 with only distinct digits.

Now you are suggested to solve the following problem: given a year number, find the minimum 
year number which is strictly larger than the given one and has only distinct digits.

Input
The single line contains integer y (1000 ≤ y ≤ 9000) — the year number.

Output
Print a single integer — the minimum year number that is strictly larger than y and all it's 
digits are distinct. It is guaranteed that the answer exists.  */

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	int yr1;
	cin >> yr1;
	int yr2 = yr1 + 1;
	while (yr2 > yr1) {
		string s = to_string(yr2);
		set<char> checker;
		for (char x: s)
			checker.insert(x);
		if (checker.size() == s.length()) {
			cout << yr2 << endl;
			break; 
		}
		checker.clear();
		yr2++;
	}
	return 0;
}