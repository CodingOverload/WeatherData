// time.h
//---------------------------------------------------------------------------------

#ifndef Time_H
#define Time_H

//---------------------------------------------------------------------------------

#include<string>

using namespace std;

//---------------------------------------------------------------------------------

    /**
     * @class Time
     * @brief  Manages all time variables
     *
     * @author Ryan Draper
     * @version 01
     * @date 21/04/2020 Ryan Draper, Started
     */

class Time
{
public:
        /**
         * @brief  Default constructor
         *
         * This constructor creates a new time with default values.
         */
    Time();

        /**
         * @brief  Constructor
         *
         * This constructor creates a new time with values set from parameters.
         *
         * @param  h - string
         * @param  m - string
         */
    Time(string h, string m);

        /**
         * @brief  Destructor
         */
    ~Time();

        /**
         * @brief  Function for getting minutes.
         *
         * This function returns the minutes.
         *
         * @return string
         */
    const string & Getminutes() const;

        /**
         * @brief  Function for setting hours.
         *
         * This function sets hours to the parameter value.
         *
         *@return void
         */
    void Setminutes(const string & m);

        /**
         * @brief  Function for getting hours.
         *
         * This function returns the hours.
         *
         * @return string
         */
    const string & Gethours() const;

        /**
         * @brief  Function for setting minutes.
         *
         * This function sets minutes to the parameter value.
         *
         *@return void
         */
    void Sethours(const string & h);

private:
        /// minutes variable
    string minutes;

        /// hours variable
    string hours;
};

#endif // Time_H
