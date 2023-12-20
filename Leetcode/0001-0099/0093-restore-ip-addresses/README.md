# Restore IP Addresses

[Link](https://leetcode.com/problems/restore-ip-addresses/description/)

## Description

A valid IP address consists of exactly four integers separated by single dots. Each integer is between `0` and `255` (inclusive) and cannot have leading zeros.

- For example, `"0.1.2.201"` and `"192.168.1.1"` are valid IP addresses, but `"0.011.255.245"`, `"192.168.1.312"` and `"192.168@1.1"` are invalid IP addresses.

Given a string `s` containing only digits, return all possible valid IP addresses that can be formed by inserting dots into `s`. You are not allowed to reorder or remove any digits in `s`. You may return the valid IP addresses in any order.

Example 1:

- Input: `s = "25525511135"`
- Output: `["255.255.11.135","255.255.111.35"]`

Example 2:

- Input: `s = "0000"`
- Output: `["0.0.0.0"]`

Example 3:

- Input: `s = "101023"`
- Output: `["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]`

Constraints:

- `1 <= s.length <= 20`
- `s` consists of digits only.

## Solution

### Way 1

```C++
class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;
    void backtracking(const string &s, int startIndex) {
        if (startIndex == s.length() && path.size() == 4) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.length(); i++) {
            if (path.size() >= 4) break;
            if (!isValidIP(s, startIndex, i)) continue;
            path.push_back(s.substr(startIndex, i - startIndex + 1));
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    bool isValidIP(const string &s, int startIndex, int i) {
        int len = i - startIndex + 1;
        if (len > 3 || len == 0) return false;
        if (len > 1 && s[startIndex] == '0') return false;
        if (stoi(s.substr(startIndex, len)) > 255) return false;
        return true;
    }

    vector<string> vecStr2Str(const vector<vector<string>> &arr) {
        vector<string> result{};
        for (vector<string> elm : arr) {
            string temp{};
            for (int i = 0; i < elm.size(); i++) {
                temp += elm[i];
                if (i < elm.size() - 1) temp += ".";
            }
            result.push_back(temp);
        }
        return result;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0);
        return vecStr2Str(res);
    }
};
```

Modified version:

```C++
class Solution {
private:
    vector<string> res; // This vector stores the final results, i.e., all valid IP addresses.
    vector<string> path; // This vector temporarily holds each part of the currently constructing IP address.

    // The backtracking function tries to build the IP address from the input string 's', starting from 'startIndex'.
    void backtracking(const string &s, int startIndex) {
        // If startIndex reaches the end of string 's' and exactly 4 parts are found, add the constructed IP to 'res'.
        if (startIndex == s.length() && path.size() == 4) {
            res.push_back(path2String(path));
            return;
        }

        // Iterate through the string to try different splits for IP address parts.
        for (int i = startIndex; i < s.size(); i++) {
            // Check if the substring from startIndex to i forms a valid IP segment.
            if (!isValidIP(s, startIndex, i)) continue;
            // If more than 4 parts are formed, it's not a valid IP, so break.
            if (path.size() >= 4) break;
            // Add the valid segment to the path.
            path.push_back(s.substr(startIndex, i - startIndex + 1));
            // Recursively call backtracking for the next segment.
            backtracking(s, i + 1);
            // Backtrack: remove the last segment before the next iteration.
            path.pop_back();
        }
    }

    // Function to check if the substring of 's' from 'start' to 'end' is a valid IP segment.
    bool isValidIP(const string &s, int start, int end) {
        // If the segment starts with '0' and is longer than 1 character, it's invalid.
        if (s[start] == '0' && start != end) return false;
        int num = 0;
        // Convert the substring to a number and check if it's <= 255.
        for (int i = start; i <= end; i++) {
            num = 10 * num + s[i] - '0';
            if (num > 255) return false;
        }
        return true;
    }

    // Function to convert the segments in 'path' into a dot-separated IP address string.
    string path2String(vector<string> &path) {
        string result = "";
        for (int i = 0; i < path.size(); i++) {
            result += path[i];
            // Add '.' between the segments, but not after the last segment.
            if (i < path.size() - 1) result += ".";
        }
        return result;
    }
public:
    // Public function to initiate the backtracking process and return all possible valid IP addresses.
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0);
        return res;
    }
};
```

## Way 2

```C++
class Solution {
private:
    vector<string> res;
    void backtracking(const string &s, int startIndex, int currSize, string path) {
        if (startIndex == s.length()) {
            if (currSize == 4) {
                path.pop_back();  // delete the final "."
                res.push_back(path);
            }
            return;
        }

        if (currSize == 4) return;

        for (int i = startIndex, temp = 0; i < s.length(); i++) {
            if (i > startIndex && s[startIndex] == '0') break;
            temp = temp * 10 + s[i] - '0';
            if (temp <= 255) // implicit backtracking
                backtracking(s, i + 1, currSize + 1, path + to_string(temp) + '.');
            else break;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0, "");
        return res;
    }
};
```

- Time Complexity: In general, if there are $n$ digits in total, the time complexity is $C_{n-1}^{3}$. It can also be represented as $O(3^4\times n)$ in the worst case. This is because at each part of the IP address, a maximum of 3 characters can be considered (IP address parts range from 0 to 255), and there are 4 parts;
- Space Complexity: $O(4)$ for the recursion stack, as the maximum depth of recursion is 4 (for the 4 parts of the IP address).
