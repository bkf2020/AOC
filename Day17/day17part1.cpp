#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct point {
	char c = '.';
};

map<tuple<int, int, int>, point> plane;
int sx = 0, sy = 0, ex = 0, ey = 0; // start x, start y, end x, end y
int sz = 0, ez = 0; // start and end z
int dx[26];
int dy[26];
int dz[26];

void read_input() {
	string line;
	vector<string> lines;
	while(getline(cin, line)) {
		lines.push_back(line);
	}
	int y = 0;
	for(int i = lines.size() - 1; i >= 0; i--) {
		for(int x = 0; x < lines[i].size(); x++) {
			plane[{x, y, 0}].c = lines[i][x];
		}
		y++;
	}
	ex = lines[0].size();
	ey = lines.size();
}

void do_cycle() {
	map<tuple<int, int, int>, point> plane_after = plane;
	sx--; ex++;
	sy--; ey++;
	sz--; ez++;
	for(int x = sx; x <= ex; x++) {
		for(int y = sy; y <= ey; y++) {
			for(int z = sz; z <= ez; z++) {
				int active_count = 0;
				for(int k = 0; k < 26; k++) {
					int nx = x + dx[k], ny = y + dy[k], nz = z + dz[k]; // neighbors of point
					if(plane[{nx, ny, nz}].c == '#') active_count++;
				}
				if(plane[{x, y, z}].c == '#') {
					if(active_count != 2 && active_count != 3) plane_after[{x, y, z}].c = '.';
				}
				else {
					if(active_count == 3) plane_after[{x, y, z}].c = '#';
				}
			}
		}
	}
	plane = plane_after;
}

void set_increments() {
	int counter = 0;
	for(int cx = -1; cx <= 1; cx++) {
		for(int cy = -1; cy <= 1; cy++) {
			for(int cz = -1; cz <= 1; cz++) {
				if(cx == 0 && cy == 0 && cz == 0) continue;
				dx[counter] = cx;
				dy[counter] = cy;
				dz[counter] = cz;
				counter++;
			}
		}
	}
}

int main() {
	set_increments();
	read_input();
	for(int i = 0; i < 6; i++) {
		do_cycle();
	}

	// count # of active
	int active = 0;
	for(int x = sx; x <= ex; x++) {
		for(int y = sy; y <= ey; y++) {
			for(int z = sz; z <= ez; z++) {
				if(plane[{x, y, z}].c == '#') active++;
			}
		}
	}
	cout << active << '\n';
}
