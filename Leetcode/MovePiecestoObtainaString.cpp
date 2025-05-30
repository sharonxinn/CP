//Solution 1
class Solution {
public:
    bool canChange(string start, string target) {
        // Remove all '_' from both strings to compare non-placeholder characters
        string startNoUnderscore, targetNoUnderscore;
        for (char c : start) if (c != '_') startNoUnderscore += c;
        for (char c : target) if (c != '_') targetNoUnderscore += c;
        
        // Check if the non-placeholder characters match
        if (startNoUnderscore != targetNoUnderscore) return false;
        
        // Check valid movements for 'L' and 'R'
        int startPos = 0, targetPos = 0;
        for (int i = 0; i < start.size(); ++i) {
            if (start[i] == 'L' || start[i] == 'R') {
                // Find the corresponding position in the target
                while (target[targetPos] == '_') ++targetPos;
                if ((start[i] == 'L' && i < targetPos) || 
                    (start[i] == 'R' && i > targetPos)) 
                    return false;
                ++targetPos;
            }
        }
        
        return true;
    }
};


//Solution 2
class Solution {
public:
    bool canChange(string start, string target) {
        // Extract positions of 'L' and 'R' from both strings
        auto startPositions = extractPositions(start);
        auto targetPositions = extractPositions(target);

        // If the number of 'L' and 'R' don't match, return false
        if (startPositions.size() != targetPositions.size()) return false;

        // Check each position for valid movement
        for (int j = 0; j < startPositions.size(); j++) {
            auto startPosition = startPositions[j];
            auto targetPosition = targetPositions[j];

            // Ensure the same character ('L' or 'R') is being compared
            if (startPosition.first != targetPosition.first) return false;

            // Check movement constraints
            if (startPosition.first == 1 && startPosition.second < targetPosition.second) 
                return false; // 'L' can't move right
            if (startPosition.first == 2 && startPosition.second > targetPosition.second) 
                return false; // 'R' can't move left
        }

        // Verify that `start` can be rearranged into `target`
        int i = 0, j = 0;
        while (i < start.size() && j < target.size()) {
            // Skip underscores in both strings
            while (i < start.size() && start[i] == '_') i++;
            while (j < target.size() && target[j] == '_') j++;

            // If one ends but the other doesn't, return false
            if (i < start.size() && j < target.size()) {
                if (start[i] != target[j]) return false;
            } else {
                if (i < start.size() || j < target.size()) return false;
            }

            i++;
            j++;
        }

        return true;
    }

    vector<pair<int, int>> extractPositions(string s) {
        vector<pair<int, int>> positions;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'L')
                positions.push_back({1, i}); // 'L' is represented as 1
            else if (s[i] == 'R')
                positions.push_back({2, i}); // 'R' is represented as 2
        }
        return positions;
    }
};