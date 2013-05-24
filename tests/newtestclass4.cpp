/*
 * File:   newtestclass4.cpp
 * Author: Ivan
 *
 * Created on May 22, 2013, 3:37:01 PM
 */

#include "newtestclass4.h"
#include "../Parsing.h"
#include <cmath>

CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass4);

newtestclass4::newtestclass4() {
}

newtestclass4::~newtestclass4() {
}

void newtestclass4::setUp() {
}

void newtestclass4::tearDown() {
}

void newtestclass4::testProcessData() {
    std::vector<std::string> GGABuffer;
    GGABuffer.push_back("$GPGGA");
    GGABuffer.push_back("160025.71");
    GGABuffer.push_back("1130.998");
    GGABuffer.push_back("N");
    GGABuffer.push_back("04344.060");
    GGABuffer.push_back("E");
    GGABuffer.push_back("2");
    GGABuffer.push_back("4");
    GGABuffer.push_back("2.7");
    GGABuffer.push_back("100.00");
    GGABuffer.push_back("M");
    GGABuffer.push_back("-33.9");
    GGABuffer.push_back("M");
    GGABuffer.push_back("0000*74");

    std::vector<std::string> RMCBuffer;
    RMCBuffer.push_back("$GPRMC");
    RMCBuffer.push_back("160026"); // Need: 160026.73
    RMCBuffer.push_back("A");
    RMCBuffer.push_back("1131.081");
    RMCBuffer.push_back("N");
    RMCBuffer.push_back("04344.067");
    RMCBuffer.push_back("E");
    RMCBuffer.push_back("300.00");
    RMCBuffer.push_back("4.96");
    RMCBuffer.push_back("110213");
    RMCBuffer.push_back("0.0");
    RMCBuffer.push_back("E*5A");

    CParsing cParsing;

    bool dataIsProcessed = cParsing.processData(GGABuffer, RMCBuffer);

    CPPUNIT_ASSERT(dataIsProcessed);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = fabs(expectedAltitude / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude,
            deltaAltitude);

    double expectedLatitude = 11.0 + (31.081 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = fabs(expectedLatitude / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude,
            deltaLatitude);

    double expectedLongitude = 43.0 + (44.067 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = fabs(expectedLongitude / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude,
            deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = fabs(expectedSpeed / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    int expectedTime = 160026; // 1360598423000
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass4::testNorthernLatitude() {
    std::vector<std::string> GGABuffer;
    GGABuffer.push_back("$GPGGA");
    GGABuffer.push_back("160025.71");
    GGABuffer.push_back("1130.998");
    GGABuffer.push_back("N");
    GGABuffer.push_back("04344.060");
    GGABuffer.push_back("E");
    GGABuffer.push_back("2");
    GGABuffer.push_back("4");
    GGABuffer.push_back("2.7");
    GGABuffer.push_back("100.00");
    GGABuffer.push_back("M");
    GGABuffer.push_back("-33.9");
    GGABuffer.push_back("M");
    GGABuffer.push_back("0000*74");

    std::vector<std::string> RMCBuffer;
    RMCBuffer.push_back("$GPRMC");
    RMCBuffer.push_back("160026"); // Need: 160026.73
    RMCBuffer.push_back("A");
    RMCBuffer.push_back("1131.081");
    RMCBuffer.push_back("N");
    RMCBuffer.push_back("04344.067");
    RMCBuffer.push_back("E");
    RMCBuffer.push_back("300.00");
    RMCBuffer.push_back("4.96");
    RMCBuffer.push_back("110213");
    RMCBuffer.push_back("0.0");
    RMCBuffer.push_back("E*5A");

    CParsing cParsing;

    bool dataIsProcessed = cParsing.processData(GGABuffer, RMCBuffer);

    CPPUNIT_ASSERT(dataIsProcessed);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = fabs(expectedAltitude / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (31.081 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = fabs(expectedLatitude / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.067 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = fabs(expectedLongitude / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = fabs(expectedSpeed / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    int expectedTime = 160026;
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass4::testSouthernLatitude() {
    std::vector<std::string> GGABuffer;
    GGABuffer.push_back("$GPGGA");
    GGABuffer.push_back("160025.71");
    GGABuffer.push_back("1130.998");
    GGABuffer.push_back("N");
    GGABuffer.push_back("04344.060");
    GGABuffer.push_back("E");
    GGABuffer.push_back("2");
    GGABuffer.push_back("4");
    GGABuffer.push_back("2.7");
    GGABuffer.push_back("100.00");
    GGABuffer.push_back("M");
    GGABuffer.push_back("-33.9");
    GGABuffer.push_back("M");
    GGABuffer.push_back("0000*74");

    std::vector<std::string> RMCBuffer;
    RMCBuffer.push_back("$GPRMC");
    RMCBuffer.push_back("160026"); // Need: 160026.73
    RMCBuffer.push_back("A");
    RMCBuffer.push_back("1131.081");
    RMCBuffer.push_back("S");
    RMCBuffer.push_back("04344.067");
    RMCBuffer.push_back("E");
    RMCBuffer.push_back("300.00");
    RMCBuffer.push_back("4.96");
    RMCBuffer.push_back("110213");
    RMCBuffer.push_back("0.0");
    RMCBuffer.push_back("E*5A");

    CParsing cParsing;

    bool dataIsProcessed = cParsing.processData(GGABuffer, RMCBuffer);

    CPPUNIT_ASSERT(dataIsProcessed);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = fabs(expectedAltitude / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = (-1) * (11.0 + (31.081 / 60.0));
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = fabs(expectedLatitude / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.067 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = fabs(expectedLongitude / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = fabs(expectedSpeed / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    int expectedTime = 160026;
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass4::testEasternLongitude() {
    std::vector<std::string> GGABuffer;
    GGABuffer.push_back("$GPGGA");
    GGABuffer.push_back("160025.71");
    GGABuffer.push_back("1130.998");
    GGABuffer.push_back("N");
    GGABuffer.push_back("04344.060");
    GGABuffer.push_back("E");
    GGABuffer.push_back("2");
    GGABuffer.push_back("4");
    GGABuffer.push_back("2.7");
    GGABuffer.push_back("100.00");
    GGABuffer.push_back("M");
    GGABuffer.push_back("-33.9");
    GGABuffer.push_back("M");
    GGABuffer.push_back("0000*74");

    std::vector<std::string> RMCBuffer;
    RMCBuffer.push_back("$GPRMC");
    RMCBuffer.push_back("160026"); // Need: 160026.73
    RMCBuffer.push_back("A");
    RMCBuffer.push_back("1131.081");
    RMCBuffer.push_back("N");
    RMCBuffer.push_back("04344.067");
    RMCBuffer.push_back("E");
    RMCBuffer.push_back("300.00");
    RMCBuffer.push_back("4.96");
    RMCBuffer.push_back("110213");
    RMCBuffer.push_back("0.0");
    RMCBuffer.push_back("E*5A");

    CParsing cParsing;

    bool dataIsProcessed = cParsing.processData(GGABuffer, RMCBuffer);

    CPPUNIT_ASSERT(dataIsProcessed);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = fabs(expectedAltitude / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (31.081 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = fabs(expectedLatitude / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = 43.0 + (44.067 / 60.0);
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = fabs(expectedLongitude / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = fabs(expectedSpeed / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    int expectedTime = 160026;
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}

void newtestclass4::testWesternLongitude() {
    std::vector<std::string> GGABuffer;
    GGABuffer.push_back("$GPGGA");
    GGABuffer.push_back("160025.71");
    GGABuffer.push_back("1130.998");
    GGABuffer.push_back("N");
    GGABuffer.push_back("04344.060");
    GGABuffer.push_back("E");
    GGABuffer.push_back("2");
    GGABuffer.push_back("4");
    GGABuffer.push_back("2.7");
    GGABuffer.push_back("100.00");
    GGABuffer.push_back("M");
    GGABuffer.push_back("-33.9");
    GGABuffer.push_back("M");
    GGABuffer.push_back("0000*74");

    std::vector<std::string> RMCBuffer;
    RMCBuffer.push_back("$GPRMC");
    RMCBuffer.push_back("160026"); // Need: 160026.73
    RMCBuffer.push_back("A");
    RMCBuffer.push_back("1131.081");
    RMCBuffer.push_back("N");
    RMCBuffer.push_back("04344.067");
    RMCBuffer.push_back("W");
    RMCBuffer.push_back("300.00");
    RMCBuffer.push_back("4.96");
    RMCBuffer.push_back("110213");
    RMCBuffer.push_back("0.0");
    RMCBuffer.push_back("E*5A");

    CParsing cParsing;

    bool dataIsProcessed = cParsing.processData(GGABuffer, RMCBuffer);

    CPPUNIT_ASSERT(dataIsProcessed);

    bool expectedIsValidGPGGAData = true;
    bool resultIsValidGPGGAData = cParsing.isValidGPGGAData();
    CPPUNIT_ASSERT(expectedIsValidGPGGAData && resultIsValidGPGGAData);

    bool expectedIsValidGPRMCData = true;
    bool resultIsValidGPRMCData = cParsing.isValidGPRMCData();
    CPPUNIT_ASSERT(expectedIsValidGPRMCData && resultIsValidGPRMCData);

    double expectedAltitude = 100.0;
    double resultAltitude = cParsing.getAltitude();
    double deltaAltitude = fabs(expectedAltitude / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedAltitude, resultAltitude, deltaAltitude);

    double expectedLatitude = 11.0 + (31.081 / 60.0);
    double resultLatitude = cParsing.getLatitude();
    double deltaLatitude = fabs(expectedLatitude / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLatitude, resultLatitude, deltaLatitude);

    double expectedLongitude = (-1) * (43.0 + (44.067 / 60.0));
    double resultLongitude = cParsing.getLongitude();
    double deltaLongitude = fabs(expectedLongitude / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedLongitude, resultLongitude, deltaLongitude);

    int expectedNSatellites = 4;
    int resultNSatellites = cParsing.getNSatellites();
    CPPUNIT_ASSERT_EQUAL(expectedNSatellites, resultNSatellites);

    double expectedSpeed = 300.0 * 1.852;
    double resultSpeed = cParsing.getSpeed();
    double deltaSpeed = fabs(expectedSpeed / 1000.0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedSpeed, resultSpeed, deltaSpeed);

    int expectedTime = 160026;
    int resultTime = cParsing.getTime();
    CPPUNIT_ASSERT_EQUAL(expectedTime, resultTime);
}
