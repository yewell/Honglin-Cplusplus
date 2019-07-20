
 //This method is the most basic of all, better understood
 //but its complexity is very high, does not involve very deep binary search, this traversal is very impractical when the amount of data is large
 //so This method is just a suggestion and does not have to be adopted.
 public int[] SearchRange(int[] nums, int target)
 {
	 int[] result = { -1,-1};
	 for (int i = 0; i < nums.Length;i++ )
	 {
		 if(nums[i] == target)
		 {
			 result[0] = i;
			 break;
		 }
	 }
	 for (int j = nums.Length - 1; j >=0;j-- )
	 {
		 if(nums[j] == target)
		 {
			 result[1] = j;
			 break;
		 }
	 }
	 return result;
 }
