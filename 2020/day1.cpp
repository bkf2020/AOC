#include <bits/stdc++.h>
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

void part2() {
	int expense; // current number on report
	vector<int> all; // all numbers on report
	while(cin >> expense) {
		all.push_back(expense);
	}
	sort(all.begin(), all.end());
	for(int i = 0; i < all.size(); i++) {
		for(int j = i + 1; j < all.size(); j++) {
			auto it = lower_bound(all.begin(), all.end(), 2020 - all[i] - all[j]);
			if(*it == 2020 - all[i] - all[j]) {
				long long ans = (long long) all[i] * (long long) all[j] * (long long) (*it);
				cout << ans << '\n';
				exit(0);
			}
		}
	}
}

int main() {
	// run part1 or part 2
	// part1();
	part2();
}