class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> heap; //Max_Heap to find maximum in a sliding window
        vector<int> ans;    //Stores all maximum values for all sliding windows

        for(int i=0;i<nums.size();++i)
        {
            while(!heap.empty() and heap.top().second<=(i-k))  //Pop the root (max_element),if it is out of sliding window
                heap.pop();
            heap.push(make_pair(nums[i],i));    //Push current element (along with its index) into the heap
            if(i>=k-1)      //Store max in the window if we have a valid window (based on size K)
                ans.push_back(heap.top().first);
        }
        return ans;
    }
};
