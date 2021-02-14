#include <ctype.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void go_through(vector<int> x_loc, string loc_string, vector<string> &all_locations, int index) {
	if(index == x_loc.size()) {
		all_locations.push_back(loc_string);
		return;
	}
	loc_string[x_loc[index]] = '0';
	go_through(x_loc, loc_string, all_locations, index + 1);
	loc_string[x_loc[index]] = '1';
	go_through(x_loc, loc_string, all_locations, index + 1);
}

int main() {
	string mask, mem_loc_string, line;
	long long num;
	int loc = 0;
	map<long long, long long> mem;
	long long pow2[36]; // powers of 2 up to 36
	pow2[0] = 1;
	for(int i = 1; i < 36; i++) {
		pow2[i] = 2 * pow2[i - 1];
	}

	while(getline(cin, line)) {
		stringstream ss(line);
		string part; ss >> part;
		if(part == "mask") {
			ss >> part; // equal sign
			ss >> mask;
		}
		else {
			mem_loc_string = part;
			ss >> part; // equal sign
			ss >> num;
			
			loc = 0;
			for(int i = 0; i < (int) mem_loc_string.size(); i++) {
				if(isdigit(mem_loc_string[i])) {
					loc *= 10;
					loc += (int) (mem_loc_string[i] - '0');
				}
			}
			
			string loc_string = "000000000000000000000000000000000000";
			while(loc > 0) {
				auto it = upper_bound(pow2, pow2 + 36, loc); it--;
				auto k = it - pow2;
				loc_string[35 - k] = '1'; // from https://cses.fi/book.pdf
				loc -= *it;
			}
			
			vector<int> x_loc;
			for(int i = 0; i < 36; i++) {
				if(mask[i] == '1') loc_string[i] = '1';
				else if(mask[i] == 'X') x_loc.push_back(i);
			}
			vector<string> all_locations;
			go_through(x_loc, loc_string, all_locations, 0);
			
			for(string location_string : all_locations) {
				long long location = 0;
				for(int i = 0; i < location_string.size(); i++) {
					location += pow2[35 - i] * (long long) (location_string[i] - '0');
				}
				mem[location] = num;
			}
		}
	}

	long long ans = 0;
	
	// from https://www.cplusplus.com/reference/map/map/begin/
	for(map<long long, long long>::iterator it = mem.begin(); it != mem.end(); it++) {
		ans += it->second;
	}
	cout << ans << '\n';
}
