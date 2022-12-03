#include <iostream>
#include "CommandLine.cpp"
#include "Calculator.cpp"
#include "WeaponCostSummary.hpp"
using namespace std;

int main ()
{
  cout <<"Benvenuto alla prima edizione di calcolo prezzo oggetti magici per D&D prima edizione"<<endl;
  CommandLine cl;
  WeaponCostSummary ws = cl.compute_cost();
  cout<<"Prezzo finale: "<<ws.price<<endl;
  return 0;
}