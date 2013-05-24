/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on May 18, 2013, 4:13 PM
 */

#include <string>
#include <iostream>
#include "Parsing.h"

int main(int argc, char** argv) {
    std::string buffer = "$GPRMC,125504.049,A,5542.2389,N,\
            03741.6063,E,0.06,25.82,200906,,,*17\r\n\
$GPGGA,160023.69,1130.832,N,04344.045,E,1\
,04,2.6,100.00,M,-33.9,M,,0000*7C";

    CParsing p;
    bool dataIsRready = true;

    p.parseData(buffer, dataIsRready);
    std::cout << "Altitude = " << p.getAltitude() << std::endl;
    std::cout << "Latitude = " << p.getLatitude() << std::endl;
    std::cout << "Longitude = " << p.getLongitude() << std::endl;
    std::cout << "NSatellites = " << p.getNSatellites() << std::endl;
    std::cout << "Speed = " << p.getSpeed() << std::endl;
    std::cout << "Time = " << p.getTime() << std::endl;
    std::cout << "isValidGPGGAData = " << p.isValidGPGGAData() << std::endl;
    std::cout << "isValidGPRMCData = " << p.isValidGPRMCData() << std::endl;

    return 0;
}
