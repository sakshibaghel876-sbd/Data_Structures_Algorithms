class Solution {
public:

    void fun(vector<int>&a, int n, int i, int sum, int target, vector<int>& diary,vector<vector<int>>& res){

        if(i==n){
            if(sum==target){
                res.push_back(diary);
            }
            return;
        }
        fun(a, n, i+1, sum, target, diary, res);

        if(sum+a[i]<=target){
            diary.push_back(a[i]);
            sum=sum+a[i];
            fun(a, n, i, sum, target, diary, res);
            diary.pop_back();
            sum=sum-a[i];
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        vector<int>diary;
        vector<vector<int>>res;
        fun(candidates, n, 0, 0, target, diary, res);
        return res;
    }
};