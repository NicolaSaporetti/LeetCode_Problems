using namespace std;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long volume = length;
        volume*=width;
        volume*=height;
        bool bulky = (length>=10000 || width>=10000 || height>=10000 || volume>=1000000000)? true : false;
        bool heavy = (mass>=100)? true : false;
        if(bulky && heavy) return "Both";
        else if(!bulky && !heavy) return "Neither";
        else if(bulky) return "Bulky";
        else return "Heavy";
    }
};