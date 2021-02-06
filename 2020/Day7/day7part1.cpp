#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

void part1() {
	string line;
	map<string, vector<string>> bag_contain; // maps a bag to the bags it will contain
	map<string, bool> contain_shiny_gold;
	vector<string> all_bags;
	
	while(getline(cin, line)) {
		vector<string> parts;
		stringstream ss(line);
		string part;
		while(ss >> part) {
			parts.push_back(part);
		}
		
		int ptr = 0;
		string bag1 = "";
		while(parts[ptr] != "bags") {
			bag1 += parts[ptr];
			bag1 += " ";
			ptr++;
		}
		bag1.erase(bag1.end() - 1);
		ptr += 3; // next bag name, "bags contain [number]..."
		
		all_bags.push_back(bag1);
		while(ptr < parts.size()) {
			string bag2;
			while(ptr < parts.size() && parts[ptr].substr(0, 3) != "bag") {
				bag2 += parts[ptr];
				bag2 += " ";
				ptr++;
			}
			bag2.erase(bag2.end() - 1);
			if(bag2 != "no other") bag_contain[bag1].push_back(bag2); // no other bags case
			ptr += 2; // punctuation is counted...
		}
	}
	
	int ans = 0;
	for(int i = 0; i < (int) all_bags.size(); i++) {
		for(int j = 0; j < bag_contain[all_bags[i]].size(); j++) {
			if(bag_contain[all_bags[i]][j] == "shiny gold") {
				contain_shiny_gold[all_bags[i]] = true;
				ans++;
				break;
			}
		}
	}

	bool bag_added = true;
	while(bag_added) {
		bool temp = false;
		for(int i = 0; i < (int) all_bags.size(); i++) {
			for(int j = 0; j < bag_contain[all_bags[i]].size(); j++) {
				if(contain_shiny_gold[bag_contain[all_bags[i]][j]] && !contain_shiny_gold[all_bags[i]]) {
					contain_shiny_gold[all_bags[i]] = true;
					temp = true;
					ans++;
					break;
				}
			}
		}
		if(!temp) bag_added = false;
	}
	cout << ans << '\n';
}

int main() {
	part1();
}
