#include <iostream>
#include <vector>
using namespace std;

class Point{
	public:
		int x;
		int y;
		Point(int newX, int newY) {
			x = newX;
			y = newY;
		}
};

class Edge{
	public:
		int node_1_index;
		int node_2_index;
		int distance;
}

int main() {
	// Read n as number of people
	int n;
	vector<Point> points(n);
	vector<vector<int>> dist_matrix;
	// Push each line to points
	int lineX, lineY;
	points.push_back(new Point(lineX, lineY));
	return 0;
}