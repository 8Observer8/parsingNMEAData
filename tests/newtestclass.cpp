/*
 * File:   newtestclass.cpp
 * Author: Ivan
 *
 * Created on May 18, 2013, 10:44:25 PM
 */

#include "newtestclass.h"
#include "../Parsing.h"
#include <ctime>


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

void newtestclass::testParseData() {
    std::string buffer = "$GPGGA,160023.69,1130.832,N,04344.045,E,1,04,\
2.6,100.00,M,-33.9,M,,0000*7C\r\n$GPGLL,1130.915,\
N,04344.052,E,160024.70,A*0C\r\n$GPGGA,160025.71,\
1130.998,N,04344.060,E,2,04,2.7,100.00,M,-33.9,M,\
,0000*74\r\n$GPRMC,160026.73,A,1131.081,N,04344.067,\
E,300.00,4.96,110213,0.0,E*5A";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (31.081 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.067 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testGetAltitude() {
    std::string buffer = "$GPGLL,1131.247,N,04344.082,E,\
160028.76,A*06\r\n$GPGLL,1131.330,N,04344.089,\
E,160029.77,A*0C\r\n$GPRMC,160030.79,A,1131.413,\
N,04344.096,E,300.00,4.96,110213,0.0,\
E*56\r\n$GPGGA,160031.80,1131.496,N,\
04344.104,E,2,04,1.8,100.00,M,-33.9,\
M,,0000*72\r\n$GPGGA,160032.81,1131.579,N";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (31.413 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.096 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testParseData_incorrectStartBuffer() {
    std::string buffer = "N,04344.074,E,300.00,4.96,110213,0.0,\
E*54\r\n$GPGLL,1131.247,N,04344.082,E,\
160028.76,A*06\r\n$GPGLL,1131.330,N,04344.089,\
E,160029.77,A*0C\r\n$GPRMC,160030.79,A,1131.413,\
N,04344.096,E,300.00,4.96,110213,0.0,\
E*56\r\n$GPGGA,160031.80,1131.496,N,\
04344.104,E,2,04,1.8,100.00,M,-33.9,\
M,,0000*72\r\n$GPGGA,160032.81,1131.579,N";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(!dataIsReady && !result);
}

void newtestclass::testGetLatitude() {
    std::string buffer = "$GPGGA,160036.87,1131.911,N,\
04344.140,E,2,04,2.9,100.00,M,-33.9,M,,0000*72\
\r\n$GPRMC,160037.88,A,1131.994,N,04344.148,E,\
300.00,4.96,110213,0.0,E*5F\r\n$GPGLL,1132.077,N,04344.155,";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (31.994 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.148 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testGetLongitude() {
    std::string buffer = "$GPGGA,160041.94,1132.326,N,\
04344.177,E,2,04,1.3,100.00,M,-33.9,M,\
,0000*70\r\n$GPGLL,1132.409,N,04344.185,E,\
160042.97,A*0C\r\n$GPGLL,1132.492,N,\
04344.192,E,160043.97,A*09\r\n$GPRMC,\
160044.98,A,1132.575,N,04344.199,E,\
300.00,4.96,110213,0.0,E*56\r\n$GPGLL,\
1132.658,N,04344.207,E,160046.00,A*09";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (32.575 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.199 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testGetNSatellites() {
    std::string buffer = "$GPRMC,160047.01,A,1132.741,N,\
04344.214,E,300.00,4.96,110213,\
0.0,E*56\r\n$GPGGA,160048.02,1132.823,\
N,04344.221,E,2,04,1.5,100.00,M,\
-33.9,M,,0000*7E\r\n$GPRMC,160049.04,\
A,1132.906,N,04344.2";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (32.741 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.221 + 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testGetSpeed() {
    std::string buffer = "1133.321,N,04344.237,E,160054.11,\
A*03\r\n$GPRMC,160055.12,A,1133.404,N,\
04344.230,E,300.00,355.32,110213,\
0.0,E*5B\r\n$GPGGA,160056.14,1133.487,\
N,04344.223,E,2,04,1.1,100.00,M,\
-33.9,M,,0000*73\r\n$GPGGA,160057.15,\
1133.570,N,04344.216,E,1,04,1.7,\
100.00,M,-33.9,M,,0000*7A";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (33.404 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.230 + 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testGetTime() {
    std::string buffer = "$GPGGA,160105.26,1134.234,N,\
04344.161,E,2,04,1.6,100.00,M,\
-33.9,M,,0000*7E\r\n$GPGLL,1134.317,\
N,04344.154,E,160106.28,A*0B\r\n$GPGLL,\
1134.400,N,04344.147,E,160107.29,\
A*08\r\n$GPRMC,160108.32,A,1134.483,N,\
04344.134,E,300.00,351.35,110213,\
0.0,E*5C\r\n$GPRMC,160109.32,A,1134.565,N,";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (34.483 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.134 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testIsValidGPGGAData() {
    std::string buffer = ",04344.096,E,160111.35,A*0F\
\r\n$GPGGA,160112.36,1134.812,N,\
04344.083,E,2,04,2.8,100.00,M,\
-33.9,M,,0000*77\r\n$GPRMC,160113.38,\
A,1134.894,N,04344.070,E,300.00,\
351.35,110213,0.0,E*57\r\n$GPRMC,\
160114.39,A,1134.977,N,04344.057";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (34.894 / 60);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.070 / 60);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testIsValidGPRMCData() {
    std::string buffer = "$GPGLL,1135.224,N,04344.019,E,\
160117.43,A*0E\r\n$GPGGA,160118.45,\
1135.304,N,04343.997,E,2,04,1.9,\
100.00,M,-33.9,M,,0000*7D\r\n$GPRMC,\
160119.46,A,1135.384,N,04343.975,\
E,300.00,344.96,110213,0.0,\
E*59\r\n$GPGLL,1135.465,N,04343.953,";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (35.384 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (43.975 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testIsNotValidGPGGAData_SetZerro() {
    std::string buffer = ",04344.096,E,160111.35,A*0F\
\r\n$GPGGA,160112.36,1134.812,N,\
04344.083,E,0,04,2.8,100.00,M,\
-33.9,M,,0000*77\r\n$GPRMC,160113.38,\
A,1134.894,N,04344.070,E,300.00,\
351.35,110213,0.0,E*57\r\n$GPRMC,\
160114.39,A,1134.977,N,04344.057";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = false;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(!expectedIsValidGPGGAData);
    CPPUNIT_ASSERT(!resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (34.894 / 60);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.070 / 60);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testIsNotValidGPGGAData_SetOne() {
    std::string buffer = ",04344.096,E,160111.35,A*0F\
\r\n$GPGGA,160112.36,1134.812,N,\
04344.083,E,1,04,2.8,100.00,M,\
-33.9,M,,0000*77\r\n$GPRMC,160113.38,\
A,1134.894,N,04344.070,E,300.00,\
351.35,110213,0.0,E*57\r\n$GPRMC,\
160114.39,A,1134.977,N,04344.057";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = false;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(!expectedIsValidGPGGAData);
    CPPUNIT_ASSERT(!resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (34.894 / 60);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.070 / 60);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testIsNotValidGPGGAData_SetThree() {
    std::string buffer = ",04344.096,E,160111.35,A*0F\
\r\n$GPGGA,160112.36,1134.812,N,\
04344.083,E,3,04,2.8,100.00,M,\
-33.9,M,,0000*77\r\n$GPRMC,160113.38,\
A,1134.894,N,04344.070,E,300.00,\
351.35,110213,0.0,E*57\r\n$GPRMC,\
160114.39,A,1134.977,N,04344.057";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = false;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(!expectedIsValidGPGGAData);
    CPPUNIT_ASSERT(!resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (34.894 / 60);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.070 / 60);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testIsNotValidGPRMCData_SetV() {
    std::string buffer = "$GPGLL,1135.224,N,04344.019,E,\
160117.43,A*0E\r\n$GPGGA,160118.45,\
1135.304,N,04343.997,E,2,04,1.9,\
100.00,M,-33.9,M,,0000*7D\r\n$GPRMC,\
160119.46,V,1135.384,N,04343.975,\
E,300.00,344.96,110213,0.0,\
E*59\r\n$GPGLL,1135.465,N,04343.953,";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = false;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(!expectedIsValidGPRMCData && !resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (35.384 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (43.975 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testIsNotValidGPRMCData_Set5() {
    std::string buffer = "$GPGLL,1135.224,N,04344.019,E,\
160117.43,A*0E\r\n$GPGGA,160118.45,\
1135.304,N,04343.997,E,2,04,1.9,\
100.00,M,-33.9,M,,0000*7D\r\n$GPRMC,\
160119.46,5,1135.384,N,04343.975,\
E,300.00,344.96,110213,0.0,\
E*59\r\n$GPGLL,1135.465,N,04343.953,";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = false;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(!expectedIsValidGPRMCData && !resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (35.384 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (43.975 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testIsNotValidGPRMCData_SetW() {
    std::string buffer = "$GPGLL,1135.224,N,04344.019,E,\
160117.43,A*0E\r\n$GPGGA,160118.45,\
1135.304,N,04343.997,E,1,04,1.9,\
100.00,M,-33.9,M,,0000*7D\r\n$GPRMC,\
160119.46,W,1135.384,N,04343.975,\
E,300.00,344.96,110213,0.0,\
E*59\r\n$GPGLL,1135.465,N,04343.953,";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = false;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(!expectedIsValidGPRMCData && !resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (35.384 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (43.975 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testParseData_partialBuffer() {
    std::vector<std::string> bufferArr;
    bufferArr.push_back("$GPGGA,160023.69,1130.832,N,04344.045,E,1,04,");
    bufferArr.push_back("2.6,100.00,M,-33.9,M,,0000*7C\r\n\r\n$GPGLL,1130.915,");
    bufferArr.push_back("N,04344.052,E,160024");
    bufferArr.push_back(".70,A*0C\r\n\r\n$GPGGA,160025.71,");
    bufferArr.push_back("1130.998,N,04344.060,E");
    bufferArr.push_back(",1,04,2.7,100.00,M,-33.9,M,");
    bufferArr.push_back(",0000*74\r\n$GP");
    bufferArr.push_back("RMC,160026.73,A,1131.081,N,04344.067,");
    bufferArr.push_back("E,300.00,4.");
    bufferArr.push_back("96,110213,0.0,E*5A");

    bool dataIsReady = false;
    bool result = false;
    CParsing cParsing;

    for (unsigned int i = 0; i < bufferArr.size(); i++) {
        result = cParsing.parseData(bufferArr[i], dataIsReady);
        if (result && dataIsReady) {
            break;
        }
    }

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (31.081 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.067 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testGetAltitude_partialBuffer() {
    std::vector<std::string> bufferArr;
    bufferArr.push_back("N,04344.074,E,300");
    bufferArr.push_back(".00,4.96,110213,0.0,");
    bufferArr.push_back("E*54\r\n$GPGLL,1131.");
    bufferArr.push_back("247,N,04344.082,E,");
    bufferArr.push_back("160028.76,A*06\r\n$GPGLL,");
    bufferArr.push_back("1131.330,N,04344.089,");
    bufferArr.push_back("E,160029.77,A*0C\r\n$GPRMC");
    bufferArr.push_back(",160030.79,A,1131.413,");
    bufferArr.push_back("N,04344.096,E,300.00,");
    bufferArr.push_back("4.96,110213,0.0,");
    bufferArr.push_back("E*56\r\n$GPGGA,160031.80,1131.496,N,");
    bufferArr.push_back("04344.104,E,1,04,1.8,100.00,M,-33.9,");
    bufferArr.push_back("M,,0000*72\r\n$GPGGA,160032.81,1131.579,N");

    bool dataIsReady = false;
    bool result = false;
    CParsing cParsing;

    for (unsigned int i = 0; i < bufferArr.size(); i++) {
        result = cParsing.parseData(bufferArr[i], dataIsReady);
        if (result && dataIsReady) {
            break;
        }
    }

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (31.413 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.096 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    int expectedTime = 160023;
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testGetLatitude_partialBuffer() {
    std::vector<std::string> bufferArr;
    bufferArr.push_back("N,04344.133,E,1,");
    bufferArr.push_back("04,2.6,100.00,");
    bufferArr.push_back("M,-33.9,M,,0000*70\r\n$GP");
    bufferArr.push_back("GGA,160036.87,1131.911,N,");
    bufferArr.push_back("04344.140,E,1,04,2.9");
    bufferArr.push_back(",100.00,M,-33.9,M,,0000*72");
    bufferArr.push_back("\r\n$GPRMC,160037.88,A,1131");
    bufferArr.push_back(".994,N,04344.148,E,");
    bufferArr.push_back("300.00,4.96,110213,0.0,E");
    bufferArr.push_back("*5F\r\n$GPGLL,1132.");
    bufferArr.push_back("077,N,04344.155,");

    bool dataIsReady = false;
    bool result = false;
    CParsing cParsing;

    for (unsigned int i = 0; i < bufferArr.size(); i++) {
        result = cParsing.parseData(bufferArr[i], dataIsReady);
        if (result && dataIsReady) {
            break;
        }
    }

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (31.994 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.148 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testGetLongitude_partialBuffer() {
    std::vector<std::string> bufferArr;
    bufferArr.push_back("$GPGGA,160041.94");
    bufferArr.push_back(",1132.326,N,");
    bufferArr.push_back("04344.177,E,1,04,");
    bufferArr.push_back("1.3,100.00,M,-33.9,M,");
    bufferArr.push_back(",0000*70\r\n$GPGLL,11");
    bufferArr.push_back("32.409,N,04344.185,E,");
    bufferArr.push_back("160042.97,A*0C\r\n$GPGL");
    bufferArr.push_back("L,1132.492,N,");
    bufferArr.push_back("04344.192,E,1600");
    bufferArr.push_back("43.97,A*09\r\n$GPRMC,");
    bufferArr.push_back("160044.98,A,1132.5");
    bufferArr.push_back("75,N,04344.199,E,");
    bufferArr.push_back("300.00,4.96,110");
    bufferArr.push_back("213,0.0,E*56\r\n$GPGLL,");
    bufferArr.push_back("1132.658,N,04344.207,");
    bufferArr.push_back("E,160046.00,A*09");

    bool dataIsReady = false;
    bool result = false;
    CParsing cParsing;

    for (unsigned int i = 0; i < bufferArr.size(); i++) {
        result = cParsing.parseData(bufferArr[i], dataIsReady);
        if (result && dataIsReady) {
            break;
        }
    }

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (32.575 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.199 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    int expectedTime = 160023;
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testGetNSatellites_partialBuffer() {
    std::vector<std::string> bufferArr;
    bufferArr.push_back("$GPRMC,160047.");
    bufferArr.push_back("01,A,1132.741,N,");
    bufferArr.push_back("04344.214,E,30");
    bufferArr.push_back("0.00,4.96,110213,");
    bufferArr.push_back("0.0,E*56\r\n$GPGGA,160");
    bufferArr.push_back("048.02,1132.823,");
    bufferArr.push_back("N,04344.221,E,1,04");
    bufferArr.push_back(",1.5,100.00,M,");
    bufferArr.push_back("-33.9,M,,0000*7");
    bufferArr.push_back("E\r\n$GPRMC,160049.04,");
    bufferArr.push_back("A,1132.906,N,");
    bufferArr.push_back("04344.2");

    bool dataIsReady = false;
    bool result = false;
    CParsing cParsing;

    for (unsigned int i = 0; i < bufferArr.size(); i++) {
        result = cParsing.parseData(bufferArr[i], dataIsReady);
        if (result && dataIsReady) {
            break;
        }
    }

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (32.741 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.214 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    int expectedTime = 160023;
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testGetSpeed_partialBuffer() {
    std::vector<std::string> bufferArr;
    bufferArr.push_back("1133.321,N,0434");
    bufferArr.push_back("4.237,E,160054.11,");
    bufferArr.push_back("A*03\r\n$GPRMC,16005");
    bufferArr.push_back("5.12,A,1133.404,N,");
    bufferArr.push_back("04344.230,E,300.00");
    bufferArr.push_back(",355.32,110213,");
    bufferArr.push_back("0.0,E*5B\r\n$GPGGA,1600");
    bufferArr.push_back("56.14,1133.487,");
    bufferArr.push_back("N,04344.223,E,1,04,1");
    bufferArr.push_back(".1,100.00,M,");
    bufferArr.push_back("-33.9,M,,0000*73$G");
    bufferArr.push_back("PGGA,160057.15,");
    bufferArr.push_back("1133.570,N,04344.21");
    bufferArr.push_back("6,E,1,04,1.7,");
    bufferArr.push_back("100.00,M,-33.9,M,");
    bufferArr.push_back(",0000*7A");

    bool dataIsReady = false;
    bool result = false;
    CParsing cParsing;

    for (unsigned int i = 0; i < bufferArr.size(); i++) {
        result = cParsing.parseData(bufferArr[i], dataIsReady);
        if (result && dataIsReady) {
            break;
        }
    }

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (33.404 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.230 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    int expectedTime = 160023;
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testGetTime_partialBuffer() {
    std::vector<std::string> bufferArr;
    bufferArr.push_back("$GPGGA,160105.2");
    bufferArr.push_back("6,1134.234,N,");
    bufferArr.push_back("04344.161,E,1,");
    bufferArr.push_back("04,1.6,100.00,M,");
    bufferArr.push_back("-33.9,M,,0000*7E$");
    bufferArr.push_back("GPGLL,1134.317,");
    bufferArr.push_back("N,04344.154,E,16010");
    bufferArr.push_back("6.28,A*0B\r\n$GPGLL,");
    bufferArr.push_back("1134.400,N,04344.14");
    bufferArr.push_back("7,E,160107.29,");
    bufferArr.push_back("A*08\r\n$GPRMC,160108");
    bufferArr.push_back(".32,A,1134.483,N,");
    bufferArr.push_back("04344.134,E,300.00,3");
    bufferArr.push_back("51.35,110213,");
    bufferArr.push_back("0.0,E*5C\r\n$GPRMC,1601");
    bufferArr.push_back("09.32,A,1134.565,N,");

    bool dataIsReady = false;
    bool result = false;
    CParsing cParsing;

    for (unsigned int i = 0; i < bufferArr.size(); i++) {
        result = cParsing.parseData(bufferArr[i], dataIsReady);
        if (result && dataIsReady) {
            break;
        }
    }

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (34.483 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.134 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    int expectedTime = 160023;
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testIsValidGPGGAData_partialBuffer() {
    std::vector<std::string> bufferArr;
    bufferArr.push_back(",04344.096,E,1");
    bufferArr.push_back("60111.35,A*0F");
    bufferArr.push_back("\r\n$GPGGA,160112.36,11");
    bufferArr.push_back("34.812,N,");
    bufferArr.push_back("04344.083,E,1,04,");
    bufferArr.push_back("2.8,100.00,M,");
    bufferArr.push_back("-33.9,M,,0000*77\r\n$GPRM");
    bufferArr.push_back("C,160113.38,");
    bufferArr.push_back("A,1134.894,N,04344.0");
    bufferArr.push_back("70,E,300.00,");
    bufferArr.push_back("351.35,110213,");
    bufferArr.push_back("0.0,E*57\r\n$GPRMC,");
    bufferArr.push_back("160114.39,A,1134.");
    bufferArr.push_back("977,N,04344.057");

    bool dataIsReady = false;
    bool result = false;
    CParsing cParsing;

    for (unsigned int i = 0; i < bufferArr.size(); i++) {
        result = cParsing.parseData(bufferArr[i], dataIsReady);
        if (result && dataIsReady) {
            break;
        }
    }

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (34.894 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.070 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    int expectedTime = 160023;
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testIsValidGPRMCData_partialBuffer() {
    std::vector<std::string> bufferArr;
    bufferArr.push_back("$GPGLL,1135.224,N");
    bufferArr.push_back(",04344.019,E,");
    bufferArr.push_back("160117.43,A*0E\r\n$GP");
    bufferArr.push_back("GGA,160118.45,");
    bufferArr.push_back("1135.304,N,04343.9");
    bufferArr.push_back("97,E,1,04,1.9,");
    bufferArr.push_back("100.00,M,-33.9,M,,0");
    bufferArr.push_back("000*7D\r\n$GPRMC,");
    bufferArr.push_back("160119.46,A,1135.38");
    bufferArr.push_back("4,N,04343.975,");
    bufferArr.push_back("E,300.00,344.96");
    bufferArr.push_back(",110213,0.0,");
    bufferArr.push_back("E*59\r\n$GPGLL,113");
    bufferArr.push_back("5.465,N,04");
    bufferArr.push_back("343.953,");

    bool dataIsReady = false;
    bool result = false;
    CParsing cParsing;

    for (unsigned int i = 0; i < bufferArr.size(); i++) {
        result = cParsing.parseData(bufferArr[i], dataIsReady);
        if (result && dataIsReady) {
            break;
        }
    }

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (35.384 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (43.975 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    int expectedTime = 160023;
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testIsValidGPRMCData_illegalData01() {
    std::vector<std::string> bufferArr;
    bufferArr.push_back("wefd,fsdfds,fsdf");
    bufferArr.push_back(",04344.019,E,");
    bufferArr.push_back("160117.43,A*0E\r\n$GP");
    bufferArr.push_back("GGA,16, ,0118.45,");
    bufferArr.push_back("1135.304,N,04343.9");
    bufferArr.push_back("dsf,04,1.9,");
    bufferArr.push_back("100.00,M,-33.9,M,,0");
    bufferArr.push_back("000*7,dsf$GPRMC,");
    bufferArr.push_back("160119.46,A,1135.38");
    bufferArr.push_back("4,N,04343.975,");
    bufferArr.push_back("E,300.00,,344.96");
    bufferArr.push_back(",110213,0.0,");
    bufferArr.push_back("E*59\r\n$GPGLL,113");
    bufferArr.push_back("5.465,N,04");
    bufferArr.push_back("343.953,");

    bool dataIsReady = false;
    bool result = false;
    CParsing cParsing;

    for (unsigned int i = 0; i < bufferArr.size(); i++) {
        result = cParsing.parseData(bufferArr[i], dataIsReady);
        if (result && dataIsReady) {
            break;
        }
    }

    CPPUNIT_ASSERT(dataIsReady && result);
}

void newtestclass::testIsValidGPRMCData_illegalData_ThereIsNo$() {
    std::vector<std::string> bufferArr;
    bufferArr.push_back("GPGLL,1135.224,N");
    bufferArr.push_back(",04344.019,E,");
    bufferArr.push_back("160117.43,A*0E\r\n$GP");
    bufferArr.push_back("GGA,160118.45,");
    bufferArr.push_back("1135.304,N,04343.9");
    bufferArr.push_back("97,E,1,04,1.9,");
    bufferArr.push_back("100.00,M,-33.9,M,,0");
    bufferArr.push_back("000*7D\r\nGPRMC,");
    bufferArr.push_back("160119.46,A,1135.38");
    bufferArr.push_back("4,N,04343.975,");
    bufferArr.push_back("E,300.00,344.96");
    bufferArr.push_back(",110213,0.0,");
    bufferArr.push_back("E*59\r\nGPGLL,113");
    bufferArr.push_back("5.465,N,04");
    bufferArr.push_back("343.953,");

    bool dataIsReady = false;
    bool result = false;
    CParsing cParsing;

    for (unsigned int i = 0; i < bufferArr.size(); i++) {
        result = cParsing.parseData(bufferArr[i], dataIsReady);
        if (result && dataIsReady) {
            break;
        }
    }

    CPPUNIT_ASSERT(dataIsReady && result);
}

void newtestclass::testIsValidGPRMCData_illegalData_packetsIsNotFull() {
    std::vector<std::string> bufferArr;
    bufferArr.push_back("$GPGLL,1135.224,N");
    bufferArr.push_back(",04344.019,E,");
    bufferArr.push_back("160117.43,A*0E\r\n$GP");
    bufferArr.push_back("GGA,160118.45,");
    bufferArr.push_back("1135.304,N,04343.9");
    bufferArr.push_back("97,E,1,04,1.9,");
    bufferArr.push_back("100.00,M,-33.9,M,,0");

    bool dataIsReady = false;
    bool result = false;
    CParsing cParsing;

    for (unsigned int i = 0; i < bufferArr.size(); i++) {
        result = cParsing.parseData(bufferArr[i], dataIsReady);
        if (result && dataIsReady) {
            break;
        }
    }

    CPPUNIT_ASSERT(dataIsReady && result);
}

void newtestclass::testIsValidGPRMCData_illegalData_tooMuchLength() {
    std::vector<std::string> bufferArr;
    bufferArr.push_back("$GPGLL,1135.224,N");
    bufferArr.push_back(",04344.019,,E,");
    bufferArr.push_back("160117.43,A*0E\r\n$GP");
    bufferArr.push_back("GGA,160118.45,");
    bufferArr.push_back("1135.304,N,04343.9");
    bufferArr.push_back("97,E,1,,04,1.9,");
    bufferArr.push_back("100.00,M,-33.9,M,,0");
    bufferArr.push_back("000*7D\r\n$GPRMC,");
    bufferArr.push_back("160119.46,A,1135.38");
    bufferArr.push_back("4,N,,04343.975,");
    bufferArr.push_back("E,300.00,344.96");
    bufferArr.push_back(",110213,0.0,");
    bufferArr.push_back("E*59\r\n$GPGLL,113");
    bufferArr.push_back("5.465,N,04");
    bufferArr.push_back("343.953,");

    bool dataIsReady = false;
    bool result = false;
    CParsing cParsing;

    for (unsigned int i = 0; i < bufferArr.size(); i++) {
        result = cParsing.parseData(bufferArr[i], dataIsReady);
        if (result && dataIsReady) {
            break;
        }
    }

    CPPUNIT_ASSERT(dataIsReady && result);
}

void newtestclass::testIsValidGPRMCData_illegalData02() {
    std::vector<std::string> bufferArr;
    bufferArr.push_back("sdf1135.224,N");
    bufferArr.push_back(",04344.019,E,");
    bufferArr.push_back("160117.43,A*0E\r\n$GP");
    bufferArr.push_back("GGdfN,04343.9");
    bufferArr.push_back("97,E,1,04,1.9,");
    bufferArr.push_back("100.00,M,-33.9,M,,0");
    bufferArr.push_back("00sdfRMC,");
    bufferArr.push_back("160119.46,A,1135.38");
    bufferArr.push_back("4,N,04343.975,");
    bufferArr.push_back("E,300.00,344.96");
    bufferArr.push_back(",110213,0.0,");
    bufferArr.push_back("E*5dfGLL,113");
    bufferArr.push_back("5.465,N,04");
    bufferArr.push_back("343.953,");

    bool dataIsReady = false;
    bool result = false;
    CParsing cParsing;

    for (unsigned int i = 0; i < bufferArr.size(); i++) {
        result = cParsing.parseData(bufferArr[i], dataIsReady);
        if (result && dataIsReady) {
            break;
        }
    }

    CPPUNIT_ASSERT(dataIsReady && result);
}

void newtestclass::testIsValidGPRMCData_illegalData_ThereAreNotAnyPackage() {
    std::vector<std::string> bufferArr;
    bufferArr.push_back(",1135.224,N");
    bufferArr.push_back(",04344.019,E,");
    bufferArr.push_back("160117.43,A*0E");
    bufferArr.push_back(",160118.45,");
    bufferArr.push_back("1135.304,N,04343.9");
    bufferArr.push_back("97,E,1,04,1.9,");
    bufferArr.push_back("100.00,M,-33.9,M,,0");
    bufferArr.push_back("000*7D,");
    bufferArr.push_back("160119.46,A,1135.38");
    bufferArr.push_back("4,N,04343.975,");
    bufferArr.push_back("E,300.00,344.96");
    bufferArr.push_back(",110213,0.0,");
    bufferArr.push_back("E*59,113");
    bufferArr.push_back("5.465,N,04");
    bufferArr.push_back("343.953,");

    bool dataIsReady = false;
    bool result = false;
    CParsing cParsing;

    for (unsigned int i = 0; i < bufferArr.size(); i++) {
        result = cParsing.parseData(bufferArr[i], dataIsReady);
        if (result && dataIsReady) {
            break;
        }
    }

    CPPUNIT_ASSERT(dataIsReady && result);
}

void newtestclass::testNorthernLatitude() {
    std::string buffer = "$GPGGA,160023.69,1130.832,N,04344.045,E,1,04,\
2.6,100.00,M,-33.9,M,,0000*7C\r\n$GPGLL,1130.915,\
N,04344.052,E,160024.70,A*0C\r\n$GPGGA,160025.71,\
1130.998,N,04344.060,E,2,04,2.7,100.00,M,-33.9,M,\
,0000*74\r\n$GPRMC,160026.73,A,1131.081,N,04344.067,\
E,300.00,4.96,110213,0.0,E*5A\r\n";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (31.081 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.067 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testSouthernLatitude() {
    std::string buffer = "$GPGGA,160023.69,1130.832,N,04344.045,E,1,04,\
2.6,100.00,M,-33.9,M,,0000*7C\r\n$GPGLL,1130.915,\
N,04344.052,E,160024.70,A*0C\r\n$GPGGA,160025.71,\
1130.998,N,04344.060,E,2,04,2.7,100.00,M,-33.9,M,\
,0000*74\r\n$GPRMC,160026.73,A,1131.081,S,04344.067,\
E,300.00,4.96,110213,0.0,E*5A\r\n";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = (-1) * (11.0 + (31.081 / 60.0));
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.067 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testEasternLongitude() {
    std::string buffer = "$GPGGA,160023.69,1130.832,N,04344.045,E,1,04,\
2.6,100.00,M,-33.9,M,,0000*7C\r\n$GPGLL,1130.915,\
N,04344.052,E,160024.70,A*0C\r\n$GPGGA,160025.71,\
1130.998,N,04344.060,E,2,04,2.7,100.00,M,-33.9,M,\
,0000*74\r\n$GPRMC,160026.73,A,1131.081,N,04344.067,\
E,300.00,4.96,110213,0.0,E*5A\r\n";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (31.081 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.067 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testWesternLongitude() {
    std::string buffer = "$GPGGA,160023.69,1130.832,N,04344.045,E,1,04,\
2.6,100.00,M,-33.9,M,,0000*7C\r\n$GPGLL,1130.915,\
N,04344.052,E,160024.70,A*0C\r\n$GPGGA,160025.71,\
1130.998,N,04344.060,E,2,04,2.7,100.00,M,-33.9,M,\
,0000*74\r\n$GPRMC,160026.73,A,1131.081,N,04344.067,\
W,300.00,4.96,110213,0.0,E*5A\r\n";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (31.081 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = (-1) * (43.0 + (44.067 / 60.0));
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testParseData_time01() {
    std::string buffer = "$GPGGA,160323.69,1130.832,N,04344.045,E,1,04,\
2.6,100.00,M,-33.9,M,,0000*7C\r\n$GPGLL,1130.915,\
N,04344.052,E,160024.70,A*0C\r\n$GPGGA,160025.71,\
1130.998,N,04344.060,E,2,04,2.7,100.00,M,-33.9,M,\
,0000*74\r\n$GPRMC,160026.73,A,1131.081,N,04344.067,\
E,300.00,4.96,110213,0.0,E*5A";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (31.081 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.067 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testParseData_time02() {
    std::string buffer = "$GPGGA,160023.69,1130.832,N,04344.045,E,1,04,\
2.6,100.00,M,-33.9,M,,0000*7C\r\n$GPGLL,1130.915,\
N,04344.052,E,160024.70,A*0C\r\n$GPGGA,160025.71,\
1130.998,N,04344.060,E,2,04,2.7,100.00,M,-33.9,M,\
,0000*74\r\n$GPRMC,160026.73,A,1131.081,N,04344.067,\
E,300.00,4.96,110213,0.0,E*5A";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (31.081 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.067 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass::testParseData_time03() {
    std::string buffer = "$GPGGA,160023.69,1130.832,N,04344.045,E,1,04,\
2.6,100.00,M,-33.9,M,,0000*7C\r\n$GPGLL,1130.915,\
N,04344.052,E,160024.70,A*0C\r\n$GPGGA,160025.71,\
1130.998,N,04344.060,E,2,04,2.7,100.00,M,-33.9,M,\
,0000*74\r\n$GPRMC,160026.73,A,1131.081,N,04344.067,\
E,300.00,4.96,110213,0.0,E*5A";

    bool dataIsReady = false;
    CParsing cParsing;
    bool result = cParsing.parseData(buffer, dataIsReady);

    CPPUNIT_ASSERT(dataIsReady);
    CPPUNIT_ASSERT(result);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = expectedAltitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (31.081 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = expectedLatitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.067 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = expectedLongitude / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = expectedSpeed / 1000.0;
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expectedTime = std::difftime( std::mktime(&time2013), 0 );
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}
