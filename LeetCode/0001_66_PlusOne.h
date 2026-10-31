#pragma once

#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>


/*
*
You are given a large integer represented as an integer array digits,
where each digits[i] is the ith digit of the integer.
The digits are ordered from most significant to least significant in left-to-right order.
The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].

Constraints:

- 1 <= digits.length <= 100
- 0 <= digits[i] <= 9
- digits does not contain any leading 0's.


*/
class Solution {
public:

	int changeToNumber(std::vector<int> a) {
		long long number = 0;
		int exp = a.size() - 1;

		for (int i = 0; i < a.size(); i++) {
			number += a[i] * pow(10, exp);
			exp--;
		}


		return number;
	}

	std::vector<int> alternativeSolution(std::vector<int>& digits) {
		int number = changeToNumber(digits);
		number++;

		std::vector<int> result;

		while (number != 0) {
			int right = number % 10;
			int left = number / 10;
			result.push_back(right);
			number = left;
		}

		std::reverse(result.begin(), result.end());
		return result;
	}

	std::vector<int> plusOne(std::vector<int>& digits) {
		if (digits.size() <= 4) {
			return alternativeSolution(digits);
		}

		bool carry = false;
		std::vector<int> result;

		int temp = *(digits.end() - 1) + 1;

		if (temp == 10) {
			carry = true;
			result.push_back(0);
		}
		else {
			result.push_back(temp);
		}


		for (int i = digits.size() - 2; i >= 1; i--) {

			if (carry) {
				digits[i] = digits[i] + 1;
			}
			else {
				
			}

			if (digits[i] == 10) {
				carry = true;
				result.push_back(digits[i] % 10);
			}
			else {
				carry = false;
				result.push_back(digits[i]);
			}
		}

		if (carry) {
			temp = *digits.begin() + 1;
			if (temp == 10) {
				result.push_back(0);
				result.push_back(1);
			}
			else {
				result.push_back(temp);
			}
		}
		else {
			result.push_back(*digits.begin());
		}



		std::reverse(result.begin(), result.end());
		return result;
	}
};

void testPlusOne() {
	Solution solution;
	std::vector<int> digits = { 1, 2, 3, 4 };
	std::vector<int> result = solution.plusOne(digits);
	for (int digit : result) {
		std::cout << digit << " ";
	}
	std::cout << std::endl; // Expected output: 1 2 4
}