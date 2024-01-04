class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 1, lastBallonShotEnd = points[0][1];
        for(int i=1; i<points.size(); i++){
            if(points[i][0] <= lastBallonShotEnd){
                lastBallonShotEnd = min(lastBallonShotEnd, points[i][1]);
            }
            else{
                count++;
                lastBallonShotEnd = points[i][1];
            }
        }

        return count;
    }
};