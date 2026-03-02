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
    Country::Country(string name, City capital, string foundation, int territory, vector<City> cities){
        name_ = name;
        capital_ = capital;
        foundation_ = foundation;
        territory_ = territory;
        for (int i = 0; i < cities.size(); ++i){
            population_ += cities.at(i).population;
        }
        cities_ = cities;
    }
    Country::Country(const Country& other){
        name_ = other.name_;
        capital_ = other.capital_;
        foundation_ = other.foundation_;
        territory_ = other.territory_;
        population_ = other.population_;
        cities_ = other.cities_;
    }

    Country& Country::operator=(const Country& other) {
        name_ = other.name_;
        capital_ = other.capital_;
        foundation_ = other.foundation_;
        territory_ = other.territory_;
        population_ = other.population_;
        cities_ = other.cities_;
        return *this;
    }
    Country Country::operator+(const Country& other) {
        string rname = name_ + "-" + other.name_;
        City rcapital;
        if (territory_ < other.territory_) {
            rcapital = other.capital_;
        }
        else{
            rcapital = capital_;
        }
        string rfoundation;
        string year;
        string otheryear;
        int c_dot = 0;
        for (int i = 0; i < foundation_.length(); ++i){
            char s = foundation_[i];

            if(c_dot == 2){
                year += s;
            }
            if(s == '.'){
                ++c_dot;
            }        
        }
        c_dot = 0;
        for (int i = 0; i < other.foundation_.length(); ++i){
            char s = other.foundation_[i];

            if(c_dot == 2){
                otheryear += s;
            }
            if(s == '.'){
                ++c_dot;
            }        
        }
        if(stoi(year) < stoi(otheryear)){
            rfoundation = foundation_;
        } 
        else if(stoi(otheryear) < stoi(year)){
            rfoundation = other.foundation_;
        }
        else{
            string month;
            string othermonth;
            c_dot = 0;

            for (int i = 0; i < foundation_.length(); ++i){
                char s = foundation_[i];

                if(c_dot == 1 && s != '.'){
                    month += s;
                }
                if(s == '.'){
                    ++c_dot;
                }        
            }
            c_dot = 0;
            for (int i = 0; i < other.foundation_.length(); ++i){
                char s = other.foundation_[i];

                if(c_dot == 1 && s != '.'){
                    othermonth += s;
                }
                if(s == '.'){
                    ++c_dot;
                }        
            }
            if(stoi(month) < stoi(othermonth)){
                rfoundation = foundation_;
            } 
            else if(stoi(othermonth) < stoi(month)){
                rfoundation = other.foundation_;
            }
            else{
                string day;
                string otherday;
                c_dot = 0;

                for (int i = 0; i < foundation_.length(); ++i){
                    char s = foundation_[i];

                    if(c_dot == 0 && s != '.'){
                        day += s;
                    }
                    if(s == '.'){
                        ++c_dot;
                    }        
                }
                c_dot = 0;
                for (int i = 0; i < other.foundation_.length(); ++i){
                    char s = other.foundation_[i];

                    if(c_dot == 0 && s != '.'){
                        otherday += s;
                    }
                    if(s == '.'){
                        ++c_dot;
                    }        
                }
                if(stoi(day) < stoi(otherday)){
                    rfoundation = foundation_;
                } 
                else if(stoi(otherday) < stoi(day)){
                    rfoundation = other.foundation_;
                }
                else{
                    rfoundation = foundation_;
                }
            }
        }
        int rterritory = territory_ + other.territory_;
        vector<City> rcities = cities_;
        for (int i = 0; i < other.cities_.size(); ++i) {
            bool is_added = false;
            for (int j = 0; j < rcities.size(); ++j) {
                if (other.cities_.at(i).name == rcities.at(j).name) {
                    City rcity = other.cities_.at(i);
                    rcity.name += " new";
                    rcities.push_back(rcity);
                    is_added = true;
                    break;
                }
            }
            if (!is_added){
                rcities.push_back(other.cities_.at(i));
            }
            
        }
        Country res(rname, rcapital, rfoundation, rterritory, rcities);
        return res;
    }
    Country& Country::operator+=(const Country& other) {
        name_ = name_ + "-" + other.name_;
        if (territory_ < other.territory_) {
            capital_ = other.capital_;
        }
        string rfoundation;
        string year;
        string otheryear;
        int c_dot = 0;
        for (int i = 0; i < foundation_.length(); ++i){
            char s = foundation_[i];

            if(c_dot == 2){
                year += s;
            }
            if(s == '.'){
                ++c_dot;
            }        
        }
        c_dot = 0;
        for (int i = 0; i < other.foundation_.length(); ++i){
            char s = other.foundation_[i];

            if(c_dot == 2){
                otheryear += s;
            }
            if(s == '.'){
                ++c_dot;
            }        
        }
        if(stoi(otheryear) < stoi(year)){
            foundation_ = other.foundation_;
        }
        else{
            string month;
            string othermonth;
            c_dot = 0;

            for (int i = 0; i < foundation_.length(); ++i){
                char s = foundation_[i];

                if(c_dot == 1 && s != '.'){
                    month += s;
                }
                if(s == '.'){
                    ++c_dot;
                }        
            }
            c_dot = 0;
            for (int i = 0; i < other.foundation_.length(); ++i){
                char s = other.foundation_[i];

                if(c_dot == 1 && s != '.'){
                    othermonth += s;
                }
                if(s == '.'){
                    ++c_dot;
                }        
            }
            if(stoi(othermonth) < stoi(month)){
                foundation_ = other.foundation_;
            }
            else{
                string day;
                string otherday;
                c_dot = 0;

                for (int i = 0; i < foundation_.length(); ++i){
                    char s = foundation_[i];

                    if(c_dot == 0 && s != '.'){
                        day += s;
                    }
                    if(s == '.'){
                        ++c_dot;
                    }        
                }
                c_dot = 0;
                for (int i = 0; i < other.foundation_.length(); ++i){
                    char s = other.foundation_[i];

                    if(c_dot == 0 && s != '.'){
                        otherday += s;
                    }
                    if(s == '.'){
                        ++c_dot;
                    }        
                }
                if(stoi(otherday) < stoi(day)){
                    foundation_ = other.foundation_;
                }
            }
        }
        territory_ = territory_ + other.territory_;
        for (int i = 0; i < other.cities_.size(); ++i) {
            bool is_added = false;
            for (int j = 0; j < cities_.size(); ++j) {
                if (other.cities_.at(i).name == cities_.at(j).name) {
                    City rcity = other.cities_.at(i);
                    rcity.name += " new";
                    cities_.push_back(rcity);
                    population_ += rcity.population;
                    is_added = true;
                    break;
                }
            }
            if (!is_added){
                cities_.push_back(other.cities_.at(i));
                population_ += other.cities_.at(i).population;
            }
        }
        return *this;
    }
    Country Country::operator*(const Country& other) {
        string rname = name_ + "->" + other.name_;
        City rcapital;
        rcapital.name = "no";
        string rfoundation = "no";
        int rterritory = min(territory_, other.territory_);
        vector<City> rcities;
        rcities.push_back(capital_);
        rcities.push_back(other.capital_);

    
        while (true) {
            srand(time(0));
            int r = rand() % cities_.size();
            if (cities_.at(r).name != capital_.name) {
                rcities.push_back(cities_.at(r));
                break;
            }

        }
        while (true) {

            int r = rand() % other.cities_.size();
            if (other.cities_.at(r).name != other.capital_.name) {
                for (int i = 0; i < other.cities_.size(); ++i) {
                    bool has_city = false;

                    for (int j = 0; j < rcities.size(); ++j) {
                        if (other.cities_.at(r).name == rcities.at(j).name) {
                            has_city = true;
                            break;
                        }
                    }
                    if (!has_city) {
                        rcities.push_back(other.cities_.at(r));
                        break;
                    }
                    else {
                        City rcity = other.cities_.at(r);
                        rcity.name += " new";
                        rcities.push_back(rcity);
                        break;
                    }
                }

                break;
            }

        }
        Country res(rname, rcapital, rfoundation, rterritory, rcities);
        return res;
    }
    
    string Country::get_name() const { return name_; }
    City Country::get_capital() const { return capital_; }
    string Country::get_foundation() const { return foundation_; }
    int Country::get_territory() const { return territory_; }
    int Country::get_population() const { return population_; }
    vector<City> Country::get_cities() const { return cities_; }

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
    void Country::set_capital(const City& capital) {
        bool allowed = false;
        if (capital.name.length() != 0) {
            allowed = true;
            for (int i = 0; i < capital.name.length(); ++i) {
                char s = capital.name[i];
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
    void Country::set_foundation(const string& foundation){
        bool allowed = false;
        if (foundation.length() > 0) {
            allowed = true;
            vector<int> dots;
            for (int i = 0; i < foundation.length(); ++i) {
                char s = foundation[i];
                if (s == '.'){
                    dots.push_back(i);
                }
            }
            if ((dots.size() == 3) && (dots.at(0) + 1 >= 2) && (dots.at(0) + 1 <= 3) && (dots.at(1) - dots.at(0) >= 2) && (dots.at(1) - dots.at(0) <= 3) && (dots.at(2) - dots.at(1) >= 2) && (dots.at(2) - dots.at(1) <= 3) && (foundation.length() - dots.at(2) >= 2)){
                string n = foundation;
                erase(n,'.');
                for (int i = 0; i < n.length(); ++i){
                    char c = n[i];
                    if(!('0' <= c && c <= '9')){
                        allowed = false;
                        break;
                    }
                }
            }
        }
        if (allowed) {
            foundation_ = foundation;
        }
        else { cout << "----Wrong foundation----" << endl; }
    
    }
    void Country::set_territory(int territory) {
        if (territory >= 0) {
            territory_ = territory;
        }
        else {
            cout << "----Wrong territory----" << endl;
        }
    }
    void Country::set_population(int population){
        if (population >= 0) {
            population_ = population;
            int pop = population;
            int c = cities_.size();
            for(int i = 0; i < cities_.size(); ++i){
                if(c != 0){
                    cities_.at(i).population = pop / c + pop % c;
                    pop -= pop / c + pop % c;
                    c -= 1;
                }
            }
        }
        else {
            cout << "----Wrong population----" << endl;
        }
    }
    void Country::set_cities(const vector<City>& cities) {
        for (int i = 0; i < cities.size(); ++i) {
            if (cities.at(i).name == capital_.name) {
                cities_ = cities;
                for (int i = 0; i < cities_.size(); ++i){
                    population_ += cities_.at(i).population;
                }
                return;
            }
        }
        cout << "----Wrong cities----" << endl;
    }

    void Country::info(){
        cout << "Name: " + name_ << endl;
        cout << "Capital: " + capital_.name << endl;
        cout << "Foundation: " + foundation_ << endl;
        cout << "Territory: " + to_string(territory_) << endl;
        cout << "Population: " + to_string(population_) << endl;
        cout << "Cities: ";
        for  (int i = 0; i < cities_.size(); ++i){
            cout << cities_.at(i).name << endl;
        }
    }
    void Country::increase_territory(Country& other, float k = 1.0){
        if (0 <= k && k <= 1){
        territory_ += other.territory_ * k;
        other.territory_ = other.territory_ * (1 - k);
        return;
        }
        cout << "----Wrong k----" << endl;
    }
    void Country::increase_population(){
        srand(time(0));
        int pop = rand() % 100000;
        population_ += pop;
        cities_.at(rand() % cities_.size()).population += pop;
    }
    void Country::budget_allocation(const Budget& budget){
        int bmoney = budget.get_money();
        int pop = population_ - capital_.population + capital_.population * budget.get_k();
            for(int i = 0; i < cities_.size(); ++i){
                if(cities_.at(i).name != capital_.name){
                    cities_.at(i).money += (bmoney * cities_.at(i).population) / pop + (bmoney * cities_.at(i).population) % pop;
                    bmoney -= (bmoney * cities_.at(i).population) / pop + (bmoney * cities_.at(i).population) % pop;
                    pop -= cities_.at(i).population;
                }
                if(cities_.at(i).name == capital_.name){
                    cities_.at(i).money += (bmoney * cities_.at(i).population * budget.get_k()) / pop + static_cast<int>(bmoney * cities_.at(i).population * budget.get_k()) % pop;
                    bmoney -= (bmoney * cities_.at(i).population) / pop + (bmoney * cities_.at(i).population) % pop;
                    pop -= cities_.at(i).population;
                }
            }
    }
