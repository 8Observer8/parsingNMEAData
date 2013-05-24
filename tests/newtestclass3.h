/*
 * File:   newtestclass3.h
 * Author: Ivan
 *
 * Created on May 22, 2013, 3:07:30 PM
 */

#ifndef NEWTESTCLASS3_H
#define	NEWTESTCLASS3_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass3 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass3);

    CPPUNIT_TEST(testHaveWeAllPackages_Yes);
    CPPUNIT_TEST(testHaveWeAllPackages_No);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass3();
    virtual ~newtestclass3();
    void setUp();
    void tearDown();

private:
    void testHaveWeAllPackages_Yes();
    void testHaveWeAllPackages_No();
};

#endif	/* NEWTESTCLASS3_H */

