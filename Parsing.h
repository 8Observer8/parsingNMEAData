/* 
 * File:   Parsing.h
 * Author: Ivan
 *
 * Created on May 18, 2013, 4:14 PM
 */

#ifndef PARSING_H
#define	PARSING_H

struct split {

    enum empties_t {
        empties_ok, no_empties
    };
};

#include <string>
#include <vector>

/**
 * The parsing of the data from the NMEA protocol
 */
class CParsing {
public:
    /**
     * The constructor
     */
    CParsing();

    /**
     * Parses the data from the NMEA protocol
     * 
     * @param buffer The buffer for parsing
     * @param dataIsRaedy Data is ready
     * @return The analysis occurred or not
     */
    bool parseData(std::string buffer, bool& dataIsReady);

    /**
     * Gets the latitude
     * 
     * @return The latitude
     */
    double getLatitude() {
        return m_dLatitude;
    }

    /**
     * Gets the longitude
     * 
     * @return The longitude
     */
    double getLongitude() {
        return m_dLongitude;
    }

    /**
     * Gets the altitude
     * 
     * @return The altitude
     */
    double getAltitude() {
        return m_dAltitude;
    }

    /**
     * Gets the time
     * 
     * @return The time
     */
    int getTime() {
        return m_iTime;
    }

    /**
     * Gets the speed
     * 
     * @return The speed
     */
    double getSpeed() {
        return m_dSpeed;
    }

    /**
     * Gets the numbers of the satellites
     * 
     * @return The numbers of the satellites
     */
    int getNSatellites() {
        return m_iNSatellites;
    }

    /**
     * Whether the GPGGA data is correct
     * 
     * @return The GPGGA data is valid
     */
    bool isValidGPGGAData() {
        return m_bIsValidGPGGAData;
    }

    /**
     * Whether the GPGGA data is correct
     * 
     * @return The GPRMC data is valid
     */
    bool isValidGPRMCData() {
        return m_bIsValidGPRMCData;
    }

    /**
     * Storages data
     * 
     * @param storageBufferArr The storage buffer array
     * @param bufferArr The buffer array
     * @return The storage buffer array
     */
    const std::vector<std::string>&
    storage(std::vector<std::string>& bufferArr);

    /**
     * Sets the GGA buffer array
     * 
     * @param s The input string
     */
    void setGGABufferArr(std::string s) {
        m_GGABuffer.push_back(s);
    }

    /**
     * Sets the RMC buffer array
     * 
     * @param s The input string
     */
    void setRMCBufferArr(std::string s) {
        m_RMCBuffer.push_back(s);
    }

    /**
     * Sets the storage buffer array
     * 
     * @param s The input string
     */
    void setStorageBufferArr(std::string s) {
        m_storageBufferArr.push_back(s);
    }

    /** Have we all the packages? */
    bool haveWeAllPackages();

    /**
     * Process data
     * 
     * @param storageBufferArr The storage buffer array
     * @param GGABuffer The output GGA buffer array
     * @param RMCBuffer The output RMC buffer array
     * @return Whether the filled packages
     */
    bool processData(std::vector<std::string>& GGABuffer,
            std::vector<std::string>& RMCBuffer);

    /**
     * Fills the package buffer arrays from the storage buffer array
     * 
     * @param storageBufferArr The storage buffer array
     * @param GGABuffer The output GGA buffer array
     * @param RMCBuffer The output RMC buffer array
     * @return Whether the filled packages
     */
    bool fillPackages(const std::vector<std::string>& storageBufferArr,
            std::vector<std::string>& GGABuffer,
            std::vector<std::string>& RMCBuffer);

    /**
     * Converts UTC time to msec from 1970
     * 
     * @param msecFrom1970 The output msec from 1970
     * @param utcTime The UTC time
     * @param date The date
     * @return The successful flag
     */
    bool utcToMsecFrom1970(int& msecFrom1970,
            const std::string& utcTime,
            const std::string& date);

private:
    /** The RMC buffer */
    std::vector<std::string> m_RMCBuffer;

    /** The GGA buffer */
    std::vector<std::string> m_GGABuffer;

    /** The storage buffer array */
    std::vector<std::string> m_storageBufferArr;

    /** The previous part of the package */
    std::string m_previousPartOfPackage;

    /**
     * Splits this string
     * 
     * @param result The result
     * @param inputBuffer The input buffer
     * @param delimiters The delimiter
     * @param empties Include or not the empty strings
     * @return The result
     */
    std::vector <std::string> & split(
            std::vector <std::string> & result,
            const std::string& inputBuffer,
            const std::string& delimiters,
            split::empties_t empties = split::empties_ok);

    /**
     * Sets the values in zero
     */
    void setValuesInZero();

    /**
     * Converts a minute record to a degree record
     * 
     * @param m The minute record
     * @return The degree record
     */
    bool minutesToDegrees(double m, double& result);

    /** The latitude */
    double m_dLatitude;

    /** The longitude */
    double m_dLongitude;

    /** The altitude */
    double m_dAltitude;

    /** The time */
    int m_iTime;

    /** The speed */
    double m_dSpeed;

    /** The number of the satellites */
    int m_iNSatellites;

    /** Whether the GPGGA data is correct */
    bool m_bIsValidGPGGAData;

    /** Whether the GPRMC data is correct */
    bool m_bIsValidGPRMCData;
};

#endif	/* PARSING_H */
