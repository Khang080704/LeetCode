#pragma once

#include<string>
#include<stack>

/*
* Given a string s containing just the characters '(', ')', '{',
* '}', '[' and ']', determine if the input string is valid.
* 
* An input string is valid if:
* 
* 1. Open brackets must be closed by the same type of brackets.
* 2. Open brackets must be closed in the correct order.
* 3. Every close bracket has a corresponding open bracket of the same type
* 
* Example 1:
* Input: s = "()"
* Output: true
* 
* Example 2:
* Input: s = "()[]{}"
* Output: true
* 
* Example 3:
* Input: s = "(]"
* Output: false
* 
* Example 4:
* Input: s = "([])"
* Output: true
* 
* Example 5:
* Input: s = "([)]"
* Output: false
* 
*/
namespace ValidParentheses {
    class Solution {
    public:

        bool isValid(std::string s) {
            if (s.length() == 1) return false;
            std::stack<char> stack;

            for (const char& x : s) {
                if (x == '(' || x == '[' || x == '{') {
                    stack.push(x);
                }
                else {
                    if (stack.empty()) return false;
                    char top = stack.top();
                    if ((top == '(' && x != ')') ||
                        (top == '[' && x != ']') ||
                        (top == '{' && x != '}')) {
                        return false;
                    }
                    stack.pop();
                }
            }

            if (stack.empty()) {
                return true;
            }
            else {
                return false;
            }
        }
    };
}