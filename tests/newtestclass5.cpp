/*
 * File:   newtestclass5.cpp
 * Author: Ivan
 *
 * Created on May 23, 2013, 10:51:39 AM
 */

#include "newtestclass5.h"
#include "../Parsing.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass5);

newtestclass5::newtestclass5() {
}

newtestclass5::~newtestclass5() {
}

void newtestclass5::setUp() {
}

void newtestclass5::tearDown() {
}

#include <iostream>

void printArr(std::vector<std::string> v) {
    for (unsigned int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
}

void newtestclass5::testFillPackages() {
    std::vector<std::string> storageBufferArr;
    std::vector<std::string> GGABuffer;
    std::vector<std::string> RMCBuffer;

    storageBufferArr.push_back("$GPGGA,160032.81,1131.579,N,04344.111,\
E,1,04,2.0,100.00,M,-33.9,M,,0000*7F");
    storageBufferArr.push_back("$GPRMC,160033.83,A,1131.662,N,04344.118,\
E,300.00,4.96,110213,0.0,E*53");
    storageBufferArr.push_back("$GPGGA,160032.81,1131.579,N,04344.111,");

    CParsing cParsing;
    storageBufferArr.size();
    bool result = cParsing.fillPackages(storageBufferArr, GGABuffer, RMCBuffer);
    
    CPPUNIT_ASSERT(result);

    std::string expected = "$GPGGA";
    std::string actual = GGABuffer[0];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "160032.81";
    actual = GGABuffer[1];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "1131.579";
    actual = GGABuffer[2];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "N";
    actual = GGABuffer[3];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "04344.111";
    actual = GGABuffer[4];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "E";
    actual = GGABuffer[5];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "1";
    actual = GGABuffer[6];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "04";
    actual = GGABuffer[7];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "2.0";
    actual = GGABuffer[8];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "100.00";
    actual = GGABuffer[9];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "M";
    actual = GGABuffer[10];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "-33.9";
    actual = GGABuffer[11];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "M";
    actual = GGABuffer[12];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "";
    actual = GGABuffer[13];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "0000*7F";
    actual = GGABuffer[14];
    CPPUNIT_ASSERT_EQUAL(actual, expected);


    // $GPRMC
    expected = "$GPRMC";
    actual = GGABuffer[0];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "160033.83";
    actual = GGABuffer[1];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "A";
    actual = GGABuffer[2];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "1131.662";
    actual = GGABuffer[3];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "N";
    actual = GGABuffer[4];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "04344.118";
    actual = GGABuffer[5];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "E";
    actual = GGABuffer[6];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "300.00";
    actual = GGABuffer[7];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "4.96";
    actual = GGABuffer[8];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "110213";
    actual = GGABuffer[9];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "0.0";
    actual = GGABuffer[10];
    CPPUNIT_ASSERT_EQUAL(actual, expected);

    expected = "E*53";
    actual = GGABuffer[11];
    CPPUNIT_ASSERT_EQUAL(actual, expected);
}

void newtestclass5::testFillPackages_inputBufferIsEmpty() {
    std::vector<std::string> storageBufferArr;
    std::vector<std::string> GGABuffer;
    std::vector<std::string> RMCBuffer;

    storageBufferArr.push_back("");

    CParsing cParsing;
    bool result = cParsing.fillPackages(storageBufferArr, GGABuffer, RMCBuffer);

    CPPUNIT_ASSERT(!result);
}

void newtestclass5::testFillPackages_packagesIsNotFull() {
    std::vector<std::string> storageBufferArr;
    std::vector<std::string> GGABuffer;
    std::vector<std::string> RMCBuffer;

    storageBufferArr.push_back("$GPGGA,160032.81,1131.579,N,04344.111,\
E,1,04,2.0,100.00,M,-33.9,M,,");
    storageBufferArr.push_back("$GPRMC,160033.83,A,1131.662,N,04344.118,\
E,300.00,4.96,110213,0.0,E*53");

    CParsing cParsing;
    bool result = cParsing.fillPackages(storageBufferArr, GGABuffer, RMCBuffer);

    CPPUNIT_ASSERT(!result);
}
