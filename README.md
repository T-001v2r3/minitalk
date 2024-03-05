# 42 Minitalk

Welcome to 42 Minitalk! This project challenges you to create a simple client-server application using inter-process communication (IPC) signals in C. The goal is to implement a basic form of communication between two processes, where one acts as the server and the other as the client.

## Table of Contents

1. [Introduction](#introduction)
2. [Getting Started](#getting-started)
3. [Usage](#usage)
4. [Protocol](#protocol)
5. [Contributing](#contributing)
6. [License](#license)

## Introduction

The `minitalk` project requires you to implement a client and a server that can communicate with each other using signals. The client sends a string message to the server, and the server prints the received message.

## Getting Started

To get started with minitalk, simply clone this repository to your local machine:

```bash
git clone https://github.com/T-001v2r3/minitalk.git
```
Once you have the repository cloned, you can compile the server and client by running:
```bash
make # to build without bonus functions
make bonus # to build with bonus functions
make re # to re-build the project
```
If you want to delete the compiled files:

```bash
make clean # to clean up objects
make fclean # to clean up everything
```
This will generate the server and client executables, which you can then use for communication.
Usage

    Start the server in one terminal:

    ```bash
./server
```
In another terminal, start the client with the server's process ID and the message to send:

```bash
./client [server_pid] [message]
```
For example:

```bash
    ./client 12345 "Hello, server!"
```
    Replace [server_pid] with the actual process ID of the server.

## Protocol

The communication protocol involves the use of signals to transmit information between the client and the server. The details of the protocol are explained in the PROTOCOL.md file.
Contributing

Contributions to minitalk are welcome! If you have ideas for improvements, bug fixes, or additional features, feel free to open an issue or submit a pull request.

Before submitting a pull request, please make sure your code follows the 42 Norm coding style.

## License

This project is licensed under the terms of the MIT license.