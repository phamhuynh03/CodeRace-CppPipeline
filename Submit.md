# Round 2 of EldersTHSPCanTho team - submission

## 1) First task:

At the beginning, when starting the job, our team wanted to manually identify the previous errors in the source code. This was done in order to gain a better understanding of the task. Below are some of the debugging findings we discovered in track 1.

### line 55
case default: ➡ default:
### line 72
LIN_Rx3.regBufferRx[idx] = 0x00; ➡            LIN_Rx3.bufferRx[idx] = 0x00;
### line 82
LIN_Rx3.regBufferRx[idx] = 0x00; ➡            LIN_Rx3.bufferRx[idx] = 0x00;
### line 106
mirro_regBufferRx[idx] = LIN_Rx3.regBufferRx[idx]; ➡        mirro_regBufferRx[idx] = LIN_Rx3.bufferRx[idx];
### line 108
}  while (idx>0) ➡     }  while (idx>0);
### line 119
LIN_Rx3.regBufferTx[idx] = mirro_regBufferTx[idx]; ➡        LIN_Rx3.bufferTx[idx] = mirro_regBufferTx[idx];
### line 121
}  while (idx>0) ➡   }  while (idx>0);
### line 130
for (idx = 0; i < (LIN_Rx3.length - 1); i++) ➡    for (idx = 0; idx < (LIN_Rx3.length - 1); idx++)
### line 132
calCS = calCS + LIN_Rx3.regBufferRx[idx]; ➡        calCS = calCS + LIN_Rx3.bufferRx[idx];
### line 135
if (calCS != LIN_Rx3.regBufferRx[idx]) ➡     if (calCS != LIN_Rx3.bufferRx[idx])

## 2) Second task: (Inside pr_develop.yaml)

Based on that, we found some basic syntax errors and issues with calling members of a struct. Therefore, we will set up some tools for compiling and generating error messages on the pipeline using GCC.

### Installing GCC 
![image](https://github.com/vietha712/CodeRace-CppPipeline/assets/113485058/d6a44421-eb42-4786-89ea-cfc6ef30d212)
  
### Installing cppcheck
We also conducted further research and discovered the cppcheck tool, which has good capabilities for checking system security errors.
![image](https://github.com/vietha712/CodeRace-CppPipeline/assets/113485058/3147a511-0664-4e04-8073-cd9807b37519)

### Run cppcheck
After that we run cpp check on all files in track1 and track2

![image](https://github.com/vietha712/CodeRace-CppPipeline/assets/113485058/82eb5499-a3ec-4f40-9392-a8e054393144)

### Run GCC for all track
First, we create a new log file, then the GCC will read all the modules (.c) in the folder and display the result on the screen.
![image](https://github.com/vietha712/CodeRace-CppPipeline/assets/113485058/9bf05892-abd1-4b49-aa27-ec2a030d13ad)


  



