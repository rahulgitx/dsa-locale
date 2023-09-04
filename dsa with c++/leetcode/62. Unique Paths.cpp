class Solution {
private:
    int x, y;
    int x_axis[2] = {1, 0};
    int y_axis[2] = {0, 1};
public:
    int dfs(int i, int j, vector<vector<int>>& visited){
        if(i == x-1 && j == y-1) return 1;
        if(visited[i][j]) return visited[i][j];
        int a, b;
        for(int k=0; k<2; k++){
            a = i+x_axis[k];
            b = j+y_axis[k];
            if(a<x && b<y) visited[i][j] += dfs(a,b, visited);
        }
        return visited[i][j];
    }

    int uniquePaths(int m, int n) {
        this->x = m; 
        this->y = n;
        vector<vector<int>> visited(x, vector<int>(y, 0));
        int ans = dfs(0,0, visited);
        return ans;
    }
};