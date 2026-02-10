#pragma once
#include <string>
#include <vector>
using namespace std;
class Country
{
private:
    string name_;
    string capital_;
    int territory_ = 0;
    vector<string> cities_;
public:
    Country();
    ~Country();
    Country(string name, string capital, int territory, vector<string> cities);

    Country& operator=(const Country& other);
    Country operator+(const Country& other);
    Country& operator+=(const Country& other);
    Country operator*(const Country& other);

    string get_name() const;
    string get_capital() const;
    int get_territory() const;
    vector<string> get_cities() const;

    void set_name(const string& name);
    void set_capital(const string& capital);
    void set_territory(int territory);
    void set_cities(const vector<string>& cities);

};
