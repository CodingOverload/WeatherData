// weather.h
//---------------------------------------------------------------------------------

#ifndef WEATHER_H
#define WEATHER_H

//---------------------------------------------------------------------------------
// Includes

#include "Vector.h"
#include "statistics.h"
#include "windLogType.h"

//---------------------------------------------------------------------------------

    /**
     * @class weather
     * @brief Holds the methods for the using the WindLogType vector
     *
     * @author Ryan Draper
     * @version 01
     * @date 26/04/2020 Ryan Draper, Started
     *
     * @version 02
     * @date 27/04/2020 Ryan Draper, Added Average and SampleDev functions.
     *
     * @version 03
     * @date 28/04/2020 Ryan Draper, Added roundNum function.
     */

class weather
{
public:

        /**
         * @brief  Default constructor
         *
         * This constructor sets member variables to default value.
         */
    weather();

        /**
         * @brief  Destructor
         */
    ~weather();

        /**
         * @brief  Constructor
         *
         * This constructor sets member variables to the parameter values/objects.
         */
    weather(unsigned int m, unsigned int y, const Vector<WindLogType> & v);

        /**
         * @brief  AddData function
         *
         * This Function adds WindLogType objects to the vector.
         *
         * @param  A WindLogType object.
         */
    void AddData(const WindLogType & w);

        /**
         * @brief  GetData function
         *
         * This function returns a WindLogType object at position i.
         *
         * @param  An integer which indicates the position of the vector to return.
         */
    const WindLogType & GetData(int i) const;

        /**
         * @brief  getSpeedVec function
         *
         * This function returns a vector of windspeed for specified month and year.
         *
         * @param string m
         * @param unsigned int y
         */
    const Vector<double> getSpeedVec() const;

        /**
         * @brief  GetAverageSpeed function
         *
         * This function returns the average value of speed variables for specified month and year.
         *
         * @param string m
         * @param unsigned int y
         */
    double GetAverageSpeed() const;

        /**
         * @brief  GetSpeedSampleDev function
         *
         * This function returns the number sample standard deviation value of speed variables for specified month and year.
         *
         * @param string m
         * @param unsigned int y
         */
    double GetSpeedSampleDev() const;

        /**
         * @brief  getAirVec function
         *
         * This function returns a vector of ambient air temperature for specified month and year.
         *
         * @param string m
         * @param unsigned int y
         */
    const Vector<double> getAirVec() const;

        /**
         * @brief  GetAverageAir function
         *
         * This function returns the average value of ambient air temperature variables for specified month and year
         *
         * @param string m
         * @param unsigned int y
         */
    double GetAverageAir() const;

        /**
         * @brief  GetAirSampleDev function
         *
         * This function returns the number sample standard deviation value of ambient air temperature variables for specified month and year
         *
         * @param string m
         * @param unsigned int y
         */
    double GetAirSampleDev() const;

        /**
         * @brief  getSolarVec function
         *
         * This function returns a vector of solar radiation for specified month and year.
         *
         * @param string m
         * @param unsigned int y
         */
    const Vector<double> getSolarVec() const;

        /**
         * @brief  GetTotalSolarRad function
         *
         * This function returns the total solar radiation for specified month and year.
         *
         * @param string m
         * @param unsigned int y
         */
    double GetTotalSolarRad() const;


        /**
         * @brief  Function for setting month.
         *
         * This function sets month to the parameter value.
         *
         * @return void
         */
    void SetMonth( unsigned int m );

        /**
         * @brief  Function for getting month.
         *
         * This function returns the month.
         *
         * @return string
         */
    unsigned int GetMonth() const;

        /**
         * @brief  Function for setting year.
         *
         * This function sets year to the parameter value.
         *
         * @return void
         */
    void SetYear( unsigned int y );

        /**
         * @brief  Function for getting year.
         *
         * This function returns the year.
         *
         * @return unsigned int
         */
    unsigned int GetYear() const;

        /**
         * @brief  Function for getting name of month.
         *
         * This function returns the name of the month.
         *
         * @return string
         */
    string getMonthName() const;

private:
        /// Vector of WindLogType
    Vector<WindLogType> vec;

        /// month variable
    unsigned int month;

        /// year variable
    unsigned int year;
};

#endif // WEATHER_H
