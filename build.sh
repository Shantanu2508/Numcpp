#!/bin/bash

# Set variables
SOURCE="src/numcpp.cpp"
HEADER_DIR="inc"
OUTPUT_DIR="build"
EXECUTABLE="program"


# Create build folder if it does not exist
if [ ! -d "$OUTPUT_DIR" ]; then
   mkdir $OUTPUT_DIR
   echo "Created build directory..."
fi


#Compile source file
g++ -o $OUTPUT_DIR/$EXECUTABLE $SOURCE -I$HEADER_DIR 2> build_errors.log

# Check if build was succesfull
if [ $? -eq 0 ]; then
   echo "Build successful! Executable created $OUTPUT_DIR/$EXECUTABLE"
else
  echo "Build failed"
  cat build_errors.log
fi
