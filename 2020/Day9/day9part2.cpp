#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	vector<long long> numbers;
	long long temp = 0, fail = 0;
	while(cin >> temp) {
		numbers.push_back(temp);
	}
	for(int i = 25; i < numbers.size(); i++) {
		bool works = false;
		for(int j = i - 25; j < i; j++) {
			for(int k = j + 1; k < i; k++) {
				if(numbers[j] + numbers[k] == numbers[i]) {
					works = true;
					break;
				}
			}
			if(works) break;
		}
		if(!works) {
			fail = numbers[i];
			break;
		}
	}
	for(int i = 0; i < numbers.size(); i++) {
		for(int j = i + 1; j < numbers.size(); j++) {
			long long sum = 0, minimum = LLONG_MAX, maximum = 0;
			for(int k = i; k <= j; k++) {
				sum += numbers[k];
				minimum = min(minimum, numbers[k]);
				maximum = max(maximum, numbers[k]);
			}
			if(sum == fail) {
				cout << minimum + maximum << '\n';
				exit(0);
			}
		}
	}
}
