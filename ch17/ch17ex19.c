/* ch17ex19.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void new_cmd(void);
void open_cmd(void);
void close_cmd(void);
void close_all_cmd(void);
void save_cmd(void);
void save_as_cmd(void);
void save_all_cmd(void);
void print_cmd(void);
void exit_cmd(void);

struct {
	char *cmd_name;
	void (*cmd_pointer)(void);
} file_cmd[] =
	{{"new",	new_cmd},
	 {"open",	open_cmd},
	 {"close",	close_cmd},
	 {"close all",	close_all_cmd},
	 {"save",	save_cmd},
	 {"save as",	save_as_cmd},
	 {"save all",	save_all_cmd},
	 {"print",	print_cmd},
	 {"exit",	exit_cmd}
	};

void run_cmd(char *cmd);

int main (void)
{

	char *cmd = "close";

	run_cmd(cmd);

	return 0;
}

void run_cmd(char *cmd)
{
	int i;

	for (i = 0; i <= 8; ++i) {
		printf("file_cmd[%d].cmd_name: %s\n", i, file_cmd[i].cmd_name);
		if (strcmp(cmd, file_cmd[i].cmd_name) == 0) {
			printf("cmd '%s' found.\n", cmd);
			file_cmd[i].cmd_pointer();
			break;
		} else
			printf("cmd '%s' not found.\n", cmd);
	}
}

void new_cmd(void)
{
	printf("This is new_cmd()\n");
}

void open_cmd(void)
{
	printf("This is open_cmd()\n");
}

void close_cmd(void)
{
	printf("This is close_cmd()\n");
}

void close_all_cmd(void)
{
	printf("This is close_all_cmd()\n");
}

void save_cmd(void)
{
	printf("This is save_cmd()\n");
}

void save_as_cmd(void)
{
	printf("This is save_as_cmd()\n");
}

void save_all_cmd(void)
{
	printf("This is save_all_cmd()\n");
}

void print_cmd(void)
{
	printf("This is print_cmd()\n");
}

void exit_cmd(void)
{
	printf("This is exit_cmd()\n");
}

