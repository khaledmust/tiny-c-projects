/**
 * Author: Khaled Mustafa
 * Created: 2023-10-19
 *
 * Description: This progrms takes a word or phrase from the user and output in
 * in the NATO phonetics.
 */

#include <ctype.h>
#include <stdio.h>

#define MAX_LENGTH 64

/**
 * main - Entry point of the program.
 *
 * Return: 0 on success.
 */
int main(void) {

  /* NATO Phonetics. */
  const char *nato[] = {
      "Alfa",   "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
      "Hotel",  "India",   "Juliett", "Kilo",   "Lima",   "Mike",    "November",
      "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
      "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};

  char user_input[MAX_LENGTH];
  char character;
  int i;

  /* Prompt user to enter their input. */
  printf("Enter your word or phrase: ");
  fgets(user_input, MAX_LENGTH, stdin);

  i = 0;

  while (user_input[i]) {
    character = toupper(user_input[i]);
    if (isalpha(character)) {
      printf("%s\n", nato[character - 'A']);
    }
    i++;

    if (i == MAX_LENGTH) {
      printf("Exceeded maximum input!\n");
      printf("Maximum input is 64 characters only.\n");
      break;
    }
  }

  return (0);
}
