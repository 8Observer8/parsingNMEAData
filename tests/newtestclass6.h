/*
 * File:   newtestclass6.h
 * Author: Ivan
 *
 * Created on May 23, 2013, 4:22:29 PM
 */

#ifndef NEWTESTCLASS6_H
#define	NEWTESTCLASS6_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass6 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass6);

    CPPUNIT_TEST(testUtcToMsecFrom1970_160026_110213);
    CPPUNIT_TEST(testUtcToMsecFrom1970_160026_110212);
    CPPUNIT_TEST(testUtcToMsecFrom1970_160027_110213);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass6();
    virtual ~newtestclass6();
    void setUp();
    void tearDown();

private:
    void testUtcToMsecFrom1970_160026_110213();
    void testUtcToMsecFrom1970_160026_110212();
    void testUtcToMsecFrom1970_160027_110213();
};

#endif	/* NEWTESTCLASS6_H */

