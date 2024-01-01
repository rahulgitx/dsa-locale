
// my solution Time complexity : O(n^3), Space Complexity : O(n)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> arrayXor;
        arrayXor.push_back(arr[0]);
        for(int i=1; i<n; i++) arrayXor.push_back(arrayXor[i-1]^arr[i]);

        int ans = 0;
        for(int k=1; k<n; k++){
            for(int i=0; i<k; i++){
                int xorUptoK = (i>0) ? arrayXor[k]^arrayXor[i-1] : arrayXor[k];
                if(xorUptoK == 0){
                    for(int j=i+1; j<=k; j++){
                        int left = (i>0) ? arrayXor[j-1]^arrayXor[i-1] : arrayXor[j-1];
                        int right = arrayXor[k]^arrayXor[j-1];
                        if(left == right) ans++;
                    }
                }
            }
        }
        return ans;
    }
}


// optimal solution Time complexity : O(n) Space Complexity : O(n) (O(2*n) to be precise)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        int arrayXor = 0, ans = 0;
        mp[0].push_back(-1);
        for(int i=0; i<arr.size(); i++){
            arrayXor = arrayXor^arr[i];
            if(mp.count(arrayXor)){
                for(int j=0; j<mp[arrayXor].size(); j++){
                    ans += (i-mp[arrayXor][j]-1);
                }
            }
            mp[arrayXor].push_back(i);
        }
        return ans;
    }
};