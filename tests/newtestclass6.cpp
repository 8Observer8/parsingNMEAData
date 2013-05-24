/*
 * File:   newtestclass6.cpp
 * Author: Ivan
 *
 * Created on May 23, 2013, 4:22:29 PM
 */

#include "newtestclass6.h"
#include "../Parsing.h"
#include <ctime>


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass6);

newtestclass6::newtestclass6() {
}

newtestclass6::~newtestclass6() {
}

void newtestclass6::setUp() {
}

void newtestclass6::tearDown() {
}

void newtestclass6::testUtcToMsecFrom1970_160026_110213() {
    int msecFrom1970;
    std::string utcTime = "160026";
    std::string date = "110213";
    CParsing cParsing;
    
    bool successful = cParsing.utcToMsecFrom1970(msecFrom1970, utcTime, date);
    
    CPPUNIT_ASSERT(successful);
    
    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 26;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expected = std::difftime( std::mktime(&time2013), 0 );

    CPPUNIT_ASSERT_EQUAL(expected, msecFrom1970);
}

void newtestclass6::testUtcToMsecFrom1970_160026_110212() {
    int msecFrom1970;
    std::string utcTime = "160026";
    std::string date = "110212";
    CParsing cParsing;
    
    bool successful = cParsing.utcToMsecFrom1970(msecFrom1970, utcTime, date);
    
    CPPUNIT_ASSERT(successful);
    
    std::tm time2012;
    time2012.tm_hour = 16;
    time2012.tm_min = 00;
    time2012.tm_sec = 26;
    time2012.tm_mday = 11;
    time2012.tm_mon = 2-1;
    time2012.tm_year = 112;
    int expected = std::difftime( std::mktime(&time2012), 0 );

    CPPUNIT_ASSERT_EQUAL(expected, msecFrom1970);
}

void newtestclass6::testUtcToMsecFrom1970_160027_110213() {
    int msecFrom1970;
    std::string utcTime = "160027";
    std::string date = "110213";
    CParsing cParsing;
    
    bool successful = cParsing.utcToMsecFrom1970(msecFrom1970, utcTime, date);
    
    CPPUNIT_ASSERT(successful);
    
    std::tm time2013;
    time2013.tm_hour = 16;
    time2013.tm_min = 00;
    time2013.tm_sec = 27;
    time2013.tm_mday = 11;
    time2013.tm_mon = 2-1;
    time2013.tm_year = 113;
    int expected = std::difftime( std::mktime(&time2013), 0 );

    CPPUNIT_ASSERT_EQUAL(expected, msecFrom1970);
}
