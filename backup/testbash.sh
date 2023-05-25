    gcc ./src/track1/test.c -o test.out > compileGCCError.txt
    if [ $? -eq 0 ]; then
      echo "Compile successful."
    else
      echo "Compile failed. Check the file compileGCCError.txt for more information".