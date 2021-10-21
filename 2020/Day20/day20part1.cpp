#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<vector<char>>> tiles;
vector<int> all_id;

vector<vector<int>> grid_id;

vector<vector<char>> flip_tile(vector<vector<char>> tile) {
	vector<vector<char>> res;
	res.resize(10);
	for(int i = 0; i < 10; i++) res[i].resize(10);
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			res[i][j] = tile[i][9 - j];
		}
	}
	return res; }

vector<vector<char>> rotate(int deg, vector<vector<char>> tile) {
	vector<vector<char>> res;
	res.resize(10);
	for(int i = 0; i < 10; i++) res[i].resize(10);
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(deg == 0) res[i][j] = tile[i][j];
			else if(deg == 90) res[j][9 - i] = tile[i][j];
			else if(deg == 180) res[9 - i][9 - j] = tile[i][j];
			else res[i][j] = tile[j][9 - i];
		}
	}
	return res;
}

void try_all(vector<vector<int>> curr_grid_id, vector<vector<char>> curr_grid, map<int, bool> vis, int used) {
	if(used == 144) {
		grid_id = curr_grid_id;
		return;
	}
	for(int id : all_id) {
		if(!vis[id]) {
			vis[id] = true;
			vector<vector<char>> tile = tiles[id];
			int degs[4] = {0, 90, 180, 270};
			int flips[2] = {0, 1};
			for(int deg : degs) {
				vector<vector<char>> curr_tile = rotate(deg, tile);
				for(int flip : flips) {
					if(flip) curr_tile = flip_tile(curr_tile);
					int row = used / 12, col = used % 12;
					curr_grid_id[row][col] = id;
					for(int i = row * 10; i < (row + 1) * 10; i++) {
						for(int j = col * 10; j < (col + 1) * 10; j++) {
							curr_grid[i][j] = curr_tile[i - row * 10][j - col * 10];
						}
					}
					bool works = true;
					if(row != 0) {
						// top of this tile vs bottom of tile above
						for(int i = 0; i < 10; i++) {
							if(curr_grid[row * 10 - 1][col * 10 + i] != curr_grid[row * 10][col * 10 + i]) {
								works = false;
								break;
							}
						}
					}
					if(col != 0) {
						for(int i = 0; i < 10; i++) {
							if(curr_grid[row * 10 + i][col * 10 - 1] != curr_grid[row * 10 + i][col * 10]) {
								works = false;
								break;
							}
						}
					}
					if(works) {
						try_all(curr_grid_id, curr_grid, vis, used + 1);
					}
				}
			}
			vis[id] = false;
		}
	}
}

int main() {
	for(int i = 0; i < 144; i++) {
		string the_word_tile; cin >> the_word_tile;
		string id_str; cin >> id_str; id_str.pop_back();
		int id = stoi(id_str);
		all_id.push_back(id);

		vector<vector<char>> curr_tile;
		for(int j = 0; j < 10; j++) {
			string row; cin >> row;
			vector<char> curr_row;
			for(int k = 0; k < 10; k++) {
				curr_row.push_back(row[k]);
			}
			curr_tile.push_back(curr_row);
		}
		tiles[id] = curr_tile;
	}
	grid_id.resize(12);
	for(int i = 0; i < 12; i++) grid_id[i].resize(12);
	vector<vector<int>> empty;
	empty.resize(12);
	for(int i = 0; i < 12; i++) empty[i].resize(12);
	vector<vector<char>> empty_grid;
	empty_grid.resize(120);
	for(int i = 0; i < 120; i++) empty_grid[i].resize(120);
	map<int, bool> empty_vis;
	try_all(empty, empty_grid, empty_vis, 0);
	long long ans = (long long) grid_id[0][0] * (long long) grid_id[11][0] * (long long) grid_id[0][11] * (long long) grid_id[11][11];
	cout << ans << '\n';
}
