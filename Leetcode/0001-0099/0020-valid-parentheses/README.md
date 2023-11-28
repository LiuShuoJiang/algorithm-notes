# Valid Parentheses

[Link](https://leetcode.com/problems/valid-parentheses/description)

## Description

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.

Example 1:

- Input: `s = "()"`
- Output: `true`

Example 2:

- Input: `s = "()[]{}"`
- Output: `true`

Example 3:

- Input: `s = "(]"`
- Output: `false`

Constraints:

- `1 <= s.length <= 10^4`
- `s` consists of parentheses only `'()[]{}'`.

## Solution

Three situations when the string is not valid:

- The first case: the string has been traversed, but the stack is not empty, indicating that there is a corresponding left bracket does not have a right bracket to match, so return `false`;
- The second case: during the process of traversing the string to match, it is found that there is no character to match in the stack. So return `false`;
- The third case: traversing the string matching process, the stack is already empty, there is no matching character, that is, the right bracket did not find the corresponding left bracket. Also return `false`.

```C++
class Solution {
public:
    bool isValid(string s) {
        // If the length of the string is odd, it cannot be a valid parentheses sequence
        if (s.size() % 2) return false;
        
        stack<char> stk; // Using a stack to keep track of the parentheses

        // Iterating through each character in the string
        for (int i = 0; i < s.size(); i++) {
            // If the current character is an opening parenthesis, push the corresponding closing one onto the stack
            if (s[i] == '(') stk.push(')');
            else if (s[i] == '[') stk.push(']');
            else if (s[i] == '{') stk.push('}');

            // If the current character is a closing parenthesis, check for matching with the top of the stack
            else if (stk.empty() || stk.top() != s[i]) 
                return false; // If no match or the stack is empty, the string is not valid
            else 
                stk.pop(); // If there is a match, pop the top element from the stack
        }

        // If the stack is empty at the end, all parentheses were matched correctly
        return stk.empty();
    }
};

```

- Time complexity: $O(n)$;
- Space complexity: $O(n)$.

Another way of writing:

```C++
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (c == '(' || c == '[' || c =='{') stk.push(c);
            else {
                // The ASCII code difference between ( and ), [ and ], { and } is no more than 2.
                if (stk.size() && abs(stk.top() - c) <= 2) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};
```
