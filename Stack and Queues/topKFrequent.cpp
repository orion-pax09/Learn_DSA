
class Solution {
public:

    // CUSTOM COMPARATOR:
    // Decides which pair gets higher priority in the priority queue.
    struct Comparator {

        // operator() makes this struct callable like a function.
        // a and b are two pairs being compared.
        // Each pair stores {frequency, word}.
        bool operator()(const pair<int, string>& a,
                        const pair<int, string>& b) const {

            // If both words have the same frequency...
            if (a.first == b.first) {

                // Alphabetically larger word has lower priority.
                // Example: "banana" > "apple" is true.
                // Therefore, "apple" gets higher priority.
                return a.second > b.second;
            }

            // If frequencies differ:
            // Lower frequency has lower priority.
            // Example: 2 < 5 is true, so frequency 2 goes behind 5.
            return a.first < b.first;
        }
    }; // Semicolon required after the struct definition.

    vector<string> topKFrequent(vector<string>& words, int k) {

        // STEP 1: Count how often each word appears.
        // Key = word, value = frequency.
        unordered_map<string, int> mp;

        for (int i = 0; i < words.size(); i++) {

            // Increase this word's frequency by 1.
            // Creates the entry with 0 first if the word is new.
            mp[words[i]]++;
        }

        // STEP 2: Create a priority queue.
        // pair<int, string> = {frequency, word}
        // vector<pair<int, string>> = internal storage container
        // Comparator = our custom ordering rule
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            Comparator
        > PQ;

        // STEP 3: Put every unique word and its frequency into the heap.
        // x.first  = word
        // x.second = frequency
        for (auto x : mp) {

            // Push {frequency, word} into the priority queue.
            PQ.push({x.second, x.first});
        }

        // STEP 4: Store the final k words here.
        vector<string> vt;

        // Continue until we have k words or the queue becomes empty.
        while (k > 0 && !PQ.empty()) {

            // top() reads the highest-priority pair.
            // .second extracts the word from {frequency, word}.
            vt.push_back(PQ.top().second);

            // Remove that highest-priority pair from the queue.
            PQ.pop();

            // One fewer word remains to be collected.
            k--;
        }

        // STEP 5: Return the k most frequent words in the required order.
        return vt;
    }
};
