class KthLargest {
public:
    int size;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
     int i;
     size=k;
     for( i=0;i<k&&i<nums.size();i++)
     {
         pq.push(nums[i]);
     }
     for(;i<nums.size();i++)
     {
         if(nums[i]>pq.top())
         {
             pq.pop();
             pq.push(nums[i]);
         }
     }

    }

    int add(int val) {
      if(pq.size()<size)
      {
          pq.push(val);
      }
      else if(pq.top()<val)
      {
          pq.pop();
          pq.push(val);
      }
      return pq.top();
    }
};
