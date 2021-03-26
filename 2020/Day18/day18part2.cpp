#include <string>
#include <iostream>
#include <ctype.h>
#include <stack>
#include <map>
using namespace std;

long long evaluate(string expression) {
	long long result = 0;
	long long second_num = 0;
	char operation = 0;
	int stage = 0;
	
	stack<int> left;
	map<int, int> left_to_right;
	for(int i = 0; i < (int) expression.size(); i++) {
		if(expression[i] == '(') left.push(i);
		else if(expression[i] == ')') {
			left_to_right[left.top()] = i;
			left.pop();
		}
	}
	
	// stage 0 is looking for operator,
	// stage 1 is looking for second number
	
	int i = 0;
	if(expression[i] == '(') {
		int end = left_to_right[i];
		string new_expression = expression.substr(i + 1, end - i - 1);
		result = evaluate(new_expression);
		i = end + 1; // add one for space after
	}
	else if(isdigit(expression[i])) {
		long long num = 0;
		while(isdigit(expression[i])) {
			num *= 10;
			num += expression[i] - '0';
			i++;
		}
		result = num;
	}
	while(i < (int) expression.size()) {
		if(stage == 0) {
			i++; // first add one for space before operator
			operation = expression[i]; // this is operator
			i += 2; // add one for space after
			if(operation == '*') {
				string new_expression = expression.substr(i);
				second_num = evaluate(new_expression);
				result *= second_num;
				i = (int) expression.size();
			}
		}
		else if(stage == 1) {
			if(expression[i] == '(') {
				int end = left_to_right[i];
				string new_expression = expression.substr(i + 1, end - i - 1);
				second_num = evaluate(new_expression);
				i = end + 1; // add one for space after
			}
			else if(isdigit(expression[i])) {
				long long num = 0;
				while(isdigit(expression[i])) {
					num *= 10;
					num += expression[i] - '0';
					i++;
				}
				second_num = num;
			}
			// calculate
			if(operation == '+') result += second_num;
		}
		stage++;
		stage %= 2;
	}
	return result;
}

int main() {
	string line;
	long long sum = 0;
	while(getline(cin, line)) {
		long long ans = evaluate(line);
		sum += ans;
	}
	cout << sum << '\n';
}
