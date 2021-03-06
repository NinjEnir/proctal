#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lib/proctal.h"

void proctal_region_new(proctal p)
{
	proctal_impl_region_new(p);
}

long proctal_region_mask(proctal p)
{
	return p->region.mask;
}

void proctal_region_set_mask(proctal p, long mask)
{
	p->region.mask = mask;
}

int proctal_region_read(proctal p)
{
	return p->region.read;
}

void proctal_region_set_read(proctal p, int read)
{
	p->region.read = read != 0;
}

int proctal_region_write(proctal p)
{
	return p->region.write;
}

void proctal_region_set_write(proctal p, int write)
{
	p->region.write = write != 0;
}

int proctal_region_execute(proctal p)
{
	return p->region.execute;
}

void proctal_region_set_execute(proctal p, int execute)
{
	p->region.execute = execute != 0;
}

int proctal_region(proctal p, void **start, void **end)
{
	return proctal_impl_region(p, start, end);
}
