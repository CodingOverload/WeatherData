// myIO.CPP - IO class implementation
//---------------------------------------------------------------------------------
// Includes

#include "myIO.h"

//---------------------------------------------------------------------------------
// Function for removing whitespaces from a string
string removeSpaces(const string & str)
{
    string store = "";

    // Loop through for each charater of a string
	for(int i=0; i<(signed)str.length(); i++)
	{
	    // If the charater is not a whitespace, add it to store
		if(!isspace(str.at(i)))
		{
			store += str.at(i);
		}
	}
	return store;
}

//---------------------------------------------------------------------------------
// Reads input lines passed from a file and separates them and sets them to weather variables.
istream & operator >>( istream & input, weather & W )
{
    WindLogType wl;
    Date d;
    Time t;
    double f;
    string line, temp;

    getline(input, line);
    stringstream buffer(line);

    getline(buffer, temp, ' '); // Read in date
    istringstream(temp) >> d;
    wl.SetDate(d);

    getline(buffer, temp, ','); // Read in time
    istringstream(temp) >> t;
    wl.SetTime(t);

    for(int i=0; i<9; i++) // Skip 9 data value
    {
        getline(buffer, temp, ',');
    }

    getline(buffer, temp, ','); // Read in speed
    temp = removeSpaces(temp); // Remove whitespace from input
    istringstream(temp) >> f;
    // If a value is missing(blank space) from the file
    if(temp.empty())
    {
        wl.SetSpeed(-1);
    }
    // If a value is not missing from the file
    else
    {
        wl.SetSpeed(f);
    }

    getline(buffer, temp, ','); // Read in solarRad
    temp = removeSpaces(temp); // Remove whitespace from input
    istringstream(temp) >> f;
    // If a value is missing from the file
    if(temp.empty())
    {
        wl.SetSolarRad(-1);
    }
    // If a value is not missing from the file
    else
    {
        wl.SetSolarRad(f);
    }

    for(int i=0; i<5; i++) // Skip 5 data values
    {
        getline(buffer, temp, ',');
    }

    getline(buffer, temp); // Read in ambAir
    temp = removeSpaces(temp);
    istringstream(temp) >> f;
    // If a value is missing from the file
    if(temp.empty())
    {
        wl.SetAmbAir(-1);
    }
    // If a value is not missing from the file
    else
    {
        wl.SetAmbAir(f);
    }

    // Add the WindLogType data to the vector
    W.AddData(wl);

    return input;
}

//---------------------------------------------------------------------------------
// Returns weather variables via ostream.
ostream & operator <<( ostream & os, const weather & W )
{
    static int noData = 0;

        int as = W.getAirVec().initialised(); // Number of ambient air temperature values
        int ss = W.getSpeedVec().initialised(); // Number of wind speed values
        int ts = W.getSolarVec().initialised(); // Number of solar radiation values

        double avgA = W.GetAverageAir(); // Ambient air temperature average
        double avgS = W.GetAverageSpeed(); // Wind speed average

        double smpS = W.GetSpeedSampleDev(); // Wind speed sample standard deviation
        double smpA = W.GetAirSampleDev(); // Ambient air temperature sample standard deviation

        double t = W.GetTotalSolarRad(); // Total solar radiation

        // If there is data for wind speed, ambient air temperature and solar radiation
        if(as > 0 || ss > 0 || ts > 0)
        {
            os << W.getMonthName() << ",";

            // If wind speed has an average
            if(avgS >= 0)
            {
                os << W.GetAverageSpeed() << "(" << W.GetSpeedSampleDev() << "),";
            }
            // If windspeed has an average but no sample standard deviation
            else if(avgS >= 0 && (int)smpS == -1)
            {
                os << W.GetAverageSpeed() << "(),";
            }
            // If wind speed has no average or sample standard deviation
            else
            {
                os << " ,";
            }

            // If ambient air temperature has an average
            if(avgA >= 0 && (int)smpA != -1)
            {
                os << W.GetAverageAir() << "(" << W.GetAirSampleDev() << "),";
            }
            // If ambient air temperature has an average but no sample standard deviation
            else if(avgA >=0 && (int)smpA == -1)
            {
                os << W.GetAverageAir() << "(),";
            }
            // If ambient air temperature has no average or sample standard deviation
            else
            {
                os << " ,";
            }

            // If solar radiation has data
            if(t >= 0)
            {
                os << W.GetTotalSolarRad() << endl;
            }
            // If there is no data for solar radiation
            else
            {
                os << "\n";
            }
        }
        // If there is no data for the month
        else
        {
            noData++;
        }

    // If there is no data for the entire year
    if(noData == 12)
    {
        os << "No Data" << endl;
        noData = 0;
    }

    return os;
}

//---------------------------------------------------------------------------------
// This function is for setting Date class detais.
istream & operator >>( istream & input, Date & D )
{
    unsigned hold;
    string line, temp;

    getline(input, line);
    stringstream buffer(line);

    getline(buffer, temp, '/'); // Read in day
    istringstream(temp) >> hold;
    D.SetDay(hold);

    getline(buffer, temp, '/'); // Read in month
    istringstream(temp) >> hold;
    D.SetMonth(hold);

    getline(buffer, temp); // Read in year
    istringstream(temp) >> hold;
    D.SetYear(hold);

    return input;
}

//---------------------------------------------------------------------------------
// This function is for setting Time class detais.
istream & operator >>( istream & input, Time & T )
{
    string line, temp;

    getline(input, line);
    stringstream buffer(line);

    getline(buffer, temp, ':'); // Read in hours
    T.Sethours(temp);

    getline(buffer, temp); // Read in minutes
    T.Setminutes(temp);

    return input;
}


