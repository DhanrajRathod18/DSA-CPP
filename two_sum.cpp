#include<bits/stdc++.h>
using namespace std;

vector<int> two_sum(vector<int> &arr, int k) {

    for(int i = 0; i < arr.size(); i++) {

        for(int j = i + 1; j < arr.size(); j++) {

            if(arr[i] + arr[j] == k) {
                return {i, j};
            }
        }
    }

    return {};
}

int main() {

    int k = 14;
    vector<int> arr = {2,6,5,8,11};

    vector<int> ans = two_sum(arr, k);

    if(ans.size() == 2)
        cout << ans[0] << " " << ans[1];
    else
        cout << "No pair found";

    return 0;
}