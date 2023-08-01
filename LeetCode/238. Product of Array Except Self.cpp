class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> answer(size);

        int totalMult = 1;
        int zeroIdx = 0;
        bool foundZero = false;
        
        for(int i = 0; i < size; i++){
            if(nums[i] == 0){
                if(foundZero) return answer;
                foundZero = true;
                zeroIdx = i;
            }
            else totalMult *= nums[i];
        }

        if(foundZero){
            answer[zeroIdx] = totalMult;
            return answer;
        }
        else{
            for(int i = 0; i < size; i++){
                answer[i] = totalMult / nums[i];
            }
        }

        return answer;
    }
};
