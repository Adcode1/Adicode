class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int a;
    KthLargest(int k, vector<int>& nums) {
      a=k;
      for(int i=0;i<nums.size();i++){
          if(pq.size()<k){
          pq.push(nums[i]);  
          }
          else{
              if(pq.top()<nums[i]){
                  pq.push(nums[i]);
              }
          }
    }}
    int add(int val) {
        if(pq.size()<a){
                pq.push(val);
            }
        else{
            if(val>pq.top()){
                pq.push(val);
            }
        }
        while(pq.size()>a){
            pq.pop();
        }
        int temp=pq.top();
        return temp;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */