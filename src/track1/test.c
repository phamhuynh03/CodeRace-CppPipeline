#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "resetRegister.h"
#include "registerMonitor.h"
#include "register.c"

static const cyclic_ptr c_InitJob[] =
	{
		&configureRegister,
};

static const cyclic_ptr c_cylicJob[] =
	{
		&checkRegisterErr,
		&receiveDataHandling,
		&errorHandling,
		&resetHandling,
		&someTp,
};

void run_startup(void)
{
	unsigned int index = 0;
	/* Running starting Jobs */
	int numOfJob = sizeof(c_InitJob)/sizeof(cyclic_ptr);
	while (index != numOfJob)
	{
		c_InitJob[index]();
		index++;
	}
	return;
}

void run_cyclic(void)
{
	unsigned int index = 0;
	unsigned int numOfCyclicJob = sizeof(c_cylicJob)/sizeof(cyclic_ptr);
	/* Running cylic Jobs */
	while (index != numOfCyclicJob)
	{
		c_cylicJob[index]();
		index++;
	}

	return;
}

#define ARRAY_LENGTH 1000U
#define DEFAULT_VALUE 0xAAU
#define HEADER_SIZE sizeof(int)
#define GET_DATA_BUFFER(_buffer) (&_buffer[HEADER_SIZE])

int get_array_element(const char *array, int array_length, int index)
{
	if (index >= array_length)	// >=
	{
		printf("Out of bound access");
		return 0;
	}

	return array[index];
}

/** Allocate a buffer on heap, the first integer is used to store buffer size
 * @param[in]   size    Size of to be allocated buffer in bytes
 * @return Pointer to allocated buffer
 */
char *allocate_buffer(int size)
{
	char *buffer = (char *)malloc(size + HEADER_SIZE);
	if (buffer != NULL)
	{
	//	char *a = buffer;
		*((int *)buffer) = size;
		unsigned int i;
		buffer = buffer + HEADER_SIZE;
		for (i = 0; i < size ; i++)
		{
			buffer[i] = DEFAULT_VALUE;
		}
		return buffer;
	}
	else
		return NULL;
}

/** Deallocate a buffer previously allocated by @ref allocate_buffer
 * @param[in]   size    Size of to be allocated buffer in bytes
 * @return Pointer to allocated buffer
 */
void deallocate_buffer(char *buffer)
{

	/* Always clear allocated buffer to prevent sensitive data leakage */
	int buffer_size = *((int*)(buffer - HEADER_SIZE));
	int i;
	for (i = 0; i < buffer_size; i++)
	{
		buffer[i] = DEFAULT_VALUE;
	}
	free(buffer - HEADER_SIZE);
}

int main(void)
{
	char *array = allocate_buffer(ARRAY_LENGTH);
	int result = get_array_element(array, ARRAY_LENGTH, ARRAY_LENGTH);
	deallocate_buffer(array);
	/* running startup task*/
	run_startup();
	/* running cyclic task*/
	while (1)
	{
		run_cyclic();
	}

	return result;
}
