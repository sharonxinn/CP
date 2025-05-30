#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 3D_INTEGER_ARRAY arr as parameter.
 */

int hourglassSum(vector<vector<vector<int>>> arr) {
    int maxSum = INT_MIN;
    // 3D hourglass pattern:
    // Top: arr[z][x][y], arr[z][x][y+1], arr[z][x][y+2]
    //      arr[z][x+1][y+1]
    //      arr[z][x+2][y], arr[z][x+2][y+1], arr[z][x+2][y+2]
    // Middle: arr[z+1][x+1][y+1]
    // Bottom: same as Top but at z+2
    for (int z = 0; z <= 3; z++) {
        for (int x = 0; x <= 3; x++) {
            for (int y = 0; y <= 3; y++) {
                int sum = 0;
                // Top layer
                sum += arr[z][x][y] + arr[z][x][y+1] + arr[z][x][y+2];
                sum += arr[z][x+1][y+1];
                sum += arr[z][x+2][y] + arr[z][x+2][y+1] + arr[z][x+2][y+2];
                // Middle layer
                sum += arr[z+1][x+1][y+1];
                // Bottom layer
                sum += arr[z+2][x][y] + arr[z+2][x][y+1] + arr[z+2][x][y+2];
                sum += arr[z+2][x+1][y+1];
                sum += arr[z+2][x+2][y] + arr[z+2][x+2][y+1] + arr[z+2][x+2][y+2];
                maxSum = max(maxSum, sum);
            }
        }
    }
    return maxSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<vector<int>>> arr(6, vector<vector<int>>(6, vector<int>(6)));

    for (int z = 0; z < 6; z++) {
        for (int x = 0; x < 6; x++) {
            string arr_row_temp_temp;
            getline(cin, arr_row_temp_temp);
            vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));
            for (int y = 0; y < 6; y++) {
                int arr_row_item = stoi(arr_row_temp[y]);
                arr[z][x][y] = arr_row_item;
            }
        }
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}