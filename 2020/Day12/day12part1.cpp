#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main() {
	double x = 0, y = 0; // x and y values of ship
	int dir = 0; // degree of ship from east
	const double PI = 3.141592653589793238463;

	string instruction;
	while(cin >> instruction) {
		char action = instruction[0];
		int num = stoi(instruction.substr(1, instruction.size() - 1));
		if(action == 'N') y += (double) num;
		else if(action == 'S') y -= (double) num;
		else if(action == 'E') x += (double) num;
		else if(action == 'W') x -= (double) num;
		else if(action == 'L') dir += num;
		else if(action == 'R') dir -= num;
		else if(action == 'F') {
			x += num * cos(dir * PI/180);
			y += num * sin(dir * PI/180);
		}
	}
	cout << abs(x) + abs(y) << '\n';
}
