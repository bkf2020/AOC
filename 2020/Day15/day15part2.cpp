#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct location {
	int recent, previous, occupied = 0;
};

int main() {
	map<int, location> locations;
	vector<int> starting;
	string line; getline(cin, line);
	stringstream ss(line);
	
	string part;
	// from https://www.tutorialspoint.com/tokenizing-a-string-in-cplusplus
	while(getline(ss, part, ',')) {
		starting.push_back(stoi(part));
	}
	for(int i = 0; i < starting.size(); i++) {
		locations[starting[i]].recent = i;
		locations[starting[i]].occupied = 1;
	}
	int prev = starting.back();
	for(int i = starting.size(); i < 30000000; i++) {
		if(locations[prev].occupied == 1) {
			prev = 0;
			if(locations[0].occupied == 0) {
				locations[0].recent = i;
			}
			else {
				locations[0].previous = locations[0].recent;
				locations[0].recent = i;
			}
			locations[0].occupied++;
		}
		else {
			int previous_turn = locations[prev].recent;
			int turn_before = locations[prev].previous;
			prev = previous_turn - turn_before;
			if(locations[prev].occupied == 0) {
				locations[prev].recent = i;
			}
			else {
				locations[prev].previous = locations[prev].recent;
				locations[prev].recent = i;
			}
			locations[prev].occupied++;
		}
	}
	cout << prev << '\n';
}
