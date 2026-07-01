class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(char& ch: s){
            mp[ch]++;
        }
        
        // maxheap to dynamically sort 'char' by 'freq'
        priority_queue<pair<int, char>> pq;
        for(auto& [ch, freq] : mp){
            pq.push({freq, ch});
        }

        string ans = "";

        // taking 2 characters from heap to prevent adjancency problem properly
        while(pq.size() >= 2){
            auto [freq1, ch1] = pq.top(); pq.pop();
            auto [freq2, ch2] = pq.top(); pq.pop();

            ans += ch1;
            ans += ch2;

            // after using the char one time decrease their freq by 1
            // and push them again if their freq is not zero
            if(--freq1 > 0) pq.push({freq1, ch1});
            if(--freq2 > 0) pq.push({freq2, ch2});
        }

        // if pq not empty then it must be the one char left
        // and its freq must be 1, otherwise it not possible
        if(!pq.empty()){
            auto [freq, ch] = pq.top();
            if(freq > 1) return "";
            ans += ch;
        }

        return ans;
        
    }
};