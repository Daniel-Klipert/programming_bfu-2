#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Country
{
private:
    string name_;
    string capital_;
    string date_;
    int territory_;
    int population_;

public:
    Country() = default;
    ~Country() {
        cout << "Run Dtor" << endl;
    }

    Country(string name, string capital, string date, int territory, int population) : name_(name), capital_(capital), date_(date), territory_(territory), population_(population){}
    Country(const Country& other){
        name_ = other.name_;
        capital_ = other.capital_;
        date_ = other.date_;
        territory_ = other.territory_;
        population_ = other.population_;
    }

    string get_name() const {return name_;}
    string get_capital() const {return capital_;}
    string get_date() const {return date_;}
    int get_territory() const {return territory_;}
    int get_population() const {return population_;}

    void set_capital(const string& capital) {
        bool allowed = false;
        if(capital.length() != 0){
            allowed = true;
            for (int i = 0; i < capital.length(); ++i){
                char s = capital[i];
                if (!('A' <= s && s <= 'Z' || 'a' <= s && s <= 'z')){
                    allowed = false;
                    break;
                }
            }
        }
        if (allowed){
            capital_ = capital;
        }
        else{ cout << "----Wrong capital----" << endl;}
    }

    void info(){
        cout << "Name: " + name_ << endl;
        cout << "Capital: " + capital_ << endl;
        cout << "Date: " + date_ << endl;
        cout << "Territory: " + to_string(territory_) << endl;
        cout << "Population: " + to_string(population_) << endl;
    }
    void increase_territory(int territory){territory_ += territory;}
    void increase_territory(Country& other, float k = 1.0){
        territory_ += other.territory_ * k;
        other.territory_ = other.territory_ * (1 - k);
    }
    void increase_population(){
        srand(time(0));
        population_ += rand() % 100000;
    }
    
};

int main(){
    
    Country China;
    Country Russia("Russian Federation", "Moscow", "25.12.1991", 17234031, 146203613);
    Country USA(Russia);

    China.info();
    cout << endl;
    Russia.info();
    cout << endl;
    USA.info();
    cout << endl;
    
    Russia.increase_territory(Russia.get_territory());
    USA.increase_population();
    USA.set_capital("Washington");
    China.set_capital("Beijing");
    
    Russia.info();
    cout << endl;
    USA.info();
    cout << endl;
    China.info();

    Russia.increase_territory(USA, 0.5);

    Russia.info();
    cout << endl;
    USA.info();
}
