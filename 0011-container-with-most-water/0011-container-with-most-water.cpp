class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int f = 0;
        int r = n-1;
        int product = 0; // least possible area

        while(f<r) {
            product = max(product, min(height[f],height[r])*(r-f));
            cout<<"f: "<<f<<" r: "<<r<<" prod: "<<product<<endl;

            if(height[f]>height[r]) r--;
            else f++;
        }

        return product;
    }
};