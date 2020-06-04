// menu.h
//---------------------------------------------------------------------------------

#ifndef MENU_H
#define MENU_H

//---------------------------------------------------------------------------------

#include <fstream>
#include <sstream>
#include "myIO.h"
#include "weather.h"

using namespace std;


//---------------------------------------------------------------------------------

    /**
     * @class menu
     * @brief  Manages all the requirements for menu
     *
     * @author Ryan Draper
     * @version 01
     * @date 29/04/2020 Ryan Draper, Started
     */

class menu
{
public:

        /**
         * @brief Default constructor
         */
    menu();

        /**
         * @brief Destructor
         */
    ~menu();

        /**
         * @brief Opens file and calls istream for reading
         *
         * @return boolean
         */
    int Read();

        /**
         * @brief Calls istream to write to a file
         *
         * @return void
         */
    void write();

        /**
         * @brief Displays menu options
         *
         * Displays a list of menu options - prints on screen
         *
         * @return void
         */
    void DisplayMenu();

        /**
         * @brief Function for menu options
         *
         * Gets the users choice of menu option to be run
         *
         * @return int
         */
    int GetChoice();

        /**
         * @brief Runs the program
         *
         * Calls functions to display menu, get menu choice, run menu options and continue running
         *
         * @return void
         */
    void RunMenu();

        /**
         * @brief Gets month input and checks that its valid
         *
         * @return void
         */
    void checkMonth();

        /**
         * @brief Gets year input and checks that its valid
         *
         * @return void
         */
    void checkYear();

        /**
         * @brief Menu option 1 function
         *
         * Displays the average wind speed and sample standard deviation
         * for a specified month and year
         *
         * @return void
         */
    void option1();

        /**
         * @brief Menu option 2 function
         *
         * Displays the average ambient air temperature and sample standard deviation
         * for each month of a specified year
         *
         * @return void
         */
    void option2();

        /**
         * @brief Menu Option 3 function
         *
         * Displays total solar radiation for each month of a specified year
         *
         * @return void
         */
    void option3();

        /**
         * @brief Menu option 4 function
         *
         * Prints all details for wind speed, ambient air temperature and solar radiation
         * for each month of a specified year
         *
         * @return void
         */
    void option4();

        /**
         * @brief Menu option 5 function - quits the program
         *
         * @return void
         */
    void option5();

private:
        /// Weather class variable
    weather w;
};

#endif // MENU_H
