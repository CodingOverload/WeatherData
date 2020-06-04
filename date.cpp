// Date.CPP - Date class implementation
//---------------------------------------------------------------------------------

//Includes

#include "date.h"

//---------------------------------------------------------------------------------
// Default constructor
Date::Date()
{
    day = 0;
    month = 0;
    year = -1010;
}

//---------------------------------------------------------------------------------

// Constructor with parameters
Date::Date(unsigned int dy, unsigned int m, unsigned int yr)
{
    day = dy;
    month = m;
    year = yr;
}

//---------------------------------------------------------------------------------
// Destructor
Date::~Date()
{
}

//---------------------------------------------------------------------------------
// Sets day to parameter
void Date::SetDay( unsigned int & d )
{
    day = d;
}

//---------------------------------------------------------------------------------
// Returns day
const unsigned int & Date::GetDay() const
{
    return day;
}

//---------------------------------------------------------------------------------
// Sets month to parameter
void Date::SetMonth( unsigned int & m )
{
    month = m;
}

//---------------------------------------------------------------------------------
// Returns month
const unsigned int & Date::GetMonth() const
{
    return month;
}

//---------------------------------------------------------------------------------
// Sets year to parameter
void Date::SetYear( unsigned int & y )
{
    year = y;
}

//---------------------------------------------------------------------------------
// Returns year
const unsigned int & Date::GetYear() const
{
    return year;
}

//---------------------------------------------------------------------------------
