class Solution {
public:
    int majorityElement(vector<int>& nums) {
    map<int ,int> mp;
    for(int i = 0 ;i<nums.size();i++){
        mp[nums[i]]++;
    }
    for(auto it : mp){
        if(it.second > nums.size()/2){
            return it.first;
        }
    }
    return -1;
    } 

    //brute force 
    #include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,2,2,2,3};
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        int cnt = 0;

        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) {
                cnt++;
            }
        }

        if(cnt > n/2) {
            cout << arr[i];
            return 0;
        }
    }

    cout << -1;
    return 0;
}