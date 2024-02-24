
class Solution {
public:

    void bfs(queue<vector<int>> q, vector<vector<char>> &arr){

        vector<vector<int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
        int n = arr.size();
        int m = arr[0].size();

        while(q.size()!=0){
            vector<int> a = q.front();
            q.pop();
            int i = a[0];
            int j = a[1];
            arr[i][j]='Y';

            for(int k=0; k<4; k++){
                int nr = i+dir[k][0];
                int nc = j+dir[k][1];

                if(nr>=0 && nc>=0 && nr<n && nc<m && arr[nr][nc]=='O'){
                    arr[nr][nc]='Y';
                    q.push({nr,nc});
                }
            }
        }
    }
    void solve(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        queue<vector<int>> q;

        for(int i=0; i<n; i++){
            if(arr[i][0]=='O'){
                q.push({i,0});
            }
            if(arr[i][m-1]=='O'){
                q.push({i,m-1});
            }
        }

        for(int j=1; j<m-1; j++){
            if(arr[0][j]=='O') q.push({0,j});
            if(arr[n-1][j]=='O') q.push({n-1,j});
        }


        bfs(q,arr);


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]=='Y') arr[i][j]='O';
                else if(arr[i][j]=='O') arr[i][j] = 'X';
            }
        }
    }
};