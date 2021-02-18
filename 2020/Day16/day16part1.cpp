#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;

bool valid(int a, int b, int c, int d, int n) {
	return (n >= a && n <= b) || (n >= c && n <= d);
}

struct four_nums {
	int a, b, c, d;
	four_nums(int w, int x, int y, int z) {
		a = w;
		b = x;
		c = y;
		d = z;
	}
};

int main() {
	string line;
	vector<four_nums> conditions;
	bool start_checking = false;
	bool dont_read = false;
	int error_rate = 0;
	while(getline(cin, line)) {
		if(line != "your ticket:" && line != "" && line != "nearby tickets:" && !start_checking && !dont_read) {
			int a, b, c, d;
			string as, bs, cs, ds;
			
			stringstream ss(line);
			string condition_name; ss >> condition_name;
			while(condition_name[condition_name.size() - 1] != ':') ss >> condition_name;
			
			string ab; ss >> ab;
			istringstream ssab(ab);
			getline(ssab, as, '-'); 
			getline(ssab, bs, '-');
			a = stoi(as);
			b = stoi(bs);
			
			string or_word; ss >> or_word;
			
			string cd; ss >> cd;
			istringstream sscd(cd);
			getline(sscd, cs, '-'); 
			getline(sscd, ds, '-');
			c = stoi(cs);
			d = stoi(ds);
			conditions.push_back(four_nums(a,b,c,d));
		}
		else if(line == "your ticket:") dont_read = true;
		else if(line == "nearby tickets:") {
			start_checking = true;
		}
		else if(start_checking) {
			vector<int> ticket_values;
			istringstream ss(line);
			string value_s;
			while(getline(ss, value_s, ',')) {
				ticket_values.push_back(stoi(value_s));
			}
			for(int i = 0; i < ticket_values.size(); i++) {
				bool not_valid = true;
				for(int j = 0; j < conditions.size(); j++) {
					if(valid(conditions[j].a, conditions[j].b, conditions[j].c, conditions[j].d, ticket_values[i])) not_valid = false;
				}
				if(not_valid) error_rate += ticket_values[i];
			}
		}
	}
	cout << error_rate << '\n';
}
