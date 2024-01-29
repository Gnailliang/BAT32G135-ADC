/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include "exception-handlers.h"

// ----------------------------------------------------------------------------

void __attribute__((weak))
Default_Handler(void);

// Forward declaration of the specific IRQ handlers. These are aliased
// to the Default_Handler, which is a 'forever' loop. When the application
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//
// TODO: Rename this and add the actual routines here.

void __attribute__ ((weak, alias ("Default_Handler")))
DeviceInterrupt_Handler(void);
// ----------------------------------------------------------------------------
void __attribute__((weak))
IRQ00_Handler(void);
void __attribute__((weak))
IRQ01_Handler(void);
void __attribute__((weak))
IRQ02_Handler(void);
void __attribute__((weak))
IRQ03_Handler(void);
void __attribute__((weak))
IRQ04_Handler(void);
void __attribute__((weak))
IRQ05_Handler(void);
void __attribute__((weak))
IRQ06_Handler(void);
void __attribute__((weak))
IRQ07_Handler(void);
void __attribute__((weak))
IRQ08_Handler(void);
void __attribute__((weak))
IRQ09_Handler(void);
void __attribute__((weak))
IRQ10_Handler(void);
void __attribute__((weak))
IRQ11_Handler(void);
void __attribute__((weak))
IRQ12_Handler(void);
void __attribute__((weak))
IRQ13_Handler(void);
void __attribute__((weak))
IRQ14_Handler(void);
void __attribute__((weak))
IRQ15_Handler(void);
void __attribute__((weak))
IRQ16_Handler(void);
void __attribute__((weak))
IRQ17_Handler(void);
void __attribute__((weak))
IRQ18_Handler(void);
void __attribute__((weak))
IRQ19_Handler(void);
void __attribute__((weak))
IRQ20_Handler(void);
void __attribute__((weak))
IRQ21_Handler(void);
void __attribute__((weak))
IRQ22_Handler(void);
void __attribute__((weak))
IRQ23_Handler(void);
void __attribute__((weak))
IRQ24_Handler(void);
void __attribute__((weak))
IRQ25_Handler(void);
void __attribute__((weak))
IRQ26_Handler(void);
void __attribute__((weak))
IRQ27_Handler(void);
void __attribute__((weak))
IRQ28_Handler(void);
void __attribute__((weak))
IRQ29_Handler(void);
void __attribute__((weak))
IRQ30_Handler(void);
void __attribute__((weak))
IRQ31_Handler(void);
// ----------------------------------------------------------------------------

extern unsigned int _estack;

typedef void
(* const pHandler)(void);

// ----------------------------------------------------------------------------

// The vector table.
// This relies on the linker script to place at correct location in memory.

__attribute__ ((section(".isr_vector"),used))
pHandler __isr_vectors[] =
  { //
    (pHandler) &_estack,                          // The initial stack pointer
        Reset_Handler,                            // The reset handler

        NMI_Handler,                              // The NMI handler
        HardFault_Handler,                        // The hard fault handler

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
        MemManage_Handler,                        // The MPU fault handler
        BusFault_Handler,// The bus fault handler
        UsageFault_Handler,// The usage fault handler
#else
        0, 0, 0,				  // Reserved
#endif
        0,                                        // Reserved
        0,                                        // Reserved
        0,                                        // Reserved
        0,                                        // Reserved
        SVC_Handler,                              // SVCall handler
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
        DebugMon_Handler,                         // Debug monitor handler
#else
        0,					  // Reserved
#endif
        0,                                        // Reserved
        PendSV_Handler,                           // The PendSV handler
        SysTick_Handler,                          // The SysTick handler

        // ----------------------------------------------------------------------
        // DEVICE vectors
		IRQ00_Handler,
		IRQ01_Handler,
		IRQ02_Handler,
		IRQ03_Handler,
		IRQ04_Handler,
		IRQ05_Handler,
		IRQ06_Handler,
		IRQ07_Handler,
		IRQ08_Handler,
		IRQ09_Handler,
		IRQ10_Handler,
		IRQ11_Handler,
		IRQ12_Handler,
		IRQ13_Handler,
		IRQ14_Handler,
		IRQ15_Handler,
		IRQ16_Handler,
		IRQ17_Handler,
		IRQ18_Handler,
		IRQ19_Handler,
		IRQ20_Handler,
		IRQ21_Handler,
		IRQ22_Handler,
		IRQ23_Handler,
		IRQ24_Handler,
		IRQ25_Handler,
		IRQ26_Handler,
		IRQ27_Handler,
		IRQ28_Handler,
		IRQ29_Handler,
		IRQ30_Handler,
		IRQ31_Handler,
    // TODO: rename and add more vectors here
    };

// ----------------------------------------------------------------------------

// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.

void __attribute__ ((section(".after_vectors")))
Default_Handler(void)
{
  while (1)
    {
	  ;
    }
}

// ----------------------------------------------------------------------------
