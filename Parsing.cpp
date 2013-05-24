/* 
 * File:   Parsing.cpp
 * Author: Ivan
 * 
 * Created on May 18, 2013, 4:14 PM
 */

#include <sstream>
#include <ctime>
#include "Parsing.h"

CParsing::CParsing() {
    setValuesInZero();
}

void CParsing::setValuesInZero() {
    m_dLatitude = 0;
    m_dLongitude = 0;
    m_dAltitude = 0;
    m_iTime = 0;
    m_dSpeed = 0;
    m_iNSatellites = 0; // m_nSatellites
    m_bIsValidGPGGAData = 0;
    m_bIsValidGPRMCData = 0;
}

#include <iostream>

void printArray(std::vector<std::string> v) {
    for (unsigned int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
}

bool CParsing::parseData(std::string buffer, bool& dataIsReady) {
    dataIsReady = false;
    setValuesInZero();

    // If the input buffer is empty, then clear the 
    // buffers and return false
    //    if (buffer.empty()) {
    //        dataIsReady = false;
    //        m_storageBufferArr.clear();
    //        m_GGABuffer.clear();
    //        m_RMCBuffer.clear();
    //        return false;
    //    }

    //    buffer.replace("\r", "");
    //    m_buffer += buffer;
    //    var arr = m_buffer.split("\n");
    //    for (int i = 0; i < arr.length - 1; i++)
    //    {
    //        string packet = arr[i];
    //        if (packet.length == 0 || packet[0] !="$")
    //            return false;
    //        if (packet.indexOf("$GPRMC") == 0)    
    //        {
    //            
    //        }
    //        if (packet.indexOf("$GPGGA") == 0)    
    //        {
    //            
    //        }
    //    }
    //    m_buffer = arr[arr.length - 1];


    // If this is the first call to the function and
    // the input buffer is not a package, then return false
    if (m_storageBufferArr.empty()) {
        //if ((beginOfPackage != "$GPGGA") && (beginOfPackage != "&GPRMC")) {
        std::string beginOfPackage = buffer.substr(0, 3);
        if (beginOfPackage != "$GP") {
            dataIsReady = false;
            m_GGABuffer.clear();
            m_RMCBuffer.clear();
            return false;
        }
        // Fill the buffer storage array
        for (unsigned int i = 0; i < buffer.length(); i++) {
            if (buffer[i] == '\r') {
                buffer.erase(i, 1);
            }
        }
        split(m_storageBufferArr, buffer, "\n");
    }// Add the input buffer to the storage buffer array
    else {
        std::vector<std::string> bufferArr;
        for (unsigned int i = 0; i < buffer.length(); i++) {
            if (buffer[i] == '\r') {
                buffer.erase(i, 1);
            }
        }
        split(bufferArr, buffer, "\n");
        storage(bufferArr);
    }

    // If we have all the packages, then proceed to the
    // processing of data
    // Have we all the packages?
    if (!haveWeAllPackages()) {
        dataIsReady = false;
        return true;
    }

    printArray(m_storageBufferArr);
    // Fill the packages
    if (!fillPackages(m_storageBufferArr, m_GGABuffer, m_RMCBuffer)) {
        dataIsReady = false;
        m_storageBufferArr.clear();
        m_GGABuffer.clear();
        m_RMCBuffer.clear();
        setValuesInZero();
        return false;
    }

    // Process data
    if (!processData(m_GGABuffer, m_RMCBuffer)) {
        dataIsReady = false;
        m_storageBufferArr.clear();
        m_GGABuffer.clear();
        m_RMCBuffer.clear();
        setValuesInZero();
        return false;
    }

    // After data clear all buffers
    m_storageBufferArr.clear();
    m_GGABuffer.clear();
    m_RMCBuffer.clear();

    dataIsReady = true;
    return true;
}

bool CParsing::fillPackages(const std::vector<std::string>& storageBufferArr,
        std::vector<std::string>& GGABuffer,
        std::vector<std::string>& RMCBuffer) {

    bool GGABufferIsFull = false;
    bool RMCBufferIsFull = false;

    bool fillingIsCompeted = false;
    for (unsigned int i = 0; i < storageBufferArr.size(); i++) {
        std::string beginOfPackage = storageBufferArr[i].substr(0, 6);
        if (!GGABufferIsFull) {
            if (beginOfPackage == "$GPGGA") {
                split(GGABuffer, storageBufferArr[i], ",");
                if ((GGABuffer.size() != 14) && (GGABuffer.size() != 15)) {
                    return false;
                }
                GGABufferIsFull = true;
            }
        }
        if (!RMCBufferIsFull) {
            if (beginOfPackage == "$GPRMC") {
                split(RMCBuffer, storageBufferArr[i], ",");
                if ((RMCBuffer.size() != 12) && (RMCBuffer.size() != 13)) {
                    return false;
                }
                RMCBufferIsFull = true;
            }
        }
    }

    if (!GGABuffer.empty() && !RMCBuffer.empty()) {
        fillingIsCompeted = true;
    } else {
        fillingIsCompeted = false;
    }

    return fillingIsCompeted;
}

const std::vector<std::string>&
CParsing::storage(std::vector<std::string>& bufferArr) {
    // Save the last line of the buffer storage array
    std::string endStringOfStorage = m_storageBufferArr.back();

    // Is the last line of the storage buffer array completed
    // If so, copy the input buffer array to the storage buffer array
    if (endStringOfStorage != "") {
        for (unsigned int i = 0; i < bufferArr.size(); i++) {
            m_storageBufferArr.pop_back();
            m_storageBufferArr.push_back(bufferArr[i]);
        }
    } else {
        // Otherwise connect two unfinished buffer
        // Extract an unfinished line from the input buffer array
        std::string endStringOfInputBuffer = bufferArr.back();
        bufferArr.pop_back();
        // Restore the unfinished line in a storage buffer array
        std::vector<std::string>::iterator itEndOfStorage =
                m_storageBufferArr.end();
        *(itEndOfStorage - 1) += endStringOfInputBuffer;
        std::string testString = *(itEndOfStorage - 1);
        for (unsigned int i = 0; i < bufferArr.size(); i++) {
            m_storageBufferArr.push_back(bufferArr[i]);
        }
    }

    return m_storageBufferArr;
}

bool CParsing::processData(std::vector<std::string>& GGABuffer,
        std::vector<std::string>& RMCBuffer) {
    // Enough or not the number of data
    if ((GGABuffer.size() != 14) && (GGABuffer.size() != 15)) {
        return false;
    }
    if ((RMCBuffer.size() != 12) && (RMCBuffer.size() != 13)) {
        return false;
    }
    // 6) GPS Quality Indicator,
    // 0 - fix not available,
    // 1 - GPS fix,
    // 2 - Differential GPS fix
    if (GGABuffer[6] != "2") {
        return false;
    } else {
        m_bIsValidGPGGAData = true;
    }

    // 7) Number of satellites in view, 00 - 12
    std::stringstream convertNSatellites(GGABuffer[7]);
    if (!(convertNSatellites >> m_iNSatellites)) {
        return false;
    }

    // 9) Antenna Altitude above/below mean-sea-level (geoid)
    std::stringstream convertAltitude(GGABuffer[9]);
    if (!(convertAltitude >> m_dAltitude)) {
        return false;
    }

    // 2) Status, V = Navigation receiver warning
    if (RMCBuffer[2] != "A") {
        return false;
    } else {
        m_bIsValidGPRMCData = true;
    }

    // 1) Time (UTC)
    int utcTime;
    std::stringstream convertTime(RMCBuffer[1]);
    if (!(convertTime >> utcTime)) {
        return false;
    }

    std::string strUtcTime = RMCBuffer[1];

    // 9) Date, ddmmyy
    int date;
    std::stringstream convertDate(RMCBuffer[9]);
    if (!(convertDate >> date)) {
        return false;
    }

    std::string strUtcDate = RMCBuffer[9];

    if (!utcToMsecFrom1970(m_iTime, strUtcTime, strUtcDate)) {
        return false;
    }

    // 3) Latitude
    double latitudeDegreeWithMinutes;
    std::stringstream convertLatitude(RMCBuffer[3]);
    if (!(convertLatitude >> latitudeDegreeWithMinutes)) {
        return false;
    }
    if (!minutesToDegrees(latitudeDegreeWithMinutes, m_dLatitude)) {
        return false;
    }

    // 4) N or S
    if (RMCBuffer[4] == "S") {
        m_dLatitude *= -1;
    }

    // 5) Longitude
    double longitudeDegreeWithMinutes;
    std::stringstream convertLongitude(RMCBuffer[5]);
    if (!(convertLongitude >> longitudeDegreeWithMinutes)) {
        return false;
    }
    if (!minutesToDegrees(longitudeDegreeWithMinutes, m_dLongitude)) {
        setValuesInZero();
        return false;
    }

    // 6) E or W
    if (RMCBuffer[6] == "W") {
        m_dLongitude *= -1;
    }

    // 7) Speed over ground, knots
    std::stringstream convertSpeed(RMCBuffer[7]);
    if (!(convertSpeed >> m_dSpeed)) {
        setValuesInZero();
        return false;
    }
    m_dSpeed *= 1.852;

    return true;
}

bool CParsing::utcToMsecFrom1970(int& msecFrom1970,
        const std::string& utcTime,
        const std::string& date) {

    bool successful = false;

    std::string strHours = utcTime.substr(0, 2);
    std::string strMinutes = utcTime.substr(2, 2);
    std::string strSeconds = utcTime.substr(4, 2);

    std::string strDays = date.substr(0, 2);
    std::string strMonths = date.substr(2, 2);
    std::string strYears = date.substr(4, 2);

    int hours;
    std::stringstream convertHour(strHours);
    if (!(convertHour >> hours)) {
        return false;
    }

    int minutes;
    std::stringstream convertMinute(strMinutes);
    if (!(convertMinute >> minutes)) {
        return false;
    }

    int seconds;
    std::stringstream convertSecond(strSeconds);
    if (!(convertSecond >> seconds)) {
        return false;
    }

    int days;
    std::stringstream convertDay(strDays);
    if (!(convertDay >> days)) {
        return false;
    }

    int months;
    std::stringstream convertMonth(strMonths);
    if (!(convertMonth >> months)) {
        return false;
    }

    int year;
    std::stringstream convertYear(strYears);
    if (!(convertYear >> year)) {
        return false;
    }

    std::tm tmTime;
    tmTime.tm_hour = hours;
    tmTime.tm_min = minutes;
    tmTime.tm_sec = seconds;
    tmTime.tm_mday = days;
    tmTime.tm_mon = months - 1;
    year += 100;
    tmTime.tm_year = year;

    msecFrom1970 = std::difftime(std::mktime(&tmTime), 0);

    if (msecFrom1970 != 0) {
        successful = true;
    }

    return successful;
}

bool CParsing::haveWeAllPackages() {
    
    // remove the last packages
    m_storageBufferArr.pop_back();
    
    bool haveWeAllPackages = false;
    bool haveWeGGAPackage = false;
    bool haveWeRMCPackage = false;
    for (unsigned int i = 0; i < m_storageBufferArr.size(); i++) {
        std::string beginOfPackage = m_storageBufferArr[i].substr(0, 6);
        if (!haveWeGGAPackage) {
            if (beginOfPackage == "$GPGGA") {
                haveWeGGAPackage = true;
            }
        }
        if (!haveWeRMCPackage) {
            if (beginOfPackage == "$GPRMC") {
                haveWeRMCPackage = true;
            }
        }
    }
    haveWeAllPackages = (haveWeGGAPackage && haveWeRMCPackage);
    return haveWeAllPackages;
}

std::vector <std::string> & CParsing::split(
        std::vector <std::string> & result,
        const std::string& s,
        const std::string& delimiters,
        split::empties_t empties) {
    result.clear();
    size_t current;
    size_t next = -1;
    do {
        if (empties == split::no_empties) {
            next = s.find_first_not_of(delimiters, next + 1);
            if (next == std::string::npos) break;
            next -= 1;
        }
        current = next + 1;
        next = s.find_first_of(delimiters, current);
        result.push_back(s.substr(current, next - current));
    } while (next != std::string::npos);
    return result;
}

bool CParsing::minutesToDegrees(double dDegreeWithMinutes, double& degrees) {
    // Conversion from double to string
    std::stringstream qDegreeWithMinutesToString;
    qDegreeWithMinutesToString << dDegreeWithMinutes;
    std::string qDegreeWithMinutesAsString(qDegreeWithMinutesToString.str());

    if (qDegreeWithMinutesAsString[4] != '.') {
        return false;
    }

    std::string degreesAsString = qDegreeWithMinutesAsString.substr(0, 2);
    std::string minutesAsString = qDegreeWithMinutesAsString.substr(2, qDegreeWithMinutesAsString.length() - 2);

    double minutes;
    std::stringstream qMinutesToString(minutesAsString);
    if (!(qMinutesToString >> minutes)) {
        return false;
    }
    double tenthsOfDegree = minutes / 60;

    std::stringstream qDegreesToString(degreesAsString);
    if (!(qDegreesToString >> degrees)) {
        return false;
    }

    degrees += tenthsOfDegree;

    return true;
}
