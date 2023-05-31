class UndergroundSystem {
public:
unordered_map<int,pair<string,int>>mp; // id, {station, checkin}
unordered_map<string, pair<int,int>>stats; // station ,{ tot duration, tripscnt}
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string start, int timeIn) {
        mp[id]={start, timeIn};
    }
    
    void checkOut(int id, string end, int timeOut) {
        const auto &[start,timeIn]= mp[id];
        auto &[totDuration, tripsCnt]= stats[start +"_"+ end];
         totDuration+= timeOut -timeIn;
         tripsCnt++;
    }
    
    double getAverageTime(string start, string end) {
        auto [totDuration, tripsCnt]= stats[start+"_"+ end];
        return (double)totDuration/ tripsCnt;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */