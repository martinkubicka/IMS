/**
 * @file CashDesk.h
 * @author Martin Kubicka (xkubic45)
 * @date 10.12.2023
 * @brief Header file where cash desks variables are declared.
*/

#ifndef CASHDESK_H
#define CASHDESK_H

#include "simlib.h"
#include "macros.h"

extern bool cashDeskOpened; // true if cas desks are opened

extern Facility CashDesk[CASHDESK]; // facility of cash desks

#endif

/*** End of CashDesk.h ***/
