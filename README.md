Project 2: Virtual Memory Manager 
---

### Components
* VM Manager Class
* main.cpp

### Functionality
* VM Manager is capable of initializing the PM, load the page from the disk when a page fault occurs and translate the virtual address into a physical one and write it to the output file.
* The program takes in three positional arguments :
  1) The path to the initialization file
  2) The path to the input file
  3) The path to the output file

### Use CLion for development
* Open or clone the repo as a CLion project
* Reload the CMake project
* Edit the configuration for the target "vmm"
  * In the program arguments add: "../input/init.txt" "../input/input.txt" "../output/output.txt"
  * To test dp and no-dp input modify the init, input and output txt file name accordingly

### Other
* From the project root directory execute the bash script by enter the command ``./run.sh`` to run the sample input
* To test dp and no-dp input use the corresponding bash script ``./run_dp.sh`` ``./run_no_dp.sh``
* The script would automatically create the build and output directory and generate the output.txt in the output folder.
