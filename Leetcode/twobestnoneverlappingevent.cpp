class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Step 1: Sort events by start time
        sort(events.begin(), events.end());

        int n = events.size();
        vector<int> sum(n + 1, 0);

        // Step 2: Populate `sum` to store maximum event value from index `i` to the end
        for (int i = n - 1; i >= 0; --i) {
            sum[i] = max(sum[i + 1], events[i][2]);
        }

        int ans = 0;

        // Step 3: Iterate through each event and find the best possible second event
        for (int i = 0; i < n; ++i) {
            int value = events[i][2]; // Value of the current event
            int l = 0, r = n;

            // Binary search to find the first event starting after the current event's end
            while (l < r) {
                int mid = (l + r) / 2;
                if (events[mid][0] > events[i][1]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }

            // Add the best possible value from the second event, if it exists
            if (l < n) {
                value += sum[l];
            }

            // Update the answer
            ans = max(ans, value);
        }

        return ans;
    }
};