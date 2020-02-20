class Solution {
public:
    string defangIPaddr(string address) {
        size_t it=address.find(".");
        while(it!=string::npos){
            address.replace(it,1,"[.]");
            it=address.find(".",it+2);
        }
        return address;
    }
};