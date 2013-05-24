/*
 * File:   newtestclass7.cpp
 * Author: Ivan
 *
 * Created on May 23, 2013, 7:03:07 PM
 */

#include "newtestclass7.h"
#include "../Parsing.h"
#include <ctime>


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass7);

newtestclass7::newtestclass7() {
}

newtestclass7::~newtestclass7() {
}

void newtestclass7::setUp() {
}

void newtestclass7::tearDown() {
}

void newtestclass7::testUtcToMsecFrom1970() {
    int msecFrom1970;
    std::string utcTime;
    std::string date;
    CParsing cParsing;
    bool successful = cParsing.utcToMsecFrom1970(msecFrom1970, utcTime, date);
    
    //CPPUNIT_ASSERT(successful);

    struct tm time2013;
    
    // time: 160026
    // date: 110213
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 2013;

    // time: 000000
    // date: 01 01 1700
    struct tm time1700;
    time1700.tm_hour = 00;
    time1700.tm_min = 00;
    time1700.tm_sec = 00;
    time1700.tm_mday = 01;
    time1700.tm_mon = 1-1;
    time1700.tm_year = 100;
    
    double seconds = difftime(mktime(&time2013), mktime(&time1700));

    int expected;
    CPPUNIT_ASSERT_EQUAL(expected, msecFrom1970);
}
