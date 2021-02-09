#include <vector>
#include <string>
#include <iostream>
using namespace std;

void part2() {
	vector<vector<char>> grid;
	string line;
	while(getline(cin, line)) {
		vector<char> curr;
		for(int i = 0; i < line.size(); i++) {
			curr.push_back(line[i]);
		}
		grid.push_back(curr);
	}
	
	long long ans = 1;
	// right 1, down 1
	int x = 0, y = 0, counter = 0;
	for(int i = 0; i < grid.size() - 1; i++) {
		x++;
		y++;
		if(grid[x][y % (grid[i].size())] == '#') counter++;
	}
	ans *= (long long) counter;
	
	x = 0, y = 0, counter = 0;
	for(int i = 0; i < grid.size() - 1; i++) {
		x++;
		y+= 3;
		if(grid[x][y % (grid[i].size())] == '#') counter++;
	}
	ans *= (long long) counter;
	
	x = 0, y = 0, counter = 0;
	for(int i = 0; i < grid.size() - 1; i++) {
		x++;
		y+= 5;
		if(grid[x][y % (grid[i].size())] == '#') counter++;
	}
	ans *= (long long) counter;
	
	x = 0, y = 0, counter = 0;
	for(int i = 0; i < grid.size() - 1; i++) {
		x++;
		y+= 7;
		if(grid[x][y % (grid[i].size())] == '#') counter++;
	}
	ans *= (long long) counter;
	
	x = 0, y = 0, counter = 0;
	for(int i = 0; i < grid.size() - 1; i += 2) {
		x += 2;
		y++;
		if(grid[x][y % (grid[i].size())] == '#') counter++;
	}
	ans *= (long long) counter;
	
	cout << ans << '\n';
}

int main() {
	part2();
}
