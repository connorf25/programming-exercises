#include <iostream>
// #include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <functional>
#include <unordered_set>
using namespace std;

struct Point{
	int x;
	int y;
	Point(int newX, int newY) {
		x = newX;
		y = newY;
	}
};

struct Edge{
	int n1_index;
	int n2_index;
	int distance;
	Edge(int n1i, int n2i, int dist) {
		n1_index = n1i;
		n2_index = n2i;
		distance = dist;
	}
};

bool operator<(const Edge& a, const Edge& b) {
	return a.distance > b.distance;
}

int calcDistance(Point p1, Point p2) {
	return pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
}

int main() {
	int n, lineX, lineY;
	int max_dist = 0;
	// Read n as number of people
	fscanf(stdin,"%d", &n);
	// Define points and edges of graph
	vector<Point> points;
	priority_queue<Edge> edges;
	unordered_set<int> grouped_points;
	// Push each line to points
	while(fscanf(stdin,"%d %d", &lineX, &lineY)==2) {
		Point newPoint(lineX, lineY);
		// Calculate distance from new node to every other node
		for(int i = 0; i < points.size(); i++) {
			Edge newEdge(i, points.size(), calcDistance(points[i], newPoint));
			edges.push(newEdge);
		}
		points.push_back(newPoint);
	}
	while(!edges.empty()) {
		Edge current = edges.top();
		edges.pop();
		// If either point is already grouped
		if (grouped_points.count(current.n1_index) || grouped_points.count(current.n2_index)) {
			max_dist = max(max_dist, current.distance);
		} else {
			grouped_points.insert(current.n1_index);
			grouped_points.insert(current.n2_index);
		}
	}
	cout << max_dist << endl;
	return 0;
}