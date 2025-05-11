class Solution {
public:int climbStairs(int n) {
    vector<int> v(n + 1, -1); // Create a table to store results
    v[0] = 1, v[1] = 1; // Base cases

    for(int i = 2; i <= n; i++) {
        v[i] = v[i - 1] + v[i - 2]; // Fill the table
    }

    return v[n]; // Return result for step n
}

};
