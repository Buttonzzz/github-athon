/*

  * Alisha, Ben, Caleb, Timmy

  * Sandwich Shop kiosk

  * 6/7/22 - imported files and libraies, made structures and variables, finished ordering menu, need to work on sorting menu


*/

#include <stdlib.h>

#include "getValid.h"

#include <algorithm>

#include <iomanip>

#include <iostream>

#include <math.h>

#include <vector>

using namespace std;

struct sandwich {
  vector < string > toppings;
  string bread;
  bool toasted;
};

void Sortorders(vector < string > & ordername, vector < sandwich > & order);
void printSandwich(vector < sandwich > & order, vector < string > name, int i);

int main() {
  int response;
  //paralell vectors
  //vector <sandwich> us erOrder;
  //userOrder.push_back(sandwich);
  //userOrder.toppings.push_back(<choicevariable>);
  char * mySecret = getenv("manager password");
  vector < sandwich > orders;
  vector < string > ordername;
  //temp structure to be pushed back to vector after order
  struct sandwich TempSandwich;
  bool repeat = true;
  do {
    do {
      cout << "\n\nWelcome to Timmy's Sussy Subs\n1) Order\n2) View Orders\n3) "
      "Quit\n";
    } while (!getValidInt(response) || response < 1 || response > 3);

    switch (response) {
    case 1: {
      int bread;
      do {
        cout << "\nWhat kind of bread would you like?\n1) Whole wheat bread\n2) "
        "Whole grain bread\n3) Flatbread\n4) White bread\n";
      } while (!getValidInt(bread) || bread > 4 || bread < 1);
      //
      switch (bread) {
      case 1: {
        TempSandwich.bread = "Whole wheat bread";
        break;
      }
      case 2: {
        TempSandwich.bread = "Whole grain bread";
        break;
      }
      case 3: {
        TempSandwich.bread = "Flatbread";
        break;
      }
      case 4: {
        TempSandwich.bread = "White bread";
        break;
      }
      }

      int toasted;
      do {
        cout << "\nWould you like your bread toasted?\n1) Yes\n2) No\n";
      } while (!getValidInt(toasted) || toasted < 1 || toasted > 2);
      bool repeat2 = true;
      int toppings;
      do {
        do {
          cout << "\nSelect Toppings:\n1) Olives\n2) Anchovies\n3) Bell Peppers\n4) Banana Peppers\n5) Jalepeños\n6) Continue\n";
        } while (!getValidInt(toppings) || toppings < 1 || toppings > 6);

        switch (toppings) {
        case 1: {
          TempSandwich.toppings.push_back("Olives");
          break;
        }
        case 2: {
          TempSandwich.toppings.push_back("Anchovies");
          break;
        }
        case 3: {
          TempSandwich.toppings.push_back("Bell Peppers");
          break;
        }
        case 4: {
          TempSandwich.toppings.push_back("Banana Peppers");
          break;
        }
        case 5: {
          TempSandwich.toppings.push_back("Jalepeños");
          break;
        }
        case 6: {
          repeat2 = false;
          break;
        }
        }
      } while (repeat2 == true);

      string ordernamesingle;
      cout << "\nPlease enter an order name: ";
      getline(cin, ordernamesingle);
      ordername.push_back(ordernamesingle);
      cout << ordernamesingle;
      orders.push_back(TempSandwich);
      break;
    }
    case 2: {

      string input;
      int sortInput;
      cout << "\n\nEnter manager password: ";
      getline(cin, input);

      if (input == mySecret) {
        string name;
        cout << "Password Accepted.\n";
        do {
          cout << "\nManager access\n1) Sort orders\n2) Find order by name\n";
        } while (!getValidInt(sortInput) || sortInput < 1 || sortInput > 2);
        switch (sortInput) {
        case 1: {
          //TIMMY your job is to make a sorting fucntion </3
          cout << "You chose " << sortInput;
          for (int i = 0; i < ordername.size(); i++) {
            cout << "Name : " << ordername[i] << endl;
          }
          cout << "Going into sort" << endl;
          Sortorders(ordername, orders);
          break;
        }
        case 2: {
          cout << "\nEnter order name (CASE SENSITIVE!!!): ";
          getline(cin, name);
          for (int x = 0; x < ordername.size(); x++) {
            if (ordername[x] == name) {
              printSandwich(orders, ordername, x);
            } else {}
          }
          break;
        }
        }
      } else {
        cout << "Incorrect Password\n";
      }
      break;
    }

    case 3: {
      cout << "Thanks for shopping at Timmy's Sussy Sandwiches\n";
      repeat = false;
      break;
    }
    }
  } while (repeat == true);
}

// Bubble Sort Function for Descending Order
void Sortorders(vector < string > & ordername, vector < sandwich > & order) {
  //cout << "I am in Sorting" << endl;
  int i, j, flag = 1; // set flag to 1 to start first pass
  string temp = ""; // holding variable
  sandwich temp2;
  cout << "I am in Sorting" << endl;
  int namelistLength = ordername.size();
  /*
  order.bread = bread
  order.topping = topping
  sandwich.push_back(order)
    */
  cout << "Hello, I am " << namelistLength << " el1ements big";
  for (i = 1;
    (i < namelistLength - 1) && flag; i++) {
    flag = 0;
    for (j = 0; j < (namelistLength - 1); j++) {
      if (ordername[j + 1] > ordername[j]) // ascending order simply changes to <
      {
        temp = ordername[j]; // swap elements
        ordername[j] = ordername[j + 1];
        ordername[j + 1] = temp;

        temp2 = order[j]; // swap elements
        order[j] = order[j + 1];
        order[j + 1] = temp2;
        flag = 1; // indicates that a swap occurred.
      }
    }
  }
}

void printSandwich(vector < struct sandwich > & order, vector < string > name, int i) {
  cout << "Order Name: " << name[i] << "\nBread: " << order[i].bread;
  if (order[i].toasted == true) {
    cout << " toasted";
  } else {
    cout << " not toasted";
  }
  cout << "\nToppings:";
  for (int x = 0; x < order[i].toppings.size(); x++) {
    cout << order[i].toppings[x] << endl;
  }
}