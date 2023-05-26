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

            add break to case some Tp_FMT_01, TP_FMT_03, TP_FMT_04
            in case someTp_FMT_02, decrease the limit of the for loop:
            ``` for (idx = 2; idx < dataLen - 2; idx++) ```
            change syntax case default to default
     
     in ```void errorHandling(void) ``` function:

              change to location of declear int idx to if range
              change "else if" to if -> can change error in two TX and RX
              in the loop of "clear TX bufffer",  LIN_Rx3.regBufferRx[idx] = 0x00 -> LIN_Rx3.bufferTx[idx] = 0x00;

            
     in ```void resetHandling(void) ``` function:
            
            not call the function errorHandling()
    
     in ```void rxHandling(void) ``` function:
            
            in do while loop:
               copy right data to the mirro:
               ``` mirro_regBufferRx[idx] = LIN_Rx3.bufferRx[idx]; ```
               change the stop condition: idx > 0 to idx >= 0
              put the semicolon at the end of while
     
      in ```void txHandling(void) ``` function:

             in do while loop:
                copy right data to the mirro:
                ``` mirro_regBufferTx[idx] = LIN_Rx3.bufferTx[idx]; ```
                change the stop condition: idx > 0 to idx >= 0
              put the semicolon at the end of while       
      in ``` void someTp(void) ``` function:
 - test.c:
      in ``` void run_startup(void) ``` function:

       declare the "int numOfJob = sizeof(c_InitJob)/sizeof(cyclic_ptr); " to be able to stop the while loop 
       change the while condition -> "index != numOfJob"
      in ``` void run_cyclic(void) ``` function:
       
       similar to void run_startup(void) function above
      in ``` int get_array_element(const char *array, int array_length, int index) ``` function:
      
             change the condition of ifstatement: index > array_length to index >= arraylength
             bring the return 0 statement under the printf function.
             ``` printf("Out of bound access"); ```
	    	``` return 0; ```
      in ``` char *allocate_buffer(int size) ``` function:
       
              after "malloc", have if function for check if malloc return the data (in case the heap is available)
              cast 4 first bytes of buffer point to integer that is a size
                    " *((int *)buffer) = size;"
              
      in ``` void deallocate_buffer(char *buffer)  ``` function:  
      
             change the return type of the function into char*
             change the return statement: ``` return allocate_buffer(buffer_size);; ```
	     
      in ``` int main(void) ``` function:
## track 2
FILE_NAME:
 - code_with_bugs.cpp:
    line 32: replace condition if ```index >= array_length ```
    in ```void * allocate_buffer(unsigned long size) ``` function:

            change the return type of the funtion into char*
	    change type of variable i into unsigned long
    in ```int deallocate_buffer(void * buffer) ``` function:

            change the type of the parameter buffer into char*
	    change type of variable i into unsigned long
    in ```int calculate_fingerprint(unsigned long uid, unsigned long counter, const char *text, unsigned int* output) ``` function:

            change the ifstatement conditon : text == (*void)0 to text == NULL
	    bring declare variable statement workspace under ifstatement
	    ``` if (text == NULL) ```
	    ``` char* workspace = (char*)malloc(sizeof(uid) + sizeof(counter) + strlen(text) + 1); ```
    in ```void exploreMe(int a, int b, string c) ``` function:

            change the tyoe of the variable n into long long
	    change the size of s in malloc statements to 12
	    bring the free(s) statements under strcpy(s,"too long");
 - register.c 
             
            
