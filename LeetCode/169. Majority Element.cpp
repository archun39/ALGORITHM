class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<string, int> m;
        for(int i = 0; i < nums.size(); i++){
            string num = to_string(nums[i]);
            if(m.find(num) == m.end()) m[num] = 1;
            else m[num]++;
            if(m[num] > nums.size()/2) return stoi(num);
        }
        return 0;
    }
};
