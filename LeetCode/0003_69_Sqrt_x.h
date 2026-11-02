#pragma once

#include<iostream>

/*
 
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
*/
namespace SqrtX {
    class Solution {
    public:
        int mySqrt(int x) {
            if (x == 0) return 0;
            if (x == 1) return 1;

            int left = 0;
            int right = x;
            long long mid = (left + right) / 2;

            while (left < right - 1) {
                if (mid * mid == x) {
                    return mid;
                }
                else if (mid * mid > x) {
                    right = mid;
                }
                else {
                    left = mid;
                }
                mid = (left + right) / 2;
            }

            return mid;

            
            
        }
    };

    void testSqrtx() {
        int x = 4;
        Solution s;
        std::cout << s.mySqrt(2147395599);
    }
}