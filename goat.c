#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include "goat.h"

int width = 0, height = 0;

static void clear_screen() {
	printf("\e[1;1H\e[2J");
}

static void get_dimensions() {
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);

	width = w.ws_col;
	height = w.ws_row;
}

static void center(char *str) {
	int left = 0;
	size_t length = 0;

	length = strlen(str);

	left = (int)((width - length) / 2);

	printf("%*s%s\n", left, " ", str);
}

static int resize(char *str, int size, int indent, int first) {
	int rc = 0, start = 0, end = 0, count = 0;
	size_t length = 0;
	char *line = NULL;

	line = malloc(sizeof(char) * (size + 1));

	if (!line) {
		rc = 1;
		goto cleanup;
	}

	length = strlen(str);
	start = 0;

	while (start < (int)length) {
		end = start + size;

		while (str[end] != ' ') {
			end--;
		}

		end++;

		strncpy(line, str + start, (size_t)(end - start));
		line[end - start] = '\0';

		printf("%*s%s\n", count == 0 ? first : indent, " ", line);

		start = end;
		count++;
	}

cleanup:
	if (line) {
		free(line);
	}

	return rc;
}

static int display_question(int index, char preset) {
	int rc = 0, i = 0, l = 0;
	int skill = 0, skill_index = 0, answer_index = 0;
	size_t line_size = 1;
	char answer = '0';
	char *line = NULL;

	line = malloc(sizeof(char) * 2);

	if (!line) {
		rc = 1;
		goto cleanup;
	}

	strcpy(line, "0");
	answer = line[0];

	while (answer < '1' || answer > '4' || strlen(line) != 2) {
		question question = questions[index];

		clear_screen();

		center("Generalized Occupational Aptitude Test");
		printf("Question %d:\n\n", index + 1);

		if (resize(question.text, width - 4, 2, 2) != 0) {
			rc = 1;
			goto cleanup;
		}

		printf("\n");

		for (i = 0, l = COUNT_CHOICES; i < l; i++) {
			printf("  [%d]", i + 1);

			if (resize(question.choices[i].text, width - 8, 6, 1) != 0) {
				rc = 1;
				goto cleanup;
			}
		}

		printf("\nAnswer [1-%d]: ", COUNT_CHOICES);

		if (preset >= '1' && preset <= '4') {
			sprintf(line, "%c\n", preset);
			answer = preset;
		} else {
			getline(&line, &line_size, stdin);
			answer = line[0];
		}

		answer_index = (int)answer - 49;
		skill = question.choices[answer_index].skill;

		for (i = 0, l = COUNT_OCCUPATIONS; i < l; i++) {
			skill_index = 0;

			if (skill & occupations[i].skill) {
				if (skill != 0) {
					while (skill != 0) {
						skill_index++;
						skill = skill >> 1;
					}
				}

				skill_index--;
				occupations[skill_index].count++;
			}
		}
	}

cleanup:
	if (line) {
		free(line);
	}

	return rc;
}

static int display_result() {
	int rc = 0, occupation = 0, i = 0, l = 0;

	for (i = 0, l = COUNT_OCCUPATIONS; i < l; i++) {
		if (occupations[i].count > occupations[occupation].count) {
			occupation = i;
		}
	}

	clear_screen();

	center("Generalized Occupational Aptitude Test");
	printf("Result:\n\n");

	if (resize(occupations[occupation].title, width - 4, 2, 2) != 0) {
		rc = 1;
		goto cleanup;
	}

	printf("\n");

	if (resize(occupations[occupation].description, width - 4, 2, 2) != 0) {
		rc = 1;
		goto cleanup;
	}

cleanup:
	return rc;
}

static void usage(char *exec) {
	int length = 0;

	length = (int)strlen(exec) + 7;

	printf("Usage: %s [-c,--cheatsheet <answers>]\n", exec);
	printf("%*s [-h,--help]\n", length, " ");
}

int main(int argc, char *argv[]) {
	int rc = 0, i = 0, l = 0;
	size_t cheatsheet_length = 0;
	char preset = '0';
	char *exec = NULL, *action = NULL, *cheatsheet = NULL;

	exec = argv[0];

	if (argc > 1) {
		action = argv[1];

		if (strcmp(action, "-c") == 0 || strcmp(action, "--cheatsheet") == 0) {
			if (argc > 2) {
				cheatsheet = argv[2];
				cheatsheet_length = strlen(cheatsheet);
			} else {
				printf("Cheatsheet missing\n");

				rc = 1;
				goto cleanup;
			}
		} else if (strcmp(action, "-h") == 0 || strcmp(action, "--help") == 0) {
			usage(exec);

			rc = 1;
			goto cleanup;
		} else {
			printf("Unknown action %s\n", action);

			rc = 1;
			goto cleanup;
		}
	}

	get_dimensions();

	for (i = 0, l = COUNT_QUESTIONS; i < l; i++) {
		if (cheatsheet_length != 0 && (int)cheatsheet_length >= i) {
			preset = cheatsheet[i];
		} else {
			preset = '0';
		}

		if (display_question(i, preset) != 0) {
			rc = 1;
			goto cleanup;
		}
	}

	if (display_result() != 0) {
		rc = 1;
		goto cleanup;
	}

cleanup:
	return rc;
}