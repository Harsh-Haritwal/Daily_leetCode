class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        string ans;

        for (auto& c : s) {
            mp[c]++;
        }

        vector<pair<int, char>> arr;

        for (auto& pair : mp) {
            arr.push_back({pair.second, pair.first});
        }

        sort(arr.begin(), arr.end(), greater<pair<int, char>>());
        for (auto& pair : arr) {
            ans.append(pair.first, pair.second);
        }

        return ans;
    }
};