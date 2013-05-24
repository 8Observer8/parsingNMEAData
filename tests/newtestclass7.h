/*
 * File:   newtestclass7.h
 * Author: Ivan
 *
 * Created on May 23, 2013, 7:03:07 PM
 */

#ifndef NEWTESTCLASS7_H
#define	NEWTESTCLASS7_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass7 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass7);

    CPPUNIT_TEST(testUtcToMsecFrom1970);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass7();
    virtual ~newtestclass7();
    void setUp();
    void tearDown();

private:
    void testUtcToMsecFrom1970();

};

#endif	/* NEWTESTCLASS7_H */

