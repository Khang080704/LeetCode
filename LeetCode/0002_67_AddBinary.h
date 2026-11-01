#pragma once

#include<string>
#include<iostream>


/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

Constraints:

- 1 <= a.length, b.length <= 104
- a and b consist only of '0' or '1' characters.
- Each string does not contain leading zeros except for the zero itself.
*/
namespace AddBinary {
    class Solution {
    public:

        std::string addTwoChar(char a, char b, bool carry) {

            if (carry) {
                if (a == '0' && b == '0') {
                    return "1";
                }

                if ((a == '1' && b == '0') || (a == '0' && b == '1')) {
                    return "10";
                }
                return "11";
            }
            else {
                if (a == '0' && b == '0') {
                    return "0";
                }

                if ((a == '1' && b == '0') || (a == '0' && b == '1')) {
                    return "1";
                }
                return "10";
            }
 
        }

        std::string addBinary(std::string a, std::string b) {
            std::string top = "";
            std::string bottom = "";
            std::string result = "";

            if (a.length() >= b.length()) {
                top = a;
                bottom = b;
            }
            else {
                top = b;
                bottom = a;
            }

            int num = top.length() - bottom.length();
            bottom.insert(bottom.begin(), num, '0');
            bool carry = false;

            for (int i = top.length() - 1; i >= 1; i--) {
                std::string sum = addTwoChar(top[i], bottom[i], carry);
                if (sum.length() == 2) {
                    carry = true;
                    result.insert(result.begin(), sum[1]);
                }
                else {
                    carry = false;
                    result.insert(result.begin(), sum[0]);
                }
            }

            std::string last = addTwoChar(top[0], bottom[0], carry);
            result.insert(0, last);
            

            return result;
        }
    };

    void testAddBinary() {
        Solution s;
        std::string a = "1111";
        std::string b = "1";
        std::string result = s.addBinary(a, b);
        std::cout << result;
    }
}

