# Professional Skills Coursework 1

This repository contains the first coursework for the Professional Skills course. The main file in this coursework is `gs.cpp`, a C++ program that simulates the Gray-Scott model, a reaction-diffusion system.

## File Analysis: `gs.cpp`

The `gs.cpp` file is a C++ program that simulates a reaction-diffusion system using the Gray-Scott model. The Gray-Scott model is a mathematical model that simulates the interaction of two chemical substances, U and V, under specific conditions.

### Program Structure

The program is structured into several parts:

1. **Global Variables and Constants**: The program starts by defining several global variables and constants that control the simulation parameters, such as the grid size, diffusion rates, feed rate, kill rate, and time step.

2. **Grid Initialization**: The `init()` function initializes the U and V grids. The U grid is initialized to 1.0 everywhere, while the V grid is initialized to 0.0 everywhere except for a rectangular region in the middle, where it is initialized to a random value between 0.0 and 1.0.

3. **VTK File Writing**: The `writeVTKFile()` function writes the current state of the V grid to a VTK file. This allows the simulation results to be visualized using a VTK viewer.

4. **Simulation Step**: The `simulateStep()` function performs one time step of the simulation. It calculates the next state of the U and V grids based on the current state and the Gray-Scott model equations.

5. **Threshold Counting**: The `countElementsAboveThreshold()` function counts the number of elements in the V grid that are above a certain threshold. This is used to measure the progress of the reaction.

6. **Main Function**: The `main()` function controls the overall flow of the program. It initializes the grids, then enters a loop where it performs a simulation step and periodically writes the V grid to a VTK file. After the simulation is complete, it counts the number of elements in the V grid that are above a certain threshold and prints this value.

### Usage

The program takes five command-line arguments: the diffusion rates of U and V, the feed rate, the kill rate, and the threshold for counting elements in the V grid. It prints the progress of the simulation to the console and writes the state of the V grid to a VTK file every 1000 iterations.

`./gs.cpp <Du> <Dv> <F> <k> <threshold>`

### Output

The program outputs a series of VTK files that can be visualized using a VTK viewer. It also prints the proportion of elements in the V grid that are above the threshold at the end of the simulation.

### Building the Application Locally

To build this application locally, you need to follow these steps:

1. Ensure that you have a C++ compiler installed on your system. This program requires a compiler that supports at least the C++11 standard.

2. Install the Boost library. You can download it from the Boost official website and follow their instructions for installation.

3. Clone the repository or download the source code.

4. Navigate to the directory containing the source code.

5. Compile the program using the following command:

`g++ -std=c++11 -o gs gs.cpp`

6. Run the program with the following command:

`./gs <Du> <Dv> <F> <k> <threshold>`

Replace <Du>, <Dv>, <F>, <k>, and <threshold> with your desired values.

### Explanation of the Verification Code

1. **Check that the type of the model parameters (F, k) matches that of the element type of the u and v vectors.**
This check is done using the Boost library's type checking functions. It ensures that the types of the model parameters F and k are the same as the type of the elements in the u and v vectors. This is important for the calculations in the simulation to work correctly.

2. **Check that the variables u and v are the same size.**
This check ensures that the u and v vectors, which represent the concentrations of the two chemicals in the simulation, are the same size. This is necessary for the simulation to work correctly, as the calculations involve element-wise operations on the u and v vectors.

3. **Check that the simulation produces the mathematically correct answer when u = 0 and v = 0.**
This check resets the u and v vectors to 0 and runs the simulation for one step. It then checks that the resulting values of u and v are still 0. This is a basic sanity check to ensure that the simulation is working correctly. If u and v are both 0, then according to the Gray-Scott model equations, they should remain 0 after one simulation step.