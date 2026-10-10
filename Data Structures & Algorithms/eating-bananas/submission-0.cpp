class Solution {
public:

    bool check(vector<int>& piles, int h, int rate){

        int time = 0;
        for (int i=0; i<piles.size(); i++){
            if (piles[i]%rate == 0)
                time+=piles[i]/rate;
            else time+=piles[i]/rate + 1;

            if (time>h) return false;
        }
        return true;


    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        int m = *max_element(piles.begin(), piles.end());

        int l = 1, r = m;
        int ans = INT_MAX;
        while (l<r){

            int mid = l + (r-l)/2;

            if (check(piles,h,mid))
                r=mid;
            else
                l = mid+1;

        }

        return r;

    }
};
