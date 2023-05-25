# TEAM NAME: BETTER LUCK

## CODE CHANGE
## track 1
FILE_NAME:
 - main.h
    line 17: delete ```#define NULL 0   ```
 - register.c
    initializing for all global function: 

        int baseAddr = 0; 
        int dataLen = 0; 
        int regStatus = 0;

    in ```void configureRegister(void) ``` function:

            make it valid initialize by cast the type:
                LIN_Rx3 = (RLIN_Register)RLIN_Rx3_REGISTERCONFIG;

     in ```void checkRegisterErr(void) ``` function:

            call the errorHandling() function
           phongcuter
           
