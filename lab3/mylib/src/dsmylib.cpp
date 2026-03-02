#include <iostream>
#include "dsmylib.h"
using namespace std;

    Budget::Budget() {}
    Budget::~Budget() {
        cout << "Run Dtor" << endl;
    }
    Budget::Budget(int money, float k) : money_(money), k_(k){}
    Budget::Budget(const Budget& other){
        money_ = other.money_;
        k_ = other.k_;
    }

    int Budget::get_money() const {
        return money_;
    }
    float Budget::get_k() const {
        return k_;
    }

    void Budget::set_money(int money){
        if(money >= 0){
            money_ = money;
            return;
        }
        cout << "----Wrong money----" << endl;
    }
    void Budget::set_k(float k){
        if(k >= 0){
            k_ = k;
            return;
        }
        cout << "----Wrong k----" << endl;
    }
