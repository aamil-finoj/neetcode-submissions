class MedianFinder {

private:
    priority_queue<int> lowerHalf;
    priority_queue<int, vector<int>, greater<int>> upperHalf;


public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        lowerHalf.push(num);

        upperHalf.push(lowerHalf.top());
        lowerHalf.pop();

        while (lowerHalf.size()<upperHalf.size()){
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
        }

    }
    
    double findMedian() {
        if (upperHalf.size()==0) return lowerHalf.top();
        if (lowerHalf.size() > upperHalf.size()) return lowerHalf.top();
        return (double)(lowerHalf.top() + upperHalf.top())/2.0;
    }
};
