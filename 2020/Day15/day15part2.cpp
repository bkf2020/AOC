#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int previous[30000000];

int main() {
	vector<int> starting;
	string line; getline(cin, line);
	stringstream ss(line);
	
	string part;
	// from https://www.tutorialspoint.com/tokenizing-a-string-in-cplusplus
	while(getline(ss, part, ',')) {
		starting.push_back(stoi(part));
	}
	// last one should not be ignored...
	for(int i = 0; i < starting.size() - 1; i++) {
		previous[starting[i]] = i + 1;
		// we increase by one, because if i is zero, the checks in the next loop won't work
	}
	int prev = starting.back();
	for(int i = starting.size(); i < 30000000; i++) {
		if(!previous[prev]) { // no previous number
			previous[prev] = i; // recent turn
			prev = 0;
		}
		else {
			int recent_turn = i;
			int turn_before = previous[prev];
			previous[prev] = i;
			prev = recent_turn - turn_before;
		}
	}
	cout << prev << '\n';
}
