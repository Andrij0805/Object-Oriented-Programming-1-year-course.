#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

class DataCarrier
{
protected:
    double sizeGB;
public:
    DataCarrier(double size = 0) : sizeGB(size) {}
    virtual ~DataCarrier() 
    {
       
    }

    virtual void print(ostream& os) const 
    {
        os << "Size: " << sizeGB << " GB\n";
    }

    friend istream& operator>>(istream& in, DataCarrier& d) 
    {
        cout << "Enter size (GB): ";
        in >> d.sizeGB;

        if (in.fail()) 
        {
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input! You must enter a number.");
        }

        if (d.sizeGB < 0)
            throw invalid_argument("Size cannot be negative!");
        return in;
    }

    friend ostream& operator<<(ostream& out, const DataCarrier& d) 
    {
        d.print(out);
        return out;
    }
};


class HDD : public DataCarrier
{
private:
    int cylinders, tracks, sectors;
    string brand;
public:
    HDD(double size = 0, int c = 0, int t = 0, int s = 0, string b = "")
        : DataCarrier(size), cylinders(c), tracks(t), sectors(s), brand(b) {}

    ~HDD()
    {
       
    }

    void print(ostream& os) const override
    {
        os << "Hard Drive:\n";
        DataCarrier::print(os);
        os << "Cylinders: " << cylinders
            << ", Tracks: " << tracks
            << ", Sectors: " << sectors
            << ", Brand: " << brand << "\n";
    }

    friend istream& operator>>(istream& in, HDD& h)
    {
        cout << "Enter data for hard drive:\n";
        in >> static_cast<DataCarrier&>(h);

        cout << "Cylinders: "; in >> h.cylinders;
        if (in.fail()) { in.clear(); in.ignore(numeric_limits<streamsize>::max(), '\n'); throw invalid_argument("Invalid input! Cylinders must be a number."); }

        cout << "Tracks: "; in >> h.tracks;
        if (in.fail()) { in.clear(); in.ignore(numeric_limits<streamsize>::max(), '\n'); throw invalid_argument("Invalid input! Tracks must be a number."); }

        cout << "Sectors: "; in >> h.sectors;
        if (in.fail()) { in.clear(); in.ignore(numeric_limits<streamsize>::max(), '\n'); throw invalid_argument("Invalid input! Sectors must be a number."); }

        cout << "Brand: "; in >> h.brand;

        if (h.cylinders < 0 || h.tracks < 0 || h.sectors < 0)
            throw invalid_argument("Negative value entered for HDD parameters!");
        return in;
    }
};


class OpticalDisk : public DataCarrier 
{
private:
    int cylinders, tracks, sectors;
    string brand;
public:
    OpticalDisk(double size = 0, int c = 0, int t = 0, int s = 0, string b = "")
        : DataCarrier(size), cylinders(c), tracks(t), sectors(s), brand(b) {}

    ~OpticalDisk()
    {
      
    }

    void print(ostream& os) const override
    {
        os << "Optical Disk:\n";
        DataCarrier::print(os);
        os << "Cylinders: " << cylinders
            << ", Tracks: " << tracks
            << ", Sectors: " << sectors
            << ", Brand: " << brand << "\n";
    }

    friend istream& operator>>(istream& in, OpticalDisk& o) 
    {
        cout << "Enter data for optical disk:\n";
        in >> static_cast<DataCarrier&>(o);

        cout << "Cylinders: "; in >> o.cylinders;
        if (in.fail()) { in.clear(); in.ignore(numeric_limits<streamsize>::max(), '\n'); throw invalid_argument("Invalid input! Cylinders must be a number."); }

        cout << "Tracks: "; in >> o.tracks;
        if (in.fail()) { in.clear(); in.ignore(numeric_limits<streamsize>::max(), '\n'); throw invalid_argument("Invalid input! Tracks must be a number."); }

        cout << "Sectors: "; in >> o.sectors;
        if (in.fail()) { in.clear(); in.ignore(numeric_limits<streamsize>::max(), '\n'); throw invalid_argument("Invalid input! Sectors must be a number."); }

        cout << "Brand: "; in >> o.brand;

        if (o.cylinders < 0 || o.tracks < 0 || o.sectors < 0)
            throw invalid_argument("Negative value entered for optical disk parameters!");
        return in;
    }
};


int main()
{
    try
    {
        HDD hdd;
        OpticalDisk disk;

        cin >> hdd;
        cin >> disk;

        cout << "\n--- Information ---\n";
        cout << hdd;
        cout << disk;

        ofstream fout("data_carriers.txt");
        if (!fout.is_open())
            throw runtime_error("File could not be opened!");

        fout << "=== Data Carriers ===\n";
        fout << hdd;
        fout << disk;
        fout.close();

        cout << "Information successfully written to data_carriers.txt\n";
    }
    catch (const invalid_argument& e)
    {
        cerr << "Input error: " << e.what() << endl;
    }
    catch (const runtime_error& e)
    {
        cerr << "Runtime error: " << e.what() << endl;
    }
    catch (...) 
    {
        cerr << "Unknown error occurred.\n";
    }

    return 0;
}
