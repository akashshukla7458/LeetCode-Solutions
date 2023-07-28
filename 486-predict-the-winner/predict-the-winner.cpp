class Solution {
public:

int solve(vector<int>&nums, int i, int j){
    if(i>j) return 0;
    if(i==j) return nums[i];
    int curr_score= max( 
       ( nums[i]+ min(solve(nums,i+2,j), solve(nums,i+1,j-1))),
    
       ( nums[j]+ min(solve(nums,i+1,j-1), solve(nums,i,j-2)))
    );
    return curr_score;
}
    bool PredictTheWinner(vector<int>& nums) {
        int score= solve(nums,0,nums.size()-1);
        int max_score=0;
        for(auto it: nums) max_score+=it;
        return score >= max_score- score;
    }
};