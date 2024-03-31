# Parallel Computing of number Pi (π)
This repository contains the code for parallel computing of number Pi (π), using a unit circle in one dimesnion and OpenMP API. The numerical and theoretical aspects relating to this code are available in this [article](https://medium.com/@SourenAM/parallel-programming-the-art-of-multi-tasking-by-computers-90f7c3b9682e).\
Beware that you don't need to install OpenMP, it's a feature integrated into certain compilers you just need to ensure that the compiler you're using supports it. `gcc` supports it and you can call it using the flag `-fopenmp`. Just make sure you have `gcc` installed.\
To check if you have `gcc` installed, on ubuntu run
`--version gcc` on your terminal. This command will display the version of `gcc` installed on your system if it is installed. If `gcc` is not installed, you'll likely see a message indicating that the command was not found or that the package needs to be installed.\
If `gcc` is not installed and you want to install it, you can do so using the following command:\
```
sudo apt update
sudo apt install gcc
```

For running the scipt `pi.c` you need to run the following command line:

```
gcc -fopenmp -O3 pi.c -o pi -lm
```
`-O3` : This flag is an optimization level for the compiler. -O3 is a high level of optimization, which tells the compiler to apply a set of aggressive optimizations to your code in order to improve its performance. These optimizations can include loop unrolling, inlining of functions, and various other techniques aimed at making the resulting executable faster. However, it might increase compilation time and might not always be suitable for debugging, as it can make the executable harder to analyze.

`-lm`: This flag links the math library (`libm`). In `C` programming, many mathematical functions like `sin()`, `cos()`, `sqrt()`, etc., are provided by the math library. When you use these functions in your `C` code, you need to link your program against the math library to include the definitions of these functions in your executable. The `-lm` flag tells the linker to include the math library during the linking phase, ensuring that your program can use these mathematical functions.

After compiling using the above command then just run `./pi` in your terminal. The above instructions assume linux command line.
