#ifndef MY_H_
	#define MY_H_

	#include <stdlib.h> // size_t

	/*
		int basic functions
	*/
	int	square(int nb); // return the square of nb (x²). -1 on error
	int 	my_pow(int nb, int pow); // return nb^pow. -1 on error
	int	square_root(int nb); // return the square root of nb. -1 on error
	int	is_prime(int nb); // return 1 if nb is a prime number. 0 otherwise

	/*
		char basic functions
	*/
	int	is_alpha(char c); // return 1 if c is alphanumericale. 0 otherwise. man ascii
	int	my_putchar(char c); // print c. man write(2)
	char	my_readchar(int fd); // read a char from a file descriptor. man read(2)
	char	low_case(char c); // return c to low case. return c in error case
	char	up_case(char c); // return c to upper case. return c in error case

	/*
		char * basic functions
	*/
	int	my_strlen(char *str); // return the number of char in str. 0 otherwise
	int	my_putstr(char *str); // print str on return the number of char printed. -1 on error
	char	*my_strcpy(char *dest, char *src); // copt src in dest. the string need to be allocated before hand. return null on error
	char	*my_strdup(char *src); // return src in a new address space. return null on error
	char	*my_strcat(char *dest, char *src); // concat src in dest. dest may have to be extend. return null on error (from here, if not specified, function returning pointer may return null on error)
	int	my_strcmp(char *s1, char *s2); // return 0 if the two string are the same. 1 or -1 in other case.
	int	my_strncmp(char *s1, char *s2, size_t nb); // same but only test for the nb first char
	int	my_find(char *str, char c); // search for c in str and return the index of the first occurence. return -1 if not found
	char	*my_revstr(char *str); // return str reversed in a new space area
	void 	my_rev_this_str(char *str); // reverse str in his own memory space

	/*
		advance int functions
	*/
	int	my_putnbr(int nb); // print nb and return the number of char printed
	int	my_getnbr(char *str); // convert str to an int and return it

	/*
		basic pointer managment
	*/
	void	my_swap(int *nb1, int *nb2); // swap the two falue
	void	my_mem_fill(void *mem, char c, size_t size); // fill the memory poited by mem with the c value to size
	void	*my_memcpy(void *dest, void *src, size_t size); // like strcpy but with void *
	void 	*my_memcmp(void *ptr1, void *ptr2, size_t len); // like strcmp but with void *
	void 	*my_memncmp(void *ptr1, void *ptr2, size_t len, size_t nb); // i think you get it

	/*
		recursive
	*/
	int	my_pow_rec(int base, int pow); // calculate base^pow. must be recursive
	int	facto(int nb); // calculate nb!. must be recursive

	/*
		advance char * function
	*/
	char	*my_hashstr(char *str, size_t start, size_t end); // return the string from the start index to the end index in a new memory space. return null on error
	int	my_strindex(char *str, char *find); // return the index of the first occurence of on of the char in find
	char	*my_realloc(char *str, char c); // reallocat the string with c concat in it. must prevent memory leak. return the new addresss

	/*
		char ** function
	*/
	//bad formated tab is not of yours responsabilites to handle but to create.
	char	**alloc_tab(size_t size, size_t len); // allocate an array in a rectangulare form where size is the height and len the width. make it viable
	char	**free_tab(char **tab); // free a array.
	int	my_tablen(char **tab); // return the len of the array
	int	my_puttab(char **tab); // print the array with \n betwee line. return the number of printed char
	int	fill_tab(char **tab, char c); // fill the table of c char.
	char	**my_tabcpy(char **dest, char **src); // from here think a little by yourself. the test will guide you if needed
	char	**my_tabdup(char **src);
	char	**my_tabfind(char **tab, char *find);
	char	**my_tabrealloc(char **tab, char *str);
	char	**my_strtowordtab(char *str); // cut the string in a new line in an array at each non alphanumericale char. return null on error
	char	**my_split(char *str, char *split); // same but split only when a char from split is encountered

	/*
		advance ptr managment
	*/
	// size is needed to know the size of value poitned by the void *. the len is needed as there may be no null pointer at the end of the array. bad place is not of your responsability
	void	*my_memmove(void *dest, void *src, size_t size); // move the src memory to dest but store it in a temporary space as the pointer may be overlaping
	int	my_dump_ptr(void *ptr, size_t size, size_t len); // dump the memory with space between the value.
	void	*my_ptr_find(void *ptr, void *find, size_t size, size_t len); // find a corresponding value in the memory space poited by ptr
	void	*my_ptr_realloc(void *ptr, void *add, size_t size, size_t len); // add the value pointed by add at the end of the space memory of ptr
	void	*my_ptr_add(void *ptr, void *add, size_t place, size_t size); // add the value pointed by add at the place after memory poited by ptr
	void 	*my_ptr_delete(void *ptr, size_t place, size_t size); // delete the value poited at the place after ptr and rearange memory space.

	/*
		error managment
	*/
	char	*my_perror(void); // define and declare my_errno in this file (*.h) as a gobal and use it in my_perror to return it
	void	my_seterror(char *error); // set my_errno to the error value
	char 	*my_puterror(char *error); // dont use my_errno internaly. print the error on stderr.
	void	my_exit(char *error); // dont use my_errno internaly. print the error on stderr and abort
	void	my_abort(char *error); // dont use my_errno internaly. print the error on stderr and abort
	void	my_errornb(int nb); // dont use my_errno internaly. print the nb on stderr.

	/*
		kind of advance functions
	*/
	char	*gnl(int fd); // read the fd until a \n or a \0 is hit
	int	write_file(char *str, int fd); // write to a fd
	int	my_srand(int seed); // prepare the rand function with a seed
	int	my_rand(void); // return a computer generated random number and set things up for the next on. static
	int 	my_tabsort(char **tab); // sort the table by len of string (asc). in case of same len sort it by difference of first differing char
	int 	my_intsort(int *tab); // same but for int

	/*
		really advanced function. do not try this at home
	*/
	int 	my_bc(char *equation); // resolve some equation like 3 * (4 + 5)

	/*
		linked list
	*/
	typedef struct		s_link_list{
		void	*mem;
		void	*next;
	}			t_link_list;

	t_link_list 	*link_init(size_t len);
	void		link_free(t_link_list *list);
	int 		link_fill(t_link_list *list, void *fill); // weak, use link_fillcpy
	int		link_fillcpy(t_link_list *list, void *fill, size_t size);
	int		link_find(t_link_list *list, void *find, size_t size);
	t_link_list	*link_get_node(t_link_list *list, size_t pos);
	t_link_list	*link_add_node(t_link_list *list, void *add, size_t pos, size_t size);
	t_link_list	*link_del_node(t_link_list *list, size_t pos);
	t_link_list 	*store_first(t_link_list *node); // static
	int		link_dump(t_link_list *list, size_t size);
	t_link_list 	*link_cpy(t_link_list *list); // weak. use link_dup
	t_link_list	*link_dup(t_link_list *list, size_t size);


	/*
		map
		learn to encapsulate. advance programming methode
	*/

	typedef struct		s_map_node{
		void *key;
		void *mem;
	}			t_map_node;

	typedef struct 		s_map{
		t_map_node *map;
		size_t key_size;
		size_t mem_size;
		size_t len;
		size_t own_size;
	}			t_map;

	typedef void 	* my_map;

	void		*map_create(size_t key_size, size_t mem_size, size_t len);
	void		map_free(void *map);
	void 		*map_find(void *map, void *key);
	t_map_node	map_get_node(void *map, void *key);
	int		*map_delete(void *map, void *key);
	int		map_len(void *map);
	void		*map_cpy(void *map); // do it like link_dup. weak ptr management is bad

	/*
		binary tree
		free to implement
	*/

	typedef struct		s_bin_tree{

	}			t_bin_tree;

#endif