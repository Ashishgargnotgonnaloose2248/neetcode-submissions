class LRUCache {
public:
    int capacity;

    // key -> {value, node position}
    unordered_map<int, pair<int, list<int>::iterator>> mp;

    // Front = most recently used
    // Back = least recently used
    list<int> recent;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {

        // Key doesn't exist
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        // Move this key to the front
        recent.erase(mp[key].second);
        recent.push_front(key);

        // Update iterator
        mp[key].second = recent.begin();

        return mp[key].first;
    }
    
    void put(int key, int value) {

        // Key already exists
        if(mp.find(key) != mp.end()) {

            // Remove old position
            recent.erase(mp[key].second);

            // Update value
            mp[key].first = value;

            // Make it most recently used
            recent.push_front(key);
            mp[key].second = recent.begin();

            return;
        }

        // Cache is full
        if(mp.size() == capacity) {

            // Last element = least recently used
            int leastRecent = recent.back();

            // Remove it from map
            mp.erase(leastRecent);

            // Remove it from list
            recent.pop_back();
        }

        // Add new key at front
        recent.push_front(key);

        // Store value and iterator
        mp[key] = {value, recent.begin()};
    }
};