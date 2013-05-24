/*
 * File:   newtestclass2.cpp
 * Author: Ivan
 *
 * Created on May 21, 2013, 2:37:03 PM
 */

#include "newtestclass2.h"
#include "../Parsing.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass2);

newtestclass2::newtestclass2() {
}

newtestclass2::~newtestclass2() {
}

void newtestclass2::setUp() {
}

void newtestclass2::tearDown() {
}

void newtestclass2::testStorage() {
    CParsing cParsing;
    cParsing.setStorageBufferArr("$GPGGA,160023.69,1130.832,N,04344.045,E,1,04,\
2.6,100.00,M,-33.9,M,,0000*7C");

    std::vector<std::string> bufferArr;
    bufferArr.push_back("$GPGGA,160023.69,1130.832,N,04344.045,E,1,04,\
2.6,100.00,M,-33.9,M,,0000*7C");
    std::vector<std::string> resultBufferArray = cParsing.storage(bufferArr);
    int s = resultBufferArray.size();
    std::string resultString = resultBufferArray[0];
    std::string expectedString = "$GPGGA,160023.69,1130.832,N,04344.045,E,1,04,\
2.6,100.00,M,-33.9,M,,0000*7C";
    
    CPPUNIT_ASSERT_EQUAL(expectedString, resultString);
}

void newtestclass2::testStorage02() {
    CParsing cParsing;
    std::vector<std::string> bufferArr;
    cParsing.setStorageBufferArr("$GPGGA,160023.69,1130.832,N,\
04344.045,E,1,04,");
    cParsing.setStorageBufferArr("");
    bufferArr.push_back("2.6,100.00,M,-33.9,M,,0000*7C");
    bufferArr.push_back("$GPRMC,160026.73,A,1131.081,N,04344.067,\
E,300.00,4.96,110213,0.0,E*5A");
    std::vector<std::string> resultBufferArray = cParsing.storage(bufferArr);
    int s = resultBufferArray.size();
    std::string resultString = resultBufferArray[1];
    std::string expectedString = "$GPRMC,160026.73,A,1131.081,N,04344.067,\
E,300.00,4.96,110213,0.0,E*5A";
    
    CPPUNIT_ASSERT_EQUAL(expectedString, resultString);
}
