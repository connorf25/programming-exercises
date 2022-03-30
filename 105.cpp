#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int l, h, r;
	vector<int> height_map;

	while(fscanf(stdin,"%d %d %d", &l, &h, &r)==3) {
		// Add zeros until the right side of the building
		while(r > height_map.size()) {
			height_map.push_back(0);
		}
		// Check if building height is greater than any existing buildings at the position
		for (int i = l; i < r; i++) {
			if (height_map[i] < h) {
				height_map[i] = h;
			}
		}
	}
	// Add final 0 to represent end of last building
	height_map.push_back(0);
	bool isFirst = true;
	for (int i = 1; i < height_map.size(); i++) {
		if(height_map[i-1] != height_map[i]) {
			if (!isFirst) {
				cout << " ";
			}
			cout << i << " " << height_map[i];
			isFirst = false;
		}
	}
	cout << endl;
}