#include <vector>
#include <string>
#include <iostream>
using namespace std;

void part1() {
	vector<vector<char>> grid;
	string line;
	while(getline(cin, line)) {
		vector<char> curr;
		for(int i = 0; i < line.size(); i++) {
			curr.push_back(line[i]);
		}
		grid.push_back(curr);
	}
	
	int x = 0, y = 0, counter = 0;
	for(int i = 0; i < grid.size() - 1; i++) {
		x++;
		y+=3;
		if(grid[x][y % (grid[i].size())] == '#') counter++;
	}
	cout << counter << '\n';
}

int main() {
	part1();
}
