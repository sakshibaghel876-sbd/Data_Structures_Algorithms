class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        vector<int> a; //negative
        vector<int> b; //positive

        for(int k = 0; k<n; k++){
            if(nums[k]<0){
                a.push_back(nums[k]);
            }
            else{
                b.push_back(nums[k]);
            }
        }
        if(a.size()==0){ // if saare positive hai

            for(int i = 0; i<n; i++){
                nums[i]= nums[i]*nums[i];
            }
            return nums;
        }

        if(b.size()==0) // saare negative hai
        {
            for(int i = 0; i<n; i++){
                nums[i]= nums[i]*nums[i];
            }
            reverse(nums.begin(), nums.end());
            return nums;
        }
        else{
            for(int i = 0; i<a.size(); i++){
                a[i]=a[i]*a[i];
            }
            reverse(a.begin(), a.end());

            for(int i = 0; i<b.size(); i++){
                b[i]=b[i]*b[i];
            }

        }

        int i = 0;
        int j = 0;

        vector<int> ans;

        while(i<a.size() && j<b.size()){

            if(a[i]<b[j]){
                ans.push_back(a[i]);
                i++;
            }
            else{
                ans.push_back(b[j]);
                j++;
            }
        }
        while(i<a.size()){
            ans.push_back(a[i]);
            i++;
        }
        while(j<b.size()){
            ans.push_back(b[j]);
            j++;
        }
        for(int k = 0; k<n ; k++){
            nums[k]=ans[k];
        }
        return nums;
    }
};