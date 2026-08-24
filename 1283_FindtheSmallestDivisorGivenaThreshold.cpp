class Solution {
public:
int sumbyD(vector<int> &nums , int div){
        int n = nums.size();
        int sum = 0 ;
        for(int i = 0 ; i < n ; i ++){ 
            sum = sum + ceil((double)(nums[i])/(double)(div));
        }
        return sum;
     }
    int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1;
    int high = *max_element(nums.begin(),nums.end());
    int ans = -1;
    while(low<=high){
        int mid = (low + high)/2;
        if(sumbyD(nums,mid)<=threshold){
            high  = mid -1 ;
        } else{ 
            low = mid + 1;
        }
    }
    return low;
    }
};