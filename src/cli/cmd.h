#ifndef CMD_H
#define CMD_H

#include "cmd/val.h"

enum proctal_cmd_execute_format {
	PROCTAL_CMD_EXECUTE_FORMAT_ASSEMBLY,
	PROCTAL_CMD_EXECUTE_FORMAT_BYTECODE,
};

struct proctal_cmd_read_arg {
	int pid;

	void *address;

	// Number of values expected to read.
	size_t array;

	proctal_cmd_val_attr value_attr;

	// Whether to additionally print the instruction's address.
	int show_instruction_address;

	// Whether to additionally print the byte code of the instruction.
	int show_instruction_byte_code;
};

struct proctal_cmd_write_arg {
	int pid;

	void *address;

	// Number of values expected to write.
	size_t array;

	// Points to the first element of the list of values.
	proctal_cmd_val *first_value;
	// Points to the address after the last element of the list of values.
	proctal_cmd_val *end_value;

	// Whether to write the same value repeatedly until the program is told
	// to shut down.
	int repeat;
	// A delay in milliseconds before writing to the address again. Without
	// a delay you could theoretically turn your CPU into a heater.
	int repeat_delay;
};

struct proctal_cmd_search_arg {
	int pid;

	proctal_cmd_val_attr value_attr;

	// Whether we're going to read from stdin.
	int input;

	// Whether to perform an equality check.
	int eq;
	proctal_cmd_val eq_value;

	// Whether to perform a not equals check.
	int ne;
	proctal_cmd_val ne_value;

	// Whether to perform greather than.
	int gt;
	proctal_cmd_val gt_value;

	// Whether to perform greather than equals.
	int gte;
	proctal_cmd_val gte_value;

	// Whether to perform less than.
	int lt;
	proctal_cmd_val lt_value;

	// Whether to perform less than equals.
	int lte;
	proctal_cmd_val lte_value;

	// Whether to check if it was incremented.
	int inc;
	proctal_cmd_val inc_value;

	// Whether to check if it was incremented up to and including value.
	int inc_up_to;
	proctal_cmd_val inc_up_to_value;

	// Whether to check if it was decremented.
	int dec;
	proctal_cmd_val dec_value;

	// Whether to check if it was decremented up to and including value.
	int dec_up_to;
	proctal_cmd_val dec_up_to_value;

	// Whether to check if it was changed.
	int changed;

	// Whether to check if it was unchanged.
	int unchanged;

	// Whether to check if it was increased.
	int increased;

	// Whether to check if it was decreased.
	int decreased;
};

struct proctal_cmd_freeze_arg {
	int pid;

	// Whether to quit when no more input is available.
	int input;
};

struct proctal_cmd_watch_arg {
	int pid;

	void *address;

	// Whether to watch for reads.
	int read;

	// Whether to watch for writes.
	int write;

	// Whether to watch for instruction execution.
	int execute;
};

struct proctal_cmd_execute_arg {
	int pid;

	// What format we're expecting the input to be.
	enum proctal_cmd_execute_format format;
};

int proctal_cmd_read(struct proctal_cmd_read_arg *arg);

int proctal_cmd_write(struct proctal_cmd_write_arg *arg);

int proctal_cmd_search(struct proctal_cmd_search_arg *arg);

int proctal_cmd_freeze(struct proctal_cmd_freeze_arg *arg);

int proctal_cmd_watch(struct proctal_cmd_watch_arg *arg);

int proctal_cmd_execute(struct proctal_cmd_execute_arg *arg);

#endif /* CMD_H */
