#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main() {
	double ship_x = 0, ship_y = 0; // x and y values of ship
	double way_east = 10, way_north = 1; // waypoint east and north values

	string instruction;
	while(cin >> instruction) {
		char action = instruction[0];
		int num = stoi(instruction.substr(1, instruction.size() - 1));
		if(action == 'N') way_north += num;
		else if(action == 'S') way_north -= num;
		else if(action == 'E') way_east += num;
		else if(action == 'W') way_east -= num;
		else if(action == 'L') {
			num %= 360;
			int we = way_east, wn = way_north;
			if(num == 90) {
				way_east = -1 * wn; way_north = we;
			}
			else if(num == 180) {
				way_east = -1 * we; way_north = -1 * wn;
			}
			else if(num == 270) {
				way_east = wn; way_north = -1 * we;
			}
		}
		else if(action == 'R') {
			num = 360 - num;
			num %= 360;
			int we = way_east, wn = way_north;
			if(num == 90) {
				way_east = -1 * wn; way_north = we;
			}
			else if(num == 180) {
				way_east = -1 * we; way_north = -1 * wn;
			}
			else if(num == 270) {
				way_east = wn; way_north = -1 * we;
			}
		}	
		else if(action == 'F') {
			ship_x += num * way_east;
			ship_y += num * way_north;
		}
	}
	cout << abs(ship_x) + abs(ship_y) << '\n';
}
