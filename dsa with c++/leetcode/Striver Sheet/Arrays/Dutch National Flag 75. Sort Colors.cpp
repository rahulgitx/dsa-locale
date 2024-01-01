class Solution {
public:
    void mergeSort(vector<int>& nums, int startIndex, int endIndex){
        // cout << "start: " << startIndex << " end " << endIndex << endl;
        if(startIndex >= endIndex) return;
        int mid = (startIndex+endIndex)/2;
        mergeSort(nums, startIndex, mid);
        mergeSort(nums, mid+1, endIndex);

        vector<int> v;
        int i=startIndex, j = mid+1;
        while(i<=mid || j <= endIndex){
            // cout << "    i:" << i << " j:" << j << endl;
            if(j>endIndex || (i<=mid && nums[i] <= nums[j])){
                v.push_back(nums[i]);
                i++;
            }
            else if((i>mid) || (j<=endIndex && nums[i] > nums[j])){
                v.push_back(nums[j]);
                j++;
            }
        }
        for(int k=startIndex; k<=endIndex; k++) nums[k] = v[k-startIndex];
        // cout << "start: " << startIndex << " end " << endIndex << " done " << endl;

        return;
    }

    int quickSortFunc(vector<int>& nums, int startIndex, int endIndex){
        int pivot = nums[startIndex];
        vector<int> smaller, larger;

        for(int i=startIndex+1; i<=endIndex; i++){
            if(nums[i] <= pivot) smaller.push_back(nums[i]);
            else larger.push_back(nums[i]);
        }

        int pivotIndex = startIndex+smaller.size();

        for(int i=0; i<smaller.size(); i++) nums[i+startIndex] = smaller[i];
        nums[pivotIndex] = pivot;
        for(int i=0; i<larger.size(); i++) nums[i+pivotIndex+1] = larger[i];
        
        // cout << "startIndex: " << startIndex << " endIndex: " << endIndex << " pivot: " << pivot << endl;
        // for(int i=0; i<nums.size(); i++) cout << nums[i] << " ";
        // cout << endl;

        return pivotIndex;
    }

    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
    void dutchNationalFlagAlgo(vector<int>& nums){
        int low = 0, high = nums.size()-1, mid=0;
        while(mid <= high){
            if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums, mid, high);
                high--;
            }
            else{ //nums[mid] == 0
                swap(nums, mid, low);
                low++;
                if(low > mid) mid = low;
            }
        }
        return;
    }
    void quickSort(vector<int>& nums, int startIndex, int endIndex){
        if(startIndex >= endIndex) return;

        int pivotIndex = quickSortFunc(nums, startIndex, endIndex);

        quickSort(nums, startIndex, pivotIndex-1);
        quickSort(nums, pivotIndex+1, endIndex);
        return;

    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        // mergeSort(nums, 0, n-1);
        // quickSort(nums, 0, n-1);
        dutchNationalFlagAlgo(nums);
        return;
    }
};