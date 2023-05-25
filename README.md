# Memeow team progress
## Stage 1: syntax error fix src/track1/register.c
* edit "case default:" to "default:": line 55.
* edit "LIN_Rx3.regBufferRx[idx]" to "LIN_Rx3.bufferRx[idx]": line 72.
* edit "LIN_Rx3.regBufferRx[idx]" to "LIN_Rx3.bufferRx[idx]": line 82.
* edit "LIN_Rx3.regBufferRx[idx]" to "LIN_Rx3.bufferRx[idx]": line 106.
* edit "while (i>0)" to "while (idx>0);": line 108.
* edit "LIN_Rx3.regBufferTx[idx]" to "LIN_Rx3.bufferTx[idx]": line 119
* edit "while (idx>0)" to "while (idx>0);": line 121
* edit "for (idx = 0; i < (LIN_Rx3.length - 1); i++)" to "for (idx = 0; idx < (LIN_Rx3.length - 1); idx++)": line 130.
* edit "LIN_Rx3.regBufferRx[idx]" to "LIN_Rx3.bufferRx[idx]": line 132.
* edit "LIN_Rx3.regBufferRx[idx]" to "LIN_Rx3.bufferRx[idx]": line 135.
