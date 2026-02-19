#include <iostream>
#include <string>

// Base class
class Device {
protected:
    std::string brand;
    double price;

public:
    Device(const std::string& b, double p): brand(b), price(p) {
        std::cout << "Device constructor" << std::endl;
    }
};

// Derived class
class Laptop : public Device {
private:
    int ram; // in GB
    int ssd; // in GB


public:
    Laptop(const std::string& b, double p, int r, int s)
        : Device(b, p), ram(r), ssd(s) {
        std::cout << "Laptop constructor" << std::endl;
    }

    void display() const {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "RAM: " << ram << " GB" << std::endl;
        std::cout << "SSD: " << ssd << " GB" << std::endl;
    }
};

int main() {
    Laptop myLaptop("ASUS-ROG", 1999.99, 64, 2048);
    myLaptop.display();

    return 0;
}
