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

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <deque>
#include <iostream>
#include "CustomerOrder.h"
#include "Station.h"
using namespace std;
extern deque<sdds::CustomerOrder> g_pending;
extern deque<sdds::CustomerOrder> g_completed;
extern deque<sdds::CustomerOrder> g_incomplete;
namespace sdds
{
    class Workstation : public Station
    {
        deque<CustomerOrder> m_orders;
        Workstation *m_pNextStation = nullptr;

    public:
        Workstation(const string &data);
        void fill(ostream &os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation *station = nullptr);
        Workstation *getNextStation() const;
        void display(ostream &os) const;
        Workstation &operator+=(CustomerOrder &&new_Order);
        bool empty() const;
    };
};
#endif