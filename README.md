# Simple Blockchain Implementation in C++

## Overview

This project is a basic implementation of a blockchain in C++ to demonstrate the fundamental principles of blockchain technology. It includes features such as block creation, chain verification, block alteration, and chain hacking to restore integrity. The project uses SHA-256 hashing for securing block data, ensuring the immutability of the blockchain.

## Features

1. **Block Creation:**
   - Each block contains data, a reference to the previous block's hash, and its own hash.
   - The hash is computed using SHA-256 and includes the block's data and the previous block's hash.

2. **Adding Blocks:**
   - New blocks can be added to the blockchain by providing the data for the block.
   - The new block’s hash is computed based on its data and the previous block's hash.

3. **Blockchain Verification:**
   - The integrity of the entire blockchain can be verified by ensuring that each block's previous hash matches the hash of the preceding block.

4. **Altering Blocks:**
   - Specific blocks in the blockchain can be altered, demonstrating how changes affect the chain’s integrity.
   - The altered block is rehashed, and subsequent blocks must be updated to maintain chain integrity.

5. **Hacking the Chain:**
   - The blockchain can be "hacked" to restore integrity after a block alteration.
   - This involves rehashing all subsequent blocks to ensure that each block's previous hash matches the hash of the preceding block.

6. **Printing Blockchain:**
   - The entire blockchain can be printed to the console, displaying each block's data, previous hash, and current hash.

## Components

- **Block Class:**
  - Represents a single block in the blockchain.
  - Contains methods for computing the block’s hash and printing block details.

- **Blockchain Class:**
  - Manages a chain of blocks.
  - Provides methods for adding blocks, verifying the chain, altering blocks, hacking the chain, and printing all blocks.

## Dependencies

- **OpenSSL:**
  - Used for SHA-256 hashing.
  - Ensure that OpenSSL is installed and properly linked with your C++ compiler.

## How to Run

1. **Compile the Code:**
   Use a C++ compiler with OpenSSL support to compile the code.
   ```sh
   g++ -o blockchain blockchain.cpp -lssl -lcrypto
