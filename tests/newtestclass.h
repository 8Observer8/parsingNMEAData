/*
 * File:   newtestclass.h
 * Author: Ivan
 *
 * Created on May 18, 2013, 10:44:25 PM
 */

#ifndef NEWTESTCLASS_H
#define	NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(testParseData);
    CPPUNIT_TEST(testParseData_incorrectStartBuffer);
    CPPUNIT_TEST(testGetAltitude);
    CPPUNIT_TEST(testGetLatitude);
    CPPUNIT_TEST(testGetLongitude);
    CPPUNIT_TEST(testGetNSatellites);
    CPPUNIT_TEST(testGetSpeed);
    CPPUNIT_TEST(testGetTime);
    CPPUNIT_TEST(testIsValidGPGGAData);

    CPPUNIT_TEST(testIsNotValidGPGGAData_SetZerro);
    CPPUNIT_TEST(testIsNotValidGPGGAData_SetOne);
    CPPUNIT_TEST(testIsNotValidGPGGAData_SetThree);
    CPPUNIT_TEST(testIsNotValidGPRMCData_SetV);
    CPPUNIT_TEST(testIsNotValidGPRMCData_Set5);
    CPPUNIT_TEST(testIsNotValidGPRMCData_SetW);

    CPPUNIT_TEST(testParseData_partialBuffer);
    CPPUNIT_TEST(testGetAltitude_partialBuffer);
    CPPUNIT_TEST(testGetLatitude_partialBuffer);
    CPPUNIT_TEST(testGetLongitude_partialBuffer);
    CPPUNIT_TEST(testGetNSatellites_partialBuffer);
    CPPUNIT_TEST(testGetSpeed_partialBuffer);
    CPPUNIT_TEST(testGetTime_partialBuffer);
    CPPUNIT_TEST(testIsValidGPGGAData_partialBuffer);

    CPPUNIT_TEST(testIsValidGPRMCData_illegalData01);
    CPPUNIT_TEST(testIsValidGPRMCData_illegalData_ThereIsNo$);
    CPPUNIT_TEST(testIsValidGPRMCData_illegalData_packetsIsNotFull);
    CPPUNIT_TEST(testIsValidGPRMCData_illegalData_tooMuchLength);
    CPPUNIT_TEST(testIsValidGPRMCData_illegalData02);
    CPPUNIT_TEST(testIsValidGPRMCData_illegalData_ThereAreNotAnyPackage);

    CPPUNIT_TEST(testNorthernLatitude);
    CPPUNIT_TEST(testSouthernLatitude);
    CPPUNIT_TEST(testEasternLongitude);
    CPPUNIT_TEST(testWesternLongitude);

    CPPUNIT_TEST(testParseData_time01);
    CPPUNIT_TEST(testParseData_time02);
    CPPUNIT_TEST(testParseData_time03);
    
    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void testParseData();
    void testParseData_incorrectStartBuffer();
    void testGetAltitude();
    void testGetLatitude();
    void testGetLongitude();
    void testGetNSatellites();
    void testGetSpeed();
    void testGetTime();
    void testIsValidGPGGAData();
    void testIsValidGPRMCData();

    void testIsNotValidGPGGAData_SetZerro();
    void testIsNotValidGPGGAData_SetOne();
    void testIsNotValidGPGGAData_SetThree();
    void testIsNotValidGPRMCData_SetV();
    void testIsNotValidGPRMCData_Set5();
    void testIsNotValidGPRMCData_SetW();

    void testParseData_partialBuffer();
    void testGetAltitude_partialBuffer();
    void testGetLatitude_partialBuffer();
    void testGetLongitude_partialBuffer();
    void testGetNSatellites_partialBuffer();
    void testGetSpeed_partialBuffer();
    void testGetTime_partialBuffer();
    void testIsValidGPGGAData_partialBuffer();
    void testIsValidGPRMCData_partialBuffer();

    void testIsValidGPRMCData_illegalData01();
    void testIsValidGPRMCData_illegalData_ThereIsNo$();
    void testIsValidGPRMCData_illegalData_packetsIsNotFull();
    void testIsValidGPRMCData_illegalData_tooMuchLength();
    void testIsValidGPRMCData_illegalData02();
    void testIsValidGPRMCData_illegalData_ThereAreNotAnyPackage();

    void testNorthernLatitude();
    void testSouthernLatitude();
    void testEasternLongitude();
    void testWesternLongitude();

    void testParseData_time01();
    void testParseData_time02();
    void testParseData_time03();
};

#endif	/* NEWTESTCLASS_H */
