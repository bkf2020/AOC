#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

#define PSI pair<int, string>
#define FI first
#define SE second

typedef long long ll;

map<string, vector<PSI>> bag_contain; // maps a bag to the bags it will contain
map<string, bool> is_it_empty;
map<string, ll> memo;
map<string, bool> visited;

ll bag_num(string bag) {
	if(is_it_empty[bag]) return 0;
	ll return_value = 0;
	for(PSI curr : bag_contain[bag]) {
		return_value += (ll) curr.FI;
		if(!visited[curr.SE]) {
			memo[curr.SE] = bag_num(curr.SE);
			visited[curr.SE] = true;
		}
		return_value += (ll) curr.FI * memo[curr.SE];	
	}
	return return_value;
}

void part2() {
	string line;
	vector<string> all_bags;
	
	while(getline(cin, line)) {
		vector<string> parts;
		stringstream ss(line);
		string part;
		while(ss >> part) {
			parts.push_back(part);
		}
		
		PSI curr;
		int ptr = 0;
		string bag1 = "";
		while(parts[ptr] != "bags") {
			bag1 += parts[ptr];
			bag1 += " ";
			ptr++;
		}
		bag1.erase(bag1.end() - 1);
		ptr += 2; // next bag name, "bags contain [number]..."
		
		if(parts[ptr] != "no") {
			curr.FI = stoi(parts[ptr]);		
			ptr++;
			
			while(ptr < parts.size()) {
				string bag2;
				while(ptr < parts.size() && parts[ptr].substr(0, 3) != "bag") {
					bag2 += parts[ptr];
					bag2 += " ";
					ptr++;
				}
				bag2.erase(bag2.end() - 1);
				if(bag2 != "no other") {
					curr.SE = bag2;
					bag_contain[bag1].push_back(curr); // no other bags case
				}
				ptr++; // punctuation is counted...
				if(ptr < parts.size()) {
					curr.FI = stoi(parts[ptr]);
					ptr++;
				}
			}
		}
		else {
			is_it_empty[bag1] = true;
		}
	}
	ll ans = bag_num("shiny gold");
	cout << ans << '\n';
}

int main() {
	part2();
}
