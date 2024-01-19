#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minTrafficFlow(vector<vector<int>>& trafficGrid, int startX, int startY, int endX, int endY) {
    int n = trafficGrid.size();
    int m = trafficGrid[0].size();

    // Create a 2D vector to store the minimum traffic flow at each junction
    vector<vector<int>> minFlow(n, vector<int>(m, INT_MAX));

    // Set the starting point
    minFlow[startX - 1][startY - 1] = trafficGrid[startX - 1][startY - 1];

    // Update the minimum traffic flow values
    for (int i = startX - 1; i < n; ++i) {
        for (int j = startY - 1; j < m; ++j) {
            if (i < n - 1) {
                minFlow[i + 1][j] = min(minFlow[i + 1][j], minFlow[i][j] + trafficGrid[i + 1][j]);
            }
            if (j < m - 1) {
                minFlow[i][j + 1] = min(minFlow[i][j + 1], minFlow[i][j] + trafficGrid[i][j + 1]);
            }
        }
    }

    // Check if there is a valid path to the destination
    if (minFlow[endX - 1][endY - 1] == INT_MAX) {
        return -1;
    }

    return minFlow[endX - 1][endY - 1];
}

int main() {
    int n, m;
    cin >> n >> m;

    // Read the traffic grid
    vector<vector<int>> trafficGrid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> trafficGrid[i][j];
        }
    }

    int startX, startY, endX, endY;
    cin >> startX >> startY ;
    cin >> endX >> endY;

    // Calculate the minimum traffic flow
    int result = minTrafficFlow(trafficGrid, startX, startY, endX, endY);

    // Print the result
    cout << result << endl;

    return 0;
}
