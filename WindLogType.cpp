// windLogType.cpp - windLogType class implementation
//---------------------------------------------------------------------------------
// Includes

#include "windLogType.h"

//---------------------------------------------------------------------------------
// Default constructor
WindLogType::WindLogType()
{
    speed = -1;
    solarRad = -1;
    ambAir = -1;
}

//---------------------------------------------------------------------------------
// Destructor
WindLogType::~WindLogType()
{

}

//---------------------------------------------------------------------------------
// Default constructor
WindLogType::WindLogType(double ws, double sr, double aa)
{
    speed = ws;
    solarRad = sr;
    ambAir = aa;
}

//---------------------------------------------------------------------------------
// Sets date
void WindLogType::SetDate( const Date & dt )
{
    d = dt;
}

//---------------------------------------------------------------------------------
// Returns date
const Date & WindLogType::GetDate() const
{
    return d;
}

//---------------------------------------------------------------------------------
// Sets time
void WindLogType::SetTime( const Time & tt )
{
    t = tt;
}

//---------------------------------------------------------------------------------
// Returns time
const Time & WindLogType::GetTime() const
{
    return t;
}

//---------------------------------------------------------------------------------
// Sets wind speed
void WindLogType::SetSpeed( const double & s )
{
    speed = s;
}

//---------------------------------------------------------------------------------
// Returns wind speed
const double & WindLogType::GetSpeed() const
{
    return speed;
}

//---------------------------------------------------------------------------------
// Sets solar radiation
void WindLogType::SetSolarRad( const double & s )
{
    solarRad = s;
}

//---------------------------------------------------------------------------------
// Returns solar radiation
const double & WindLogType::GetSolarRad() const
{
    return solarRad;
}

//---------------------------------------------------------------------------------
// Sets ambient air temperature
void WindLogType::SetAmbAir( const double & a )
{
    ambAir = a;
}

//---------------------------------------------------------------------------------
// Returns ambient air temperature
const double & WindLogType::GetAmbAir() const
{
    return ambAir;
}

//---------------------------------------------------------------------------------
