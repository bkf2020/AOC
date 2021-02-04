#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void part1() {
	int expense; // current number on report
	vector<int> all; // all numbers on report
	while(cin >> expense) {
		all.push_back(expense);
	}
	sort(all.begin(), all.end());
	for(int i = 0; i < all.size(); i++) {
		auto it = lower_bound(all.begin(), all.end(), 2020 - all[i]);
		if(*it == 2020 - all[i]) {
			long long ans = (long long) all[i] * (long long) (*it);
			cout << ans << '\n';
			break;
		}
	}
}

int main() {
	part1();
}
