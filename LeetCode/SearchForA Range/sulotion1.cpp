#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	// Improve the binary search and modify the value of the target.
	//the interval of the element can be obtained by searching for up to two binary searches.
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result = { -1,1 };
		if (nums.empty())
			return result;
		int min_rank = -1;
		int max_rank = -1;
		int low = 0;
		int high = nums.size();
		//Improve the binary search so that it always returns the largest rank of multiple hit elements.
		//Time - consuming O(logn).
		while (low < high) { 
			int midium = low + ((high - low) >> 1);
			(target < nums[midium]) ? (high = midium) : (low = midium + 1);
		}
		//At the end of the loop, low is the minimum rank of the element larger than the target.
		//so --low is not greater than the maximum rank of the element of the target.
		if (--low != -1 && nums[low] == target) { 
			max_rank = low; 
			--target; 
			high = low; 
			low = 0; 
			//The second binary search find object becomes target - 1.
			//and the search interval is reduced to[0, max_rank).
			//Time - consuming O(log(max_rank + 1)).
			while (low < high) { 
				int mi = low + ((high - low) >> 1);
				(target < nums[mi]) ? high = mi : low = mi + 1;
			} 
			//At the end of the loop, low is the smallest rank of the element greater than target - 1.
			//the minimum rank of the target (if any)
			min_rank = low; 
		}
		if (min_rank != -1) {
			result = { min_rank,max_rank };
		}
		return result;
	}
};