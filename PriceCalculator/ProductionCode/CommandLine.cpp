#include "CommandLine.hpp"
#include "Item.hpp"
#include "ItemSummary.hpp"
#include "ObjectCreationSummary.hpp"
#include "ObjectRecipe.hpp"
#include "Calculator.hpp"
#include <iostream>
using namespace std;

ItemSummary CommandLine::compute_cost()
{
    int choice =0;
    cout<<"Digitare tipologia equipaggiamento\n1: Armi\n2: Armature scudi\n3: Pozioni\n4: Pergamene\n5: Bacchette"<<endl;
    cout<<"6: Oggetti magici con cariche (Bastoni)\n7: Anelli accumulatori\n8: Oggetti magici permanenti"<<endl;
    cin>>choice;
    ItemSummary result;
    switch(choice) {
        case 1:
        {
            cout<<"Digitare tipologia di arma\n1: Spade\n2: Altre armi"<<endl;
            cin>>choice;
            if(choice==1)
            {
                Sword sword = {{get_sword_type(),fill_primary_bonus(),fill_secondary_bonus()},fill_third_bonus()};
                result = calculator.calculate_cost_sword(sword);
            }
            else{
                Weapon weapon = {get_various_weapon_type(),fill_primary_bonus(),fill_secondary_bonus()};
                result = calculator.calculate_cost_weapon(weapon);
            }
            break;
        }
        case 2:
        {
            Armor armor = {get_armor_type(),fill_primary_bonus()};
            result = calculator.calculate_cost_armor(armor);
            break;
        }
        case 3:
        {
            ItemWithCharges potion = {RechargeType::Non_recheargeable,{fill_spell_level()},fill_doses()};
            result = calculator.calculate_cost_item_with_charges(potion);
            break;
        }
        case 4:
        {
            ItemWithCharges scroll = {RechargeType::Non_recheargeable,fill_spells(),1};
            result = calculator.calculate_cost_item_with_charges(scroll);
            break;
        }
        case 5:
        {
            ItemWithCharges item_with_charges = {get_recharge_type(),{fill_spell_level()},fill_charges()};
            result = calculator.calculate_cost_item_with_charges(item_with_charges);
            break;
        }
        case 6:
        {
            ItemWithCharges item_with_charges = {get_recharge_type(),fill_spells(),fill_charges()};
            result = calculator.calculate_cost_item_with_charges(item_with_charges);
            break;
        }
        case 7:
        {
            ItemWithCharges item_with_charges = {RechargeType::Recheargeable,fill_spells(),1};
            result = calculator.calculate_cost_item_with_charges(item_with_charges);
            break;
        }
        case 8:
        {
            PermanentItem permanent_item = {fill_spell_level()};
            result = calculator.calculate_cost_permanent_item(permanent_item);
            break;
        }
    }
    return result;
}

ObjectCreationSummary CommandLine::compute_details_object_creation(const ItemSummary& item)
{
    ObjectCreationSummary result;
    ObjectRecipe recipe = {item.total_cost,fill_caster_levels(),item.enchantment_levels};
    result = objectCreator.calculate_cost_magic_object(recipe);
    return result;
} 

int CommandLine::fill_primary_bonus()
{
    cout<<"Digitare bonus primario (1-5)"<<endl;
    int value = fill_int();
    while (!inputValidation.verify_bonus_is_correct(value))
    {
        cout<<"Valore incorretto, riprovare"<<endl;
        value = fill_int(); 
    }
    return value;
}

int CommandLine::fill_secondary_bonus()
{
    cout<<"Digitare bonus secondario (0-5)"<<endl;
    return fill_second_bonus();
}

int CommandLine::fill_third_bonus()
{
    cout<<"Digitare bonus terziario (0-5)"<<endl;
    return fill_second_bonus();
}

int CommandLine::fill_second_bonus()
{
    int value = fill_int();
    while (!inputValidation.verify_secondary_bonus_is_correct(value))
    {
        cout<<"Valore incorretto, riprovare"<<endl;
        value = fill_int(); 
    }
    return value;
}

int CommandLine::fill_doses()
{
    cout<<"Digitare numero dosi (1-3)"<<endl;
    int value = fill_int();
    while (!inputValidation.verify_doses_are_correct(value))
    {
        cout<<"Valore incorretto, riprovare"<<endl;
        value = fill_int(); 
    }
    return value;
}

vector<int> CommandLine::fill_spells()
{
    int spell_num = fill_number_of_spells();
    vector<int> spells(spell_num);
    for(size_t i=0;i<spell_num;i++)
    {
        spells[i]=fill_spell_level();
    }
    return spells;
}

int CommandLine::fill_number_of_spells()
{
    cout<<"Digitare numero di incantesimi"<<endl;
    int value = fill_int();
    while (!inputValidation.verify_number_of_spells(value))
    {
        cout<<"Valore incorretto, riprovare"<<endl;
        value = fill_int(); 
    }
    return value;
}

int CommandLine::fill_spell_level()
{
    cout<<"Digitare livello incantesimo (1-9)"<<endl;
    int value = fill_int();
    while (!inputValidation.verify_spell_level_is_correct(value))
    {
        cout<<"Valore incorretto, riprovare"<<endl;
        int value = fill_int(); 
    }
    return value;
}

int CommandLine::fill_charges()
{
    cout<<"Digitare numero cariche (1-40)"<<endl;
    int value = fill_int();
    while (!inputValidation.verify_charges_are_correct(value))
    {
        cout<<"Valore incorretto, riprovare"<<endl;
        value = fill_int(); 
    }
    return value;
}

WeaponType CommandLine::get_sword_type()
{
    cout<<"Digitare il tipo di spada:\n1: Spada\n2: Spada_a_2_mani\n3: Spada_bastarda\n4: Spadino"<<endl;
    int value = fill_int();
    WeaponType type;
    switch(value)
    {
        case 1: type= WeaponType::Spada; break;
        case 2: type= WeaponType::Spada_a_2_mani; break;
        case 3: type= WeaponType::Spada_bastarda; break;
        case 4: type= WeaponType::Spadino; break;
    }
    return type;
}

WeaponType CommandLine::get_various_weapon_type()
{
    cout<<"Digitare il tipo di arma:\n1: Cerbottana_piccola\n2: Cerbottana_grande\n3: Bolas\n4: Arco_lungo\n5: Arco_corto\n6: Balestra_pesante\n7: Balestra_leggera\n8: Fionda\n9: Accetta"<<endl;
    cout<<"10: Martello_da_lancio\n11: Giavellotto\n12: Rete\n13: Lancia\n14: Tridente\n15: Manganello\n16: Alabarda\n17: Lancia_da_cavaliere\n18: Picca\n19: Ascia_lunga\n20: Bastone"<<endl;
    cout<<"21: Frusta\n22: Ascia_da_battaglia\n23: Clava\n24: Martello_da_guerra\n25: Mazza\n26: Pugnale"<<endl;
    int value = fill_int();
    WeaponType type;
    switch(value)
    {
        case 1: type=WeaponType::Cerbottana_piccola; break;
        case 2: type=WeaponType::Cerbottana_grande; break;
        case 3: type=WeaponType::Bolas; break;
        case 4: type=WeaponType::Arco_lungo; break;
        case 5: type=WeaponType::Arco_corto; break;
        case 6: type=WeaponType::Balestra_pesante; break;
        case 7: type=WeaponType::Balestra_leggera; break;
        case 8: type=WeaponType::Fionda; break;
        case 9: type=WeaponType::Accetta; break;
        case 10: type=WeaponType::Martello_da_lancio; break;
        case 11: type=WeaponType::Giavellotto; break;
        case 12: type=WeaponType::Rete; break;
        case 13: type=WeaponType::Lancia; break;
        case 14: type=WeaponType::Tridente; break;
        case 15: type=WeaponType::Manganello; break;
        case 16: type=WeaponType::Alabarda; break;
        case 17: type=WeaponType::Lancia_da_cavaliere; break;
        case 18: type=WeaponType::Picca; break;
        case 19: type=WeaponType::Ascia_lunga; break;
        case 20: type=WeaponType::Bastone; break;
        case 21: type=WeaponType::Frusta; break;
        case 22: type=WeaponType::Ascia_da_battaglia; break;
        case 23: type=WeaponType::Clava; break;
        case 24: type=WeaponType::Martello_da_guerra; break;
        case 25: type=WeaponType::Mazza; break;
        case 26: type=WeaponType::Pugnale; break;
    }
    return type;    
}

ArmorType CommandLine::get_armor_type()
{
    cout<<"Digitare tipologia di armatura\n1: Scudo_appuntito\n2: Scudo_laminato\n3: Scudo_lanceolato\n4: Scudo_dentato\n5: Scudo\n6: Cuoio\n7: Maglia"<<endl;
    cout<<"8: Piastre\n9: Bardatura per cavalli"<<endl;
    int value = fill_int();
    ArmorType type;
    switch(value)
    {
        case 1: type=ArmorType::Scudo_appuntito; break;
        case 2: type=ArmorType::Scudo_laminato; break;
        case 3: type=ArmorType::Scudo_lanceolato; break;
        case 4: type=ArmorType::Scudo_dentato; break;
        case 5: type=ArmorType::Scudo; break;
        case 6: type=ArmorType::Cuoio; break;
        case 7: type=ArmorType::Maglia; break;
        case 8: type=ArmorType::Piastre; break;
        case 9: type=ArmorType::Bardatura_per_cavalli; break;
    }
    return type;    
}

RechargeType CommandLine::get_recharge_type()
{
    cout<<"Cariche:\n1: Non Ricaricabile\n2: Ricaricabile\n3: Usabile per ora\n4: Usabile per giorno\n5: Usabile per settimana\n6: Usabile per mese"<<endl;
    int value = fill_int();
    RechargeType recharge;
    switch(value)
    {
        case 1: recharge=RechargeType::Non_recheargeable; break;
        case 2: recharge=RechargeType::Recheargeable; break;
        case 3: recharge=RechargeType::Hourly; break;
        case 4: recharge=RechargeType::Daily; break;
        case 5: recharge=RechargeType::Weekly; break;
        case 6: recharge=RechargeType::Montly; break;
    }
    return recharge;
}

int CommandLine::fill_caster_levels()
{
    cout<<"Digitare livello creatore oggetti magici (9-36)"<<endl;
    int value = fill_int();
    while (!inputValidation.verify_caster_level_is_correct(value))
    {
        cout<<"Valore incorretto, riprovare"<<endl;
        value = fill_int(); 
    }
    return value;
}

int CommandLine::fill_int()
{
    int value; 
    cin>>value;
    return value;
}