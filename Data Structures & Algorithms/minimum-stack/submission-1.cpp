class MinStack {

private:
    vector<pair<int,int>> arr;
    int minimum;
    int current;

public:
    MinStack() {
        current = -1;
    }
    
    void push(int val) {
        if (arr.size() == 0){
            current = 0;
            arr.push_back({val, val});
            minimum = val;
        }
        else{
            current++;
            minimum = min(val, arr.back().second);
            arr.push_back({val, minimum});
        }
        return;
    }
    
    void pop() {
        if (arr.size() == 1){
            current = -1;
            arr.pop_back();
        }
        else if (arr.size() == 0){
            return;
        }
        else{
            current--;
            arr.pop_back();
        }
    }
    
    int top() {
        return arr[current].first;
    }
    
    int getMin() {
        return arr[current].second;
    }
};
