// Copyright (C) 2025 by Jericho S.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class BoxOfProduce {
private:
  string box[3];

public:
  // Constructor
  BoxOfProduce(string produceList[], int size) {
    srand(time(0));
    for (int i = 0; i < 3; ++i) {
      int randIndex = rand() % size;
      box[i] = produceList[randIndex];
    }
  }

  // Methods
  void displayContents() {
    cout << "\nBox of Produce Contents:\n";
    for (int i = 0; i < 3; ++i) {
      cout << "  Slot " << i + 1 << ": " << box[i] << '\n';
    }
  }

  // Accessors
  string getItem(int index) {
    if (index >= 0 && index < 3) return box[index];
    return "";
  }

  // Mutators
  void setItem(int index, string newItem) {
    if (index >= 0 && index < 3) box[index] = newItem;
  }
};

// Reads produce items from a file into an array
int loadProduceList(string produceList[], int maxSize) {
  ifstream input("produce.txt");
  int count = 0;
  while (count < maxSize && input >> produceList[count]) {
    ++count;
  }
  input.close();
  return count;
}

int main() {
  const int MAX_ITEMS = 5;
  string produceList[MAX_ITEMS];

  int actualSize = loadProduceList(produceList, MAX_ITEMS);
  if (actualSize != MAX_ITEMS) {
    cout << "Error: Expected exactly " << MAX_ITEMS << " produce items in file.\n";
    return 1;
  }

  BoxOfProduce box(produceList, actualSize);
  box.displayContents();

  char choice = 'y';

  while (choice == 'y' || choice == 'Y') {
    cout << "\nWould you like to substitute an item? (y/n): ";
    cin >> choice;
    if (choice != 'y' || choice == 'Y') {
      break;
    }

    int index;
    int newItemIndex;

    cout << "Enter slot number to replace (1-3): ";
    cin >> index;
    if (index < 1 || index > 3) {
      cout << "Invalid slot number.\n";
      return 1;
    }

    cout << "Enter new produce item from the list:\n";
    for (int i = 0; i < actualSize; ++i) {
      cout << "  [" << i << "] " << produceList[i] << '\n';
    }
    cout << "Enter Index: ";
    cin >> newItemIndex;

    box.setItem(index - 1, produceList[newItemIndex]);
    cout << "\nUpdated ";
    box.displayContents();
  }

  box.displayContents();

  return 0;
}
