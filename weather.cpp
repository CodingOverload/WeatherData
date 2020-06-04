// weather.cpp - weather class implementation
//---------------------------------------------------------------------------------
// Includes

#include "weather.h"

//---------------------------------------------------------------------------------
// Default constructor
weather::weather()
{
    month = 0;
    year = -1010;
}

//---------------------------------------------------------------------------------
// Destructor
weather::~weather()
{

}

//---------------------------------------------------------------------------------
// Constructor
weather::weather(unsigned int m, unsigned int y, const Vector<WindLogType> & v)
{
    month = m;
    year = y;
    for(int i=0; i<v.initialised(); i++)
    {
        vec = v[i];
    }
}

//---------------------------------------------------------------------------------
// This Function adds WindLogType objects to the vector.
void weather::AddData(const WindLogType & w)
{
    vec = w;
}

//---------------------------------------------------------------------------------
// This function returns a WindLogType object at position i.
const WindLogType & weather::GetData(int i) const
{
    return vec[i];
}

//---------------------------------------------------------------------------------
// This function returns a vector of windspeed for specified month and year.
const Vector<double> weather::getSpeedVec() const
{
    Vector<double> s;

    for(int i=0; i<vec.initialised(); i++)
    {   // checks if month is equal to m parameter, checks if year is equal to y parameter
        if(vec[i].GetDate().GetMonth() == GetMonth() && vec[i].GetDate().GetYear() == GetYear() && (int)vec[i].GetSpeed() != -1)
        {
            s = (vec[i].GetSpeed())*3.6; // Converts speed from m/s to km/h and adds to s vector
        }
    }
    return s; // Returns Vector a
}

//---------------------------------------------------------------------------------
// This function returns the average value of speed variables for specified month and year
double weather::GetAverageSpeed() const
{
    double avg=0;

    Vector<double> speed(getSpeedVec()); // Gets a vector of speed values for specified month and year
    statistics<double> s;

    // If there are wind speed values
    if(speed.initialised() > 0)
    {
        avg = s.Average(speed); // Calls method in statistics class to return average

        avg = s.roundNum(avg); // Calls function to round the number to 1 decimal place
        return avg;
    }
    // If there are no wind speed values
    else
    {
        return -1;
    }
}

//---------------------------------------------------------------------------------
// This function returns the number sample standard deviation value of speed variables for specified month and year
double weather::GetSpeedSampleDev() const
{
    statistics<double> s;
    double sdev=0;
    Vector<double> speed(getSpeedVec()); // Gets a vector of speed values for specified month and year

    // If there are wind speed values
    if(speed.initialised() > 1)
    {
        double avg = s.Average(speed); // Calls method in statistics class to return average

        sdev = s.SampleDev(speed, avg); // Calls method in statistics class to return sample standard deviation

        sdev = s.roundNum(sdev); // Calls function to round the number to 1 decimal place
        return sdev;
    }
    // If there are no wind speed values
    else
    {
        return -1;
    }
}

//---------------------------------------------------------------------------------
// This function returns a vector of ambient air temperature for specified month and year.
const Vector<double> weather::getAirVec() const
{
    Vector<double> a;
    for(int i=0; i<vec.initialised(); i++)
    {
        // Checks if month is equal to m parameter, checks if year is equal to y parameter
        if(vec[i].GetDate().GetMonth() == GetMonth() && vec[i].GetDate().GetYear() == GetYear() && (int)vec[i].GetAmbAir() != -1)
        {
            a = vec[i].GetAmbAir(); // Adds ambient air temp from vec to a
        }
    }
    return a; // Returns Vector a
}

//---------------------------------------------------------------------------------
// This function returns the average value of ambient air temperature variables for specified month and year
double weather::GetAverageAir() const
{
    double avg=0;

    Vector<double> air(getAirVec()); // Gets a vector of ambient air values for specified month and year
    statistics<double> s;

    // If there are ambient air temperature values
    if(air.initialised() > 0)
    {
        avg = s.Average(air); // Calls method in statistics class to return average

        avg = s.roundNum(avg); // Calls function to round the number to 1 decimal place
        return avg;
    }
    // If there are no ambient air temperature values
    else
    {
        return -1;
    }

}

//---------------------------------------------------------------------------------
// This function returns the number sample standard deviation value of ambient air temperature variables for specified month and year
double weather::GetAirSampleDev() const
{
    statistics<double> s;
    double sdev=0;
    Vector<double> air(getAirVec()); // Gets a vector of ambient air values for specified month and year

    // If there are solar radiation values
    if(air.initialised() > 1)
    {
        double avg = s.Average(air); // Calls method in statistics class to return average

        sdev = s.SampleDev(air, avg); // Calls method in statistics class to return sample standard deviation

        sdev = s.roundNum(sdev); // Calls function to round the number to 1 decimal place
        return sdev;
    }
    // If there are no solar radiation values
    else
    {
        return -1;
    }
}

//---------------------------------------------------------------------------------
// This function returns a vector of solar radiation for specified month and year.

const Vector<double> weather::getSolarVec() const
{
    Vector<double> sr;
    for(int i=0; i<vec.initialised(); i++)
    {
        // Checks if month is equal to m parameter, checks if year is equal to y parameter and solar radiation greater or equal to 100
        if(vec[i].GetDate().GetMonth() == GetMonth() && vec[i].GetDate().GetYear() == GetYear() && vec[i].GetSolarRad() >= 100)
        {
                sr = ((vec[i].GetSolarRad() * 1/6)/1000); // Converts solarRad from w/m2 to kwh/m2 and adds to sr vector
        }
    }
    return sr; // Returns Vector sr
}

//---------------------------------------------------------------------------------
// This function returns the total of solar radiation for specified month and year
double weather::GetTotalSolarRad() const
{
    statistics<double> s;
    Vector<double> solar(getSolarVec()); // Gets a vector of solar radiation values for specified month and year
    double total = s.GetTotal(solar); // Calls method in statistics class to return total
    total = s.roundNum(total); // Calls function to round the number to 1 decimal place
    return total;
}

//---------------------------------------------------------------------------------
// Sets month to parameter
void weather::SetMonth( unsigned int m )
{
    month = m;
}

//---------------------------------------------------------------------------------
// Returns month
unsigned int weather::GetMonth() const
{
    return month;
}

//---------------------------------------------------------------------------------
// Sets year to parameter
void weather::SetYear( unsigned int y )
{
    year = y;
}

//---------------------------------------------------------------------------------
// Returns year
unsigned int weather::GetYear() const
{
    return year;
}

//---------------------------------------------------------------------------------
// Returns the name of the month
string weather::getMonthName() const
{
    switch(GetMonth())
    {
    case 1:
        return "January";
        break;
    case 2:
        return "February";
        break;
    case 3:
        return "March";
        break;
    case 4:
        return "April";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "June";
        break;
    case 7:
        return "July";
        break;
    case 8:
        return "August";
        break;
    case 9:
        return "September";
        break;
    case 10:
        return "October";
        break;
    case 11:
        return "November";
        break;
    case 12:
        return "December";
        break;
    default:
        return "Error has occured";
        break;
    }
}

//---------------------------------------------------------------------------------
