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
