/*
    Time Complexity : O(N*log(N))
    Space Complexity : O(N)

    Where, N is the size of the array.
*/

#include<map>
int maxFriends(int n, vector<int> &s, vector<int> &e) {
    map<int, int> numOfPeoples;
    for (int i = 0; i < n; i++) {

        // Increment the day when a friend is available.
        numOfPeoples[ s[i] ]++;

        // Decrement the day when that friend becomes unavailable.
        numOfPeoples[ e[i] + 1 ]--;
    }

    // Counter to store the current available friends.
    int counter = 0;

    // Integer to store the final answer.
    int mx = 0;
    map<int, int>::iterator itr = numOfPeoples.begin();

    // Iterate over the map.
    while ( itr != numOfPeoples.end()) {
        counter += itr->second;
        mx = max(mx, counter);
        itr++;
    }

    return mx;
}
