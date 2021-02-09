#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

void part1() {
	string line = " ";
	int valid = 0;
	vector<string> missing = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
	while(getline(cin, line)) {
		if(line == "") {
			bool ok = true;
			for(string missed : missing) {
				if(missed != "cid") {
					ok = false;
				}
			}
			if(ok) valid++;
			missing = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
		}
		stringstream ss(line);
		string part;
		while(ss >> part) {
			auto it = find(missing.begin(), missing.end(), part.substr(0,3));
			if(it != missing.end()) missing.erase(it); // first three letters
			// make sure to check if element exists
		}
	}
	// check for last passport
	bool ok = true;
	for(string missed : missing) {
		if(missed != "cid") {
			ok = false;
		}
	}
	if(ok) valid++;
	cout << valid << '\n';
}

int main() {
	part1();
}
