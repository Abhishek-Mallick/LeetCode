class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        // heap helps in approaching problems regarding kth largest or kth smallest
        K = k;
        for(int num : nums) {
            pq.push(num);

            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > K)
            pq.pop();
        
        return pq.top();
    }
};
/*
2 3 3 4 5 8 -> 3
2 3 3 4 5 5 8 -> 5
2 3 3 4 5 5 8 10 -> 
*/

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */