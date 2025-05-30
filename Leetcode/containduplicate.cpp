class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> hashSet;  // Correct initialization of unordered_map

        for(int i = 0; i < nums.size(); i++) {  // Correct usage of .size() instead of .length
            if(hashSet.find(nums[i]) != hashSet.end())  // Use find() to check if key exists
                return true;
            else
                hashSet[nums[i]] = true;  // Add the element to the map
        }

        return false;
    }
};