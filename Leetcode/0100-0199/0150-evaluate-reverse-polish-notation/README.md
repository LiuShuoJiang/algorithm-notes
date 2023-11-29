# Evaluate Reverse Polish Notation

[Link](https://leetcode.com/problems/evaluate-reverse-polish-notation/description/)

## Description

You are given an array of strings `tokens` that represents an arithmetic expression in a [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation).

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

- The valid operators are `'+'`, `'-'`, `'*'`, and `'/'`.
- Each operand may be an integer or another expression.
- The division between two integers always truncates toward zero.
- There will not be any division by zero.
- The input represents a valid arithmetic expression in a reverse polish notation.
- The answer and all the intermediate calculations can be represented in a 32-bit integer.

Example 1:

- Input: `tokens = ["2","1","+","3","*"]`
- Output: `9`
- Explanation: `((2 + 1) * 3) = 9`

Example 2:

- Input: `tokens = ["4","13","5","/","+"]`
- Output: `6`
- Explanation: `(4 + (13 / 5)) = 6`

Example 3:

- Input: `tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]`
- Output: `22`
- Explanation:

```
((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

Constraints:

- `1 <= tokens.length <= 10^4`
- `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200, 200]`.

## Solution

Iterate through the entire array and:

- Push each number that we meet to the stack;
- If we meet operation token - pop two numbers from the stack and evaluate the operation;
- Push the result of our operation back to the stack.

### Original Solution

```C++
class Solution {
    public:
        bool isInteger(const string& str) {
            if (str.empty()) return false;
            string::size_type sz;
            try {
                int num = stoll(str, &sz);
                return sz == str.size();
            } catch (const invalid_argument& e) {
                return false;
            } catch (const std::out_of_range& e) {
                return false;
            }
        }

        int evalRPN(vector<string>& tokens) {
            stack<int> stk;
            for (auto &c : tokens) {
                if (isInteger(c)) stk.push(stoll(c));
                else if (!stk.empty()) {
                    auto num1 = stk.top();
                    stk.pop();
                    auto num2 = stk.top();
                    stk.pop();
                    if (c == "+") stk.push(num1 + num2);
                    else if (c == "-") stk.push(num2 - num1);
                    else if (c == "*") stk.push(num1 * num2);
                    else stk.push(num2 / num1);
                }
            }
            return stk.top();
        }
};
```

- Time complexity: $O(n)$;
- Space complexity: $O(n)$.

### Easier Way of Writing

```C++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto &s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                auto num1 = stk.top(); stk.pop();
                auto num2 = stk.top(); stk.pop();
                if (s == "+") num2 += num1;
                else if (s == "-") num2 -= num1;
                else if (s == "*") num2 *= num1;
                else num2 /= num1;
                stk.push(num2);
            } else stk.push(stoi(s));
        }
        return stk.top();
    }
};
```

Note: The Polish postfix notation is similar to the ***post-ordering*** of a binary tree consisting of all the operators and operands.

### Other Easy Ways of Writing

Fancy way 1:

```C++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int)> > mapping = {
            { "+", [] (int a, int b) {return a + b; } },
            { "-", [] (int a, int b) {return a - b; } },
            { "*", [] (int a, int b) {return a * b; } },
            { "/", [] (int a, int b) {return a / b; } }
        };

        stack<int> stk;
        for (auto &s : tokens) {
            if (!mapping.count(s)) stk.push(stoi(s));
            else {
                auto b = stk.top(); stk.pop();
                auto a = stk.top(); stk.pop();
                stk.push(mapping[s](a, b));
            }
        }
        return stk.top();
    }
};
```

Fancy way 2:

```C++
int evalRPN(vector<string>& tokens) {
    stack<int> s;
    unordered_map<string, function<int(int,int)>> mapping {
        { "+", std::plus<int>() },
        { "-", std::minus<int>() },
        { "*", std::multiplies<int>() },
        { "/", std::divides<int>() }
    };
    
    for (const auto& token : tokens) {
        const auto& op = mapping.find(token);
        if (op != mapping.end()) {
            assert(s.size() >= 2);
            int rhs = s.top(); s.pop();
            int lhs = s.top(); s.pop();
            s.push((*op).second(lhs, rhs));
        } else {
            s.push(stoi(token));
        }
    }
    
    assert(s.size() == 1);
    return s.top();
}
```

Fancy way 3:

```C++
class Solution {
public:
    // Function to evaluate Reverse Polish Notation
    int evalRPN(vector<string>& tokens) {
        // Lambda function to return the appropriate arithmetic operation
        // based on the operator character.
        constexpr auto eval = [](char op) -> function<int(int, int)> {
            switch (op) {
                case '+': return plus<>();      // For addition
                case '-': return minus<>();     // For subtraction
                case '*': return multiplies<>();// For multiplication
                case '/': return divides<>();   // For division
                default: return nullptr;        // For invalid operators
            }
        };

        stack<int> stk; // Stack to store integers

        // Iterate over each token in the input vector
        for (const auto &str : tokens) {
            // Check if the token is an operator
            if (str.length() == 1 && eval(str[0])) {
                const auto rhs = stk.top(); stk.pop(); // Right-hand side operand
                const auto lhs = stk.top(); stk.pop(); // Left-hand side operand

                // Apply the operation and push the result back onto the stack
                stk.push(eval(str[0])(lhs, rhs));
            } else {
                // If the token is a number, convert it to an integer and push onto the stack
                stk.push(stoi(str));
            }
        }
        // Return the top element of the stack, which is the final result
        return stk.top();
    }
};
```

Grammar and Concepts Used:

- Lambda Functions: Anonymous functions used for defining the eval function inline.
- Stack: A LIFO (Last In, First Out) data structure used for storing operands.
- Auto Keyword: For type inference in C++.
- Range-based For Loop: To iterate over each element in the tokens vector.
- Function Objects: Standard library function objects for arithmetic operations.
- Ternary Operator: Used in the lambda function for concise conditional logic.
- Constexpr: Indicates that the value of a variable or function can be evaluated at compile time.
