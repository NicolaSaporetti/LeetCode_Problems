#include "CommandLine.hpp"
#include "Weapon.hpp"
#include "WeaponCostSummary.hpp"
#include "Calculator.hpp"
#include <iostream>
using namespace std;

WeaponCostSummary CommandLine::compute_cost()
{
    int choice =0;
    cout<<"Digitare tipologia equipaggiamento\n1: Arma\n2: Armatura\n3: Pozioni\n4: Pergamene"<<endl;
    cin>>choice;
    WeaponCostSummary result;
    switch(choice) {
        case 1:
        {
            int price = fill_cost();
            int encoumber = fill_encoumber();
            int primary_bonus = fill_primary_bonus();
            int secondary_bonus = fill_secondary_bonus();
            Weapon weapon = {price,encoumber,primary_bonus,secondary_bonus};
            result = calculator.calculate_cost_weapon(weapon);
            break;
        }
        case 2:
        {
            int price = fill_cost();
            int encoumber = fill_encoumber();
            int primary_bonus = fill_primary_bonus();
            Armor armor = {price,encoumber,primary_bonus};
            result = calculator.calculate_cost_armor(armor);
            break;
        }
        case 3:
        {
            int spell_level = fill_spell_level();
            int doses = fill_doses();
            Potion armor = {spell_level,doses};
            //result = calculator.calculate_cost_armor(armor);
            break;
        }
        case 4:
        {
            int spell_levels = fill_spell_levels();
            Scroll armor = {spell_levels};
            //result = calculator.calculate_cost_armor(armor);
            break;
        }
    }
    return result;
}

int CommandLine::fill_cost()
{
    cout<<"Digitare costo"<<endl;
    return fill_int();
}

int CommandLine::fill_encoumber()
{
    cout<<"Digitare ingombro"<<endl;
    return fill_int();
}

int CommandLine::fill_primary_bonus()
{
    cout<<"Digitare bonus primario"<<endl;
    return fill_int();
}

int CommandLine::fill_secondary_bonus()
{
    cout<<"Digitare bonus secondario"<<endl;
    return fill_int();
}

int CommandLine::fill_spell_level()
{
    cout<<"Digitare livello incantesimo"<<endl;
    return fill_int();
}

int CommandLine::fill_doses()
{
    cout<<"Digitare numero dosi"<<endl;
    return fill_int();
}

int CommandLine::fill_spell_levels()
{
    cout<<"Digitare somma livelli incantesimi"<<endl;
    return fill_int();
}

int CommandLine::fill_int()
{
    int value; 
    cin>>value;
    return value;
}