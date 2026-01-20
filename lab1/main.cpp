#include <string>
#include <iostream>
using namespace std;
class Country
{

public:
    Country() = default;
    ~Country() = default;

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

    void set_capital(const string& capital) {capital_ = capital;}

    void info(){
        cout << "Название: " + name_ << endl;
        cout << "Столица: " + capital_ << endl;
        cout << "Дата основания: " + date_ << endl;
        cout << "Площадь: " + to_string(territory_) << endl;
        cout << "Населние: " + to_string(population_) << endl;
    }
    void increase_territory(int territory){territory_ += territory;}
    void increase_population(int growth){population_ += growth;}
    
private:
    string name_;
    string capital_;
    string date_;
    int territory_;
    int population_;
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
    USA.increase_population(-1*USA.get_population());
    
    Russia.info();
    cout << endl;
    USA.info();

}
