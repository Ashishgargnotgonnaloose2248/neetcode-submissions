class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        vector<int> result;

        int count = 0;

        for(int x: nums){
            mp[x]++;
        }

        vector<pair<int,int>> v;

        for(auto it: mp){
            v.push_back({it.second, it.first});
        }

        sort(v.rbegin(), v.rend());

        for(int i = 0; i<k; i++){
            result.push_back(v[i].second);
        }
      return result;
    }
};
