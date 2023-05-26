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
## Stage 2: find security scan tools
* First, we try some tools as SonarQube, KlocWork, Kiuwan and Snyk.
* The problems are: SonarQube is not free, KlocWork does not have trial for students, Kiuwan need a brief call to discuss about project and Snyk has a problem that we cant figure it out what the problem is.

KlocWork email.
![klocwork](./img/klocwork.png)

Kiuwan email.
![kiuwan](./img/kiuwan.png)

Snyk problem.
![snyk](./img/snyk.png)

* Then we found another tool - cppcheck. Luckily it works perfectly fine in our local machine.

Cppcheck
![cppcheck](./img/cppcheck.png)

* Our pipeline test.

Cppcheck on Azure pipeline output.
![cppcheck-azure](./img/cppcheck-azure.png)

## Stage 3: extend pipeline file
* Add step install cppcheck
* Add step run cppcheck

