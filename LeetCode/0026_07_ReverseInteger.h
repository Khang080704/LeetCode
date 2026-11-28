#pragma once

#include <math.h>
#include <climits>
#include <iostream>

namespace ReverseInteger {
    class Solution {
    public:

        int countNum(int x) {
            if (x <= 9 && x >= -9) {
                return 1;
            }

            return 1 + countNum(x / 10);
        }

        int pow(int x, int n) {
            int result = 1;
            for (int i = 1; i <= n; i++) {
                result *= x;
            }

            return result;
        }

        int reverse(int x) {

            if (x > INT_MAX) return INT_MAX;
            if (x < INT_MIN) return INT_MIN;

            
            int result = 0;
            int exp = countNum(x) - 1;

            while (x != 0) {
                int right = x % 10;

                if (right * pow(10, exp) > INT_MAX || right * pow(10, exp) < INT_MIN) {
                    return 0;
                }

                if (result + right * pow(10, exp) > INT_MAX || result + right * pow(10, exp) < INT_MIN) {
                    return 0;
                }

                result += right * pow(10, exp);
                exp--;


                x /= 10;
            }

            return result;

        }

    };

    void testReverseInteger() {
        std::cout << std::endl;
        Solution s;
        int x = -1234;

        std::cout << s.reverse(x);
    }
}