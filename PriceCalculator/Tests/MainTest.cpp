#include "Test_Calculator.cpp"
#include "Test_WeaponCalculator.cpp"
#include "Test_ArmorCalculator.cpp"
#include "Test_InputValidation.cpp"
#include "Test_ObjectCreator.cpp"
using namespace std;

int main ()
{
  Test_Calculator calculator;
  calculator.run();
  Test_WeaponCalculator weapon_test;
  weapon_test.run();
  Test_ArmorCalculator armor_test;
  armor_test.run();
  Test_InputValidation input_validation_test;
  input_validation_test.run();
  Test_ObjectCreator object_creator;
  object_creator.run();
  return 0;
}