class MedianFinder {
private:
    // Rlements on left half.
    priority_queue<int, vector<int>, less<int>> max_heap;
    // Elements on the right half.
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (max_heap.size() == 0 && min_heap.size() == 0) {
            max_heap.push(num);
        } else if (max_heap.size() == min_heap.size()) {
            if (max_heap.top() >= num)
                max_heap.push(num);
            else 
                min_heap.push(num);
        } else if (max_heap.size() > min_heap.size()) {
            // Max-heap has 1 element more than the min-heap.
            if (max_heap.top() < num) {
                min_heap.push(num);
            } else {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
        } else {
            // Min-heap has 1 element more than the max-heap.
            if (min_heap.top() > num) {
                max_heap.push(num);
            } else {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
        }
    }
    
    double findMedian() {
        if (min_heap.size() > max_heap.size()) {
            return min_heap.top();
        } else if (min_heap.size() < max_heap.size()) {
            return max_heap.top();
        } else {
            return ((double)min_heap.top() + (double)max_heap.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
