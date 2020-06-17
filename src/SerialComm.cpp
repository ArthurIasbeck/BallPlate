/**
 * @file SerialComm.cpp
 * @author Arthur Iasbeck (arthuriasbeck@gmail.com)
 * @brief Implementação da classe SerialComm.
 * @version 0.1
 * @date 2020-06-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "SerialComm.h"

SerialComm::SerialComm()
{
    precision = 5;
}

void SerialComm::setupComm()
{
    Serial.begin(BAUD_RATE);
    while (!Serial);
}

void SerialComm::sendData(String data)
{
    Serial.println(data);
}

void SerialComm::sendData(float data)
{
    Serial.println(data, precision);
}

void SerialComm::sendData(float data[], int sizeData)
{
    String msg;

    msg = String(data[0], precision); 
    for(int i = 1; i < sizeData; i++)
    {
        msg += MSG_BREAK + String(data[i], precision);
    }
    sendData(msg);
}

float SerialComm::rcvData()
{
    String rcvString; 
    float rcvFloat;
    char rcvChar;

    received = false; 
    if (Serial.available())
    {
        rcvString = "";
        while (true)
        {
            rcvChar = Serial.read();
            if (rcvChar == '\n') break;
            rcvString += rcvChar;
        }
        rcvFloat = rcvString.toFloat();
        serialClear();
        received = true; 
    }
    return rcvFloat;
}

void SerialComm::rcvData(float* rcvFloat, int sizeData)
{
    String rcvStrings[sizeData];
    String rcvString = "";
    int rcvStringIndex = 0;
    char rcvChar;

    received = false; 
    if (Serial.available())
    {
        rcvString = "";
        while (true)
        {
            rcvChar = Serial.read();
            if((rcvChar == '\n') || (rcvChar == MSG_BREAK))
            {
                rcvStrings[rcvStringIndex] = rcvString;
                rcvStringIndex++;
                rcvString = "";

                if (rcvChar == '\n') 
                {
                    break; 
                }
            }
            else
            {
                rcvString += rcvChar;
            }
        }

        for(int i = 0; i < sizeData; i++)
        {
            rcvFloat[i] = rcvStrings[i].toFloat();
        }

        serialClear();
        received = true; 
    }
}

bool SerialComm::dataReceived()
{
    return received;
}

void SerialComm::setPrecision(int precision)
{
    this->precision = precision;
}

void SerialComm::serialClear() 
{
    while (Serial.available() > 0) 
    {
        Serial.read();
    }
}