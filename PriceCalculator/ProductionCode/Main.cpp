#include <iostream>
#include "CommandLine.cpp"
#include "Calculator.cpp"
#include "ItemSummary.hpp"
using namespace std;

int main ()
{
  cout <<"Benvenuto alla prima edizione di calcolo prezzo oggetti magici per D&D prima edizione"<<endl;
  CommandLine cl;
  ItemSummary ws = cl.compute_cost();
  cout<<"Prezzo finale: "<<ws.price<<endl;
  return 0;
}