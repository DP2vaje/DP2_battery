/**************************************************************
* FILE:         PCB_util.c 
* DESCRIPTION:  PCB initialization & Support Functions
* VERSION:      1.0
* AUTHOR:       Mitja Nemec
**************************************************************/
#include "PCB_util.h"


/**************************************************************
* Funckija ki vklopi breme
**************************************************************/
#pragma CODE_SECTION(PCB_LED_on, "ramfuncs");
void PCB_load_on(void)
{
    //pri control sticku-u je ledica na GPIO34
    GpioDataRegs.GPASET.bit.GPIO0 = 1;
}

/**************************************************************
* Funckija ki izklopi breme
**************************************************************/
#pragma CODE_SECTION(PCB_LED_on, "ramfuncs");
void PCB_load_off(void)
{
    //pri control sticku-u je ledica na GPIO34
    GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;
}

/**************************************************************
* Funckija ki preveri ali se polnimo
**************************************************************/
#pragma CODE_SECTION(PCB_LED_on, "ramfuncs");
int PCB_charge_state(void)
{
    if (GpioDataRegs.GPADAT.bit.GPIO1 == 1)
    {
        return(TRUE);
    }
    else
    {
        return(FALSE);
    }
}

/**************************************************************
* Funckija ki prizge LED diodo 1
**************************************************************/
#pragma CODE_SECTION(PCB_LED_on, "ramfuncs");
void PCB_LED_on(void)
{
    GpioDataRegs.GPBSET.bit.GPIO34 = 1;
}

/**************************************************************
* Funckija ki ugasne LED diodo 1
**************************************************************/
#pragma CODE_SECTION(PCB_LED_off, "ramfuncs");
void PCB_LED_off(void)
{
    GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;
}

/**************************************************************
* Funckija ki spremeni stanje LED diode
**************************************************************/
#pragma CODE_SECTION(PCB_LED_toggle, "ramfuncs");
void PCB_LED_toggle(void)
{
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;
}

/**************************************************************
* Funckija ki inicializira PCB
**************************************************************/
void PCB_init(void)
{
    EALLOW;

    /* IZHODI */
    // LED
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;
    GpioDataRegs.GPBDAT.bit.GPIO34 = 0;

    // LOAD ON
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;
    GpioDataRegs.GPADAT.bit.GPIO0 = 0;

    // CHARGE
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO1 = 0;

    EDIS;

}
