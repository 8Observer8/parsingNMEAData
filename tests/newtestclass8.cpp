/*
 * File:   newtestclass8.cpp
 * Author: Ivan
 *
 * Created on May 23, 2013, 8:28:47 PM
 */

#include "newtestclass8.h"
#include "../Parsing.h"
#include <ctime>

CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass8);

newtestclass8::newtestclass8() {
}

newtestclass8::~newtestclass8() {
}

void newtestclass8::setUp() {
}

void newtestclass8::tearDown() {
}

void newtestclass8::testUtcToMsecFrom1970() {
    int msecFrom1970;
    std::string utcTime = "160026";
    std::string date = "110213";
    CParsing cParsing;
    //bool successful = cParsing.utcToMsecFrom1970(msecFrom1970, utcTime, date);
    //CPPUNIT_ASSERT(successful);
    
    // time: 16 00 26
    // date: 11 02 13
    struct tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;

    // time: 00 00 00
    // date: 01 01 1970
    struct tm time1970;
    time1970.tm_hour = 00;
    time1970.tm_min = 00;
    time1970.tm_sec = 00;
    time1970.tm_mday = 01;
    time1970.tm_mon = 1-1;
    time1970.tm_year = 70;
    
    double seconds = difftime(mktime(&time2013), mktime(&time1970));

    int expected;
    CPPUNIT_ASSERT_EQUAL(expected, msecFrom1970);
}

