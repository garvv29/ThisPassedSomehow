class Solution {
public:
    int scheduleCourse(vector<vector<int>>& cs) {
        sort(cs.begin(), cs.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        priority_queue<int> pq;   // max-heap for durations
        int days = 0;

        for(auto &c : cs)
        {
            int duration = c[0];
            int lastDay = c[1];

            // If we can take it directly
            if(days + duration <= lastDay) {
                pq.push(duration);
                days += duration;
            }
            // Else replace the longest course if current one is shorter
            else if(!pq.empty() && pq.top() > duration) {
                days -= pq.top();
                pq.pop();
                pq.push(duration);
                days += duration;
            }
        }

        return pq.size();
    }
};

