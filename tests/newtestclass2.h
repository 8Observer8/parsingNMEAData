/*
 * File:   newtestclass2.h
 * Author: Ivan
 *
 * Created on May 21, 2013, 2:37:03 PM
 */

#ifndef NEWTESTCLASS2_H
#define	NEWTESTCLASS2_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass2 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass2);

    CPPUNIT_TEST(testStorage);
    CPPUNIT_TEST(testStorage02);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass2();
    virtual ~newtestclass2();
    void setUp();
    void tearDown();

private:
    void testStorage();
    void testStorage02();
};

#endif	/* NEWTESTCLASS2_H */

