/*
 * File:   newtestclass8.h
 * Author: Ivan
 *
 * Created on May 23, 2013, 8:28:46 PM
 */

#ifndef NEWTESTCLASS8_H
#define	NEWTESTCLASS8_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass8 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass8);

    CPPUNIT_TEST(testUtcToMsecFrom1970);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass8();
    virtual ~newtestclass8();
    void setUp();
    void tearDown();

private:
    void testUtcToMsecFrom1970();

};

#endif	/* NEWTESTCLASS8_H */

