#pragma once
#include <string>
#include <vector>
#include <dsmylib.h>
using namespace std;
class Country
{
private:
    string name_;
    City capital_;
    string foundation_;
    int territory_ = 0;
    int population_ = 0;
    vector<City> cities_;
public:
    Country();
    ~Country();
    Country(string name, City capital, string foundation, int territory, vector<City> cities);
    Country(const Country& other);

    Country& operator=(const Country& other);
    Country operator+(const Country& other);
    Country& operator+=(const Country& other);
    Country operator*(const Country& other);

    string get_name() const;
    City get_capital() const;
    string get_foundation() const;
    int get_territory() const;
    int get_population() const;
    vector<City> get_cities() const;

    void set_name(const string& name);
    void set_capital(const City& capital);
    void set_foundation(const string& foundation);
    void set_territory(int territory);
    void set_population(int population);
    void set_cities(const vector<City>& cities);

    void info();
    void increase_territory(Country& other, float k);
    void increase_population();
    void budget_allocation(const Budget& budget);


};
