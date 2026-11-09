#pragma once

#include<vector>
#include<string>
#include<iostream>

/*
* Given a string containing digits from 2-9 inclusive, return all
* possible letter combinations that the number could represent.
* Return the answer in any order.
* A mapping of digits to letters (just like on the telephone buttons) is
* given below. Note that 1 does not map to any letters.
* 
* Example 1:
* Input: digits = "23"
* Output:
* ["ad","ae","af","bd","be","bf","cd","ce","cf"]
* 
* Example 2:
* Input: digits = "2"
* Output: ["a","b","c"]
* 
* Constraints:
* - 1 <= digits.length <= 4
* - digits[i] is a digit in the range ['2', '9'].
*/
namespace LetterCombinationsOfAPhoneNumber {
    class Solution {
    public:
        std::vector<std::string> getChars(char _character) {
            switch (_character)
            {
            case '2': 
                return { "a", "b", "c" };
            case '3':  
                return { "d", "e", "f" };
            case '4':  
                return { "g", "h", "i" };
            case '5':  
                return { "j", "k", "l" };
            case '6':  
                return { "m", "n", "o" };
            case '7':  
                return { "p", "q", "r", "s" };
            case '8':  
                return { "t", "u", "v" };
             case '9':  
                 return { "w", "x", "y", "z" };
            default:
                return {};
            }
        }

        void combineTwoChars(char a, char b, std::vector<std::string>& result) {
            std::vector<std::string> first = getChars(a);
            std::vector<std::string> second = getChars(b);

            for (const std::string x : first) {
                for (const std::string y : second) {
                    std::string temp = x + y;
                    result.push_back(temp);
                }
            }
        }

        void combineTwoChars(std::vector<std::string> src, char des, std::vector<std::string>& result) {
            std::vector<std::string> second = getChars(des);

            for (const std::string x : src) {
                for (const std::string y : second) {
                    std::string temp = x + y;
                    result.push_back(temp);
                }
            }
        }

        std::vector<std::string> letterCombinations(std::string digits) {
            std::vector<std::string> result;

            if (digits.length() == 1) {
                return getChars(digits[0]);
            }

            combineTwoChars(digits[0], digits[1], result);

            for (int i = 2; i < digits.length(); i++) {
                combineTwoChars(result, digits[i], result);
            }

            for (int i = 0; i < result.size(); i++) {
                if (result[i].length() != digits.length()) {
                    result.erase(result.begin() + i);
                    i--;
                }
            }

            return result;
        }
    };

    void testLetterCombinationsOfAPhoneNumber() {
        std::string digits = "239";
        Solution s;
        std::vector<std::string> result = s.letterCombinations(digits);

        for (auto x : result) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}