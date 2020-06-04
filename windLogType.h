// windLog.h
//---------------------------------------------------------------------------------

#ifndef WINDLOGTYPE_H
#define WINDLOGTYPE_H

//---------------------------------------------------------------------------------

#include "date.h"
#include "time.h"

//---------------------------------------------------------------------------------

    /**
     * @class WindLogType
     * @brief Holds the methods and variables for WindLogType
     *
     * @author Ryan Draper
     * @version 01
     * @date 26/04/2020 Ryan Draper, Started
     */

class WindLogType
{
public:
        /**
         * @brief  Default constructor
         *
         * This sets member variables to default values
         */
    WindLogType();

        /**
         * @brief  Destructor
         */
    ~WindLogType();

        /**
         * @brief  Constructor
         *
         * This sets member variables to parameter variables
         */
    WindLogType(double ws, double sr, double aa);

        /**
         * @brief Sets date object to parameter
         *
         * @param  Const Date &
         * @return void
         */
    void SetDate( const Date & dt );

        /**
         * @brief  Returns the date object
         *
         * @return const Date &
         */
    const Date & GetDate() const;

        /**
         * @brief  Sets the time object to parameter
         *
         * @param  const Time &
         * @return void
         */
    void SetTime( const Time & tt );

        /**
         * @brief  Returns time object
         *
         * @return const Time &
         */
    const Time & GetTime() const;

        /**
         * @brief  Sets the wind speed variable to parameter
         *
         * @param  const double &
         * @return void
         */
    void SetSpeed( const double & s );

        /**
         * @brief  Returns the wind speed
         *
         * @return const double &
         */
    const double & GetSpeed() const;

        /**
         * @brief  Sets the solar radiation variable to parameter
         *
         * @param  const double &
         * @return void
         */
    void SetSolarRad( const double & s );

        /**
         * @brief  Returns the solar radiation
         *
         * @return const double &
         */
    const double & GetSolarRad() const;

        /**
         * @brief  Sets the ambient air temperature variable to the parameter
         *
         * @param  const double &
         * @return void
         */
    void SetAmbAir( const double & a );

        /**
         * @brief  Returns the ambient air temperature
         *
         * @return const double &
         */
    const double & GetAmbAir() const;

private:
        /// Wind speed variable
    double speed;

        /// Solar radiation variable
    double solarRad;

        /// Ambient air temperature variable
    double ambAir;

        /// Date class object
    Date d;

        /// Time class object
    Time t;
};

#endif // WINDLOGTYPE_H
