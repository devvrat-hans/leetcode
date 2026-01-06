// Last updated: 1/6/2026, 10:01:49 PM
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> available(supplies.begin(), supplies.end());
        queue<string> q;
        vector<string> result;

        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();
            for (const string& ingredient : ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);
            }
        }

        for (const string& item : supplies) {
            q.push(item);
        }

        while (!q.empty()) {
            string item = q.front();
            q.pop();

            if (find(recipes.begin(), recipes.end(), item) != recipes.end()) {
                result.push_back(item);
            }

            for (const string& nextRecipe : graph[item]) {
                if (--indegree[nextRecipe] == 0) {
                    q.push(nextRecipe);
                    available.insert(nextRecipe);
                }
            }
        }

        return result;
    }
};
