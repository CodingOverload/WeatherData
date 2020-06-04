// statistics.h
//---------------------------------------------------------------------------------

#ifndef STATISTICS_H
#define STATISTICS_H

//---------------------------------------------------------------------------------
// Includes

#include "Vector.h"
#include<string>
#include <cmath>
using namespace std;

//---------------------------------------------------------------------------------

    /**
     * @class template statistics
     * @brief  Has template methods for some calculations and comparisons.
     *
     * @author Ryan Draper
     * @version 01
     * @date 22/04/2020 Ryan Draper, Started
     */

template<class T>
class statistics
{
public:
        /**
         * @brief Default constructor
         */
    statistics();

        /**
         * @brief Destructor
         */
    ~statistics();

        /**
         * @brief  calculates and returns an average
         *
         * This function is for returning an average.
         *
         * @param a Vector and count(number of initialised elements in the Vector)
         *
         * @return T
         */
    T Average(const Vector<T> &vec) const;

        /**
         * @brief  calculates and returns a sample standard deviation
         *
         * This function is for returning a sample standard deviation
         *
         * @param a Vector, count(number of initialised elements in the Vector), and average.
         *
         * @return T
         */
    T SampleDev(const Vector<T> &vec, double m) const;

        /**
         * @brief  returns total sum of all elements in vec.
         *
         * This function is for calculating the sum of all elements in vec.
         *
         * @param a vector of type T and int count.
         *
         * @return T
         */
    T GetTotal(const Vector<T> & vec) const;

        /**
         * @brief  roundNum function
         *
         * This function rounds a double to 1 decimal place then returns that value.
         *
         * @param double f
         */
    double roundNum(T f) const;
};

//---------------------------------------------------------------------------------
    /**
     *Default constructor
     */
template<class T>
statistics<T>::statistics()
{

}

//---------------------------------------------------------------------------------
    /**
     *Destructor
     */
template<class T>
statistics<T>::~statistics()
{

}

//---------------------------------------------------------------------------------
    /**
     *calculates and returns an average.
     */
template<class T>
T statistics<T>::Average(const Vector<T> &vec) const
{
    T avg=0;

    for(int i=0; i<vec.initialised(); i++)
    {
        avg += vec[i];
    }
    avg /= vec.initialised();

    return avg;
}

//---------------------------------------------------------------------------------
    /**
     *calculates and returns a sample standard deviation.
     */
template<class T>
T statistics<T>::SampleDev(const Vector<T> &vec,double m) const
{
    T sdev=0;
    for(int i=0; i<vec.initialised(); i++)
    {
        sdev += (vec[i]-m)*(vec[i]-m);
    }
    sdev /= (vec.initialised()-1);
    sdev = sqrt(sdev);
    return sdev;
}

//---------------------------------------------------------------------------------
    /**
     *calculates and returns the sum of all elements in vec.
     */
template<class T>
T statistics<T>::GetTotal(const Vector<T> & vec) const
{
    T sum = 0;
    for(int i=0; i<vec.initialised(); i++)
    {
        sum += vec[i];
    }
    return sum;
}

//---------------------------------------------------------------------------------
    /**
     * This function rounds a double to 1 decimal place then returns that value.
     */
template<class T>
double statistics<T>::roundNum(T f) const
{
    int whole = (int) f; // gets the whole number before decimal point
    string num = std::to_string(f); // converts double into string
    int decPos = num.find("."); // finds the position of the decimal point
    int x = stoi(num.substr(decPos+1, 1)); // gets the 1st number after the decimal point
    int y = stoi(num.substr(decPos+2, 1)); // gets the 2nd number after the decimal point

    if(y >= 5) // checks if the second number after decimal point is equal to or greater than 5
    {
        x++; // rounds the first number after decimal point up 1 if second number is >= 5
    }

    string ans = to_string(whole) + "." + to_string(x); // creates a new string with the number before decimal point and the 1st number after decimal point
    return stof(ans); // converts string to double and returns
}

//---------------------------------------------------------------------------------
#endif // STATISTICS_H
