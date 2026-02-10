#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "country.hpp"
using namespace std;

    Country::Country() {}
    Country::~Country() {
        cities_.clear();
        cout << "Run Dtor" << endl;
    }
    Country::Country(string name, string capital, int territory, vector<string> cities) : name_(name), capital_(capital), territory_(territory), cities_(cities){}

    Country& Country::operator=(const Country& other) {
        name_ = other.name_;
        capital_ = other.capital_;
        territory_ = other.territory_;
        cities_ = other.cities_;
        return *this;
    }
    Country Country::operator+(const Country& other) {
        string rname = name_ + "-" + other.name_;
        string rcapital;
        if (territory_ < other.territory_) {
            rcapital = other.capital_;
        }
        else{
            rcapital = capital_;
        }
        int rterritory = territory_ + other.territory_;
        vector<string> rcities = cities_;
        for (int i = 0; i < other.cities_.size(); ++i) {
            bool is_added = false;
            for (int j = 0; j < rcities.size(); ++j) {
                if (other.cities_.at(i) == rcities.at(j)) {
                    rcities.push_back(other.cities_.at(i) + "новый");
                    is_added = true;
                    break;
                }
            }
            if (!is_added){
                rcities.push_back(other.cities_.at(i));
            }
            
        }
        Country res(rname, rcapital, rterritory, rcities);
        return res;
    }
    Country& Country::operator+=(const Country& other) {
        name_ = name_ + "-" + other.name_;
        if (territory_ < other.territory_) {
            capital_ = other.capital_;
        }
        territory_ = territory_ + other.territory_;
        for (int i = 0; i < other.cities_.size(); ++i) {
            bool is_added = false;
            for (int j = 0; j < cities_.size(); ++j) {
                if (other.cities_.at(i) == cities_.at(j)) {
                    cities_.push_back(other.cities_.at(i) + "новый");
                    is_added = true;
                    break;
                }
            }
            if (!is_added){
                cities_.push_back(other.cities_.at(i));
            }
        }
        return *this;
    }
    Country Country::operator*(const Country& other) {
        string rname = name_ + "->" + other.name_;
        string rcapital = "нет";
        int rterritory = min(territory_, other.territory_);
        vector<string> rcities;
        rcities.push_back(capital_);
        rcities.push_back(other.capital_);
        
        for (int i = 0; i < cities_.size(); ++i) {
            if (cities_.at(i) != capital_) {
                rcities.push_back(cities_.at(i));
                break;
            }
        }
        for (int i = 0; i < other.cities_.size(); ++i) {
            bool has_city = false;
            if (other.cities_.at(i) != other.capital_) {
                for (int j = 0; j < rcities.size(); ++j) {
                    if (other.cities_.at(i) == rcities.at(j)) {
                        has_city = true;
                        break;
                    }
                }
                if (!has_city) {
                    rcities.push_back(other.cities_.at(i));
                }
                else {
                    rcities.push_back(other.cities_.at(i) + "новый");
                }
                break;
            }   
        }
        Country res(rname, rcapital, rterritory, rcities);
        return res;
    }

    string Country::get_name() const { return name_; }
    string Country::get_capital() const { return capital_; }
    int Country::get_territory() const { return territory_; }
    vector<string> Country::get_cities() const { return cities_; }

    void Country::set_name(const string& name) {
        bool allowed = false;
        if (name.length() != 0) {
            allowed = true;
            for (int i = 0; i < name.length(); ++i) {
                char s = name[i];
                if (!('A' <= s && s <= 'Z' || 'a' <= s && s <= 'z')) {
                    allowed = false;
                    break;
                }
            }
        }
        if (allowed) {
            name_ = name;
        }
        else { cout << "----Wrong name----" << endl; }
    }
    void Country::set_capital(const string& capital) {
        bool allowed = false;
        if (capital.length() != 0) {
            allowed = true;
            for (int i = 0; i < capital.length(); ++i) {
                char s = capital[i];
                if (!('A' <= s && s <= 'Z' || 'a' <= s && s <= 'z')) {
                    allowed = false;
                    break;
                }
            }
        }
        if (allowed) {
            capital_ = capital;
        }
        else { cout << "----Wrong capital----" << endl; }
    }
    void Country::set_territory(int territory) {
        if (territory >= 0) {
            territory_ = territory;
        }
        else {
            cout << "----Wrong territory----" << endl;
        }
    }
    void Country::set_cities(const vector<string>& cities) {
        for (int i = 0; i < cities.size(); ++i) {
            if (cities.at(i) == capital_) {
                cities_ = cities;
                return;
            }
        }
        cout << "----Wrong cities----" << endl;
    }