/**
 * This program takes as command-line arguments a series of encodings, transforms
 * these encodings, and prints the transformed values to standard output.
 *
 * Example arguments: c48 c65 c6c c6c c6f c2c c20 l49d50000 c21 c0a
 *
 * Author: Isabella Breuhl
 * Date: 09-12-2024
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convert_character(char string[]);
void convert_big_endian(char string[]);
void convert_little_endian(char string[]);
void bad_input();

int main(int argc, char* argv[]) {
	int i;
	int rc;
	char type = 'a';

	/* Checking for ill-formed input */
	for (i = 1; i < argc; i++) {
                rc = sscanf(argv[i], "%c", &type);

		if (rc != 1 || rc == 0) {
			bad_input();
                } else if (type != 'c' && type != 'b' && type != 'l') {
                        bad_input();
                } else if (type == 'b' && strlen(&argv[i][1]) !=8) {
			bad_input();
		} else if (type == 'l' && strlen(&argv[i][1]) !=8) {
                        bad_input();
		} else if (type == 'c' && strlen(&argv[i][1]) != 2) {
			bad_input();
		}
        }

	for (i = 1; i < argc; i++) {
		rc = sscanf(argv[i], "%c", &type);

		if (rc != 1 || rc == 0) {
                        bad_input();
                } else if (type == 'c') {
			convert_character(&argv[i][1]);
		} else if (type == 'b') {
			convert_big_endian(&argv[i][1]);
		} else {
			convert_little_endian(&argv[i][1]);
		}
	}

	return 0;
}

/* Given a hexadecimal digit, converts it and prints its associated ASCII */
void convert_character(char string[]) {
	int hex;
	int rc;
	rc = sscanf(string, "%x", &hex);

	if (rc != 1 || rc == 0) {
        	bad_input();
        }

	printf("%c", (char)hex);
}

/* Given eight big-endian hexadecimal digits, converts and prints it as a decimal */
void convert_big_endian(char string[]) {
	unsigned int endian;
	int rc;
	rc = sscanf(string, "%x", &endian);

	if (rc != 1 || rc == 0) {
                bad_input();
        }

	printf("%d", endian);
}

/* Given eight little-endian hexadecimal digits, converts and prints it as a decimal */
void convert_little_endian(char string[]) {
	unsigned int endian;
	int rc;
	rc = sscanf(string, "%x", &endian);

	if (rc != 1 || rc == 0) {
                bad_input();
        }

	endian = (((endian & 0xff) << 24) |
		  ((endian & 0xff00) << 8) |
		  ((endian & 0xff0000) >> 8) |
		  ((endian & 0xff000000) >> 24));
	printf("%d", endian);
}

/* Handling ill-formed input */
void bad_input() {
	fprintf(stderr, "bad input\n");
        exit(1);
}
