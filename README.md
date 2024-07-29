# Secure-Object-Chain : Simple Blockchain Implementation in C++
Overview
This project implements a basic blockchain in C++ to demonstrate the core principles behind blockchain technology. It includes functionalities for adding blocks, verifying the integrity of the blockchain, altering blocks, and hacking the chain to restore integrity. The project uses SHA-256 hashing for securing block data and ensuring the immutability of the blockchain.


Features
    Block Creation:
        Each block contains data, a reference to the previous block's hash, and its own hash. The hash is computed using SHA-256 and includes the block's data and the previous block's hash.

    Adding Blocks:
        New blocks can be added to the blockchain by providing the data for the block.The new block’s hash is computed based on its data and the previous block's hash.

    Blockchain Verification:
        The integrity of the entire blockchain can be verified by ensuring that each block's previous hash matches the hash of the preceding block.

    Altering Blocks:
        Specific blocks in the blockchain can be altered, demonstrating how changes affect the chain’s integrity. The altered block is rehashed, and subsequent blocks must be updated to maintain chain integrity.

    Hacking the Chain:
        The blockchain can be "hacked" to restore integrity after a block alteration. This involves rehashing all subsequent blocks to ensure that each block's previous hash matches the hash of the preceding block.

    Printing Blockchain:
        The entire blockchain can be printed to the console, displaying each block's data, previous hash, and current hash.


Components:

    Block Class:
        Represents a single block in the blockchain. Contains methods for computing the block’s hash and printing block details.

    Blockchain Class:
        Manages a chain of blocks. Provides methods for adding blocks, verifying the chain, altering blocks, hacking the chain, and printing all blocks.

    Main Function:  

        The main function provides a command-line interface for interacting with the blockchain. Users can add new blocks, verify the blockchain, alter specific blocks, hack the chain, and print all blocks.


Dependencies:
    OpenSSL:
        Used for SHA-256 hashing.
        Ensure that OpenSSL is installed and properly linked with your C++ compiler.

How to Run:

    Compile the Code:
        Use a C++ compiler with OpenSSL support to compile the code.
        Prefer to use linux based system.

     ```   g++ -o blockchain blockchain.cpp -lssl -lcrypto 

Interact with the Blockchain:
Follow the on-screen prompts to add blocks, verify the chain, alter blocks, hack the chain, and print the blockchain.