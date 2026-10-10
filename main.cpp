#include <iostream>
#include <string>
#include<vector>
using namespace std;
class Patient {
  private:
      int id;
      string name;
      int bedType;       
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
const int NUM_LOCATIONS = 4;
const int INF = 9999;
class CityMap {
  private:
      int roadMatrix[NUM_LOCATIONS][NUM_LOCATIONS];
      string locationNames[NUM_LOCATIONS];
  public:
      CityMap() {
          locationNames[0] = "Accident Spot A";
          locationNames[1] = "Junction B";
          locationNames[2] = "City Center C";
          locationNames[3] = "Central Hospital";
          int defaultRoads[NUM_LOCATIONS][NUM_LOCATIONS] = {
              { 0,   6, INF,  14 },
              { 6,   0,   5,   8 },
              { INF, 5,   0,   3 },
              { 14,  8,   3,   0 }
          };
          for (int i = 0; i < NUM_LOCATIONS; i++) {
              for (int j = 0; j < NUM_LOCATIONS; j++) {
                  roadMatrix[i][j] = defaultRoads[i][j];
              }
          }
      }

      string getLocationName(int index) {
          return locationNames[index];
      }
      int findFastestRoute(int startNode, int destNode) {
          int minTime = roadMatrix[startNode][destNode];
          for (int k = 0; k < NUM_LOCATIONS; k++) {
              if (roadMatrix[startNode][k] != INF && roadMatrix[k][destNode] != INF) {
                  int transitViaK = roadMatrix[startNode][k] + roadMatrix[k][destNode];
                  if (transitViaK < minTime) {
                      minTime = transitViaK;
                  }
              }
          }
          return minTime;
      }
};
const int MAX_BEDS = 4;

class HospitalSystem {
  private:
      vector<Patient> admittedPatients;
      CityMap cityMap;

  public:
      void admitPatient(int pickupLoc, int id, string name, int bedType) {
          if (admittedPatients.size() >= MAX_BEDS) {
              cout <<endl<< "[ALERT] All " << MAX_BEDS << " beds occupied! Triage diversion required."<<endl;
              return;
          }
          int travelTime = cityMap.findFastestRoute(pickupLoc, 3);
          int fare = travelTime * 50; 

          admittedPatients.push_back(Patient(id, name, bedType, fare));
