#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void part1() {
	int max_id = 0;
	string line;
	while(cin >> line) {
		int row_f = 0, row_b = 127, col_l = 0, col_r = 7;
		int row_final = 0, col_final = 0;
		for(int i = 0; i < 10; i++) {
			if(line[i] == 'F') {
				if(row_f != row_b - 1) {
					row_b = (row_f + row_b) / 2;
				}
				else {
					row_final = row_f;
				}
			}
			else if(line[i] == 'B') {
				if(row_f != row_b - 1) {
					row_f = (row_f + row_b) / 2 + 1;
				}
				else {
					row_final = row_b;
				}
			}
			else if(line[i] == 'R') {
				if(col_l != col_r - 1) {
					col_l = (col_l + col_r) / 2 + 1;
				}
				else {
					col_final = col_r;
				}
			}
			else if(line[i] == 'L') {
				if(col_l != col_r - 1) {
					col_r = (col_l + col_r) / 2;
				}
				else {
					col_final = col_l;
				}
			}
		}
		int curr_id = 8 * row_final + col_final;
		max_id = max(curr_id, max_id);
	}
	cout << max_id << '\n';
}

int main() {
	part1();
}
