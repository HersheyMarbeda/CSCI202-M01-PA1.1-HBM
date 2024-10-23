/*
    Programmer Name: Hershey Beatrice A. Marbeda
    Professor: Dr. Steven Carver
    Course: CSCI 202-Data Structures and Algorithm

    Last Date Updated: 10.23.2024

    Assignemt: Programming #1.1: Polymorphism and Validation
    Purpose of the Program: To conver input Roman Numeral to Decimal
 */


#include <iostream>
#include <iomanip>
#include <unordered_map> // to store the input roman numeral
#include <cctype>        // toUpper()

using namespace std;


class romanType
{
private:
    int M, D, C, L, X, V, I;
    
public:
        // Constructor
    romanType(int m = 1000, int d = 500, int c = 100, int l = 50, int x = 10, int v = 5, int i = 1)
    : M(m), D(d), C(c), L(l), X(x), V(v), I(i) {}
    
        // Getters
    int getM() const { return M; }
    int getD() const { return D; }
    int getC() const { return C; }
    int getL() const { return L; }
    int getX() const { return X; }
    int getV() const { return V; }
    int getI() const { return I; }
    
    // Function to convert Roman Numeral to Decimal
    int RomanToDecimal(const string& Roman)
    {
        // Initializing the map according to my logic
        unordered_map<char, int> RomanValues =
        {
            {'M', M}, {'D', D}, {'C', C}, {'L', L}, {'X', X}, {'V', V}, {'I', I}
        };
        
        int total = 0, previous_value = 0;
        
       // Loop through the Roman numeral from right to left
        for (int i = Roman.length() - 1; i >= 0; --i)
        {
            int value = RomanValues[Roman[i]];
            
            if (value < previous_value)
            {
                total -= value; // subtract if numeral is smaller than previous
            }
            
            else
            {
                total += value; // otherwise, add the value
            }
            
            previous_value = value; // update previous_value
        }
        
        return total;
    }
    
    
    // Function to Validate user's input
    bool isValidRoman(const string& Roman)
    {
        for (char c : Roman)
        {
            if (c != 'I' && c != 'V' && c != 'X' && c != 'L' && c != 'C' && c != 'D' && c != 'M')
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    // Class Object
    romanType Numeral;
    
    
    // Declaration of Variables
    string romanNumeral;
    int decimalValue ;
    
    // Table Headings
    cout << string(100, '*') << endl
         << "\t\t\t\t\t\t\tM01-Programming #1: Polymorphism and Validation " << endl
         << string(100, '*') << endl
         << "Welcome to Roman Numeral Converter!\n\n";
    
    cout << string(30, '-') << endl
         << "\tRoman Numeral Table" << setw(8) << "|\n" << string(30, '-') << endl
         << "I: " << Numeral.getI() << setw(15) << "C: " << Numeral.getC() << setw(8) << "|" << endl
         << "V: " << Numeral.getV() << setw(15) << "D: " << Numeral.getD() << setw(8) << "|" << endl
         << "X: " << Numeral.getX() << setw(14) << "M: " << Numeral.getM() << setw(7) << "|" << endl
         << "L: " << Numeral.getL() << setw(25) << "|" << endl
         << string(30, '-') << endl ;
        
    do
    {
        cout << "\nEnter the Roman Numeral (or 'Y' to exit): ";
        cin >> romanNumeral;
        
        // Convert the input to uppercase
        for (char& c : romanNumeral)
        {
            c = toupper(c);
        }
        
        // Check for exit condition
        if (romanNumeral == "Y" || romanNumeral == "y")
        {
            break;
        }
        
        // Input validation
        while (cin.fail() || !Numeral.isValidRoman(romanNumeral))
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid Roman numeral. Please enter a valid Roman numeral: ";
            cin >> romanNumeral;
            
            // Convert the input to uppercase again since it's inside the loop
            for (char& c : romanNumeral)
            {
                c = toupper(c);
            }
            
            // Check for exit condition again
            if (romanNumeral == "Y" || romanNumeral == "y")
            {
                break;
            }
        }
 
        if (romanNumeral != "Y" && romanNumeral != "y")
        {
            decimalValue = Numeral.RomanToDecimal(romanNumeral);
            cout << "\nRoman Numeral: " << romanNumeral << endl
                 << "Decimal value: " << decimalValue << endl;
        }
        
        
    } while (romanNumeral != "Y");
    
    // To make it readable to screen
    cout << "\nExiting the program...\n\n" ;
    return 0;
}

