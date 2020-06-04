// date.h
//---------------------------------------------------------------------------------

#ifndef DATE_H
#define DATE_H

//---------------------------------------------------------------------------------

    /**
     * @class Date
     * @brief  Manages all date variables
     *
     * @author Ryan Draper
     */

class Date
{

public:
        /**
         * @brief  Default constructor
         *
         * This constructor creates a new date with default values.
         */
    Date();

        /**
         * @brief  Constructor
         *
         * This constructor creates a new date with values set from parameters.
         *
         * @param  dy - unsigned int
         * @param  m - unsigned int
         * @param  dy - unsigned int
         */
    Date(unsigned int dy, unsigned int m, unsigned int yr);

        /**
         * @brief  Destructor
         */
    ~Date();

        /**
         * @brief  Function for setting day.
         *
         * This function sets day to the parameter value.
         *
         * @return void
         */
    void SetDay( unsigned int & d );

        /**
         * @brief  Function for getting day.
         *
         * This function returns the day.
         *
         * @return unsigned int
         */
    const unsigned int & GetDay() const;

        /**
         * @brief  Function for setting month.
         *
         * This function sets month to the parameter value.
         *
         * @return void
         */
    void SetMonth( unsigned int & m );

        /**
         * @brief  Function for getting month.
         *
         * This function returns the month.
         *
         * @return string
         */
    const unsigned int & GetMonth() const;

        /**
         * @brief  Function for setting year.
         *
         * This function sets year to the parameter value.
         *
         * @return void
         */
    void SetYear( unsigned int & y );

        /**
         * @brief  Function for getting year.
         *
         * This function returns the year.
         *
         * @return unsigned int
         */
    const unsigned int & GetYear() const;

private:
        /// day variable
    unsigned int day;

        /// month variable
    unsigned int month;

        /// year variable
    unsigned int year;
};

#endif // DATE_H
