#include <iostream>
#include "InputValidation.cpp"
#include "CommandLine.cpp"
#include "Calculator.cpp"
#include "ObjectCreator.cpp"
#include "WeaponCalculator.cpp"
#include "ArmorCalculator.cpp"
#include "ItemSummary.hpp"
#include "ObjectCreationSummary.hpp"
using namespace std;

int main ()
{
   cout <<"\nBenvenuto alla prima edizione di calcolo prezzo oggetti magici per D&D prima edizione"<<endl;
   CommandLine cl;
   while(true)
   {
      ItemSummary item = cl.compute_cost();
      cout<<"Prezzo incantamento iniziale: "<<item.initial_enchantment_cost<<endl;
      cout<<"Prezzo totale: "<<item.total_cost<<endl;
      cout<<"Prezzo per carica: "<<item.charge_cost<<endl;
      cout<<"Livelli di incantamento: ";
      for(size_t i=0;i<item.enchantment_levels.size();i++)
      {
         cout<<item.enchantment_levels[i]<<" ";
      }
      cout<<"\n"<<endl;
      ObjectCreationSummary summary = cl.compute_details_object_creation(item);
      cout<<"Days to create: "<<summary.days_to_create<<endl;
      cout<<"Costo materiali: "<<summary.material_cost<<endl;
      cout<<"Costo lavoro: "<<summary.labor_cost<<endl;
      cout<<"Costo totale: "<<summary.total_cost<<endl;
      cout<<"Tiri richiesti: ";
      for(size_t i=0;i<summary.rolls_required.size();i++)
      {
         cout<<summary.rolls_required[i]<<" ";
      }
      cout<<"\n\n"<<endl;
   }
   return 0;
}