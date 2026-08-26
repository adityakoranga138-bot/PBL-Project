#include <iostream>
#include <string>
using namespace std;

class Patient {
  private:
      int id;
      string name;
      int bedType;       // 1 = General Ward (800 rupees), 2 = ICU (15,000 rupees)
      int ambulanceFare;
  
  public:
      Patient() {
          id = 0;
          name = "EMPTY";
          bedType = 0;
          ambulanceFare = 0;
      }
      
      Patient(int pId, string pName, int bType, int fare) {
          id = pId;
          name = pName;
          bedType = bType;
          ambulanceFare = fare;
      }
  
      int getId() {
        return id;
      }
      string getName() {
        return name;
      }
      int getBedType() {
        return bedType;
      }
      int getAmbulanceFare() {
        return ambulanceFare;
      }
};

class Medicine {
  private:
      string name;
      int stock;
      float price;
  
  public:
      Medicine(string mName, int mStock, float mPrice) {
          name = mName;
          stock = mStock;
          price = mPrice;
      }
  
      string getName() {
        return name;
      }
      int getStock() {
        return stock;
      }
      float getPrice() {
        return price;
      }
};

int main() {
    cout << "SmartCare System : OOP Base Initialized.\n";
    return 0;
}
