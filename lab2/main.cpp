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
    int territory_;
public:
    Country() = default;
    ~Country() {
        cout << "Run Dtor" << endl;
    }

    Country(string name, string capital, int territory) : name_(name), capital_(capital), territory_(territory){}
    Country(const Country& other){
        name_ = other.name_;
        capital_ = other.capital_;
        territory_ = other.territory_;
    }

    string get_name() const {return name_;}
    string get_capital() const {return capital_;}
    int get_territory() const {return territory_;}

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
        cout << "Territory: " + to_string(territory_) << endl;
    }
    void increase_territory(int territory){territory_ += territory;}
    void increase_territory(Country& other, float k = 1.0){
        territory_ += other.territory_ * k;
        other.territory_ = other.territory_ * (1 - k);
    }
    
};

int main(){
    
    Country China;
    Country Russia("Russian Federation", "Moscow", 17234031);
    Country USA(Russia);

    China.info();
    cout << endl;
    Russia.info();
    cout << endl;
    USA.info();
    cout << endl;
    
    Russia.increase_territory(Russia.get_territory());
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
