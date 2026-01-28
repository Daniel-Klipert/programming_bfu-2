#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
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
    Country() = default;
    ~Country() {cout << "Run Dtor" << endl;}
    Country(string name, string capital, int territory, vector<string> cities) : name_(name), capital_(capital), territory_(territory), cities_(cities) {}

    Country& operator=(const Country& other) {
        name_ = other.name_;
        capital_ = other.capital_;
        territory_ = other.territory_;
        cities_ = other.cities_;
        return *this;
    }
    Country& operator+(const Country& other) {
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
            for (int j = 0; j < rcities.size(); ++j) {
                if (other.cities_.at(i) == rcities.at(j)) {
                    rcities.push_back(other.cities_.at(i) + "новый");
                    break;
                }
            }
            rcities.push_back(other.cities_.at(i));
        }

        Country res(rname, rcapital, rterritory, rcities);
        return res;
    }
    Country& operator+=(const Country& other) {
        name_ = name_ + "-" + other.name_;
        if (territory_ < other.territory_) {
            capital_ = other.capital_;
        }
        territory_ = territory_ + other.territory_;
        for (int i = 0; i < other.cities_.size(); ++i) {
            for (int j = 0; j < cities_.size(); ++j) {
                if (other.cities_.at(i) == cities_.at(j)) {
                    cities_.push_back(other.cities_.at(i) + "новый");
                    break;
                }
            }
            cities_.push_back(other.cities_.at(i));
        }
        return *this;
    }
    Country& operator*(const Country& other) {
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

    string get_name() const { return name_; }
    string get_capital() const { return capital_; }
    int get_territory() const { return territory_; }
    vector<string> get_cities() const { return cities_; }

    void set_name(const string& name) {
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
    void set_capital(const string& capital) {
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
    void set_territory(int territory) {
        if (territory >= 0) {
            territory_ = territory;
        }
        else {
            cout << "----Wrong territory----" << endl;
        }
    }
    void set_cities(const vector<string>& cities) {
        for (int i = 0; i < cities.size(); ++i) {
            if (cities.at(i) == capital_) {
                cities_ = cities;
                return;
            }
        }
        cout << "----Wrong cities----" << endl;
    }

protected:
    string date_;
    int population_ = 0;

    Country(string name, string capital, string date, int territory, int population) : name_(name), capital_(capital), date_(date), territory_(territory), population_(population) {}
    Country(const Country& other) {
        name_ = other.name_;
        capital_ = other.capital_;
        date_ = other.date_;
        territory_ = other.territory_;
        population_ = other.population_;
    }


    string get_date() const { return date_; }
    int get_population() const { return population_; }


    void info() {
        cout << "Name: " + name_ << endl;
        cout << "Capital: " + capital_ << endl;
        cout << "Date: " + date_ << endl;
        cout << "Territory: " + to_string(territory_) << endl;
        cout << "Population: " + to_string(population_) << endl;
    }
    void increase_territory(int territory) { territory_ += territory; }
    void increase_territory(Country& other, float k = 1.0) {
        territory_ += other.territory_ * k;
        other.territory_ = other.territory_ * (1 - k);
    }
    void increase_population() {
        srand(time(0));
        population_ += rand() % 100000;
    }
};

int main() {

}
