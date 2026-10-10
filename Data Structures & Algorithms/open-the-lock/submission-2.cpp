class Solution {
public:

    vector<string> addNext (string curr){
        vector<string> ans;

        for (int i=0; i<4; i++){
            string temp = curr;
            temp[i] = (temp[i] - '0' + 1) % 10 + '0';
            ans.push_back(temp);

            temp = curr;
            temp[i] = (temp[i] - '0' - 1 + 10) % 10 + '0';
            ans.push_back(temp);
        }

        return ans;
    }

    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> s;
        for (string it : deadends) s.insert(it);

        if (s.count("0000")) return -1;

        queue<pair<string,int>> q;
        q.push({"0000", 0});
        s.insert("0000");


        while (!q.empty()){
            string curr = q.front().first;
            int turns = q.front().second;
            q.pop();

            if (curr == target) return turns;
            
            for (string child : addNext(curr)){
                if (!s.count(child)){
                    s.insert(child);
                    q.push({child, turns+1});
                }
            }

        }

        return -1;


    }
};