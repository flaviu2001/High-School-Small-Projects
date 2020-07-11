#include "common.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

void add(Node *&node, string code, char init_value, int pos = 0)
{
	if (node == nullptr)
		node = new Node;
	if (pos == (int)code.length()){
		node->code = init_value;
		return;
	}
	if (code[pos] == '0')
		add(node->left, code, init_value, pos+1);
	else add(node->right, code, init_value, pos+1);
}

int main(int argc, char **argv)
{
	if (argc != 3){
		cerr << "Needs two arguments.\n";
		exit(1);
	}
	int read_descriptor = open(argv[1], O_RDONLY); ropen_check(read_descriptor);
	int codes_size;
	read_check(read(read_descriptor, &codes_size, sizeof(int)), 1);
	Node *root = nullptr;	//Don't forget to dealloc it
	for (int i = 0; i < codes_size; ++i){
		char code, bits;
		read_check(read(read_descriptor, &code, sizeof(char)), 2);
		read_check(read(read_descriptor, &bits, sizeof(char)), 3);
		string s;
		int need_bytes = (bits+7)/8;
		char array[need_bytes];
		read_check(read(read_descriptor, array, need_bytes*sizeof(char)), 4);
		int pos_array = 0, pos = 0;
		for (int i = 0; i < bits; ++i){
			if (array[pos_array] & (1<<pos))
				s += "1";
			else s += "0";
			++pos;
			if (pos == 8*sizeof(char)){
				pos = 0;
				++pos_array;
			}
		}
		reverse(s.begin(), s.end());
		add(root, s, code);
	}
	int write_descriptor = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644); wopen_check(write_descriptor);
	long long byte_size;
	read_check(read(read_descriptor, &byte_size, sizeof(long long)), 5);
	char c[buffer_size], bitbuffer[buffer_size];
	for (int i = 0; i < buffer_size; ++i)
		c[i] = 0;
	int pos_c = 0;
	long long overall = 0;
	Node *where = root;
	while(overall < byte_size){
		int bytes_read = read(read_descriptor, bitbuffer, buffer_size*sizeof(char)); read_check(bytes_read, 6);
		for (int i = 0; i < bytes_read && overall < byte_size; ++i){
			for (int j = 0; j < (int)(8*sizeof(char)) && overall < byte_size; ++j){
				if (bitbuffer[i] & (1<<j))
					where = where->right;
				else where = where->left;
				++overall;
				if (where->left == nullptr && where->right == nullptr){
					c[pos_c++] = where->code;
					if (pos_c == buffer_size){
						pos_c = 0;
						write_check(write(write_descriptor, c, buffer_size*sizeof(char)), 1);
					}
					where = root;
				}
			}

		}
		if (bytes_read < buffer_size)
			break;
	}
	write_check(write(write_descriptor, c, pos_c*sizeof(char)), 2, true);
	dealloc(root);
	close(read_descriptor);
	close(write_descriptor);
	return 0;
}