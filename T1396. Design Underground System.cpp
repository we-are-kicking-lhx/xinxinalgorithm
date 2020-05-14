class UndergroundSystem {
public:
	unordered_map<int,pair<int,string>> psg;
    unordered_map<string,pair<double,int>>record;
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        psg[id] = make_pair(t,stationName);
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<int,string>psg_info = psg[id];
        string key = psg_info.second + " " + stationName;
        pair<double,int>stn_info = record[key];
        record[key].first += 1.0;
        record[key].second += t - psg_info.first;
    }
    
    double getAverageTime(string startStation, string endStation) {
         pair<double,int>stn_info = record[startStation+" "+endStation];
         return stn_info.second/stn_info.first;
    }
};