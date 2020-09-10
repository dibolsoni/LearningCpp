#include <iostream>

#include <string>
 
class PoweredDevice
{
public:
    std::string p_name;
    PoweredDevice(int power)
        : p_name{"PoweredDevice"}
    {
		std::cout << "PoweredDevice: " << power << '\n';
    }
};
 
class Scanner: virtual public PoweredDevice // note: PoweredDevice is now a virtual base class
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice(power) // this line is required to create Scanner objects, but ignored in this case
    {
		std::cout << "Scanner: " << scanner << '\n';
    }
};
 
class Printer: virtual public PoweredDevice // note: PoweredDevice is now a virtual base class
{
public:
    Printer(int printer, int power)
        : PoweredDevice(power) // this line is required to create Printer objects, but ignored in this case
    {
		std::cout << "Printer: " << printer << '\n';
    }
};
 
class Copier: public Scanner, public Printer
{
public:
    std::string c_name;
    Copier(int scanner, int printer, int power)
        : PoweredDevice(power), // PoweredDevice is constructed here
        Scanner(scanner, power), Printer(printer, power), c_name{"copier"}
    {
    }
};