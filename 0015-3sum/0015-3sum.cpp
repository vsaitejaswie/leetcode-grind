class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // a+b+c = 0
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(auto i=nums.begin(); i!=nums.end(); i++) {
            cout<<*i<<endl;
        }

        for(int i=0; i<n; i++) {

            // this is to make sure same value is not considered to be a as it would lead to duplicate triplets
            while(i>0 && nums[i] == nums[i-1] && i<n-2) { // i<n-2 is an important condition, it will give rise to segmentation errors otherwise.
                i++;
            }

            int f=i+1, r=n-1;
            while(f<r) {
                int threesum = nums[i] + nums[f] + nums[r];
                if(threesum > 0) r--;
                else if(threesum < 0) f++;
                if(threesum == 0) {
                    result.push_back({nums[i], nums[f], nums[r]});

                    // before finding next triplet update either front or back t=such that they are not same as the previous value. Handling one of them is enough as the other would be handled by the if conditions checking the value of threesum

                    f++;
                    while(nums[f] == nums[f-1] && f<r) f++;
                    }

            } 
        }

        return result;
    }
};