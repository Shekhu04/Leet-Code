class Solution {

long long getHours(vector<int>& piles, long long speed) {
    long long count = 0;
    for(auto itr:piles) {
        count += (itr/speed + (itr%speed != 0));
    }
    return count;
}

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long high = 1e10, low = 1;
        long long ans = low;
        while(low <= high) {
            int mid = (low + high)/2;
            if(h >= getHours(piles, mid)) {
                ans = mid;
                high = mid - 1;
            } else 
                low = mid + 1;
        }
        return (int)ans;
    }
};