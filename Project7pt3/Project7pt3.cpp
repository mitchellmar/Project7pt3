#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <numeric>
#include "Utility.h"
#include "Car.h"

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    int totalCars = cars.size();

    int totalPrice =
    std::accumulate(cars.begin(), cars.end(), 0, [](const int& i, Car& c) {
        return i + c.price();
        });
    
    int avgPrice = totalPrice / totalCars;
    
    struct pricesort {
        inline bool operator() (const Car& car1, const Car& car2)
        {
            return (car1.price() < car2.price());
        }
    };
   
    std::sort(cars.begin(), cars.end(), pricesort());

    Car min = cars.front();
    Car max = cars.back();

    int range = max.price() - min.price();

    // TODO: print the average price and price range
    std::cout << "The average price is: $" << avgPrice << "\n";

    std::cout << "The range is: $" << range << "\n";

}
