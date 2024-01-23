class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int f=0, r=n-1;
        int sum = 0;

        while(f<r) {
            sum = numbers[f] + numbers[r];
            if (sum == target) break;
            else if (sum > target) r--;
            else f++;
        }

        return {f+1, r+1};
    }
};