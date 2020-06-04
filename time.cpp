// Time.CPP - Time class implementation
// Version
// 01 21/04/2020 Ryan Draper, Started
//---------------------------------------------------------------------------------

//Includes

#include "Time.h"

//---------------------------------------------------------------------------------
// Default constructor
Time::Time()
{
    hours = " ";
    minutes = " ";
}

//---------------------------------------------------------------------------------
// Destructor
Time::~Time()
{
    //dtor
}

//---------------------------------------------------------------------------------
// Constructor with parameters
Time::Time(string h, string m)
{
    hours = h;
    minutes = m;
}

//---------------------------------------------------------------------------------
// Returns hours
const string & Time::Gethours() const
{
    return hours;
}

//---------------------------------------------------------------------------------
// Sets hours to parameter
void Time::Sethours(const string & h)
{
    hours = h;
}

//---------------------------------------------------------------------------------
// Returns minutes
const string & Time::Getminutes() const
{
    return minutes;
}

//---------------------------------------------------------------------------------
// Sets minutes to parameter
void Time::Setminutes(const string & m)
{
    minutes = m;
}

//---------------------------------------------------------------------------------
