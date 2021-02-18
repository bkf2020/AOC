#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <map>
#include <set>
using namespace std;

struct four_nums {
	int a, b, c, d;
	four_nums(int w, int x, int y, int z) {
		a = w;
		b = x;
		c = y;
		d = z;
	}
};

string line;
bool start_checking = false;
bool read_yours = false;
vector<int> yours;
vector<four_nums> conditions;
vector<int> condition_with_departure;
vector<vector<int>> all_tickets;
map<int, int> condition_to_value;
map<int, set<int>> possible_conditions;

bool valid(int a, int b, int c, int d, int n) {
	return (n >= a && n <= b) || (n >= c && n <= d);
}

void read_input() {
	int curr_condition = 0;
	while(getline(cin, line)) {
		if(line != "your ticket:" && line != "" && line != "nearby tickets:" && !start_checking && !read_yours) {
			int a, b, c, d;
			string as, bs, cs, ds;
			
			stringstream ss(line);
			string condition_name; ss >> condition_name;
			if(condition_name == "departure") condition_with_departure.push_back(curr_condition);
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
			curr_condition++;
		}
		else if(read_yours) {
			istringstream ss(line);
			string value_s;
			while(getline(ss, value_s, ',')) {
				yours.push_back(stoi(value_s));
			}
			read_yours = false;
		}
		else if(line == "your ticket:") read_yours = true;
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
			bool works = true;
			for(int i = 0; i < ticket_values.size(); i++) {
				bool not_valid = true;
				for(int j = 0; j < conditions.size(); j++) {
					if(valid(conditions[j].a, conditions[j].b, conditions[j].c, conditions[j].d, ticket_values[i])) not_valid = false;
				}
				if(not_valid) {
					works = false;
					break;
				}
			}
			if(works) all_tickets.push_back(ticket_values);
		}
	}
}

int main() {
	read_input();
	for(int col = 0; col < all_tickets[0].size(); col++) {
		for(int con = 0; con < conditions.size(); con++) {
			bool works = true;
			for(int ticket = 0; ticket < all_tickets.size(); ticket++) {
				if(!valid(conditions[con].a, conditions[con].b, conditions[con].c, conditions[con].d, all_tickets[ticket][col])) {
					works = false;
					//cout <<conditions[con].a <<' ' << conditions[con].b << ' ' << conditions[con].c << ' ' << conditions[con].d << ' ' << all_tickets[ticket][col]<<'\n';
					break;
				}
			}
			if(works) {
				possible_conditions[col].insert(con);
			}
		}
	}
	
	bool not_assigned = true;
	while(not_assigned) {
		int to_remove = 0;
		for(int i = 0; i < all_tickets[0].size(); i++) {
			if(possible_conditions[i].size() == 1) {
				condition_to_value[*possible_conditions[i].begin()] = i;
				to_remove = *possible_conditions[i].begin();
				possible_conditions[i].clear();
				break;
			}
		}
		for(int i = 0; i < all_tickets[0].size(); i++) {
			if(possible_conditions[i].count(to_remove) == 1) {
				possible_conditions[i].erase(to_remove);
			}
		}

		not_assigned = false;
		for(int i = 0; i < all_tickets[0].size(); i++) {
			if(possible_conditions[i].size() > 1) {
				not_assigned = true;
				break;
			}
		}
	}
	
	long long ans = 1;
	for(int i = 0; i < condition_with_departure.size(); i++) {
		ans *= (long long) yours[condition_to_value[condition_with_departure[i]]];
	}
	cout << ans << '\n';
}
