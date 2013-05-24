#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Parsing.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f8 \
	${TESTDIR}/TestFiles/f9 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f6 \
	${TESTDIR}/TestFiles/f7

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=/C/cppUnit/lib/libcppunit.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/parsingnmeadata.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/parsingnmeadata.exe: /C/cppUnit/lib/libcppunit.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/parsingnmeadata.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/parsingnmeadata ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Parsing.o: Parsing.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Parsing.o Parsing.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/newtestclass1.o ${TESTDIR}/tests/newtestrunner1.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/newtestclass3.o ${TESTDIR}/tests/newtestrunner3.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/newtestclass4.o ${TESTDIR}/tests/newtestrunner4.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f8: ${TESTDIR}/tests/newtestclass7.o ${TESTDIR}/tests/newtestrunner7.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f8 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f9: ${TESTDIR}/tests/newtestclass8.o ${TESTDIR}/tests/newtestrunner8.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f9 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/newtestclass.o ${TESTDIR}/tests/newtestrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/newtestclass2.o ${TESTDIR}/tests/newtestrunner2.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f6: ${TESTDIR}/tests/newtestclass5.o ${TESTDIR}/tests/newtestrunner5.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f6 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f7: ${TESTDIR}/tests/newtestclass6.o ${TESTDIR}/tests/newtestrunner6.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f7 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/tests/newtestclass1.o: tests/newtestclass1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestclass1.o tests/newtestclass1.cpp


${TESTDIR}/tests/newtestrunner1.o: tests/newtestrunner1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestrunner1.o tests/newtestrunner1.cpp


${TESTDIR}/tests/newtestclass3.o: tests/newtestclass3.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestclass3.o tests/newtestclass3.cpp


${TESTDIR}/tests/newtestrunner3.o: tests/newtestrunner3.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestrunner3.o tests/newtestrunner3.cpp


${TESTDIR}/tests/newtestclass4.o: tests/newtestclass4.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestclass4.o tests/newtestclass4.cpp


${TESTDIR}/tests/newtestrunner4.o: tests/newtestrunner4.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestrunner4.o tests/newtestrunner4.cpp


${TESTDIR}/tests/newtestclass7.o: tests/newtestclass7.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestclass7.o tests/newtestclass7.cpp


${TESTDIR}/tests/newtestrunner7.o: tests/newtestrunner7.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestrunner7.o tests/newtestrunner7.cpp


${TESTDIR}/tests/newtestclass8.o: tests/newtestclass8.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestclass8.o tests/newtestclass8.cpp


${TESTDIR}/tests/newtestrunner8.o: tests/newtestrunner8.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestrunner8.o tests/newtestrunner8.cpp


${TESTDIR}/tests/newtestclass.o: tests/newtestclass.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestclass.o tests/newtestclass.cpp


${TESTDIR}/tests/newtestrunner.o: tests/newtestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestrunner.o tests/newtestrunner.cpp


${TESTDIR}/tests/newtestclass2.o: tests/newtestclass2.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestclass2.o tests/newtestclass2.cpp


${TESTDIR}/tests/newtestrunner2.o: tests/newtestrunner2.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestrunner2.o tests/newtestrunner2.cpp


${TESTDIR}/tests/newtestclass5.o: tests/newtestclass5.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestclass5.o tests/newtestclass5.cpp


${TESTDIR}/tests/newtestrunner5.o: tests/newtestrunner5.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestrunner5.o tests/newtestrunner5.cpp


${TESTDIR}/tests/newtestclass6.o: tests/newtestclass6.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestclass6.o tests/newtestclass6.cpp


${TESTDIR}/tests/newtestrunner6.o: tests/newtestrunner6.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/cppUnit/include `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newtestrunner6.o tests/newtestrunner6.cpp


${OBJECTDIR}/Parsing_nomain.o: ${OBJECTDIR}/Parsing.o Parsing.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Parsing.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/C/cppUnit/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Parsing_nomain.o Parsing.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Parsing.o ${OBJECTDIR}/Parsing_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/C/cppUnit/include -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f8 || true; \
	    ${TESTDIR}/TestFiles/f9 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f6 || true; \
	    ${TESTDIR}/TestFiles/f7 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/parsingnmeadata.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
