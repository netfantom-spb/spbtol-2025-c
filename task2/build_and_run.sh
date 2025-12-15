#/bin/bash
# gcc -o generate-data.o generate-data.c && \
# ./generate-data.o && \
gcc -o task.o task.c -lm &&
./task.o