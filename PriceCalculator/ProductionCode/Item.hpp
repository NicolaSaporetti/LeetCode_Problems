#ifndef Item_HPP
#define Item_HPP
using namespace std;

enum class RechargeType {Non_recheargeable, Recheargeable, Hourly, Daily, Weekly, Montly};

enum class WeaponType {Cerbottana_piccola, Cerbottana_grande, Bolas, Arco_lungo, Arco_corto, Balestra_pesante, Balestra_leggera, Fionda, Accetta,
                       Pugnale, Martello_da_lancio, Giavellotto, Rete, Lancia, Tridente, Manganello, Alabarda, Lancia_da_cavaliere, Picca, Ascia_lunga,
                       Bastone, Spada_a_2_mani, Frusta, Ascia_da_battaglia, Clava, Martello_da_guerra, Mazza, Spada_bastarda, Spada, Spadino};

enum class ArmorType {Scudo_appuntito, Scudo_laminato, Scudo_lanceolato, Scudo_dentato, Scudo, Cuoio, Maglia, Piastre, Bardatura_per_cavalli};

typedef struct ArmorAndWeapon {
    int price_base_object;
    int encoumber;
} ArmorAndWeapon;

typedef struct Weapon {
    WeaponType weaponType;
    int bonus;
    int secondary_bonus;
} Weapon;

typedef struct Sword {
    Weapon weapon;
    int third_bonus;
} Sword;

typedef struct Armor {
    ArmorType armorType;
    int bonus;
} Armor;

typedef struct ItemWithCharges {
    RechargeType recharge_type;
    vector<int> spells_level;
    int charges;
} ItemWithCharges;

typedef struct PermanentItem {
    int spell_level;
} PermanentItem;
#endif