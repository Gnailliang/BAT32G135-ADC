/*
 *-----------------------------------------------------------------------------
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from ARM Limited.
 *
 *            (C) COPYRIGHT 2011-2012 ARM Limited.
 *                ALL RIGHTS RESERVED
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from ARM Limited.
 *
 *      SVN Information
 *
 *      Checked In          : $Date: 2012-01-11 17:13:57 +0000 (Wed, 11 Jan 2012) $
 *
 *      Revision            : $Revision: 197600 $
 *
 *      Release Information : Cortex-M0+ AT590-r0p1-00rel0
 *-----------------------------------------------------------------------------
 */

//
// printf retargetting functions
//

#include <stdio.h>
#include <stdint.h>
#include "BAT32G135.h"
#include "userdefine.h"
#include "sci.h"

#if defined ( __CC_ARM   )
#if (__ARMCC_VERSION < 400000)
#else
// Insist on keeping widthprec, to avoid X propagation by benign code in C-lib
#pragma import _printf_widthprec
#endif
#endif

//
// C library retargetting
//

#if defined ( __CC_ARM )
struct __FILE { int handle; /* Add whatever you need here */ };
#endif
FILE __stdout;
FILE __stdin;


//int _read(FILE *f, char * str, int len)
//{
//  int i;
//  for (i=0; i < len; i++){
//	  str[i] = UART0_Receive();
//  }
//  return len;
//}
int _read(FILE *f, char * str, int len)
{
  str[0] = UART0_Receive();
  return 1;
}

int _write(FILE *f, char * str, int len)
{
  int i;
  for (i=0; i < len; i++)
	UART0_Send(str[i]);

  return len;
}

int _lseek(int a,int b,int c)
{
  return -1;
}

int _fstat(int a,int b,int c)
{
  return -1;
}

int _close(int a,int b,int c)
{
  return -1;
}

int _isatty(int a,int b,int c)
{
  return -1;
}

void _sys_exit(int return_code) {
	if(return_code)
	{
		*((volatile uint32_t*)0x40028020) = 0x00000BAD;  /* simulation NG */
	}
	else
	{
		*((volatile uint32_t*)0x40028020) = 0x00000001;  /* simulation OK */
	}
  while (1);    /* endless loop */
}
