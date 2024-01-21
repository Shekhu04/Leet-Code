class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1) return 1; // Means 1 point only available...
        int ans = 0, frequency = 0;
        for(int i = 0; i < points.size(); ++i){ // consider first point P1(x1, y1)...
            for(int j = i + 1; j < points.size(); ++j){ // consider second point P2(x2, y2)...
                frequency = 2; // coz, minimum points required to find slope...
                int dx = points[j][0] - points[i][0]; // (x2 - x1)
                int dy = points[j][1] - points[i][1]; // (y2 - y1)

                for(int k = 0; k < points.size(); ++k){ // consider kth point Pk(xk, yk)...
                    if(k != i && k != j){
                        int dx_ = points[k][0] - points[i][0]; // (xk - x1)
                        int dy_ = points[k][1] - points[i][1]; // (yk - y1)
                        
                        if(dy * dx_ == dy_ * dx) frequency++;
                    }
                }
                ans = max(ans, frequency); // find maximum...
            }
        }
        return ans;
    }
};