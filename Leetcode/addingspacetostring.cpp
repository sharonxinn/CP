class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";
        for (int i =0; i<s.size();i++){
            if(int j=0; j <spaces.size() && i==spaces[j]){
                result += " ";
                ++j
            }
            result += s[i];
        }
        return result;
    }
};