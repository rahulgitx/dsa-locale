class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++){
            for(int j=i; j<matrix[0].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<matrix.size(); i++){
            reverse(matrix[i]);
        }
        return;
    }

    void reverse(vector<int>& v){
        int i=0, j=v.size()-1;
        while(i<j){
            swap(v[i], v[j]);
            i++; j--;
        }
        return;
    }

};