class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int farthestPoint = 0;
        int currentJumpEnd = 0;
        for(int i=0; i<nums.size()-1; i++){
            farthestPoint = max(farthestPoint, i+nums[i]);
            if(i == currentJumpEnd){
                jumps++;
                currentJumpEnd = farthestPoint;
            }
        }
        return jumps;
    }
};