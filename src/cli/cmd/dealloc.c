#include <proctal.h>

#include "cmd.h"

int proctal_cmd_dealloc(struct proctal_cmd_dealloc_arg *arg)
{
	proctal p = proctal_create();

	switch (proctal_error(p)) {
	case 0:
		break;

	case PROCTAL_ERROR_OUT_OF_MEMORY:
		fprintf(stderr, "Out of memory.\n");
		proctal_destroy(p);
		return 1;

	default:
		fprintf(stderr, "Unable to create an instance of Proctal.\n");
		proctal_destroy(p);
		return 1;
	}

	proctal_set_pid(p, arg->pid);

	proctal_dealloc(p, arg->address);

	switch (proctal_error(p)) {
	case 0:
		break;

	case PROCTAL_ERROR_UNIMPLEMENTED:
		fprintf(stderr, "Not implemented.\n");
		proctal_destroy(p);
		return 1;

	case PROCTAL_ERROR_PERMISSION_DENIED:
		fprintf(stderr, "Permission denied.\n");
		proctal_destroy(p);
		return 1;

	case PROCTAL_ERROR_PROCESS_NOT_FOUND:
		fprintf(stderr, "Process not found.\n");
		proctal_destroy(p);
		return 1;

	default:
		fprintf(stderr, "Failed to cleanup properly.\n");
		proctal_destroy(p);
		return 1;
	}

	proctal_destroy(p);

	return 0;
}
