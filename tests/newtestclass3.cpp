/*
 * File:   newtestclass3.cpp
 * Author: Ivan
 *
 * Created on May 22, 2013, 3:07:31 PM
 */

#include "newtestclass3.h"
#include "../Parsing.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass3);

newtestclass3::newtestclass3() {
}

newtestclass3::~newtestclass3() {
}

void newtestclass3::setUp() {
}

void newtestclass3::tearDown() {
}

void newtestclass3::testHaveWeAllPackages_Yes() {
    std::string package01 = "$GPRMC,160033.83,A,1131.662,N,\
04344.118,E,300.00,4.96,110213,0.0,E*53";
    std::string package02 = "$GPGGA,160034.84,1131.745,N,\
04344.126,E,1,04,2.9,100.00,M,-33.9,M,,0000*7C";
    CParsing cParsing;
    cParsing.setStorageBufferArr(package01);
    cParsing.setStorageBufferArr(package02);
    CPPUNIT_ASSERT(cParsing.haveWeAllPackages());
}

void newtestclass3::testHaveWeAllPackages_No() {
    std::string package01 = "$GPRMC,160033.83,A,1131.662,N,\
04344.118,E,300.00,4.96,110213,0.0,E*53";
    std::string package02 = "$GPGLL,1132.077,N,04344.155,\
E,160038.90,A*06";
    CParsing cParsing;
    cParsing.setStorageBufferArr(package01);
    cParsing.setStorageBufferArr(package02);
    CPPUNIT_ASSERT(!cParsing.haveWeAllPackages());
}
