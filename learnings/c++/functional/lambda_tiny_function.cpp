#include <algorithm>
#include <iostream>
#include <vector>
#include "vehicle.h"

using namespace std;

auto main() -> int {
  cout << "[lambda_tiny_function.cpp]" << endl;

  Vehicle car("car", 4);
  Vehicle motorcycle("motorcycle", 2);
  Vehicle bicycle("bicycle", 2);
  Vehicle bus("bus", 6);

  vetcor<Vehicle> vehicles = {car, motorcycle, bicycle, bus};

  cout << "All Vehicles: " << endl;
  for_each(begin(vehicles), end(vehicles),
           [](const Vehicle &vehicle) { cout << vehicle.GetType() << endl; });
  return 0;
}