#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int temp = 0;
	vector<int> all_adapters;
	while(cin >> temp) {
		all_adapters.push_back(temp);
	}
	all_adapters.push_back(0);  // this is the power outlet
	sort(all_adapters.begin(), all_adapters.end());
	
	map<int, long long> count;
	count[all_adapters[all_adapters.size() - 1]] = 1;
	for(int i = all_adapters.size() - 2; i >= 0; i--) {
		count[all_adapters[i]] = count[all_adapters[i] + 1] + count[all_adapters[i] + 2] + count[all_adapters[i] + 3];
	}
	cout << count[all_adapters[0]] << '\n';
}
