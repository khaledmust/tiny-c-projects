# A NATO Phonetics Converter

I have developed a basic C program designed to read input from a file, parse it, and generate output using NATO phonetics.

This program, while straightforward, offers valuable insights into several essential C functions.

To begin, our program will include an array that holds all the NATO phonetics strings.

``` c
  /* NATO Phonetics. */
  const char *nato[] = {
      "Alfa",   "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
      "Hotel",  "India",   "Juliett", "Kilo",   "Lima",   "Mike",    "November",
      "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
      "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};
```

Then this is what we want to do:

We intend to allow the user to provide the file name as an argument when running the program. To ensure this, we'll implement a check. If the user doesn't supply an input file, we'll gracefully exit the program and present them with an error message. To accomplish this, we will make use of the standard input arguments passed to the main function. If the count of arguments is less than 2, we will display an error message printed on the standard error stream and terminate the program. You might wonder why we're checking for a count of 2. This is because the first argument passed is always a pointer to a character array containing the program's name, and the second one is the pointer to the input file we aim to process.

``` c
   if (argc < 2) {
      fprintf(stderr, "Please enter the name of your file.\n");
      return (1);
  }
```

Next, we need to open the file in read-only mode, as we don't intend to make any modifications to it. We achieve this by using the fopen() function, which provides us with a pointer to a FILE object. It's a good coding practice to always verify the state of a pointer before using it. If the pointer has a value of NULL, it's essential to notify the user and terminate the program.

``` c
FILE *user_file;
user_file = fopen(argv[1], "r");

if (user_file == NULL) {
    fprintf(stderr, "Error!, couldn't open the file.\n");
    return (1);
}
```

Subsequently, we aim to parse the input file. This parsing operation is carried out using the fgetc() function, which reads and returns each character in the input file. It's important to note that fgetc() returns an integer representing the parsed character.

Following this, we want to examine if the parsed character is an alphabetic character. If it is, we transform the letter into its uppercase form. Why do we make this conversion? This is done to obtain the index for the NATO phonetics array by subtracting the character 'A' which corresponds to the integer 65.

Finally, we print out the NATO phonetics.

The final code

```c
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  /* NATO Phonetics. */
  const char *nato[] = {
      "Alfa",   "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
      "Hotel",  "India",   "Juliett", "Kilo",   "Lima",   "Mike",    "November",
      "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
      "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};

  FILE *user_file;
  int character;

  if (argc < 2) {
      fprintf(stderr, "Please enter the name of your file.\n");
      return (1);
  }

  /* Open the input file in read-only mode. */
  user_file = fopen(argv[1], "r");

  if (user_file == NULL) {
      fprintf(stderr, "Error!, couldn't open the supplied file.\n");
      return (1);
  } else {
      while ((character = fgetc(user_file)) != EOF) {
          if (isalpha(character)) {
              character = toupper(character);
              printf("%s\n", nato[character - 'A']);
          }
              }
  }
}
```

## Usage

``` shell
gcc ./main.c inputFile.txt -o output
```

## Output

Such that the input text file contains the following string "Testing".

``` text
Tango
Echo
Sierra
Tango
India
November
Golf 
```

