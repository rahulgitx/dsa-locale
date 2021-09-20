 long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long presum, currsum = arr[0];
        long long max = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (currsum < 0 && arr[i] < 0)
            {
                if (arr[i] > currsum)
                {
                    currsum = arr[i];
                }
            }
            else if (currsum <= 0 && arr[i] > 0)
            {
                currsum = arr[i];
            }
            else
            {
                currsum += arr[i];
            }
            // currsum += arr[i];
            if (max < 0 && arr[i] > 0)
            {
                max = arr[i];
            }
            if (currsum > max)
            {
                max = currsum;
            }

            
        }
        return max;
    }
