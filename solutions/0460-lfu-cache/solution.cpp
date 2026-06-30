class LFUCache {
public:
    int cap;
    int minFreq;

    // key -> {value, frequency}
    unordered_map<int, pair<int, int>> keyValue;

    // freq -> list of keys
    unordered_map<int, list<int>> freqList;

    // key -> iterator in its frequency list
    unordered_map<int, list<int>::iterator> position;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyValue.find(key) == keyValue.end())
            return -1;

        updateFrequency(key);
        return keyValue[key].first;
    }

    void put(int key, int value) {

        if (cap == 0)
            return;

        // Key already exists
        if (keyValue.find(key) != keyValue.end()) {
            keyValue[key].first = value;
            updateFrequency(key);
            return;
        }

        // Cache Full
        if (keyValue.size() == cap) {

            int removeKey = freqList[minFreq].back();

            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty())
                freqList.erase(minFreq);

            keyValue.erase(removeKey);
            position.erase(removeKey);
        }

        // Insert new key

        keyValue[key] = {value, 1};

        freqList[1].push_front(key);

        position[key] = freqList[1].begin();

        minFreq = 1;
    }

    void updateFrequency(int key) {

        int freq = keyValue[key].second;

        // Remove from old frequency list
        freqList[freq].erase(position[key]);

        if (freqList[freq].empty()) {

            freqList.erase(freq);

            if (minFreq == freq)
                minFreq++;
        }

        // Increase frequency
        keyValue[key].second++;

        freq++;

        // Insert into new frequency list
        freqList[freq].push_front(key);

        position[key] = freqList[freq].begin();
    }
};
