class Solution {
public:
    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void reverse(vector<int>& nums, int i, int j){
        while(i<=j){
            swap(nums,i,j);
            i++; j--;
        }
        return;
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        int n = nums.size();

        // if last two digits in increasing order : then just swap them
        if(nums[n-2] < nums[n-1]){
            swap(nums, n-2, n-1);
            return;
        }

        // if last digits are in decreasing order, arrange them in increasing order than swap the digit before the decreasing subsequence (if any) with the digits just greater than it
        int index = n-1, beforeDescending=-1;
        while(index-1>=0){
            if(nums[index-1] >= nums[index]) index--;
            else{
                beforeDescending = nums[index-1];
                break;
            }
        }
        reverse(nums, index, n-1);

        if(beforeDescending != -1){
            int nextGreater=INT_MAX, nextGreaterIndex;
            for(int i=index; i<n; i++){
                if(nums[i]>beforeDescending) {
                    if(nextGreater > nums[i]){
                        nextGreater = nums[i];
                        nextGreaterIndex = i;
                    }
                } 
            }
            swap(nums,index-1,nextGreaterIndex);
        }
        return;
    }
};