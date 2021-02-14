#include <ctype.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

int main() {
	string mask, mem_loc_string, line;
	long long num;
	int loc = 0;
	map<int, long long> mem;
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
			
			string num_string = "000000000000000000000000000000000000";
			while(num > 0) {
				auto it = upper_bound(pow2, pow2 + 36, num); it--;
				auto k = it - pow2;
				num_string[35 - k] = '1'; // from https://cses.fi/book.pdf
				num -= *it;
			}
			
			for(int i = 0; i < 36; i++) {
				if(mask[i] == '0') num_string[i] = '0';
				else if(mask[i] == '1') num_string[i] = '1';
				num += pow2[35 - i] * (long long) (num_string[i] - '0');
			}
			mem[loc] = num;
		}
	}

	long long ans = 0;
	
	// from https://www.cplusplus.com/reference/map/map/begin/
	for(map<int, long long>::iterator it = mem.begin(); it != mem.end(); it++) {
		ans += it->second;
	}
	cout << ans << '\n';
}
