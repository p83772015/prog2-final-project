// Copyright (C) 2025 by Jericho S.
#include <iostream>
using namespace std;

class Pizza {
public:
  string topping;
  double diameter;
  double price;

  string getTopping() {
    return topping;
  }
  double getDiameter() {
    return diameter;
  }
  void setPrice() {
    if (diameter == 12) {
      price = 13.99;
      cout << "    Price: [ Price Set to " << price << "! ]\n";
    }
    else if (diameter == 14) {
      price = 16.99;
      cout << "    Price: [ Price Set to " << price << "! ]\n";
    }
    else if (diameter == 15) {
      price = 19.99;
      cout << "    Price: [ Price Set to " << price << "! ]\n";
    }
    else {
      cout << "    Price: [ Invalid size. Set price to 0 ]\n";
      price = 0;
    }
  }
};

int
main ()
{
  Pizza pepperoni;
  Pizza hawaiian;
  Pizza pizzas[10];

  cout << "+---------------------------+\n";
  cout << "| Welcome to Pizza Factory! |\n";
  cout << "+---------------------------+\n";
 
  for (int i = 0; i < 3; ++i) {
    cout << "Enter data for pizza" << "[" << i + 1 << "]:\n";
    cout << "    Topping: ";
    cin >> pizzas[i].topping;
    cout << "    Diameter: ";
    cin >> pizzas[i].diameter;
    pizzas[i].setPrice();
    if (pizzas[i].price != 0) {
    }
    cout << '\n';
  }

  cout << "--------------- Summary ---------------:\n\n";
  for (int i = 0; i < 3; ++i) {
    cout << "Pizza[" << i + 1 << "]:\n";
    cout << "    " << "Topping: " << pizzas[i].topping << '\n';
    cout << "    " << "Diameter: " << pizzas[i].diameter << '\n';
    cout << "    " << "Price: " << pizzas[i].price << '\n';
    cout << '\n';
  }

  
  return 0;
}
