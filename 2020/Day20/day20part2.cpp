#include <vector>
#include <iostream>
using namespace std;

/* USAGE
   run day20picture.cpp
   on your puzzle input

   then run this program day20 part 2
   on your puzzle input
*/

vector<vector<char>> flip(vector<vector<char>> tile) {
	vector<vector<char>> res;
	res.resize(96);
	for(int i = 0; i < 96; i++) res[i].resize(96);
	for(int i = 0; i < 96; i++) {
		for(int j = 0; j < 96; j++) {
			res[i][j] = tile[i][95 - j];
		}
	}
	return res;
}

vector<vector<char>> rotate(int deg, vector<vector<char>> tile) {
	vector<vector<char>> res;
	res.resize(96);
	for(int i = 0; i < 96; i++) res[i].resize(96);
	for(int i = 0; i < 96; i++) {
		for(int j = 0; j < 96; j++) {
			if(deg == 0) res[i][j] = tile[i][j];
			else if(deg == 90) res[j][95 - i] = tile[i][j];
			else if(deg == 180) res[95 - i][95 - j] = tile[i][j];
			else res[i][j] = tile[j][95 - i];
		}
	}
	return res;
}

int main() {
	vector<vector<char>> input; input.resize(96);
	for(int i = 0; i < 96; i++) {
		string line; cin >> line;
		input[i].resize(96);
		for(int j = 0; j < 96; j++) {
			input[i][j] = line[j];
		}
	}

/*
                  #
#    ##    ##    ###
 #  #  #  #  #  #

 must be #:
 row, col
 (i,j)
 (i + 1, j - 18)
 (i + 1, j - 13)
 (i + 1, j - 12)
 (i + 1, j - 7)
 (i + 1, j - 6)
 (i + 1, j - 1)
 (i + 1, j)
 (i + 1, j + 1)
 (i + 2, j - 17)
 (i + 2, j - 14)
 (i + 2, j - 11)
 (i + 2, j - 8)
 (i + 2, j - 5)
 (i + 2, j - 2)
 */
	int deg[4] = {0, 90, 180, 270};
	int cx[15] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};
	int cy[15] = {0, -18, -13, -12, -7, -6, -1, 0, 1, -17, -14, -11, -8, -5, -2};
	for(int d = 0; d < 4; d++) {
		for(int f = 0; f < 2; f++) {
			vector<vector<char>> new_input = rotate(deg[d], input);
			if(f) new_input = flip(new_input);

			bool is_ans = false;
			for(int i = 0; i < 96; i++) {
				for(int j = 0; j < 96; j++) {
					bool works = true;
					for(int k = 0; k < 15; k++) {
						int nx = i + cx[k], ny = j + cy[k];
						if(nx < 0 || ny < 0 || nx >= 96 || ny >= 96 || new_input[nx][ny] != '#') {
							works = false;
							break;
						}
					}
					if(works) {
						for(int k = 0; k < 15; k++) {
							int nx = i + cx[k], ny = j + cy[k];
							new_input[nx][ny] = 'O';
						}
						is_ans = true;
					}
				}
			}

			int ans = 0;
			for(int i = 0; i < 96; i++) {
				for(int j = 0; j < 96; j++) {
					if(new_input[i][j] == '#') {
						ans++;
					}
				}
			}
			if(is_ans) cout << ans << '\n';
		}
	}
}
