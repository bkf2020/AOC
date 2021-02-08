#include <set>
#include <iostream>
using namespace std;

int main() {
	int one_count = 0, three_count = 0, temp = 0;
	set<int> all_adapters;
	while(cin >> temp) {
		all_adapters.insert(temp);
	}
	int previous = 0;
	for(auto it = all_adapters.begin(); it != all_adapters.end(); it++) {
		if(*it - previous == 1) one_count++;
		else if(*it - previous == 3) three_count++;
		previous = *it;
	}
	three_count++; // your device is always 3 more than the largest adapter!!!
	cout << (long long) one_count * (long long) three_count << '\n';
}
