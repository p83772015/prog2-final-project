// Copyright (C) 2025 by Jericho S.
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

class GasPump {
private:
  double amountDispensed;
  double amountCharged;
  double costPerGallon;
  bool dispensing;

public:
  // Constructor
  GasPump(double cost) {
    amountDispensed = 0.0;
    amountCharged = 0.0;
    costPerGallon = cost;
    dispensing = false;
  }

  // Methods
  void reset() {
    amountDispensed = 0.0;
    amountCharged = 0.0;
    cout << "    Pump reset.\n";
  }

  void startDispensing() {
    reset();
    dispensing = true;
    cout << "    Dispensing started...\n";
  }

  void dispense(double targetGallons) {
    if (!dispensing) {
      cout << "    Error: Pump is not started.\n";
      return;
    }

    double step = 0.1;
    while (amountDispensed < targetGallons) {
      amountDispensed += step;
      if (amountDispensed > targetGallons) {
	amountDispensed = targetGallons;
      }

      amountCharged = amountDispensed * costPerGallon;

      cout << "    Dispensed: " << amountDispensed << " gal | "
           << "Charged: $" << amountCharged << '\r';
      cout.flush();

      this_thread::sleep_for(chrono::milliseconds(200));
    }

    cout << '\n';
  }

  void stopDispensing() {
    dispensing = false;
    cout << "    Dispensing stopped.\n";
  }

  // Accessors
  double getAmountDispensed() { return amountDispensed; }
  double getAmountCharged() { return amountCharged; }
  double getCostPerGallon() { return costPerGallon; }
  bool getDispensing() { return dispensing; }

  // Mutators
  void setAmountDispensed(double amt) { amountDispensed = amt; }
  void setAmountCharged(double amt) { amountCharged = amt; }
  void setCostPerGallon(double cost) { costPerGallon = cost; }
  void setDispensing(bool status) { dispensing = status; }
};

void runDispensingSession(GasPump& pump) {
  double gallons;
  cout << "Enter gallons to dispense: ";
  cin >> gallons;

  pump.startDispensing();
  pump.dispense(gallons);
  pump.stopDispensing();
}

int main() {
  cout << "+-----------------------------+\n";
  cout << "| Welcome to the Gas Station! |\n";
  cout << "+-----------------------------+\n\n";

  double cost;
  cout << "Enter cost per gallon to initialize the pump: $";
  cin >> cost;

  GasPump pump(cost);
  runDispensingSession(pump);  // object modified directly

  cout << "\nSummary:\n";
  cout << "    Total Dispensed: " << pump.getAmountDispensed() << " gallons\n";
  cout << "    Total Charged: $" << pump.getAmountCharged() << '\n';

  return 0;
}
