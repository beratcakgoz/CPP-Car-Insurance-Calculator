#include <iostream>
#include <string>

using namespace std;

class Car {
protected:
    string make, model, licenseplate, color, chassisnumber, enginenumber, purposeofuse;
    int year;
    int price;

public:
    Car(string make, string model, string licenseplate, string color, string chassisnumber, string enginenumber, string purposeofuse, int year, int price) {
        this->make = make;
        this->model = model;
        SetLicenseplate(licenseplate);
        SetColor(color);
        this->chassisnumber = chassisnumber;
        this->enginenumber = enginenumber;
        SetPurposeofuse(purposeofuse);
        this->year = year;
        SetPrice(price);
    }

    Car() {}

    virtual ~Car() {}

    void SetColor(string newColor) {
        color = newColor;
    }

    void SetPurposeofuse(string newPurposeofuse) {
        purposeofuse = newPurposeofuse;
    }

    void SetPrice(int newPrice) {
        if (newPrice > 0) {
            price = newPrice;
        }
    }

    string GetLicenseplate() const {
        return licenseplate;
    }

    void SetLicenseplate(string newLicensePlate) {
        bool platecontrol = false;

        if (newLicensePlate.length() == 6) {
            if (newLicensePlate[0] >= '0' && newLicensePlate[0] <= '9' &&
                newLicensePlate[1] >= '0' && newLicensePlate[1] <= '9' &&
                newLicensePlate[2] >= 'A' && newLicensePlate[2] <= 'Z' &&
                newLicensePlate[3] >= '0' && newLicensePlate[3] <= '9' &&
                newLicensePlate[4] >= '0' && newLicensePlate[4] <= '9' &&
                newLicensePlate[5] >= '0' && newLicensePlate[5] <= '9') {
                platecontrol = true;
            }
        } else if (newLicensePlate.length() == 7) {
            if (newLicensePlate[0] >= '0' && newLicensePlate[0] <= '9' &&
                newLicensePlate[1] >= '0' && newLicensePlate[1] <= '9') {
                if (newLicensePlate[2] >= 'A' && newLicensePlate[2] <= 'Z' &&
                    newLicensePlate[3] >= '0' && newLicensePlate[3] <= '9' &&
                    newLicensePlate[4] >= '0' && newLicensePlate[4] <= '9' &&
                    newLicensePlate[5] >= '0' && newLicensePlate[5] <= '9') {
                    platecontrol = true;
                } else if (newLicensePlate[2] >= 'A' && newLicensePlate[2] <= 'Z' &&
                           newLicensePlate[3] >= 'A' && newLicensePlate[3] <= 'Z' &&
                           newLicensePlate[4] >= '0' && newLicensePlate[4] <= '9' &&
                           newLicensePlate[5] >= '0' && newLicensePlate[5] <= '9' &&
                           newLicensePlate[6] >= '0' && newLicensePlate[6] <= '9') {
                    platecontrol = true;
                } else if (newLicensePlate[2] >= 'A' && newLicensePlate[2] <= 'Z' &&
                           newLicensePlate[3] >= '0' && newLicensePlate[3] <= '9' &&
                           newLicensePlate[4] >= '0' && newLicensePlate[4] <= '9' &&
                           newLicensePlate[5] >= '0' && newLicensePlate[5] <= '9' &&
                           newLicensePlate[6] >= '0' && newLicensePlate[6] <= '9') {
                    platecontrol = true;
                }
            }
        } else if (newLicensePlate.length() == 8) {
            if (newLicensePlate[0] >= '0' && newLicensePlate[0] <= '9' &&
                newLicensePlate[1] >= '0' && newLicensePlate[1] <= '9') {
                if (newLicensePlate[2] >= 'A' && newLicensePlate[2] <= 'Z' &&
                    newLicensePlate[3] >= '0' && newLicensePlate[3] <= '9' &&
                    newLicensePlate[4] >= '0' && newLicensePlate[4] <= '9' &&
                    newLicensePlate[5] >= '0' && newLicensePlate[5] <= '9' &&
                    newLicensePlate[6] >= '0' && newLicensePlate[6] <= '9') {
                    platecontrol = true;
                } else if (newLicensePlate[2] >= 'A' && newLicensePlate[2] <= 'Z' &&
                           newLicensePlate[3] >= 'A' && newLicensePlate[3] <= 'Z' &&
                           newLicensePlate[4] >= '0' && newLicensePlate[4] <= '9' &&
                           newLicensePlate[5] >= '0' && newLicensePlate[5] <= '9' &&
                           newLicensePlate[6] >= '0' && newLicensePlate[6] <= '9' &&
                           newLicensePlate[7] >= '0' && newLicensePlate[7] <= '9') {
                    platecontrol = true;
                }
            }
        }

        if (platecontrol) {
            licenseplate = newLicensePlate;
        } else {
            licenseplate = "";
        }
    }

    friend ostream& operator<<(ostream& os, const Car& car) {
        os << "Make:" << car.make << endl;
        os << "Model: " << car.model << endl;
        os << "Licensse plate: " << car.licenseplate << endl;
        os << "Color:" << car.color << endl;
        os << "Year:" << car.year << endl;
        os << " chassis Number: " << car.chassisnumber << endl;
        os << "engine Number: " << car.enginenumber << endl;
        os << "Purpose of Use: " << car.purposeofuse << endl;
        os << "Price:" << car.price << endl << endl << endl;
        return os;
    }

    virtual double Calculateinsurance() const {
        return 0;
    }
};

class Personalcar : public Car {
private:
    int millimit;
public:
    Personalcar(string make, string model, string licenseplate, string color,
                string chassisnumber, string enginenumber, string purposeofuse, int year, int price, int millimit)
        : Car(make, model, licenseplate, color, chassisnumber, enginenumber, purposeofuse, year, price) {
        if (millimit < 10000)
            this->millimit = 10000;
        else
            this->millimit = millimit;
    }

    double Calculateinsurance() const override {
        double first = 0.01 * price;
        double secnd = 1000 * (millimit / 10000.0);
        return first + secnd;
    }
};

class Companycar : public Car {
protected:
    int companystotalcars;
public:
    Companycar(string make, string model, string licenseplate, string color, string chassisnumber,
               string enginenumber, string purposeofuse, int year, int price, int companystotalcars)
        : Car(make, model, licenseplate, color, chassisnumber, enginenumber, purposeofuse, year, price) {
        this->companystotalcars = companystotalcars;
    }

    double Calculateinsurance() const override {
        double discount = companystotalcars / 10;
        double rate = 0.02 - 0.001 * discount;
        if (rate < 0.012)
            rate = 0.012;
        return rate * price;
    }
};

class Fleetcar : public Companycar {
private:
    int citiesnumber;
public:
    Fleetcar(string make, string model, string licenseplate, string color, string chassisnumber,
             string enginenumber, string purposeofuse, int year, int price, int companystotalcars, int citiesnumber)
        : Companycar(make, model, licenseplate, color, chassisnumber, enginenumber, purposeofuse, year, price, companystotalcars) {
        this->citiesnumber = citiesnumber;
    }

    double Calculateinsurance() const override {
        double insurance = Companycar::Calculateinsurance();
        return insurance * (1.0 + citiesnumber / 10.0);
    }
};

int main() {
    const int MAX_CARS = 3;
    Car* cars[MAX_CARS];

    {
        string make, model, licenseplate, color, chassisnumber, enginenumber, purpose;
        int year, price, millimit;

        cout << "Enter details for Personal Car:" << endl;
        cout << "Make: "; cin >> make;
        cout << "Model: "; cin >> model;

        do {
            cout << "License plate(n=numbers, X=letters. Valid formats are: nnXXnnn, nnXnnn, nnXnnnn, nnXXnnnn): ";
            cin >> licenseplate;
            if (licenseplate.length() < 6 || licenseplate.length() > 10) {
                cout << "Invalid license plate format. Try again." << endl;
            } else {
                break;
            }
        } while (true);

        do {
            cout << "Color (White/Black/Red/Blue): ";
            cin >> color;
            if (color != "White" && color != "Black" && color != "Red" && color != "Blue")
                cout << "Invalid color. Try again." << endl;
        } while (color != "White" && color != "Black" && color != "Red" && color != "Blue");

        do {
            cout << "Chassis Number (it must be 17 chars): ";
            cin >> chassisnumber;
        } while (chassisnumber.length() != 17);

        do {
            cout << "Engine Number (it must be 17 chars): ";
            cin >> enginenumber;
        } while (enginenumber.length() != 17);

        cout << "Purpose of Use: "; cin >> purpose;
        cout << "Year: "; cin >> year;
        cout << "Price: "; cin >> price;

        do {
            cout << "Yearly mil limit (>=10000): ";
            cin >> millimit;
        } while (millimit < 10000);

        cars[0] = new Personalcar(make, model, licenseplate, color, chassisnumber, enginenumber, purpose, year, price, millimit);
    }

    {
        string make, model, licenseplate, color, chassisnumber, enginenumber, purpose;
        int year, price, totalcars;

        cout << "\nEnter details for Company Car:" << endl;
        cout << "Make: "; cin >> make;
        cout << "Model: "; cin >> model;

        do {
            cout << "License plate(n=numbers, X=letters. Valid formats are: nnXXnnn, nnXnnn, nnXnnnn, nnXXnnnn): ";
            cin >> licenseplate;
            if (licenseplate.length() < 6 || licenseplate.length() > 10) {
                cout << "Invalid license plate.Pleade try again." << endl;
            } else {
                break;
            }
        } while (true);

        do {
            cout << "Color (White/Black/Red/Blue): ";
            cin >> color;
            if (color != "White" && color != "Black" && color != "Red" && color != "Blue")
                cout << "Invalidcolor. Try again." << endl;
        } while (color != "White" && color != "Black" && color != "Red" && color != "Blue");

        do {
            cout << "Chassiss Number (must be 17 chars): ";
            cin >> chassisnumber;
        } while (chassisnumber.length() != 17);

        do {
            cout << "Engine Number (it must be 17chars): ";
            cin >> enginenumber;
        } while (enginenumber.length() != 17);

        cout << "Purpose of Use: "; cin >> purpose;
        cout << "Year: "; cin >> year;
        cout << "Price: "; cin >> price;
        cout << "Total number of cars company owns: "; cin >> totalcars;

        cars[1] = new Companycar(make, model, licenseplate, color, chassisnumber, enginenumber, purpose, year, price, totalcars);
    }

    {
        string make, model, licenseplate, color, chassisnumber, enginenumber, purpose;
        int year, price, totalcars, citiesnumber;

        cout << "\nEnter details for Fleet Car:" << endl;
        cout << "Make: "; cin >> make;
        cout << "Model: "; cin >> model;

        do {
            cout << "License plate(n=numbers, X=letters. Valid formats are: nnXXnnn, nnXnnn, nnXnnnn, nnXXnnnn): ";
            cin >> licenseplate;
            if (licenseplate.length() < 6 || licenseplate.length() > 10) {
                cout << "Invalid license plate format. Try again." << endl;
            } else {
                break;
            }
        } while (true);

        do {
            cout << "Color (White/Black/Red/Blue): ";
            cin >> color;
            if (color != "White" && color != "Black" && color != "Red" && color != "Blue")
                cout << "Invalid color. Try again." << endl;
        } while (color != "White" && color != "Black" && color != "Red" && color != "Blue");

        do {
            cout << "Chassis Number (it must 17 chars): ";
            cin >> chassisnumber;
        } while (chassisnumber.length() != 17);

        do {
            cout << "Engine Number (it must be 17 chars): ";
            cin >> enginenumber;
        } while (enginenumber.length() != 17);

        cout << "Purpose of Use: "; cin >> purpose;
        cout << "Year: "; cin >> year;
        cout << "Price: "; cin >> price;
        cout << "Total number of cars company owns: "; cin >> totalcars;
        cout << "Number of cities company operates: "; cin >> citiesnumber;

        cars[2] = new Fleetcar(make, model, licenseplate, color, chassisnumber, enginenumber, purpose, year, price, totalcars, citiesnumber);
    }

    cout << "\nAll cars and insurance prices" << endl;
    for (int i = 0; i < MAX_CARS; i++) {
        cout << *cars[i];
        cout << "Insurance Price is: " << cars[i]->Calculateinsurance() << endl << endl;
    }

    for (int i = 0; i < MAX_CARS; i++) {
        delete cars[i];
    }

    return 0;
}