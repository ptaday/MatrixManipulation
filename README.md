# MatrixManipulation

This repository contains the implementation of a program to perform matrices computations, including matrix addition, multiplication, and transpose. The program reads scripts containing mathematical expressions involving matrices and evaluates these expressions to produce results.

## Table of Contents

- [Mathematical Preliminaries](#mathematical-preliminaries)
- [Script Format](#script-format)
- [Data Structures](#data-structures)
- [Functions Implemented](#functions-implemented)
- [Usage](#usage)
- [Contributing](#contributing)
- [Testing](#testing)
- [License](#license)
- [Contact](#contact)

## Mathematical Preliminaries

Matrices are rectangular arrays of numbers used in various fields, including mathematics, physics, and computer science. This program supports basic matrix operations: addition, multiplication, and transpose.

## Script Format

The program reads scripts containing two types of lines:
1. Matrix definition: Defines a new matrix using values or a formula.
2. Formula evaluation: Performs operations on matrices using expressions.

## Data Structures

The program uses two primary data structures:
- `matrix_sf`: Represents a matrix of integers, including its name, dimensions, and values.
- `bst_sf`: Represents a binary search tree to store matrix names and pointers.

## Functions Implemented

The following functions are implemented in this program:
- `add_mats_sf`: Performs matrix addition.
- `mult_mats_sf`: Performs matrix multiplication.
- `transpose_mat_sf`: Computes the transpose of a matrix.
- `create_matrix_sf`: Parses and creates a matrix from a string.
- `insert_bst_sf`: Inserts a matrix into a binary search tree.
- `find_bst_sf`: Searches for a matrix in the binary search tree.
- `free_bst_sf`: Frees memory associated with the binary search tree.
- `infix2postfix_sf`: Converts an infix expression to postfix notation.
- `evaluate_expr_sf`: Evaluates a matrix expression and returns the result.
- `execute_script_sf`: Executes a script and returns the final matrix result.
  
## Usage

To use this implementation of the WolfPack network protocol:

1. Include the necessary headers from the `include` directory.
2. Implement the provided functions in your code to work with above stated function descriptions.
3. Utilize the functions description to compute the matrix manipulations.

Ensure that you handle error cases, follow the guidelines outlined in the assignment description, and use the functions as intended.

## Contributing

Contributions to this project are welcome. If you find any issues or improvements, please submit a pull request. Follow the provided guidelines for contributing and ensure that your code adheres to the coding standards.

## Testing 

- The provided unit tests (written using Criterion) help verify the correctness of your implementation.
- Test your code with both computational tests and Valgrind tests for memory errors.
- Use the provided make commands to compile, test, and check test coverage.

git add .
git commit -am " any message here"
git push origin

## License

This project is licensed under the [MIT License](LICENSE).

## Contact

For any inquiries or feedback, please contact:
- Pushkar Taday
- Email: pmtaday@gmail.com
- GitHub: ptaday
