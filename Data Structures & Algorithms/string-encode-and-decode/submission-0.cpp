class Solution {
public:

    string encode(vector<string>& strs) {
        // how about: 
        // we encode a number follow by : followed by str, followed by number followed by :

        string encodedString;
        for (auto &str: strs) {
            encodedString += to_string(str.size());
            encodedString += ":";
            encodedString += str;
        }

        return encodedString;
    }

    vector<string> decode(string s) {
        // Decode the same way
        int readPtr = 0;
        vector<string> decodedStrings;
        while (readPtr < s.size()) {
            // First decode the number which is length
            int currentStringLength = 0;
            string currentString;
            while (s[readPtr] != ':') {
                currentStringLength *= 10;
                currentStringLength += s[readPtr] - '0';
                readPtr++;
            }

            // Read the colon
            readPtr++;
            

            // Start reading and writing till length 
            while (currentStringLength--) {
                currentString += s[readPtr++];
            }

            // Add to decoded strings
            decodedStrings.push_back(currentString);

        }
        return decodedStrings;
    }
};
