class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string,string>hmap;
        hmap["Jan"] = "01";
        hmap["Feb"] = "02";
        hmap["Mar"] = "03";
        hmap["Apr"] = "04";
        hmap["May"] = "05";
        hmap["Jun"] = "06";
        hmap["Jul"] = "07";
        hmap["Aug"] = "08";
        hmap["Sep"] = "09";
        hmap["Oct"] = "10";
        hmap["Nov"] = "11";
        hmap["Dec"] = "12";
        string day,month,year;
        int len = date.length();
        year = date.substr(len - 4,4);
        month = date.substr(len - 4 - 1 - 3,3);
        day = date.substr(0,len - 2 - 4 - 3 - 2);
        month = hmap[month];
        if(day.length()==1)day = "0" + day;
        return year + "-" + month + "-" + day;
    }
};
