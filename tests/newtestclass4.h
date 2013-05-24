/*
 * File:   newtestclass4.h
 * Author: Ivan
 *
 * Created on May 22, 2013, 3:37:01 PM
 */

#ifndef NEWTESTCLASS4_H
#define	NEWTESTCLASS4_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass4 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass4);

    CPPUNIT_TEST(testProcessData);
    CPPUNIT_TEST(testNorthernLatitude);
    CPPUNIT_TEST(testSouthernLatitude);
    CPPUNIT_TEST(testEasternLongitude);
    CPPUNIT_TEST(testWesternLongitude);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass4();
    virtual ~newtestclass4();
    void setUp();
    void tearDown();

private:
    void testProcessData();
    void testNorthernLatitude();
    void testSouthernLatitude();
    void testEasternLongitude();
    void testWesternLongitude();
};

#endif	/* NEWTESTCLASS4_H */

