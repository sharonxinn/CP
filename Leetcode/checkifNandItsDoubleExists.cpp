class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (int x : arr){
            // If 2*x is present in the set or x is even and x/2 is present in the set, return true.
            // Otherwise, insert x into the set.
            // If the loop completes, return false.
            if (s.contains(2*x) || (x%2 == 0 && s.contains(x/2))){
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};