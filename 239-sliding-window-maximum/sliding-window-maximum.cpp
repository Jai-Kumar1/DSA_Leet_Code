class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;
        vector<int>ans;
        for(int i =0;i<k;i++){
            int element =nums[i];
            while(!dq.empty() && nums[dq.back()] < element){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        int index = dq.front();
        int element = nums[index];
        ans.push_back(element);
        for(int i = k;i<n;i++){
            if(!dq.empty() &&  dq.front() < i-k+1){
                dq.pop_front();
            }
            int element =nums[i];
            while(!dq.empty() && nums[dq.back()] < element){
                dq.pop_back();
            }
            dq.push_back(i);

            int index = dq.front();
            int ansElement = nums[index];
            ans.push_back(ansElement);
        }
        return ans;
    }
};