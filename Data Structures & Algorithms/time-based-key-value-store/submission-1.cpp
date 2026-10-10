class TimeMap {

private:
    unordered_map<string, vector<pair<int,string>>> master;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        master[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!master.count(key) || master[key].size()==0) return "";

        int l = 0, r = master[key].size() - 1;
        int idx = -1;

        while (l<=r){
            int mid = l + (r-l)/2;
            if (master[key][mid].first == timestamp){
                idx = mid;
                break;
            }
            else if (master[key][mid].first < timestamp){
                idx = mid;
                l = mid+1;
            }
            else 
                r = mid-1;
        }

        if (idx==-1) return "";
        return master[key][idx].second;


    }


};
