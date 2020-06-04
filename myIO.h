// myIO.h
//---------------------------------------------------------------------------------

#include <iostream>
#include <sstream>
#include <string>
#include "weather.h"

using namespace std;

//---------------------------------------------------------------------------------

    /**
     * @brief  Holds istream and ostream definitions for weather, date and time.
     *
     * @author Ryan Draper
     * @version 01
     * @date 21/04/2020 Ryan Draper, Started
     */

//---------------------------------------------------------------------------------

    /**
     * @brief  Output method for weather class
     *
     * This function returns formatted output for weather class detais.
     *
     * @param ostream & os
     * @param const weather & W
     * @return ostream
     */
ostream & operator <<( ostream & os, const weather & W );

    /**
     * @brief  Input method for weather class
     *
     * This function is for setting weather class detais.
     *
     * @param istream & input
     * @param weather & W
     * @return input
     */
istream & operator >>( istream & input, weather & W );


    /**
     * @brief  Input method for Date class
     *
     * This function is for setting Date class detais.
     *
     * @param istream & input
     * @param Date & D
     * @return input
     */
istream & operator >>( istream & input, Date & D );


    /**
     * @brief  Input method for Time class
     *
     * This function is for setting Time class detais.
     *
     * @param istream & input
     * @param Time & T
     * @return input
     */
istream & operator >>( istream & input, Time & T );


    /**
     * @brief  Function for removing whitespace from a string
     *
     * @param string & str
     * @return string
     */
string removeSpaces(const string & str);
