This repository contains an implementation of the Simplex Method for solving linear programming problems, written in C. The program calculates the optimal solution to a linear optimization problem given constraints and an objective function.

**Features :**

1. Solves linear programming problems in standard form.

2. Handles multiple variables and constraints.

3. Provides the optimal solution and the maximum value of the objective function.

4. Detects unbounded problems and displays appropriate warnings.

**How to Use :**

1. Clone the Repository
        
        git clone https://github.com/yourusername/simplex-method-c.git
        cd simplex-method-c
                
2. Compile the Program
        
        gcc simplex.c -o simplex
                
3. Run the Program
        
        ./simplex
                
4. Input Format
   
   - Enter the number of variables in the objective function.
   - Enter the number of constraints.
   - Provide:
     - Coefficients of the objective function.
     - Coefficients and constants for the constraints.

**Code Overview :**

1. simplex(): Core function implementing the Simplex algorithm.
2. main(): Handles user input and invokes the simplex() function.
        
**Limitations :**

   Only works with problems in standard form (all constraints are ≤).
   Assumes input data is valid.
        
**Contributing :**

   Contributions are welcome! Feel free to fork the repository, make improvements, and submit a pull request.

**License :**

   This project is licensed under the MIT License. See the LICENSE file for more details.
