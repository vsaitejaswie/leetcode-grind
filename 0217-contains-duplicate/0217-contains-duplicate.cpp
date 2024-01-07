// Map implementation

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         map<int, int> hstore;
//         for(int i=0; i<nums.size(); i++)
//         if(hstore.count(nums[i]) == 0) hstore[nums[i]] = 1;
//         else return true;
//         return false;
//     }
// };

// // Set implementation
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         set<int> hstore;
//         for(int i=0; i<nums.size(); i++)
//         if(hstore.count(nums[i]) == 0) hstore.insert(nums[i]);
//         else return true;
//         return false;
//     }
// };

// Unordered Set implementation - ir has faster retrieval rate comlared to set
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hstore;
        for(int i=0; i<nums.size(); i++)
        if(hstore.count(nums[i]) == 0) hstore.insert(nums[i]);
        else return true;
        return false;
    }
};