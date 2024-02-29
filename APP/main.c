/*
 * main.c
 *
 *  Created on: 30 Sep 2022
 *      Author: magdy
 */


/*
 * DIO.c
 *
 * Created: 28/09/2022 15:46:53
 * Author : magdy
 */


#include "TYPES.h"
#include "Interface.h"

int main(void)
{
   DIO_SETDIR_PORT(PORTA_, OUTPUT);

   while(1)
   {
	   DIO_SETVAL_PIN(PORTA_, PIN0, HIGH);
   }
}

