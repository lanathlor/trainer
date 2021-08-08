#ifndef MY_H_
	#define MY_H_

	#include <stdlib.h> // size_t

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
	void	*my_memcpy(void *dest, void *src, size_t size); // memcpy
	void 	*my_memcmp(void *ptr1, void *ptr2, size_t len); // like strcmp but with void *
	void 	*my_memncmp(void *ptr1, void *ptr2, size_t len, size_t nb);

	/*
		recursive
	*/

	/*
		advance char * function
	*/
	char	*my_realloc(char *str, char c); // reallocat the string with c concat in it. must prevent memory leak. return the new addresss

	/*
		char ** function
	*/
	//bad formated tab is not of yours responsabilites to handle but to create.
	char	**alloc_tab(size_t size, size_t len); // allocate an array in a rectangulare form where size is the height and len the width. make it viable
	char	**free_tab(char **tab); // free a array.
	int	my_tablen(char **tab); // return the len of the array
	int	my_puttab(char **tab); // print the array with \n betwee line. return the number of printed char
	int	fill_tab(char **tab, char c);
	char	**my_tabcpy(char **dest, char **src);
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
	int	my_dump_ptr(void *ptr, size_t size); // dump the memory with space between the value.
	void	*my_ptr_find(void *ptr, void *find, size_t size, size_t len); // find a corresponding value in the memory space pointed by ptr
	void	*my_ptr_cat(void *ptr, void *add, size_t size); // add the value pointed by add at the end of the space memory of ptr
	void	*my_ptr_dup(void *ptr, size_t size); // dup ptr memory
	void	*my_ptr_realloc(void *ptr, size_t size, size_t bytes); // realloc memory, padding of n bytes.
	void 	*my_ptr_delete(void *ptr, void *place, size_t size); // delete the value poited at the place after ptr and rearange memory space.
	void	*my_ptr_emplace(void *ptr, void *add, void *place, size_t size, size_t len); /* emplace add in ptr where place point. place is always inside the range of ptr. Size is the size of ptr, len is the size of add. Move bytes in ptr so they are not overwirten. You should realloc*/


	/*
		kind of advance functions
	*/
	int	write_file(char *str, int fd); // write to a fd
	int	my_srand(int seed); // prepare the rand function with a seed
	int	my_rand(void); // return a computer generated random number and set things up for the next on. static
	char	*gnl(int fd); // read the fd until a \n or a \0 is hit

	/*
		really advanced function. do not try this at home
	*/
	void	*xml_parser_create(char *file); // open an xml file and return all the data
	void	*xml_parser_find(void *data, char *tag, char *value); // get the first element that matche the value for the tag
	char	**xml_parser_explode(void *elem); // explode (by copy) the elem as a char ** with [0] as the tag and [1] as the corresponding value
	char	*xml_parser_getValue(void *elem, char *tag); // return the value of a tag in a specified elem
	int	xml_parser_save(void *data, char *file); // save the xml data in a file. handle indent

	/*
		linked list
	*/
	typedef struct		link_list_s {
		void	*mem;
		void	*next;
	}			link_list_t;

	link_list_t 	*link_init(size_t len);
	void		link_free(link_list_t *list);
	link_list_t	link_dup(link_list_t *list);
	void		link_apply(link_list_t *list, void (*pf)(void *data));
	void 		link_append(link_list_t *list, void *data);
	link_list_t 	*link_find(link_list_t *list, void *data, int (*cmp)());
	int		link_delete_node(link_list_t **list, void *data, int (*cmp)());
	int		link_concat(link_list_t *dest, link_list_t *src);
	link_list_t 	*link_sort(link_list_t **list, void *data, int (*cmp)());
	int		link_add_in_sorted(link_list_t **list, void *data, int (*cmp)());
	int		link_merge(link_list_t **dest, link_list_t *src, int (*cmp)());


	/*
		map
		learn to encapsulate. advance programming methode
		always sorted
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
	t_map_node	map_emplace(void *map, void *key);
	int		*map_delete(void *map, void *key);
	int		map_len(void *map);
	void		*map_cpy(void *map);
	void		*map_dup(void *map);
	int		map_apply(void *map, void (*pf)(void *data));

#endif
