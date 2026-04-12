class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        char c=digit+'0'; 
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            for(auto it : s){
                if(it==c)cnt++;
            }
        }

        return cnt;
    }
};