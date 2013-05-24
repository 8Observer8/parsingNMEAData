/*
 * File:   newtestclass5.h
 * Author: Ivan
 *
 * Created on May 23, 2013, 10:51:39 AM
 */

#ifndef NEWTESTCLASS5_H
#define	NEWTESTCLASS5_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass5 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass5);

    CPPUNIT_TEST(testFillPackages);
    CPPUNIT_TEST(testFillPackages_inputBufferIsEmpty);
    CPPUNIT_TEST(testFillPackages_packagesIsNotFull);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass5();
    virtual ~newtestclass5();
    void setUp();
    void tearDown();

private:
    void testFillPackages();
    void testFillPackages_inputBufferIsEmpty();
    void testFillPackages_packagesIsNotFull();
};

#endif	/* NEWTESTCLASS5_H */

