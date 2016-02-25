#include <iostream>


using namespace std;


class Date
{
    int mo, da, yr;

    public:
    Date(){};
    Date(int m, int d, int y) {
        this->mo = m;
        this->da = d;
        this->yr = y;
    }

    friend ostream& operator << (ostream & os, const Date& dt);
    friend istream& operator >> (istream & os, Date& dt);
};

ostream& operator<< (ostream& os, const Date& dt)
{
    os << dt.mo << '/' << dt.da << '/' << dt.yr;
    return os;
}

istream& operator>> (istream& os, Date& dt)
{
    os >> dt.mo;
    os >> dt.da;
    os >> dt.yr;
    return os;
}


int main()
{
    Date dt(5, 6, 92);
    Date new_dt;
    cout << dt;

    cin >> new_dt;
    cout << "New date: " << new_dt << endl;
    
    return 0;
}
