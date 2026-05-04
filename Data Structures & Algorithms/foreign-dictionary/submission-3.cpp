class Solution {
    /* private function to compare and return letter ordering */
    pair<char, char> getLetterOrdering(const string& wordA, const string &wordB) {
        // Go through each letter and see the first mismatch
        for (int i = 0;i < (int)min(wordA.size(), wordB.size()); i++) {
            if (wordA[i] != wordB[i]) {
                return {wordA[i], wordB[i]};
            }
        }

        // Dummy response if no ordering found.
        return {'*', '*'};
    }

public:
    string foreignDictionary(vector<string>& words) {
        /*
        Compare every two adjacent words, and try to find the first letter which differs.
        Create an edge between those letters, and finally apply topological sorting.

        */


        vector<bool> letterPresent(26, false);
        for (const auto &word: words) {
            for (char letter: word) {
                letterPresent[letter - 'a'] = true;
            }
        }
        vector<vector<bool>> adjGraph(26, vector<bool>(26, false));
        
        // compare each of the two words.
        for (int i = 0;i < (int)words.size() - 1; i++) {
            auto ordering = getLetterOrdering(words[i], words[i + 1]);
            if (ordering.first == '*') {
                if (words[i].size() > words[i + 1].size()) {
                    return "";
                }
                continue;
            }

            // Create edge between these 2 letters
            adjGraph[ordering.first - 'a'][ordering.second - 'a'] = true;
        }

        // Calculate indegree and check for cycle as well as proper ordering
        // using topological sort
        vector<int> indegree(26, 0);
        for (int i = 0; i < 26; i++) {
            if (!letterPresent[i]) {
                continue;
            }

            for (int j = 0;j < 26; j++) {
                if (!letterPresent[j]) {
                    continue;
                }
                
                if (i == j) {
                    continue;
                }

                if (adjGraph[i][j]) {
                    indegree[j]++;
                }
            }
        }

        // Find all 0 indegree letters and push to queue
        queue<int> toVisit;
        for (int i = 0;i < 26; i++) {
            if (indegree[i] == 0 && letterPresent[i]) {
                toVisit.push(i);
            }
        }
        string solution;
        while (!toVisit.empty()) {
            int letter = toVisit.front(); toVisit.pop();
            // Push to solution
            solution += letter + 'a';

            for (int i = 0;i < 26; i++) {
                if (letterPresent[i] && adjGraph[letter][i]) {
                    indegree[i]--;
                    if (indegree[i] == 0) {
                        toVisit.push(i);
                    }
                }
            }
        }

        cout << solution << endl;

        // Make sure all letters are included and we have found the solution.
        int letterCount = 0;
        for (auto isPresent: letterPresent) {
            if (isPresent) {
                letterCount++;
            }
        }

        cout << letterCount << endl;

        if (letterCount != (int)solution.size()) {
            // We could not find a valid ordering
            return "";
        }

        return solution;
    }
};
