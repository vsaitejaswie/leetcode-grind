//Trial 1 - passed 89/212 test cases

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {

//         int maximum = INT_MIN;
//         int n = prices.size();
//         if(n == 0 || n == 1) return 0;
//         int f=0,r=n-1;

//         while(f<r){
//             int difference = prices[r] - prices[f];
//             if (difference <= 0) {f++; maximum = max(maximum, 0);}
//             else {r--; maximum = max(maximum, difference);}
            
//         }

//         return maximum;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maximum = 0;
        int n = prices.size();
        //if(n == 0 || n == 1) return 0;
        int f=0,r=1;

        while(f<r && r<n){
            int difference = prices[r] - prices[f];
            if(prices[r] <= prices[f] && r<n) {
                f = r; 
                //r = f+1; // this is right but instead use it outside the condition
            }
            else if(prices[r] > prices[f] && r<n) {
                maximum = max(maximum, difference);
                //r++; // this is right but instead use it outside the condition
            }
            r++;
        }

        return maximum;
    }
};