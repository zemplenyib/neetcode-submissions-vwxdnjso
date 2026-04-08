class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<string>> groups;
        for (const auto& word : strs) {
            std::string key(26, 0);
            for (auto c : word) {
                key[c - 'a']++;
            }
            
            groups[key].push_back(word);
        }
        std::vector<std::vector<std::string>> result;
        result.reserve(groups.size());
        for (auto& pair : groups) {
            result.push_back(std::move(pair.second));
        }
        return result;
    }
};
