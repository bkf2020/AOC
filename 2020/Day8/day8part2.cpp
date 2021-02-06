#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, bool> visited;
int acc = 0;
vector<string> steps;
vector<int> changes;

bool run_program(int step_num) {
	if(step_num >= (int) steps.size()) return true;
	if(visited[step_num]) return false;
	visited[step_num] = true;
	if(steps[step_num] == "acc") {
		acc += changes[step_num];
		return run_program(step_num + 1);
	}
	else if(steps[step_num] == "jmp") {
		return run_program(step_num + changes[step_num]);
	}
	else {
		return run_program(step_num + 1);
	}
}

void part2() {
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
	for(int i = 0; i < steps.size(); i++) {
		if(steps[i] == "nop") {
			steps[i] = "jmp";
			if(run_program(0)) { // no repeats
				cout << acc << '\n';
				exit(0);
			}
			acc = 0;
			steps[i] = "nop";
			for(int j = 0; j < steps.size(); j++) {
				visited[j] = false;
			}
		}
		else if(steps[i] == "jmp") {
			steps[i] = "nop";
			if(run_program(0)) { // no repeats
				cout << acc << '\n';
				exit(0);
			}
			acc = 0;
			steps[i] = "jmp";
			for(int j = 0; j < steps.size(); j++) {
				visited[j] = false;
			}
		}
	}
}

int main() {
	part2();
}