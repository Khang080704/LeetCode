#pragma once

#include <vector>
#include <map>

/*
* Given a non-empty array of integers nums, every element appears twice
* except for one. Find that single one.
* 
* You must implement a solution with a linear runtime complexity and use only
* constant extra space.
* 
* Example 1:
* Input: nums = [2,2,1]
* Output: 1
* 
* Example 2:
* Input: nums = [4,1,2,1,2]
* Output: 4
* 
* Example 3:
* Input: nums = [1]
* Output: 1
*/
namespace SingleNumber {

    namespace Map {
        class Solution {
        public:
            int singleNumber(std::vector<int>& nums) {
                std::map<int, int> count;

                for (auto x : nums) {
                    count[x]++;
                }

                for (auto x : count) {
                    if (x.second == 1) {
                        return x.first;
                    }
                }
            }
        };
    }

    /*
    * Using xor operation:
    * Principle: A number XORed with itself equals 0
    * and a number XORed with 0 remains unchanged 
    * 
    * When XORing all elements in an array, 
    * numbers that appear twice cancel each other out, 
    * leaving only the number that appears once.
    */
    namespace XOR {
        class Solution {
        public:
            int singleNumber(std::vector<int>& nums) {
                int result = 0;

                for (int x : nums) {
                    result ^= x;
                }
                
                return result;
            }
        };
    }
    
}
