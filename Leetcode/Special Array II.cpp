class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(); // Get the size of the input array `nums`
        
        // `d` is an auxiliary array to store the start index of contiguous subarrays with the same parity
        vector<int> d(n); 
        iota(d.begin(), d.end(), 0); // Initialize `d` with indices 0, 1, ..., n-1
        
        // Traverse the array to identify contiguous subarrays of the same parity
        for (int i = 1; i < n; ++i) {
            if (nums[i] % 2 != nums[i - 1] % 2) { // Check if the current element has a different parity from the previous one
                d[i] = d[i - 1]; // If parities differ, update `d[i]` to point to the start of the current subarray
            }
        }

        vector<bool> ans; // To store the results of each query
        
        // Process each query in `queries`
        for (auto& q : queries) {
            // Query `q` contains [l, r]
            // Check if the contiguous subarray starting at `d[r]` includes the index `l`
            ans.push_back(d[q[1]] <= q[0]); 
        }
        
        return ans; // Return the results for all queries
    }
};