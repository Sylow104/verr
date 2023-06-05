#pragma once
#include <stdint.h>
#include <stddef.h>

enum packet_element_e
{
	NONE,
	BYTE,
	SHORT,
	INT,
	LONG,
	FLOAT,
	STRING,
	BIN
};

struct packet_buffer_u;
struct packet_element_u;

class packet_c
{
	public:
	packet_c(uint32_t op, uint64_t id, size_t block_n);
	packet_c(uint32_t op, uint64_t id);
	~packet_c();

	template<typename T> int add_simple(enum packet_element_e type, 
		T to_add)
	{
		return add(type, &to_add, sizeof(T));
	};

	int add_binstr(enum packet_element_e type,
		void *to_add, size_t len)
	{
		return add(type, to_add, len);
	};
	int add_leb128(enum packet_element_e type, 
		void *to_add, size_t len);

	protected:

	private:
	int add(enum packet_element_e type, void *addr, size_t len);
	enum packet_element_e next();
	enum packet_element_e type();

	struct packet_buffer_u *buffer;
	struct packet_element_u *cur;
};

/*
struct packet_u;

struct packet_u *packet_new(uint32_t op, uint64_t id, size_t block_n);
int packet_destroy(struct packet_u *to_destroy);

int packet_add_c(struct packet_u *to_add, char *c);
int packet_add_s(struct packet_u *to_add, short *s);
int packet_add_i(struct packet_u *to_add, int *i);
int packet_add_d(struct packet_u *to_add, double *d);
int packet_add_bin(struct packet_u *to_add, void *c, size_t len);
int packet_add_str(struct packet_u *to_add, char *c, size_t len);
int packet_add_leb128(struct packet_u *to_add, char *c, size_t len);

enum packet_element_e packet_cur_type(struct packet_u *cur);
size_t packet_cur_size(struct packet_u *cur);
char *packet_val_c(struct packet_u *cur);
short *packet_val_s(struct packet_u *cur);
int *packet_val_i(struct packet_u *cur);
double *packet_val_d(struct packet_u *cur);
void *packet_val_bin(struct packet_u *cur, size_t *size_ret);
char *packet_val_str(struct packet_u *cur, size_t *size_ret);
enum packet_element_e packet_next(struct packet_u *cur);
*/