#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, bool> visited;
int acc = 0;
vector<string> steps;
vector<int> changes;

void run_program(int step_num) {
	if(visited[step_num]) return;
	visited[step_num] = true;
	if(steps[step_num] == "acc") {
		acc += changes[step_num];
		run_program(step_num + 1);
	}
	else if(steps[step_num] == "jmp") {
		run_program(step_num + changes[step_num]);
	}
	else {
		run_program(step_num + 1);
	}
}

void part1() {
	string step, change;
	while(cin >> step >> change) {
		steps.push_back(step);
		if(change[0] == '+') {
			change.erase(change.begin());
			changes.push_back(stoi(change));
		}
		else {
			changes.push_back(stoi(change));
		}
	}
	run_program(0);
	cout << acc << '\n';
}

int main() {
	part1();
}