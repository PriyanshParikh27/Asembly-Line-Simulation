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

#ifndef STATION_H
#define STATION_H
#include <string>
using namespace std; 
namespace sdds
{
    class Station
    {
        int id;
        string name;
        string desc;
        unsigned int nextSerialNo;
        unsigned int noItems;
        static size_t m_widthField;
        static int id_generator;

    public:
        Station(const string &record);
        const string &getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(ostream &os, bool full) const;
    };
};

#endif
