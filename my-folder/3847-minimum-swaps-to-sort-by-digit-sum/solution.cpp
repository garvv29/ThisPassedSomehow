class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Create a vector of (digitSum, value)
        vector<pair<int, int>> sortedArray;
        for (int num : nums) {
            sortedArray.push_back({digitSum(num), num});
        }

        // Sort based on digit sum, then value
        sort(sortedArray.begin(), sortedArray.end());

        // Map from value to target index in the sorted array
        unordered_map<int, int> valueToIndex;
        for (int i = 0; i < n; ++i) {
            valueToIndex[sortedArray[i].second] = i;
        }

        // Visited array for cycle detection
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            // If already in the right place or visited, skip
            if (visited[i] || valueToIndex[nums[i]] == i) continue;

            int cycle_size = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = valueToIndex[nums[j]];
                cycle_size++;
            }

            if (cycle_size > 1)
                swaps += cycle_size - 1;
        }

        return swaps;
    }
};

