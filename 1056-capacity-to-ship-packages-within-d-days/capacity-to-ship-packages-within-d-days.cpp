
int findDays(vector<int> &weights , int cap) {
    int days = 1, load = 0;
    for(int i = 0; i < weights.size(); i++) {
        if(weights[i] + load > cap){
            days = days + 1;
            load = weights[i];
        }
        else{
            load = load + weights[i];
        }
    }
    return days;
}

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

    int low = *max_element(weights.begin(), weights.end()); //max element in array
    int high = accumulate(weights.begin(), weights.end(), 0); // sum of arrays

    while (low <= high){
        int mid = low + (high-low)/2;
        int numberOfDays = findDays(weights, mid);
        if(numberOfDays <= days) high = mid-1;
        else low = mid+1;
    }
    return low;
        
    }
};