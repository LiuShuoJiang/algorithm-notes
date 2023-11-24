# Reverse Words in a String

- [Reverse Words in a String](#reverse-words-in-a-string)
  - [Description](#description)
  - [Solution](#solution)
    - [Original Solution Using Library Functions](#original-solution-using-library-functions)
      - [Code](#code)
      - [Detailed complexity analysis](#detailed-complexity-analysis)
        - [Overall Time Complexity Analysis](#overall-time-complexity-analysis)
        - [Overall Space Complexity Analysis](#overall-space-complexity-analysis)
        - [Summarization: Complexity of C++ Standard Library Functions](#summarization-complexity-of-c-standard-library-functions)
    - [Solution Implementing the Function Ourselves](#solution-implementing-the-function-ourselves)
      - [Way 1](#way-1)
      - [Way 2 (Recommended)](#way-2-recommended)
    - [Python Solution](#python-solution)
      - [Function Breakdown](#function-breakdown)
      - [Time Complexity Analysis](#time-complexity-analysis)
      - [Space Complexity Analysis](#space-complexity-analysis)

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

#### Way 1

The entire string is reversed first, and then each word is reversed back internally.

```C++
class Solution {
public:
    // Reversing strings; interval: left-closed right-closed []
    void myReverse(string &s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--)
            swap(s[i], s[j]);
    }

    // Remove all spaces and add spaces between neighboring words
    // using fast and slow pointers
    void removeExtraSpace(string &s) {
        int slow = 0;
        for (int i = 0; i < s.size(); i++) {
            // Handle non-spaces as they are encountered, i.e., remove all spaces
            if (s[i] != ' ') {
                // Manually control spaces by adding spaces between words;
                // slow ! = 0 means that it is not the first word 
                // and a space needs to be added before the word
                if (slow != 0) s[slow++] = ' ';
                // Fill in the word 
                // and a space indicates the end of the word
                while (i < s.size() && s[i] != ' ') s[slow++] = s[i++];
            }
        }
        // size of slow is the size of the string after removing the extra spaces
        s.resize(slow); 
    }

    string reverseWords(string s) {
        // Remove extra spaces, 
        // make sure there is only one space between words 
        // and no space at the beginning and end of the string.
        removeExtraSpace(s);
        myReverse(s, 0, s.size() - 1);
        // RemoveExtraSpace guarantees that the first word 
        // must start with a 0 subscript.
        int start = 0;
        // It is i <= s.size() here!
        for (int i = 0; i <= s.size(); i++) {
            // Reaching a space or the end of a string indicates the end of a word;
            // Perform a reversal
            if (i == s.size() || s[i] == ' ') {
                // Reversal. Note that it's a left-closed right-closed [] flip
                myReverse(s, start, i - 1);
                // Update the start subscript of the next word start
                start = i + 1;
            }
        }
        return s;
    }
};
```

- Time complexity: $O(n)$;
- Space complexity: $O(1)$ for C++.

#### Way 2 (Recommended)

Flip each word internally first, then reverse the entire string back.

```C++
class Solution {
public:
    string reverseWords(string s) {
        int slow = 0; // Initialize a 'slow' pointer

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue; // Skip spaces

            // Find the start and end of the next word
            int j = i, t = slow;
            while (j < s.size() && s[j] != ' ') s[t++] = s[j++];
            // Reverse the word in-place
            reverse(s.begin() + slow, s.begin() + t);

            // Add a space after the word and update pointers
            s[t++] = ' ';
            slow = t;
            i = j; // Jump to the end of the word
        }

        // Remove the last space if the string is not empty
        if (slow) slow--;
        // Erase the trailing spaces
        s.erase(s.begin() + slow, s.end());
        // Reverse the entire string to get words in reverse order
        reverse(s.begin(), s.end());

        return s;
    }
};
```

### Python Solution

```Python
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.strip().split()[::-1])
```

#### Function Breakdown

1. **`s.strip()`**:
   - `strip()` is a string method in Python that removes any leading and trailing whitespace (including spaces, newlines, and tabs) from the string `s`.
   - For instance, `"  hello world  ".strip()` would result in `"hello world"`.
2. **`split()`**:
   - `split()` is a method that divides a string into a list of substrings, separated by the specified separator. By default, it splits based on any whitespace and removes it.
   - For example, `"hello   world".split()` results in `["hello", "world"]`.
3. **`[::-1]`**:
   - This is a slicing operation that reverses the list. `[::-1]` means start at the end of the list and end at position 0, move with the step -1 (one step backward).
   - For a list `["hello", "world"]`, the result of `[::-1]` would be `["world", "hello"]`.
4. **`' '.join(...)`**:
   - `join()` is a string method used to join elements of an iterable (like a list) into a single string, with the specified string as a separator. Here, it uses a space `' '` as the separator.
   - For example, `' '.join(["world", "hello"])` would result in `"world hello"`.

Putting it all together, this one-liner first removes leading and trailing spaces from the input string, splits the string into words, reverses the list of words, and then joins them back into a single string with spaces in between.

#### Time Complexity Analysis

1. **Strip Operation:** $O(N)$, where $N$ is the length of the string. This is because it potentially needs to check each character at both ends of the string.
2. **Split Operation:** $O(N)$, as it goes through the entire string to split it into words.
3. **List Reversal:** $O(W)$, where $W$ is the number of words in the string. This is typically considered a linear operation with respect to the number of elements in the list.
4. **Join Operation:** $O(N)$, as it has to combine all the words back into a single string.

The overall time complexity of the function is $O(N)$, as each character in the string is processed a constant number of times.

#### Space Complexity Analysis

**Intermediate Lists and Strings:** The space complexity is mainly due to the storage of the split words and the final string. This would be $O(N)$, as in the worst case, the number of words and the total length of the words (including the spaces in the final joined string) can be proportional to the length of the original string.
