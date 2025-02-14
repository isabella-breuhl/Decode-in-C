# Decode-in-C
C program that takes as command-line arguments a series of encodings, transforms these encodings, and prints the transformed values to standard output.

# Arguments
An argument of the form cNM, where N and M are hex digits represents an American Standard Code for Information Interchange (ASCII) character. Your program must transform these values into the corresponding ASCII character before printing that character.

An argument of the form bN, where N is a number represented by eight big-endian hexadecimal digits, must be printed as a signed decimal number.

An argument of the form lN, where N is a number represented by eight little-endian hexadecimal digits, must be printed as a signed decimal number.

# Example input/output
Input: c48 c65 c6c c6c c6f c2c c20 l49d50000 c21 c0a
Output: Hello, 54601!
