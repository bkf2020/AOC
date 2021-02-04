#include <string>
#include <iostream>
#include <sstream>
using namespace std;

void part2() {
	// string stream info from https://www.geeksforgeeks.org/stringstream-c-applications/
	string line;
	int valid = 0;
	while(getline(cin, line)) { // from https://www.geeksforgeeks.org/getline-string-c/
		string line2 = line;
		stringstream ss(line2);
		string part, password;
		int num1 = 0, num2 = 0;
		char desired;
		for(int counter = 0; counter < 3; counter++) {
			ss >> part;
			if(counter == 0) {
				string num1_str = "", num2_str = "";
				bool reached = false;
				for(int i = 0; i < part.size(); i++) {
					if(part[i] == '-') {
						reached = true;
						continue;
					}
					if(reached) {
						num2_str += part[i];
					}
					else {
						num1_str += part[i];
					}
				}
				stringstream ss1(num1_str); // from https://www.geeksforgeeks.org/converting-strings-numbers-cc/
				stringstream ss2(num2_str); 
				ss1 >> num1;
				ss2 >> num2;
			}
			else if(counter == 1) {
				desired = part[0];
			}
			else if(counter == 2) {
				password = part;
			}
		}
		
		int char_count = 0;
		if(password[num1 - 1] == desired) char_count++;
		if(password[num2 - 1] == desired) char_count++;
		
		if(char_count == 1) {
			valid++;
		}
	}
	cout << valid << '\n';
}

int main() {
	part2();
}
