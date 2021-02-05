#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

void part2() {
	int total = 0;
	set<char> curr_group;
	map<char, int> count;
	string curr_answer;
	int group_size = 0;
	while(getline(cin, curr_answer)) {
		if(curr_answer == "") {
			for(char c : curr_group) {
				if(count[c] == group_size) total++;
				count[c] = 0;
			}
			group_size = 0;
			curr_group.clear();
		}
		else {
			group_size++;
			for(char c : curr_answer) {
				curr_group.insert(c);
				count[c]++;
			}
		}
	}
	for(char c : curr_group) {
		if(count[c] == group_size) total++;
	}
	cout << total << '\n';
}

int main() {
	part2();
}
