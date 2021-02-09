#include <iostream>
#include <string>
#include <set>
using namespace std;

void part1() {
	int total = 0;
	set<char> curr_group;
	string curr_answer;
	while(getline(cin, curr_answer)) {
		if(curr_answer == "") {
			total += curr_group.size();
			curr_group.clear();
		}
		else {
			for(char c : curr_answer) {
				curr_group.insert(c);
			}
		}
	}
	total += curr_group.size();
	cout << total << '\n';
}

int main() {
	part1();
}
