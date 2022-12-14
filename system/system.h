/*******************************************************************************
 * File Name   : system.h
 * Author      : Ascua
 ******************************************************************************/

#ifndef SYSTEM_SETTINGS_H
#define	SYSTEM_SETTINGS_H

/*******************************************************************************
* Section: Included Files and Definitions
*******************************************************************************/

#include <xc.h>
#include "global_app_data.h"

/*******************************************************************************
 * Section: Interrupt Management
 ******************************************************************************/

#define INTERRUPT_DisableADCV04()   IEC5bits.ADCAN4IE = 0; /* Disable ADCV interrupt     */
#define INTERRUPT_EnableADCV04()    IEC5bits.ADCAN4IE = 1; /* Enable ADCV interrupt      */

#define INTERRUPT_DisableTimer1()   IEC0bits.T1IE     = 0; /* Disable TIMER1 interrupt   */
#define INTERRUPT_EnableTimer1()    IEC0bits.T1IE     = 1; /* Enable TIMER1 interrupt    */

#define INTERRUPT_DisableReceive()  IEC0bits.U1RXIE   = 0; /* Disable UART1 Rx interrupt */
#define INTERRUPT_EnableReceive()   IEC0bits.U1RXIE   = 1; /* Enable UART1 Rx interrupt  */
#define INTERRUPT_DisableTransmit() IEC0bits.U1TXIE   = 0; /* Disable UART1 Tx interrupt */
#define INTERRUPT_EnableTransmit()  IEC0bits.U1TXIE   = 1; /* Enable UART1 Tx interrupt  */

#define INTERRUPT_DisableMSIM()     IEC8bits.MSIS1IE  = 0; /* Disable MSIM interrupt     */
#define INTERRUPT_EnableMSIM()      IEC8bits.MSIS1IE  = 1; /* Enable MSIM interrupt      */

/* !!!!!!
   !!!!!! Remember to add to InterruptDisableAll and InterruptEnableAll */

typedef enum
{
    TRAPS_OSC_FAIL    = 0,  /* Oscillator Fail Trap vector */
    TRAPS_STACK_ERR   = 1,  /* Stack Error Trap Vector     */
    TRAPS_ADDRESS_ERR = 2,  /* Address error Trap vector   */
    TRAPS_MATH_ERR    = 3,  /* Math Error Trap vector      */
    TRAPS_HARD_ERR    = 7,  /* Generic Hard Trap vector    */
    TRAPS_NVM_ERR     = 12, /* Generic Soft Trap vector    */
    TRAPS_DAE_ERR     = 9,  /* Generic Soft Trap vector    */
    TRAPS_DOOVR_ERR   = 10, /* Generic Soft Trap vector    */
    TRAPS_APLL_ERR    = 11, /* Generic Soft Trap vector    */
} TRAPS_ERROR_CODE;

/*******************************************************************************
* Section: Variables and Functions
*******************************************************************************/

/*******************************************************************************
 * Function     : void SYSTEM_Init()
 *
 * Description  : This routine initializes peripherals. In a bare-metal
 *               environment (where no OS is supported), this routine should
 *               be called almost immediately after entering the "main" routine.
 *
 * Precondition : The C-language run-time environment and stack must
 *                have been initialized.
 *
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : Basic System Initialization Sequence:
 *                1.  Initilize minimal board services and processor-specific items
 *                    (enough to use the board to initialize drivers and services)
 *                2.  Initialize all supported system services
 *                3.  Initialize all supported modules
 *                    (libraries, drivers, middleware, and application-level modules)
 *                4.  Initialize the main (static) application, if present.
 *                    The order in which services and modules are initialized
 *                    and started may be important.
 ******************************************************************************/
void SYSTEM_Init();

/*******************************************************************************
 * Function     : void SYSTEM_InterruptDisableAll()
 *
 * Description  : This routine disables all interrupts.
 *
 * Precondition : None.
 *
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : None.
 ******************************************************************************/
void SYSTEM_InterruptDisableAll();

/*******************************************************************************
 * Function     : void SYSTEM_InterruptEnableAll()
 *
 * Description  : This routine enables all interrupts.
 *
 * Precondition : None.
 *
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : None.
 ******************************************************************************/
void SYSTEM_InterruptEnableAll();

/*******************************************************************************
 * Function     : void SYSTEM_SlaveStart()
 *
 * Description  : This routine starts up the slave.
 *
 * Precondition : None.
 *
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : None.
 ******************************************************************************/
void SYSTEM_SlaveStart();

/*******************************************************************************
 * Function     : void SYSTEM_SlaveProgram()
 *
 * Description  : This routine programs the slave.
 *
 * Precondition : None.
 *
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : None.
 ******************************************************************************/
void SYSTEM_SlaveProgram();

/*******************************************************************************
 * Function     : SYSTEM_TrapError(uint16_t code)
 *
 * Description  : This routine process traps.
 *
 * Precondition : None.
 *
 * Input        : None
 *
 * Output       : None
 *
 * Remarks      : None.
 ******************************************************************************/
void SYSTEM_TrapError(uint16_t code);

#endif	/* SYSTEM_SETTINGS_H */
