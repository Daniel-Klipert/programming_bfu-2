#pragma once
#include <string>
using namespace std;

struct City{
    string name;
    int population = 0;
    int money = 0;
};


class Budget
{
private:
    int money_ = 0;
    float k_ = 1;

public:
    Budget();
    ~Budget();
    Budget(int money, float k);
    Budget(const Budget& other);

    int get_money() const;
    float get_k() const;

    void set_money(int money);
    void set_k(float k);
};