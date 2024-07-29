# SHA-256 Algorithm

## Overview

SHA-256 (Secure Hash Algorithm 256-bit) is a member of the SHA-2 (Secure Hash Algorithm 2) family of cryptographic hash functions. It is designed to securely encode data in a way that produces a fixed-size 256-bit (32-byte) hash value, irrespective of the input data size. SHA-256 is widely used in various security applications and protocols, including TLS and SSL, digital signatures, and cryptocurrencies like Bitcoin.

## How SHA-256 Works

### Steps:

1. **Preprocessing**:
   - **Padding**: The message is padded so that its length is congruent to 448 modulo 512, followed by a 64-bit representation of the message length.
   - **Parsing**: The padded message is parsed into 512-bit blocks.

2. **Initialization**:
   - **Set Initial Hash Values**: Eight 32-bit words are used as initial hash values. These words are derived from the fractional parts of the square roots of the first eight prime numbers.

3. **Hash Computation**:
   - **Message Schedule**: Each 512-bit block is expanded into 64 32-bit words.
   - **Compression Function**: For each block, the words are processed through 64 rounds of bitwise operations, logical functions, and modular additions. This involves constants derived from the first 32 bits of the fractional parts of the cube roots of the first 64 prime numbers.
   - **Update Hash Values**: The hash values are updated with the results from the compression function.

4. **Final Hash**:
   - After processing all blocks, the final hash value is produced by concatenating the eight hash values.

## Applications

### Blockchain Technology
- **Proof-of-Work (PoW)**: SHA-256 is crucial in Bitcoin's PoW consensus algorithm. Miners compete to find a hash below a certain target by varying a nonce. The enormous computational power required to find this nonce ensures the security of the blockchain.
- **Further Reading**: [Techopedia on SHA-256 in Blockchain](https://www.techopedia.com/what-is-sha-256/how-it-works-in-blockchain-cryptography)

### Digital Signatures
- SHA-256 is used to generate a hash of a message, which is then signed with a private key. This allows verification of the message's integrity without revealing its content.
- **Further Reading**: [Boot.dev blog on SHA-256](https://blog.boot.dev/cryptography/sha-256)

### Password Security
- User passwords are hashed using SHA-256 before storing them in databases. During login, the password is hashed again and compared to the stored hash. This protects passwords even if the database is compromised.

### File Integrity Verification
- SHA-256 is used to verify the integrity of files during transfer. A hash of the file is computed before and after the transfer to ensure it has not been altered.

### Digital Certificates
- SHA-256 is widely used in SSL/TLS certificates to create secure connections between web servers and browsers.

## Security
SHA-256 is considered highly secure and is currently resistant to all known practical attacks. However, as with any cryptographic algorithm, it is theoretically vulnerable to advances in computational power, such as quantum computing.

*Credit: [Wikipedia](https://en.wikipedia.org/wiki/SHA-2)*

## Resources

- [NIST SHA-3 Standard](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.202.pdf)
- [RFC 6234 - US Secure Hash Algorithms](https://tools.ietf.org/html/rfc6234)
- [SHA-3 Algorithm Explained](https://keccak.team/keccak.html)
- [NIST Computer Security Resource Center - Hash Functions](https://csrc.nist.gov/projects/hash-functions)

## Disclaimer

This implementation is for educational purposes only. For production use, please refer to well-audited cryptographic libraries.