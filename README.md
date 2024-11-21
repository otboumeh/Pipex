# Pipex

## Overview

The **Pipex** project, part of the 42 curriculum, is designed to recreate the behavior of a Unix pipeline. It simulates how data flows through a series of programs connected by pipes. The main goal of the project is to implement a program that will execute multiple commands in a sequence, with the output of one command serving as the input for the next. The **bonus part** extends the functionality by adding more advanced features, such as handling heredocs.

---

## Features

- Recreates the behavior of Unix pipelines using `fork()`, `exec()`, and `pipe()`.
- Executes multiple commands connected by pipes in the proper sequence.
- **Bonus part**: Implements a heredoc feature, allowing the program to read from a user-defined input stream.

---

## Functions Implemented

### Core Functions

- `pipex`:  
  The main function that sets up the pipe, forks processes, and executes commands sequentially, passing the output of one command to the next through the pipe.

- `exec_command`:  
  Executes a command by calling `execve`, which replaces the current process with the new command.

- `setup_pipes`:  
  Sets up the pipes that connect the commands, allowing data to flow between them.

- `close_pipes`:  
  Closes the pipes after the commands are executed.

### Bonus Features

- **Heredoc Implementation**:  
  The bonus part allows handling heredoc functionality. Heredoc lets you pass input to a command before the program executes, and it is often used in shell scripting.

---

## How It Works

1. **Creating the Pipe:**  
   The `pipe()` system call is used to create a pipe. This allows data to flow from one command to another by writing to and reading from the pipe.

2. **Forking Processes:**  
   The `fork()` system call creates child processes for each command in the pipeline. Each child process executes a specific command using `execve()`.

3. **Executing Commands:**  
   The program executes commands by calling `execve()` in each child process. The output of the first command is passed through the pipe to the next command.

4. **Handling Heredoc (Bonus):**  
   The bonus part allows the program to process heredocs. Heredocs are used to provide input to a command directly from the terminal or from a file. This functionality is particularly useful when chaining commands that require special input.

5. **Closing Pipes:**  
   After each command is executed, the pipes are closed to prevent file descriptor leaks.

---

## Limitations

- The implementation does not handle certain edge cases, such as when a command fails or when the user provides incorrect input.
- The bonus part introduces additional complexity, especially with managing heredoc input.

---

## How to Use

1. **Compile the Program:**
   ```bash
   make
2. Run Pipex for Multiple Commands:
   ```bash
   ./pipex infile "cmd1 args" "cmd2 args" outfile
  - `infile`: Input file.
  - `cmd1 args`: First command with its arguments.
  - `cmd2 args`: Second command with its arguments.
  - `outfile`: Output file where the final result will be written.

3. Using Heredoc (Bonus):
   ```bash
    ./pipex here_doc LIMITER cmd1 args cmd2 args outfile
2.  *   `here_doc`: Flag to enable heredoc.
    *   `LIMITER`: The string used to terminate the heredoc input.
    *   The rest works the same as the standard pipex.

---

## Conclusion

The **Pipex** project is a practical exercise in process management, file descriptors, and inter-process communication in Unix-like systems. By implementing this project, you gain a deeper understanding of how pipelines and processes work in shell environments. The bonus part introduces a powerful feature (heredoc), which enhances the flexibility of the program by allowing dynamic input.

Completing this project strengthens the skills required for more advanced system programming tasks and prepares you for future challenges in the 42 curriculum.

