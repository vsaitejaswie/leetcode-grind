class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> compare;
        vector<int> result;

        //two-pass hash table cannot be implemented without figuring out how to handle collisions
        //because values in the nums vector are repeating

        //one-pass hast table: faced similar issues while implementing this too

        //looks like the only way to avoid these issues by first checking if the 
        //complement exists in the map and then proceeding with new map additions

        for(int i=0; i<nums.size(); i++){
            bool match = compare.count(target-nums[i]); // for debug
            cout<<match<<endl; // for debug
            if(compare.find(target-nums[i]) != compare.end()){
                    result.push_back(i);
                    result.push_back(compare[target-nums[i]]);
                    break;
                } else {
                    compare[nums[i]] = i;
                }
        }

        return result;
    }
};