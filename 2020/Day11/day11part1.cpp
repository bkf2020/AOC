#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<char>> prev_seating;
vector<vector<char>> next_seating;

// 8 directions
int dx[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[8] = {0, -1, 0, 1, 1, -1, -1, 1};
bool first_round = true;

bool in_range(int i, int j) {
	return (i >= 0) && (j >= 0) && (i < prev_seating.size()) && (j < prev_seating[0].size());
}

bool changed() {
	return prev_seating != next_seating;
}

void simulate() {
	prev_seating = next_seating;
	for(int i = 0; i < prev_seating.size(); i++) {
		for(int j = 0; j < prev_seating[i].size(); j++) {
			int occupied_count = 0;
			for(int k = 0; k < 8; k++) {
				// check all 8 adjacent
				int new_i = i + dx[k];
				int new_j = j + dy[k];
				if(in_range(new_i, new_j) && prev_seating[new_i][new_j] == '#') occupied_count++;
			}
			if(occupied_count == 0 && prev_seating[i][j] == 'L') next_seating[i][j] = '#';
			if(occupied_count >= 4 && prev_seating[i][j] == '#') next_seating[i][j] = 'L';
		}
	}
}

int count_occupied() {
	int count = 0;
	for(vector<char> vc : next_seating) { // final seating at this point
		for(char c : vc) {
			if(c == '#') count++;
		}
	}
	return count;
}

int main() {
	string line;
	while(cin >> line) {
		vector<char> curr_line;
		for(char c : line) {
			curr_line.push_back(c);
		}
		next_seating.push_back(curr_line);
	}
	while(changed()) {
		simulate();
	}
	cout << count_occupied() << '\n';
}
