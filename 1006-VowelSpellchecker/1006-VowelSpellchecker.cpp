// Last updated: 1/6/2026, 10:02:30 PM
class Solution {
public:
    // Converts a word to lowercase
    string toLowercase(const string &word) {
        string res = word;
        for (char &c : res) c = tolower(c);
        return res;
    }

    // Converts vowels to '*' for vowel error matching
    string maskVowels(const string &word) {
        string res = word;
        for (char &c : res) {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                c = '*';
            else
                c = lower;
        }
        return res;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactMatch(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;

        // Preprocess wordlist
        for (const string &word : wordlist) {
            string lower = toLowercase(word);
            string vowelMasked = maskVowels(word);

            // Only store the first occurrence
            if (!caseInsensitive.count(lower))
                caseInsensitive[lower] = word;
            if (!vowelInsensitive.count(vowelMasked))
                vowelInsensitive[vowelMasked] = word;
        }

        vector<string> result;
        for (const string &query : queries) {
            if (exactMatch.count(query)) {
                result.push_back(query);
                continue;
            }

            string lower = toLowercase(query);
            if (caseInsensitive.count(lower)) {
                result.push_back(caseInsensitive[lower]);
                continue;
            }

            string vowelMasked = maskVowels(query);
            if (vowelInsensitive.count(vowelMasked)) {
                result.push_back(vowelInsensitive[vowelMasked]);
                continue;
            }

            result.push_back(""); // no match
        }

        return result;
    }
};
