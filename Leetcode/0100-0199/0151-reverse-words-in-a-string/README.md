# Reverse Words in a String

[Link](https://leetcode.com/problems/reverse-words-in-a-string/description/)

## Description

Given an input string `s`, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in `s` will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that `s` may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:

- Input: `s = "the sky is blue"`
- Output: `"blue is sky the"`

Example 2:

- Input: `s = "  hello world  "`
- Output: `"world hello"`
- Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

- Input: `s = "a good   example"`
- Output: `"example good a"`
- Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Constraints:

- `1 <= s.length <= 10^4`
- `s` contains English letters (upper-case and lower-case), digits, and spaces `' '`.
- There is at least one word in `s`.

## Solution

### Original Solution Using Library Functions

#### Code

```C++
class Solution {
public:
    string reverseWords(string s) {
        size_t start = s.find_first_not_of(" ");
        size_t end = s.find_last_not_of(" ");

        if (start == string::npos) return "";

        s = s.substr(start, end - start + 1);

        vector<string> words;
        string word;
        istringstream tokenStream(s);
        while (tokenStream >> word) {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string result;
        for (size_t i = 0; i < words.size(); i++) {
            result += words[i];
            if (i < words.size() - 1) result += " ";
        }
        return result;
    }
};
```

Full testing code:

```C++
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::string reverseWords(std::string s) {
    // Step 1: Trim leading and trailing spaces
    size_t start = s.find_first_not_of(" ");
    size_t end = s.find_last_not_of(" ");

    // Handle the case where the string contains only spaces
    if (start == std::string::npos) return "";

    // Trim the string
    s = s.substr(start, end - start + 1);

    // Step 2: Split the string into words
    std::istringstream iss(s);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }

    // Step 3: Reverse the words
    std::reverse(words.begin(), words.end());

    // Step 4: Concatenate the words
    std::string result;
    for (size_t i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i < words.size() - 1) {
            result += " ";  // Add a space between words
        }
    }

    return result;
}

int main() {
    std::string s1 = "the sky is blue";
    std::string s2 = "  hello world  ";
    std::string s3 = "a good   example";

    std::cout << reverseWords(s1) << std::endl;
    std::cout << reverseWords(s2) << std::endl;
    std::cout << reverseWords(s3) << std::endl;

    return 0;
}
```

`iss >> word` is an extraction operation that reads data from `iss` and stores it in `word`. It automatically splits the input based on whitespace (spaces, tabs, newlines).

#### Detailed complexity analysis

##### Overall Time Complexity Analysis

1. **Trimming Spaces:**
   - The functions `find_first_not_of` and `find_last_not_of` both run in linear time, $O(N)$, where $N$ is the length of the string `s`.
   - The `substr` operation is also $O(N)$, as it potentially needs to copy the entire string.
2. **Splitting the String into Words:**
   - The `istringstream` constructor and the loop that reads words both operate in $O(N)$ time. Each character is read and processed once to split the string into words.
3. **Reversing the Words:**
   - The `reverse` function operates in $O(\frac{W}{2})$, where W is the number of words. In terms of Big O notation, this simplifies to $O(W)$.
4. **Concatenating the Words:**
   - The loop for concatenating words runs in $O(W)$, as it iterates over all words. However, the string concatenation inside the loop (`result += words[i]`) has its own complexity. In the worst case, each concatenation can be $O(N)$ due to potential reallocation and copying of the entire string. Thus, this step could be as bad as $O(WN)$.

##### Overall Space Complexity Analysis

1. **Additional String Storage:**
   - The `substr` operation creates a new string, which is $O(N)$ in space.
2. **Storing Words:**
   - The `vector<string>` `words` stores each word separately. In the worst case, if the string is composed entirely of single-character words separated by spaces, the number of words will be approximately $\frac{N}{2}$ (every other character is a space), leading to a space complexity of $O(N)$.
3. **Intermediate String Storage:**
   - The `result` string, in the worst case, will hold the entire input string in reverse order, which is $O(N)$.

##### Summarization: Complexity of C++ Standard Library Functions

- `find_first_not_of`, `find_last_not_of`: $O(N)$
- `substr`: $O(N)$ for copying the substring.
- `istringstream`: The construction is $O(N)$ as it copies the string.
- `istringstream::operator>>`: $O(N)$ overall for reading the entire string.
- `vector::push_back`: Amortized $O(1)$ for each call, but can lead to occasional resizing, which is $O(N)$ for that operation.
- `reverse`: $O(\frac{W}{2})$ which simplifies to $O(W)$.
- String concatenation (`+=`): $O(N)$ in the worst case for each operation due to potential reallocation and copying.

The overall time complexity of the implementation is dominated by the string splitting and concatenation steps, both of which can approach $O(N^2)$ in the worst case due to the way strings are handled in C++. The space complexity is primarily $O(N)$, driven by the storage of the words and the final result string.

### Solution Implementing the Function Ourselves



