// frequency map
#include <iostream>         // For input and output operations
#include <vector>           // For using the vector container
#include <unordered_map>    // For using the unordered_map (hash map)
#include <algorithm>        // For using the min function
using namespace std;        // Use the standard namespace

int main() {
    int t;                  // Number of test cases
    cin >> t;               // Read the number of test cases
    while (t--) {           // Loop for each test case
        int n, k;           // n: number of integers, k: target sum
        cin >> n >> k;      // Read n and k
        vector<int> x(n);   // Vector to store the n integers
        unordered_map<int, int> freq; // Hash map to store frequency of each integer
        for (int i = 0; i < n; ++i) { // Loop to read all integers
            cin >> x[i];              // Read integer
            freq[x[i]]++;             // Increment frequency count for this integer
        }
        int score = 0;                // Initialize score to 0
        for (auto& [num, count] : freq) { // Iterate over each unique number and its count
            int complement = k - num;      // Calculate the complement needed to sum to k
            if (freq.count(complement)) {  // If complement exists in the map
                if (num == complement) {   // If number and complement are the same
                    score += freq[num] / 2; // Add half the count (number of pairs)
                } else if (num < complement) { // Avoid double counting, only process if num < complement
                    int pairs = min(freq[num], freq[complement]); // Number of pairs is min of counts
                    score += pairs;           // Add pairs to score
                }
            }
        }
        cout << score << endl; // Output the score for this test case
    }
    return 0; // End of program
}