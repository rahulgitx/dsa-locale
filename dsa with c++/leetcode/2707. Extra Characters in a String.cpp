// first approach

class Solution {
public:
    int smallestLeftOut(string& s, unordered_map<string, int>& mp, int startIndex, int lastIndex){
        string temp = "";
        for(int k=startIndex; k<=lastIndex; k++){
            temp += s[k];
        }
        while(temp.size()){
            if(mp[temp]) return (lastIndex-startIndex+1)-temp.size();
            temp = temp.erase(0,1);
        }
        return (lastIndex-startIndex+1);
    }

    int findMinAns(string& s, unordered_map<string, int>& dictionaryMap, int startIndex, vector<int>& dp){
        if(startIndex>s.size()-1) return 0;
        if(dp[startIndex] != -1) return dp[startIndex];

        int ans = INT_MAX;
        for(int k=startIndex; k<s.size(); k++){
            ans = min(ans, smallestLeftOut(s, dictionaryMap, startIndex, k) + findMinAns(s, dictionaryMap, k+1, dp));
        }
        dp[startIndex] = ans;
        return ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> dictionaryMap;
        for(int i=0; i<dictionary.size(); i++){
            dictionaryMap[dictionary[i]]++;
        }

        vector<int> dp(s.size(), -1);

        return findMinAns(s, dictionaryMap, 0, dp);
    }
};