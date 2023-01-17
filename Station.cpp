/*
*****************************************************************************
                            Final Project MS3
Full Name  : Priyansh Parikh
Student ID#: 158341214
Email      : pparikh8@myseneca.ca
Section    : NGG
Date       : 02/12/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

namespace sdds
{
    size_t sdds::Station::m_widthField = 0;
    int sdds::Station::id_generator = 0;
    sdds::Station::Station(const string &record)
    {
        Utilities utilities;
        size_t next_pos = 0;
        bool more = true;
        id = ++id_generator;
        name = utilities.extractToken(record, next_pos, more);
        nextSerialNo = stoi(utilities.extractToken(record, next_pos, more));
        noItems = stoi(utilities.extractToken(record, next_pos, more));
        m_widthField = m_widthField > utilities.getFieldWidth() ? m_widthField : utilities.getFieldWidth();
        desc = utilities.extractToken(record, next_pos, more);
    }
    const string &sdds::Station::getItemName() const
    {
        return name;
    }
    size_t sdds::Station::getNextSerialNumber()
    {
        return nextSerialNo++;
    }
    size_t sdds::Station::getQuantity() const
    {
        return noItems;
    }
    void sdds::Station::updateQuantity()
    {
        if (noItems > 0)
        {
            noItems--;
        }
    }
    void sdds::Station::display(ostream &os, bool full) const
    {
        os << std::right;
        os << setw(3) << setfill('0') << id << " | ";
        os << left << setfill(' ') << setw(m_widthField + 1) << name << " | ";
        os << right << setw(6) << setfill('0') << nextSerialNo << " | ";
        if (full)
        {
            os << setfill(' ');
            os << right;
            os << setw(4) << noItems << " | " << desc;
        }
        os << endl;
    }
}