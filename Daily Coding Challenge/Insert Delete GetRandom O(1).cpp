class RandomizedSet {
public:
    set<int>randomizedSet;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!randomizedSet.count(val))
        {
            randomizedSet.insert(val);
            return true;
        }
        
        return false;
    }
    
    bool remove(int val) {
        if(randomizedSet.count(val))
        {
            randomizedSet.erase(val);
            return true;
        }
            return false;

    }
    
    int getRandom() {
        if(randomizedSet.size() != 0)
            return *next(randomizedSet.begin(),rand()%randomizedSet.size()); 
    return 0;
    }
};
/**
