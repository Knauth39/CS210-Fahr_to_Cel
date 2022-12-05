#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Functions to convert temp from F to C degrees, and print out new vectors

// @return  Temperature in Celcius that was converted from Farenheit in String format
// @param   tempF - Temperature in Farenheit
double FahrenheitToCelcius(double tempF) {
    double           tempC;                          // Initialize Cel variable
    tempC =          (tempF - 32) * (5.0 / 9.0);     // Formula for converstion
    return           tempC;                          // return Cel temp
}



//          Main function
// @return  Opens file, reads file, converts temp, writes data to new file
// @param   No parameters in main()
int main() {
    ifstream  inFS;       // Input file streat
    string    city;       // Declare variable for city name
    int       temp;       // Declare variable for temperature

    // Declare vectors to store file data of city name and temperatures
    vector<string>  cityNameList;         // String vector holding city names
    vector<double>     tempFahrenheitList;   // Int vector holding Fahrenheit temps

    // Try to open file
    inFS.open("FahrenheitTemperature.txt");
    if (!inFS.is_open()) {
        cout << "Could not open file";          // If file is unable to open
        return 1;                               // Return 1 to end program
    }

    // Read throough data and push into appropriate vecotor
    // While loop until the end of the file
    while (!inFS.eof()) {
        inFS >> city;                         // Get city name and assign to variable
        cityNameList.push_back(city);         // Push data to cityName vector
        inFS >> temp;                         // Get temp and assign to variable
        tempFahrenheitList.push_back(temp);   // Push data to tempFahrenheit vector
    }

    // Finished with file, close
    inFS.close();

    // Create and open new file to output data to
    ofstream outFS;
    outFS.open("CelciusTemperature.txt");

    // Read through Temperature vector and convert to celsius
    // Push celsius temperature to tempCelsius vector
    for (int f = 0; f <= tempFahrenheitList.size(); f++) {
        double val;
        val = FahrenheitToCelcius(tempFahrenheitList.at(f);
        outFS << cityNameList.at(f) << " " << val << endl;
    }

    // Close file
    outFS.close();
    return 0;
}
