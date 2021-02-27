#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct point {
	char c = '.';
};

map<pair<pair<int, int>, pair<int, int>>, point> plane;
int sx = 0, sy = 0, ex = 0, ey = 0; // start x, start y, end x, end y
int sz = 0, ez = 0, sw = 0, ew = 0; // start z, end z, start w, end w
int dx[80];
int dy[80];
int dz[80];
int dw[80];

void read_input() {
	string line;
	vector<string> lines;
	while(getline(cin, line)) {
		lines.push_back(line);
	}
	int y = 0;
	for(int i = lines.size() - 1; i >= 0; i--) {
		for(int x = 0; x < lines[i].size(); x++) {
			plane[{{x, y}, {0, 0}}].c = lines[i][x];
		}
		y++;
	}
	ex = lines[0].size();
	ey = lines.size();
}

void do_cycle() {
	map<pair<pair<int, int>, pair<int, int>>, point> plane_after = plane;
	sx--; ex++;
	sy--; ey++;
	sz--; ez++;
	sw--; ew++;
	for(int x = sx; x <= ex; x++) {
		for(int y = sy; y <= ey; y++) {
			for(int z = sz; z <= ez; z++) {
				for(int w = sw; w <= ew; w++) {
					int active_count = 0;
					for(int k = 0; k < 80; k++) {
						int nx = x + dx[k], ny = y + dy[k], nz = z + dz[k], nw = w + dw[k]; // neighbors of point
						if(plane[{{nx, ny}, {nz, nw}}].c == '#') active_count++;
					}
					if(plane[{{x, y}, {z, w}}].c == '#') {
						if(active_count != 2 && active_count != 3) plane_after[{{x, y}, {z, w}}].c = '.';
					}
					else {
						if(active_count == 3) plane_after[{{x, y}, {z, w}}].c = '#';
					}
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
				for(int cw = -1; cw <= 1; cw++) {
					if(cx == 0 && cy == 0 && cz == 0 && cw == 0) continue;
					dx[counter] = cx;
					dy[counter] = cy;
					dz[counter] = cz;
					dw[counter] = cw;
					counter++;
				}
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
				for(int w = sw; w <= ew; w++) {
					if(plane[{{x, y}, {z, w}}].c == '#') active++;
				}
			}
		}
	}
	cout << active << '\n';
}
