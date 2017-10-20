/* Petya and Vasya decided to play a game. They have n cards (n is an even number). A single 
integer is written on each card.

Before the game Petya will choose an integer and after that Vasya will choose another integer 
(different from the number that Petya chose). During the game each player takes all the cards 
with number he chose. For example, if Petya chose number 5 before the game he will take all 
cards on which 5 is written and if Vasya chose number 10 before the game he will take all cards 
on which 10 is written.

The game is considered fair if Petya and Vasya can take all n cards, and the number of cards each 
player gets is the same.

Determine whether Petya and Vasya can choose integer numbers before the game so that the game is 
fair.

Input
The first line contains a single integer n (2 ≤ n ≤ 100) — number of cards. It is guaranteed that 
n is an even number.

The following n lines contain a sequence of integers a1, a2, ..., an (one integer per line, 1 ≤ ai ≤ 100) 
— numbers written on the n cards.

Output
If it is impossible for Petya and Vasya to choose numbers in such a way that the game will be fair, print 
"NO" (without quotes) in the first line. In this case you should not print anything more.

In the other case print "YES" (without quotes) in the first line. In the second line print two distinct 
integers — number that Petya should choose and the number that Vasya should choose to make the game fair. 
If there are several solutions, print any of them. */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int n;
	string output;
	cin >> n;
	vector<int> v(n);
	set<int> dist;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	dist.insert(v.begin(), v.end());
	if (dist.size() == 2) {
		sort(v.begin(), v.end()); 
		int pos = (n / 2) - 1;
		set<int>::iterator it = dist.begin();
		if (v[pos] == v[pos + 1])
			cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			for ( ; it != dist.end(); it++)
				cout << *it << " ";
			cout << endl;
		}
	}
	else
		cout << "NO" << endl;
	return 0;
}