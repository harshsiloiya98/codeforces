/* «One dragon. Two dragon. Three dragon», — the princess was counting. She had trouble 
falling asleep, and she got bored of counting lambs when she was nine.

However, just counting dragons was boring as well, so she entertained herself at best she 
could. Tonight she imagined that all dragons were here to steal her, and she was fighting 
them off. Every k-th dragon got punched in the face with a frying pan. Every l-th dragon got 
his tail shut into the balcony door. Every m-th dragon got his paws trampled with sharp heels. 
Finally, she threatened every n-th dragon to call her mom, and he withdrew in panic.

How many imaginary dragons suffered moral or physical damage tonight, if the princess counted 
a total of d dragons?

Input
Input data contains integer numbers k, l, m, n and d, each number in a separate line 
(1 ≤ k, l, m, n ≤ 10, 1 ≤ d ≤ 10^5).

Output
Output the number of damaged dragons. */

#include <iostream>

using namespace std;

int gcd(int x, int y) {
	return (y == 0 ? x : gcd(y, x % y));
}

int lcm(int x, int y) {
	return (x * (y / gcd(x, y)));
}

int lcm(int x, int y, int z) {
	return lcm(x, lcm(y, z));
}

int lcm(int w, int x, int y, int z) {
	return lcm(w, lcm(x, y, z));
}

int main()
{
	int k, l, m, n, d;
	cin >> k >> l >> m >> n >> d;
	// Method of solving hint - inclusion-exclusion principle
	int count = (d/k + d/l + d/m + d/n);
	count -= (d/lcm(k, l) + d/lcm(l, m) + d/lcm(m, n) + d/lcm(n, k) + d/lcm(k, m) + d/lcm(n, l));
	count += (d/lcm(k ,l, m) + d/lcm(l, m, n) + d/lcm(n, k, m) + d/lcm(k, l, n));
	count -= d/lcm(k, l, m, n);
	cout << count << endl;
	return 0;
}