# TEAM NAME: BETTER LUCK

## CODE CHANGE
## track 1
FILE_NAME:
 - main.h
    line 17: delete ```#define NULL 0   ```
 - register.c
    initializing for all global variables: 

        int baseAddr = 0; 
        int dataLen = 0; 
        int regStatus = 0;

    in ```void configureRegister(void) ``` function:

            make it valid initialize by cast the type:
                LIN_Rx3 = (RLIN_Register)RLIN_Rx3_REGISTERCONFIG;

     in ```void checkRegisterErr(void) ``` function:

            call the errorHandling() function
     
     in ```void receiveDataHandling(void) ``` function:

            add break to case someTp_FMT_01
            in case someTp_FMT_02, decrease the limit of the for loop:
            ``` for (idx = 2; idx < dataLen - 2; idx++) ```
            change syntax case default to default
     
     in ```void errorHandling(void) ``` function:

            
     in ```void resetHandling(void) ``` function:
            
            not call the function errorHandling()
    
     in ```void rxHandling(void) ``` function:
            
            in do while loop:
               copy right data to the mirro:
               ``` mirro_regBufferRx[idx] = LIN_Rx3.bufferRx[idx]; ```
               change the stop condition: idx > 0 to idx >= 0
     
      in ```void txHandling(void) ``` function:

             in do while loop:
                copy right data to the mirro:
                ``` mirro_regBufferTx[idx] = LIN_Rx3.bufferTx[idx]; ```
                change the stop condition: idx > 0 to idx >= 0
      
      in ``` void someTp(void) ``` function:
 - test.c:
      in ``` void run_startup(void) ``` function:
      
      in ``` void run_cyclic(void) ``` function:
      
      in ``` int get_array_element(const char *array, int array_length, int index) ``` function:
      
             change the condition of ifstatement: index > array_length to index >= arraylength
             bring the return 0 statement under the printf function.
             ``` printf("Out of bound access"); ```
	     ``` return 0; ```
      in ``` char *allocate_buffer(int size) ``` function:
             
             
      in ``` void deallocate_buffer(char *buffer)  ``` function:  
      
             change the return type of the function into char*
             change the return statement: ``` return buffer; ```
	     
      in ``` int main(void) ``` function:
             
            
