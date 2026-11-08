#pragma once

#include<string>
#include<math.h>
#include<iostream>

/*
* Implement the myAtoi(string s) function, which converts a
* string to a 32-bit signed integer.
* The algorithm for myAtoi(string s) is as follows:
* 
* 1. Whitespace: Ignore any leading whitespace (" ").
* 2. Signedness: Determine the sign by checking if the next
*    character is '-' or '+', assuming positivity if neither present.
* 3. Conversion: Read the integer by skipping leading zeros until
*    a non-digit character is encountered or the end of the string
*    is reached. If no digits were read, then the result is 0.
* 4. Rounding: If the integer is out of the 32-bit signed integer
*    range [-2^31, 2^31 - 1], then round the integer to remain in the range.
*    Specifically, integers less than -2^31 should be rounded to -2^31, 
*    and integers greater than 2^31 - 1 should be rounded to 2^31 - 1. 
* 
*/
namespace StringToInteger {
    class Solution {
    public:
        void removeWhiteSpace(std::string& s) {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != ' ') {
                    return;
                }
                s.erase(0, 1);
                i--;
            }
        }

        bool isPositiveOrNegative(std::string& s) {
            if (s[0] == '-') {
                s.erase(0, 1);
                return false;
            }
            else if (s[0] == '+') {
                s.erase(0, 1);
            }
            return true;
        }

        void skippingLeadingZero(std::string& s) {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != '0') {
                    return;
                }
                s.erase(0, 1);
                i--;
            }
        }

        std::string getNumber(std::string s) {
            std::string result = "";

            for (const char x: s) {
                if (x >= '0' && x <= '9') {
                    result += x;
                }
                else {
                    break;
                }
            }

            return result;
        }

        bool isSrcLargerOrSmallerThanLimit(std::string src, std::string intLimit) {

            if (src.length() > intLimit.length()) return true;
            if (src.length() < intLimit.length()) return false;

            for (int i = 0; i < src.length(); i++) {
                if (src[i] > intLimit[i]) return true;
                if (src[i] < intLimit[i]) return false;
            }
            return false;
        }

        int convertStringToInteger(std::string s, bool isPositive) {

            bool overLimit;
            if (isPositive) {
                overLimit = isSrcLargerOrSmallerThanLimit(s, std::to_string(INT_MAX));
                if (overLimit) return INT_MAX;
            }
            else {
                overLimit = isSrcLargerOrSmallerThanLimit(s, std::to_string(INT_MIN).erase(0, 1));
                if (overLimit) return INT_MIN;
            }

            long long result = 0;
            int exp = s.length() - 1;

            for (const char x : s) {
                int temp = x - '0';
                result += temp * pow(10, exp);
                exp--;
            }

            return isPositive ? result : -result;
            
        }

        int myAtoi(std::string s) {
            removeWhiteSpace(s);

            bool isPositive = isPositiveOrNegative(s);

            skippingLeadingZero(s);
            std::string number = getNumber(s);

            return convertStringToInteger(number, isPositive);
            
        }
    };

    void testStringToInteger() {
        std::string temp = "20000000000000000000";
        Solution s;
        std::cout << s.myAtoi(temp) << std::endl;
    }
}