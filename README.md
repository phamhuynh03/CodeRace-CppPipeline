# Welcome to BGSV Code Race 2023 - Round 2 of EldersTHSPCanTho team
## Our first commit of fixing bugs on track 1
We have fixed some bug on module: register.c
#line 55
case default: -> default:
#line 72
LIN_Rx3.regBufferRx[idx] = 0x00; ->            LIN_Rx3.bufferRx[idx] = 0x00;
#line 82
LIN_Rx3.regBufferRx[idx] = 0x00; ->            LIN_Rx3.bufferRx[idx] = 0x00;
#line 106
mirro_regBufferRx[idx] = LIN_Rx3.regBufferRx[idx]; ->        mirro_regBufferRx[idx] = LIN_Rx3.bufferRx[idx];
#line 108
}  while (idx>0) ->     }  while (idx>0);
#line 119
LIN_Rx3.regBufferTx[idx] = mirro_regBufferTx[idx]; ->        LIN_Rx3.bufferTx[idx] = mirro_regBufferTx[idx];
#line 121
}  while (idx>0) ->   }  while (idx>0);
#line 130
for (idx = 0; i < (LIN_Rx3.length - 1); i++) ->    for (idx = 0; idx < (LIN_Rx3.length - 1); idx++)
# line 132
calCS = calCS + LIN_Rx3.regBufferRx[idx]; ->        calCS = calCS + LIN_Rx3.bufferRx[idx];
# line 135
if (calCS != LIN_Rx3.regBufferRx[idx]) ->     if (calCS != LIN_Rx3.bufferRx[idx])