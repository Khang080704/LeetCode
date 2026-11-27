#pragma once

#include <string>
#include <map>
#include <vector>
#include <iostream>

namespace LongestSubstringWithoutRepeatingCharacters {
    class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {
            std::vector<int> exist(128, 0);
            
            int left = 0;
            int right = 0;

            int max_len = 0;
            

            for (int i = 0; i < s.length(); i++) {
                while (exist[s[i]] == 1) {
                    exist[s[left]] = 0;
                    left++;
                }
                exist[s[i]] = 1;
                max_len = std::max(max_len, i - left + 1);
            }



            return max_len;
        }
    };

    void test() {
        std::cout << std::endl;
        std::string a = "abcb";
        Solution s;
        std::cout << s.lengthOfLongestSubstring(a);
    }
}
