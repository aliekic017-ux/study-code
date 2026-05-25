#include "drone_test_bench.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

// ***** TASK 9A *****
// Generische Funktionen für Summe, Maximum, Durchschnitt und Report

template <typename T>
void printVector(const std::vector<T>& data)
{
    std::cout << "[";

    for (std::size_t i = 0; i < data.size(); i++)
    {
        std::cout << data[i];

        if (i < data.size() - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << "]";
}

template <typename T>
T computeSum(const std::vector<T>& data)
{
    return std::accumulate(data.begin(), data.end(), T());
}

template <typename T>
T computeMax(const std::vector<T>& data)
{
    return *std::max_element(data.begin(), data.end());
}

template <typename T>
double computeAverage(const std::vector<T>& data)
{
    T sum = computeSum(data);
    return static_cast<double>(sum) / data.size();
}

template <typename T>
void printMetricsReport(const std::vector<T>& data)
{
    std::cout << "Raw data: ";
    printVector(data);
    std::cout << '\n';

    std::cout << "Sum: " << computeSum(data) << '\n';
    std::cout << "Maximum: " << computeMax(data) << '\n';
    std::cout << "Average: " << computeAverage(data) << '\n';
}

// ***** TASK 9B *****
// Festes Array in std::vector umwandeln

template <typename T, std::size_t N>
std::vector<T> convertToVector(const T (&frame)[N])
{
    std::vector<T> result;

    for (std::size_t i = 0; i < N; i++)
    {
        result.push_back(frame[i]);
    }

    return result;
}

// ***** TASK 9C *****
// Spezialisierung für bool
// Hier wird für bool der Anteil der true-Werte berechnet

template <>
double computeAverage<bool>(const std::vector<bool>& data) // Spezialisierung f+r den Datentyp bool
{
    int trueCount = 0;

    for (std::size_t i = 0; i < data.size(); i++)
    {
        if (data[i] == true)
        {
            trueCount++;
        }
    }

    return static_cast<double>(trueCount) / data.size();
}


int main ()
{
// ***** Task 1 *****
 /*   int a = 10;
    int b = 4;

    std::cout << "Before swapping:" << a << b << std::endl;
    
    swap (a,b);

    std::cout << "After swapping:" << a << b << std::endl;
 */
// ***** Task 2 *****
 /*int intFrame[] = {12, 15, 18, 21};
 double doubleFrame [] = {1.5, 2.7, 3.2, 4.8};
 char charFrame[] = {'A', 'B', 'C', 'D'};

 printFrame(intFrame, 4);
 printFrame(doubleFrame, 4);
 printFrame(charFrame, 4);
*/

// ***** TAsk 3 *****
/*int intSearch[] = {12, 53, 67, 39, 21, 8};
double doubleSearch[] = {2.2, 1.2, 4.9, 4.8, 0.6, 0.7, 0.4};

std::cout << "Minimum int: "<< findMinimum(intSearch, 6) << '\n';
std::cout << "Minimum double"<< findMinimum(doubleSearch, 7) <<'\n';
*/

// ***** Task 4 *****


//verknüpfen("Voltage", 12.5, "Status", true);


// ***** Task 5 ***** 
// erweiterung vion Task 2 & 3, sodass die Größe des Arrays nicht mehr mit übergeben werden muss an die DFunktion 
/*
int intFrame[4] = {1, 5, 7, 90};
double doubleFrame[6] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};

printFrame(intFrame);
printFrame(doubleFrame);



int intSearch[4] = {12, 53, 67, 8};
double doubleSearch[6] = {2.2, 1.2, 4.9, 0.6, 0.7, 0.4};

std::cout << "Minimum int: " << findMinimum(intSearch) << '\n';
std::cout << "Minimum double: " << findMinimum(doubleSearch) << '\n';


// Why is the size no longer needed as a parameter??
// --> die Größe des Arrays muss der Funktion nicht mehr zusätzlich übergeben werden, da die Größe bereits im Array-Typ steckkt
// und vom Compiler automatisch erkannt wird.

// What advantage does this have compared to the previous version??
// sicherer, weniger fehleranfällig, da dfie Größe der Funktion nicht übergeben werden muss, einfacher

*/

// Section 2

// ***** Task 6 *****
/*
//Vector anlegen && Daten in dem Vector ausgeben

std::vector<int> recordedData = {42, 17, 42, 5, 99, 17, 63, 12};
std::cout << "Origirnale Daten vom Vector: ";
for (int Wert : recordedData)
{
   std::cout << Wert << " ";
}
std::cout << '\n';

// Werte vom Vector sortieren

std::sort(recordedData.begin(), recordedData.end()); // begin und end geben immer ein Iterator zurück
std::cout << "Sortierte Daten vom Vector: ";
for (int Wert : recordedData)
{
   std::cout << Wert << " ";
}
std::cout << "\n";

// Nach dem Wert 63 in dem Vector suchen 

std::vector<int>::iterator SucheWert;
SucheWert = std::find(recordedData.begin(), recordedData.end(), 63);
if (SucheWert != recordedData.end())   // oder if Abfrage (SucheWert == 63)
{
   std::cout << "Es existiert der Wert 63 in dem Vector recordedData";
}
else
{
   std::cout << "Es existiert der Wert 63 nicht in dem Vector recordedData";
}
*/

// ***** TASk 7 *****

std::vector<int> recordedData2 = {7, -1, 13, -1, 21, 21, 8, -1, 8};
std::cout<< "Originale Daten vom Vector recordedData 2: ";
for (int Wert : recordedData2)
{
   std::cout<< Wert << " ";
}
std::cout << '\n';

// alle -1 durch eine 0 ersetzen --> STL Algorithmus
std::replace(recordedData2.begin(), recordedData2.end(), -1, 0);
std::cout << "Nach dem Ersetzen von -1 zu 0: ";
for (int Wert : recordedData2)
{
   std::cout << Wert << " ";
}
std::cout << '\n';

// Zählen wie oft die 8 vorkommt 

int counter = std::count(recordedData2.begin(), recordedData2.end(), 8);
std::cout << "Die Zahl 8 kommt " << counter << " mal vor." << '\n';

// Vector umkehren

std::reverse(recordedData2.begin(), recordedData2.end());
std::cout << "Umgedrehte Daten: ";
for (int Wert : recordedData2)
{
   std::cout << Wert << " ";
}
std::cout << '\n';

// ***** TASK 8 *****

std::cout << "Ausgabe mit explizitem Iterator: " << '\n';

std::vector<int>::iterator it;

for (it = recordedData2.begin(); it != recordedData2.end(); ++it)
{
    std::cout << *it << " ";
}

std::cout << '\n';

/*
 * Frage 1: Was macht *it?
 * Antwort:
 * *it dereferenziert den Iterator.
 * Dadurch erhält man das Element, auf das der Iterator aktuell zeigt.
 *
 * Frage 2: Was macht ++it?
 * Antwort:
 * ++it verschiebt den Iterator auf das nächste Element im Vector.
 */

 // ***** TASK 9 *****

// ----- TASK 9A -----
// Test mit int- und double-Vektor

std::cout << "----- TASK 9A -----" << '\n';

std::vector<int> intData = {4, 7, 2, 9};
std::vector<double> doubleData = {2.5, 3.0, 4.5, 1.0};

std::cout << "Integer dataset:" << '\n';
printMetricsReport(intData);
std::cout << '\n';

std::cout << "Double dataset:" << '\n';
printMetricsReport(doubleData);
std::cout << '\n';


// ----- TASK 9B -----
// Festes Array in Vector umwandeln und analysieren

std::cout << "----- TASK 9B -----" << '\n';

int temperatureFrame[5] = {22, 24, 23, 25, 21};
std::vector<int> temperatureData = convertToVector(temperatureFrame);

std::cout << "Temperature frame analysis:" << '\n';
printMetricsReport(temperatureData);
std::cout << '\n';


// ----- TASK 9C -----
// Bool-Daten speziell auswerten

std::cout << "----- TASK 9C -----" << '\n';

std::vector<bool> motorStatus = {true, true, false, true, false};

double avg = computeAverage(motorStatus);
bool majority = (avg > 0.5);

std::cout << "Motor was active for most of the test run: "
          << std::boolalpha << majority << '\n';

return 0;
}