#pragma once

#include <vector>
#include <iostream>

/*
* You are given an integer numRows.
* Return the first numRows of Pascal's triangle.
* In Pascal's triangle, each number is the sum of the two numbers directly
* above it and the first and last number on each row must be equal to 1, as
* shown below:
* 
* Example 1:
* Input: numRows = 5
* Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
* 
* Example 2:
* Input: numRows = 1
* Output: [[1]]
*/
namespace PascalTriangle {
    class Solution {
    public:
        std::vector<std::vector<int>> generate(int numRows) {
            std::vector<std::vector<int>> result (numRows);

            for (int i = 0; i < numRows; i++) {
                result[i].resize(i + 1);
                result[i][0] = 1;
                int lastIndex = result[i].size() - 1;

                result[i][lastIndex] = 1;
            }

            for (int i = 2; i < numRows; i++) {
                for (int j = 1; j < result[i].size() - 1; j++) {
                    result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
                }
            }

            return result;


        }
    };

    void testPascalTriangle() {
        Solution s;
        int n = 6;
        std::vector<std::vector<int>> result = s.generate(n);

        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                std::cout << result[i][j] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }
}