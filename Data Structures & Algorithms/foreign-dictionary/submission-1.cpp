const int LETTERS_IN_ALPHABET = 26;

class Solution {

    vector<char> compare(const string &wordA, const string &wordB) {
        int sz = min(wordA.size(), wordB.size());

        for (int i = 0;i < sz; i++) {
            if (wordA[i] != wordB[i]) {
                return { wordA[i], wordB[i] };
            }
        }

        return {};
    }

public:
    string foreignDictionary(vector<string>& words) {
        // Compare each of the two letters in two adjancent strings,
        // and figure out the relation between them.
        // Use that relation to generate an ordering if possible.

        // Get all possible letters
        unordered_map<char, unordered_set<char>> ordering;
        for (auto word: words) {
            for (auto ch: word) {
                ordering[ch];
            }
        }


        unordered_map<char, int> indegree;
        for (int i = 0;i < (int)words.size() - 1; i++) {
            // Compare both words and get order
            vector<char> currentOrder = compare(words[i], words[i + 1]);
            if (!currentOrder.empty()) {
                if (!ordering[currentOrder[0]].count(currentOrder[1]) > 0) {
                    ordering[currentOrder[0]].insert(currentOrder[1]);
                    indegree[currentOrder[1]]++;
                }
            } else if (words[i].size() > words[i + 1].size()) {
                // Handle the case when the ordering itself is wrong due to
                // current word and previous word have same prefix and previous word
                // has more letters.
                return "";
            }
        }

        queue<char> lettersToVisit;
        for (auto [ch, nextSet]: ordering) {
            if (indegree[ch] == 0) {
                lettersToVisit.push(ch);
            }
        }

        string alienOrder;
        while (!lettersToVisit.empty()) {
            auto currentLetter = lettersToVisit.front();
            lettersToVisit.pop();

            // Update alien order
            alienOrder += currentLetter;

            // Visit next set of letters
            for (auto nextLetter: ordering[currentLetter]) {
                indegree[nextLetter]--;
                if (indegree[nextLetter] == 0) {
                    lettersToVisit.push(nextLetter);
                }
            }
        }

        if (alienOrder.size() == ordering.size()) {
            return alienOrder;
        }

        return "";

    }
};
