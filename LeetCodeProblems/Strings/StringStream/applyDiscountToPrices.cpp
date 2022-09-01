#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
  string discountPrices(string& sentence, int discount) {
    double dis = 1.0 - discount / 100.0;
    
    stringstream ss (sentence);
    string word, result;
    while (ss >> word) {
      result += applyDiscount(word, dis) + ' ';
    }
    result.pop_back();
    return result;
  }
  
private:
  string applyDiscount(string& s, double discount) {
    if (s[0] != '$' or s.length() == 1)
      return s;
    
    for (int i = 1; i < s.length(); i++) {
      if (!isdigit(s[i]))
        return s;
    }
    double price = stod(s.substr(1,s.length()-1));
      
    stringstream ss;
    ss << '$' << fixed << setprecision(2) << price * discount;
    return ss.str();
  }
};