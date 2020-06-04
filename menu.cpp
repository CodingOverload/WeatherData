// menu.CPP - menu class implementation
// Version
// 01 29/04/2020 Ryan Draper, Started
//---------------------------------------------------------------------------------
// Includes

#include "menu.h"
#include "Vector.h"

//---------------------------------------------------------------------------------
// Global variables

const string outFile = "WindTempSolar.csv";
const string fileName = "MetData_Mar01-2015-Mar01-2016-ALL.csv";

//---------------------------------------------------------------------------------
// Default constructor, calls functions for running the program.
menu::menu()
{
    Read();
    RunMenu(); //calls function to run menu

}

//---------------------------------------------------------------------------------
// Destructor
menu::~menu()
{

}

//---------------------------------------------------------------------------------
// Function for reading the file
int menu::Read()
{
    ifstream infile( fileName );
    if( !infile )
        return -1;

    string line, temp;
    getline(infile, line); // Gets the first line of the file
    stringstream buffer(line);

    while(!infile.eof()) // From line 2 until the end
    {
        infile >> w; // Passes the line to the weather input stream in myIO.h
    }

    infile.close(); // Closes the file

    return 0;
}

//---------------------------------------------------------------------------------
// Function for writing to a csv file
void menu::write()
{
    ofstream ofile( outFile );

    ofile << w.GetYear() << endl; // Writes year in csv file
    for(int i=0; i<12; i++) // Loops 12 times (each month)
    {
        w.SetMonth(i+1); // Changes month
        ofile << w; // Calls ostream operator for printing results to the file
    }

    ofile.close(); // Closes the file
}

//---------------------------------------------------------------------------------
// Gets the users choice of menu option
int menu::GetChoice()
{
    int opt=0;

    do  //runs once, checks for valid option and continues to loop while option is invalid.
    {
        cout << "please choose an option: " << endl;
        cin >> opt;
        cout << endl;
        while(!cin.good()) //while input is not an integer
        {
            cin.clear();
            cin.ignore();
            cout << "Choice should be a number (1-5)\n" << endl;
            cout << "please choose an option: " << endl;
            cin >> opt;
        }
        if(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5) // if input is not 1-5
        {
            cout << "Choice should be a number (1-5)\n" << endl;
        }
    }
    while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5); //while input is not 1-5
    cout << endl;

    return opt;
}

//---------------------------------------------------------------------------------
// Displays the menu options to the user
void menu::DisplayMenu()
{
    cout << " ----------------------------------------------------------------------------------------------------- " << endl;
    cout << "|  Menu Options:                                                                                     |" << endl;
    cout << "|                                                                                                    |" << endl;
    cout << "|  1. Average wind speed and sample standard deviation for wind speed of X month and X year          |" << endl;
    cout << "|                                                                                                    |" << endl;
    cout << "|  2. Average ambient air temperature and sample standard deviation for                              |" << endl;
    cout << "|     ambient air temperature of each month for X year                                               |" << endl;
    cout << "|                                                                                                    |" << endl;
    cout << "|  3. Total solar radiation for each month of X year                                                 |" << endl;
    cout << "|                                                                                                    |" << endl;
    cout << "|  4. CSV file containing average and sample standard deviation for wind speed,                      |" << endl;
    cout << "|     average and sample standard deviation for ambient air temperature and                          |" << endl;
    cout << "|     total solar radiation for each month of X year                                                 |" << endl;
    cout << "|                                                                                                    |" << endl;
    cout << "|  5. Exit the program                                                                               |" << endl;
    cout << " ----------------------------------------------------------------------------------------------------- \n" << endl;

}

//---------------------------------------------------------------------------------
// Calls menu option functions depending on users choice
void menu::RunMenu()
{
    string again = "y";
    do
    {
        DisplayMenu(); // Calls function to display menu
        int opt = GetChoice(); // Calls function to get users choice

        switch(opt)
        {
        case 1:
            option1(); // Calls function for choice 1
            break;
        case 2:
            option2(); // Calls function for choice 2
            break;
        case 3:
            option3(); // Calls function for choice 3
            break;
        case 4:
            option4(); // Calls function for choice 4
            break;
        case 5:
            option5(); // Calls function for choice 5
            break;
        default:
            cout << "Choice should be a number (1-5)\n" << endl;
            break;
        }

        // While again is not y or n
        do
        {
            cout << "Run again? y/n" << endl;
            cin >> again;
            cout << endl;
            again = tolower(again[0]);
        }
        while(again != "y" && again != "n");
    }
    // While again is true, keeps looping
    while(again == "y");
}

//---------------------------------------------------------------------------------
// Gets the users choice of month
void menu::checkMonth()
{
    unsigned int m;
    string in;

    cout << "please enter a month (1-12): " << endl;
    cin >> in; // Gets input as a string
    cout << endl;

    // Loops while month is not between 1 and 12 inclusive
    while(in!="1" && in!="2" && in!="3" && in!="4" && in!="5" && in!="6" && in!="7" && in!="8" && in!="9" && in!="10" && in!="11" && in!="12")
    {
        cout << "invalid" << endl;
        cout << "please enter a month (1-12): " << endl;
        cin >> in;
        cout << endl;
    }

    istringstream(in) >> m; // Converts input to unsigned int
    w.SetMonth(m); // Sets month input


}

//---------------------------------------------------------------------------------
// Gets the users choice of year
void menu::checkYear()
{
    unsigned int y;
    string str;
    int count;
    bool valid = true;

    // Loops while valid is false
    do
    {
        count = 0;
        cout << "please enter a year: " << endl;
        cin >> str;
        cout << endl;

        // Checks that each digit is an integer
        for(int i=0; i<(signed)str.length(); i++)
        {
            // If digit is an integer, adds 1 to count
            if(isdigit(str.at(i)))
            {
                count ++;
            }
        }

        // If count does not equal 4 and or, the first digit is a 0
        if(count != 4 || str.find("0")==0)
        {
            cout << "Year must be 4 digits and not begin with a 0" << endl;
            valid = false;
        }
        else
        {
            valid = true;
        }
    }while(valid == false);

    istringstream(str) >> y; // Converts the input to an unsigned int
    w.SetYear(y); // Sets the year
}

//---------------------------------------------------------------------------------
// Menu option 1 function
void menu::option1()
{
    checkMonth(); // Calls function for getting month
    checkYear(); // Calls function for getting year
    double avg = w.GetAverageSpeed(); // Gets the average wind speed
    double stdev = w.GetSpeedSampleDev(); // Gets the wind speed sample standard deviation

    cout << " ----------------------------------------------------------------------------------------------------- " << endl;
    cout << "  " << w.getMonthName() << " " << w.GetYear() << ":";
    // If there is no average
    if(avg < 0)
    {
        cout << "  No Data" << endl;
        cout << " ----------------------------------------------------------------------------------------------------- " << endl;
    }
    // If there is an average but no sample standard deviation
    else if(avg > 0 && (int)stdev == -1)
    {
        cout << "\n  Average Speed: " << avg << " km/h" << endl;
        cout << "  Sample stdev: " << "Not enough data to calculate" << endl;
        cout << " ----------------------------------------------------------------------------------------------------- " << endl;
    }
    // If there is an average and sample standard deviation
    else
    {
        cout << "\n  Average Speed: " << avg << " km/h" << endl;
        cout << "  Sample stdev: " << stdev << endl;
        cout << " ----------------------------------------------------------------------------------------------------- " << endl;
    }
    cout << endl;
}

//---------------------------------------------------------------------------------
// Menu option 2 function
void menu::option2()
{
    checkYear(); // Calls function to get year
    cout << " ----------------------------------------------------------------------------------------------------- " << endl;
    cout << "  " << w.GetYear() << ":" << endl;
    // Loops 12 times (each month of the year)
    for(int i=0; i<12; i++)
    {
        w.SetMonth(i+1);
        double avg = w.GetAverageAir();
        double stdev = w.GetAirSampleDev();

        // If there is no average ambient air temperature
        if(avg < 0)
        {
            cout << "  " << w.getMonthName() << ": No Data" << "\n" <<endl;
        }
        // If there is an average but no sample standard deviation for ambient air temperature
        else if(avg > 0 && (int)stdev == -1)
        {
            cout << "  " << w.getMonthName() << ": Average: " << avg << " degrees C," << " Sample stdev: " << "Not enough data to calculate" << "\n" << endl;
        }
        // If there is an average and sample standard deviation for ambient air temperature
        else
        {
            cout << "  " << w.getMonthName() << ": Average: " << avg << " degrees C," << " Sample stdev: " << stdev << "\n" << endl;
        }
    }
    cout << " ----------------------------------------------------------------------------------------------------- " << endl;
}

//---------------------------------------------------------------------------------
// Menu option 3 function
void menu::option3()
{
    checkYear(); // Calls function to get year
    cout << " ----------------------------------------------------------------------------------------------------- " << endl;
    cout << "  " << w.GetYear() << ":" << endl;
    // Loops 12 times (for each month)
    for(int i=0; i<12; i++)
    {
        w.SetMonth(i+1);
        int s = w.getSolarVec().initialised(); // Gets the number of Solar Radiation elements in the file
        // If there is no solar radiation data
        if(s == 0)
        {
            cout << "  " << w.getMonthName() << ": No Data" << "\n" << endl;
        }
        else
        {
            cout << "  " << w.getMonthName() << ": " << w.GetTotalSolarRad() << " kWh/m2" << "\n" << endl;
        }
    }
    cout << " ----------------------------------------------------------------------------------------------------- " << endl;
}

//---------------------------------------------------------------------------------
// Menu option 4 function
void menu::option4()
{
    checkYear(); // Calls function to get year
    write(); // Calls function for writing data to the output file
    cout << " ----------------------------------------------------------------------------------------------------- " << endl;
    cout << "  Data written to CSV file" << endl;
    cout << " ----------------------------------------------------------------------------------------------------- " << endl;
}

//---------------------------------------------------------------------------------
// Menu option 5 function - Tells to user they have quit and exits the program
void menu::option5()
{
    cout << " ----------------------------------------------------------------------------------------------------- " << endl;
    cout << "  You have quit the program" << endl;
    cout << " ----------------------------------------------------------------------------------------------------- " << endl;
    exit(0); // Exits the program
}

//---------------------------------------------------------------------------------
