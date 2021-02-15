#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
	map<int, vector<int>> locations;
	vector<int> starting;
	vector<int> numbers_said;
	string line; getline(cin, line);
	stringstream ss(line);
	
	string part;
	// from https://www.tutorialspoint.com/tokenizing-a-string-in-cplusplus
	while(getline(ss, part, ',')) {
		starting.push_back(stoi(part));
	}
	for(int i = 0; i < starting.size(); i++) {
		locations[starting[i]].push_back(i);
		numbers_said.push_back(starting[i]);
	}
	for(int i = starting.size(); i < 2020; i++) {
		int previous = numbers_said.back();
		if((int) locations[previous].size() == 1) {
			numbers_said.push_back(0);
			locations[0].push_back(i);
		}
		else {
			int previous_turn = locations[previous].back();
			int turn_before = locations[previous][locations[previous].size() - 2];
			numbers_said.push_back(previous_turn - turn_before);
			locations[previous_turn - turn_before].push_back(i);
		}
	}
	cout << numbers_said.back() << '\n';
}
