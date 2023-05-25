/*
 * register.c
 *
 *  Created on: May 18, 2023
 *      Author: gogoCow
 */

#include "resetRegister.h"
#include "registerMonitor.h"

static RLIN_Register LIN_Rx3;
int baseAddr = 0;
int regBufferRx[255];
int regBufferTx[255];
int dataLen = 0;
int regStatus = 0;

int mirro_regBufferRx[256];
int mirro_regBufferTx[256];

void configureRegister(void)
{

    LIN_Rx3 = (RLIN_Register)RLIN_Rx3_REGISTERCONFIG;
    return;
}

void checkRegisterErr(void)
{

    return;
}

void receiveDataHandling(void)
{
    int l_fmt__u8;
    l_fmt__u8 = (int)(mirro_regBufferRx[0] >> 6);
    switch (l_fmt__u8)
    {
    case someTp_FMT_01:
    {
        break;
    }
    case someTp_FMT_02:
    {

        mirro_regBufferTx[0] = (int)(l_fmt__u8 << 6);
        mirro_regBufferTx[1] = dataLen;
        int idx;
        for (idx = 2; idx < dataLen; idx++)
        {
            /* code */
            mirro_regBufferTx[idx + 2] = mirro_regBufferRx[idx] & 0x55;
        }
        mirro_regBufferTx[idx + 2] = 0xFE;
        break;
    }
    case someTp_FMT_03:
    {
        break;
    }
    case someTp_FMT_04:
    {
        break;
    }
    default:
    {
        /* Do not support*/
        break;
    }
    }

    return;
}
void errorHandling(void)
{

    if (LIN_Rx3.registerStatus & TX_ERROR)
    {
        int idx;
        /* clear TX buffer */
        for (idx = 0; idx < 255; idx++)
        {
            LIN_Rx3.bufferTx[idx] = 0x00;
            mirro_regBufferTx[idx] = 0x00;
        }
    }
    if (LIN_Rx3.registerStatus & RX_ERROR)
    {
        int idx;
        /* clear RX buffer */
        for (idx = 0; idx < 255; idx++)
        {
            LIN_Rx3.bufferRx[idx] = 0x00;
            mirro_regBufferRx[idx] = 0x00;
        }
    }

    return;
}
void resetHandling(void)
{
    if (LIN_Rx3.registerStatus && 0xFF)
    {
        LIN_Rx3.registerStatus = 0x00;
    }
    errorHandling();
    return;
}

void rxHandling(void)
{
    int idx = 0;

    idx = LIN_Rx3.length - 1;
    /* copy data to the mirror*/
    do
    {
        mirro_regBufferRx[idx] = LIN_Rx3.bufferRx[idx];
        idx--;
    } while (idx >= 0);
    return;
}

void txHandling(void)
{
    int idx = 0;

    idx = LIN_Rx3.length - 1;
    /* copy data to the mirror*/
    do
    {
        //  LIN_Rx3.bufferTx[idx] = mirro_regBufferTx[idx];
        mirro_regBufferTx[idx] = LIN_Rx3.bufferTx[idx];
        idx--;
    } while (idx >= 0);
    return;
}

void someTp(void)
{
    int idx = 0;
    int calCS = 0;
    /*Calculate checksum*/
    for (idx = 0; idx < (LIN_Rx3.length); idx++)
    {
        calCS = calCS + LIN_Rx3.bufferRx[idx];
    }

    if (calCS != LIN_Rx3.bufferRx[idx])
    {
        resetHandling();
    }
    else
    {
        /*Handling the data received*/
        receiveDataHandling();
    }
    return;
}