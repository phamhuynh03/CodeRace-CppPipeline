# Round 2 of EldersTHSPCanTho team - submission

## 1) First task: Identify system errors and find the right tool

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

## Base on that:
- We found some basic syntax errors and issues with calling members of a struct. Therefore, we will set up some tools for compiling and generating error messages on the pipeline using GCC.
- Beside that, we find more tools that popular in use:

1) Static Vulnerability Scanning Tools:
- SonarQube: A widely used open-source platform for static code analysis, providing security and code quality checks.
- Checkmarx: A commercial tool for static application security testing (SAST), which can identify vulnerabilities in your code.
- Fortify: A comprehensive application security suite that includes static code analysis to identify security flaws.
2) Fuzz Testing Tools:

- AFL (American Fuzzy Lop): A popular fuzzing tool for finding vulnerabilities by generating mutated inputs and monitoring crashes.
- LibFuzzer: Part of the LLVM project, it provides an efficient fuzzing engine for C/C++ code.
- Peach Fuzzer: A versatile fuzzing platform that can be used for various types of software testing, including security testing.

## Conclusion
-> We choose 3 tools as follow: cppcheck, GCC, and AFL.
- GCC is the most common on compiling and check errors on system, that's the first thing on our head for choosing a tool
- cppcheck show more powerfull on finding the vulnerable code and help us fix it
- AFL for fuzzing is the great way to do fuzzing testing on system

## 2) Second task: (Inside pr_develop.yaml)



### Installing GCC 
![image](https://github.com/vietha712/CodeRace-CppPipeline/assets/113485058/d6a44421-eb42-4786-89ea-cfc6ef30d212)
  
### Installing cppcheck
We also conducted further research and discovered the cppcheck tool, which has good capabilities for checking system security errors.
![image](https://github.com/vietha712/CodeRace-CppPipeline/assets/113485058/3147a511-0664-4e04-8073-cd9807b37519)

### Installing AFL
Due to the requirements for fuzzing testing, we have chosen AFL as the fuzzing software.

AFL (American Fuzzy Lop): It is a popular fuzzing testing tool that utilizes evolutionary-based search techniques to generate random inputs and search for vulnerabilities.

### Run cppcheck
After that we run cpp check on all files in track1 and track2

![image](https://github.com/vietha712/CodeRace-CppPipeline/assets/113485058/82eb5499-a3ec-4f40-9392-a8e054393144)

Here is the result:

![image](https://github.com/vietha712/CodeRace-CppPipeline/assets/113485058/db3bcd24-190b-4751-b102-4e1680a638bf)
![image](https://github.com/vietha712/CodeRace-CppPipeline/assets/113485058/8c612724-2333-439a-a4b6-ff80c46cd2ff)
![image](https://github.com/vietha712/CodeRace-CppPipeline/assets/113485058/526daefc-c555-491b-a111-eac9194bc411)


### Run GCC for all track
First, we create a new log file, then the GCC will read all the modules (.c) in the folder and display the result on the screen.
![image](https://github.com/vietha712/CodeRace-CppPipeline/assets/113485058/9bf05892-abd1-4b49-aa27-ec2a030d13ad)

Here is the result:
- Track1:

![image](https://github.com/vietha712/CodeRace-CppPipeline/assets/113485058/7b7629de-2480-490c-92a6-3b1a43e5e698)
- Track2:

![image](https://github.com/vietha712/CodeRace-CppPipeline/assets/113485058/b8d647b2-62ce-4f6f-ae23-683884bb2a82)

### Run AFL for all track
Here, we have created two directories for input and output, and the results will also be recorded in a log file.
![image](https://github.com/vietha712/CodeRace-CppPipeline/assets/113485058/911a7aa5-6039-4fb6-b7ea-aad6de5f5138)

Here is the result:
![image](https://github.com/vietha712/CodeRace-CppPipeline/assets/113485058/5ae20ef7-f6da-4e29-aa47-e05d884ea0dd)

- Because of the syntax errors due to the files haven't fixed yet
- So we cannot get the best result for fuzzing testing
- The program was stopped 
  



