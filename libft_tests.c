#include "libft.h"

void	printtab(int *tab, int size)
{
	int	pos;

	printf("[ ");
	pos = 0;
	while (pos < size)
	{
		printf("%i ", tab[pos]);
		pos++;
	}
	printf("]");
}

void	printmem(void *s, int size)
{
	int		pos;
	char	*s2;

	pos = 0;
	s2 = (char *)s;
	printf("<");
	while (pos < size)
	{
		printf("%i-", s2[pos]);
		pos++;
	}
	printf(">");
}

void	printparts(char **tab)
{
	int	pos;

	printf("[ ");
	pos = 0;
	while (tab[pos])
	{
		printf("%s ", tab[pos]);
		pos++;
	}
	printf("]");
}

char	_toupper(unsigned int n, char c)
{
	(void)n;
	if (c < 123 && c >= 97)
		return (c - 32);
	else
		return (c);
}

void	_toupperat(unsigned int n, char *c)
{
	(void)n;
	if (*c < 123 && *c >= 97)
		*c = *c - 32;
}

char	_toupper_even(unsigned int n, char c)
{
	if (n % 2 == 0 && c < 123 && c >= 97)
		return (c - 32);
	else
		return (c);
}

void	_tolowerat_even(unsigned int n, char *c)
{
	if (n % 2 == 0 && *c < 91 && *c >= 65)
		*c = *c + 32;
}

// Fonctions de tests pour les listes chainees

void	display_elem(t_list *elem)
{
	if (elem)
		printf("[addr %p : data = %s, next = %p]\n", elem, (char *)elem->content, elem->next);
	else
		printf("\n");
}

void	display_list(t_list *elem)
{
	if (elem)
	{
		display_elem(elem);
		display_list(elem->next);
	}
	else 
		printf("-End of list\n");
}

void	free_content(void *content)
{
	printf("Freeing NOT REALLY : %s\n", (char *)content);
}

void	free_content_duplicate(void *content)
{
	printf("Freeing REALLY : %s\n", (char *)content);
	free(content);
}


void	str_toupperat(void *s)
{
	char	*s2;

	s2 = (char *) s;
	while (*s2)
	{
		if (*s2 < 123 && *s2 >= 97)
			*s2 = *s2 - 32;
		s2++;
	}
}

void	str_toupperat_even(void *s)
{
	char	*s2;
	int		ind;

	s2 = (char *) s;
	ind = 0;
	while (s2[ind])
	{
		if (ind % 2 == 0 && s2[ind] < 123 && s2[ind] >= 97)
			s2[ind] = s2[ind] - 32;
		ind++;
	}
}

void	*ft_strdup_upper(void *src2)
{
	char	*dup;
	char	*src;
	int		len_src;
	int		pos;

	len_src = 0;
	src = (char *) src2;
	while (src[len_src] != '\0')
		len_src++;
	dup = malloc((len_src + 1) * sizeof(char));
	if (!dup)
		return ((char *) 0);
	pos = 0;
	while (pos < len_src)
	{
		dup[pos] = src[pos];
		if (dup[pos] < 123 && dup[pos] >= 97)
			dup[pos] = dup[pos] - 32;
		pos++;
	}
	dup[len_src] = '\0';
	return ((void *) dup);
}

t_list	*ft_lstat(t_list *lst, int ind)
{
	if (lst)
	{
		if (ind == 0)
			return (lst);
		else
		{
			if (lst->next)
				return (ft_lstat(lst->next, ind - 1));
			else
				return (NULL);
		}
	}
	else
		return (NULL);
}

// INSTRUCTIONS DE TEST :
//  - pas d'arguments
//  - pas besoin de valgrind, aucune fonction ne doit liberer quelque chose
int	main(int ac, char **av)
{
	char	s1[100];
	char	s2[100];
	char	c;
	int		i;

	(void)ac;
	(void)av;
	printf("\033[1;31m=== TESTS ON LIBFT FUNCTIONS ===\033[0m\n\n");
	
	// Character category
	printf("\n\033[1;32m--- Character category ---\033[0m\n\n");
	strcpy(s1, "Aa9- \0o");
	i = 0;
	while (i < 7)
	{
		c = s1[i];
		if (i == 6)
			c = -10;
		printf("character '%c',%i is alnum : %i\n", c, c, ft_isalnum(c));
		printf("character '%c',%i is alpha : %i\n", c, c, ft_isalpha(c));
		printf("character '%c',%i is ascii : %i\n", c, c, ft_isascii(c));
		printf("character '%c',%i is digit : %i\n", c, c, ft_isdigit(c));
		printf("character '%c',%i is print : %i\n", c, c, ft_isprint(c));
		i++;
	}

	// Case change
	printf("\n\033[1;32m--- Case change ---\033[0m\n\n");
	strcpy(s1, "Aa9- \0o");
	i = 0;
	while (i < 7)
	{
		c = s1[i];
		if (i == 6)
			c = -10;
		printf("[\033[1mft_toupper\033[0m] character '%c',%i uppered -> '%c',%i\n", c, c, ft_toupper(c), ft_toupper(c));
		printf("[\033[1mft_tolower\033[0m] character '%c',%i lowered -> '%c',%i\n", c, c, ft_tolower(c), ft_tolower(c));
		i++;
	}

	// Print
	printf("\n\033[1;32m--- Print ---\033[0m\n\n");
	printf("=> Printing on file descriptor 1\n");
	printf("[\033[1mft_putchar_fd\033[0m] Printing 'A' :\n");
	ft_putchar_fd('A', 1);
	printf("\n[\033[1mft_putstr_fd\033[0m] Printing nothing :\n");
	ft_putstr_fd("", 1);
	printf("\n[\033[1mft_putstr_fd\033[0m] Printing 'abcdefghij' :\n");
	ft_putstr_fd("abcdefghij", 1);
	printf("\n[\033[1mft_putendl_fd\033[0m] Printing nothing :\n");
	ft_putendl_fd("", 1);
	printf("\n[\033[1mft_putendl_fd\033[0m] Printing 'abcdefghij' :\n");
	ft_putendl_fd("abcdefghij", 1);
	int		tabput[6] = {0, 1, 111, -111, 2147483647, -2147483648};
	i = 0;
	while (i < 6)
	{
		printf("\n[\033[1mft_putnbr_fd\033[0m] Printing %i with ft_putnbr_fd :\n", tabput[i]);
		ft_putnbr_fd(tabput[i], 1);
		i++;
	}

	printf("\n=> Printing on other file descriptors, 2 (error) and 3 (opened file) :\n");
	printf("Creating a file 'f' for fd-3, command line should redirect errors to an error file.\n");
	printf("[\033[1mft_putendl_fd\033[0m] File 'f' should contain the alphabet with a newline\n");
	printf("[\033[1mft_putnbr_fd\033[0m] Error file should contain INT MIN without a newline\n");
	int fd = open("f", O_WRONLY | O_CREAT);
	ft_putendl_fd("abcdefghijklmnopqrstuvwxyz", fd);
	close(fd);
	ft_putnbr_fd(-2147483648, 2);

	// String and memory search
	printf("\n\n\033[1;32m--- String and memory search ---\033[0m\n\n");
	strcpy(s1, "");
	printf("[\033[1mft_strlen\033[0m] length of string '%s' : %i\n", s1, (int)ft_strlen(s1));
	strcpy(s1, "caracteres");
	printf("[\033[1mft_strlen\033[0m] length of string '%s' : %i\n", s1, (int)ft_strlen(s1));

	printf("[\033[1mft_strncmp\033[0m] Result of comparison between 'abc' and 'abc' with n = 3: %i, expected %i\n", ft_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3));
	printf("[\033[1mft_strncmp\033[0m] Result of comparison between 'abc' and 'abd' with n = 3: %i, expected %i\n", ft_strncmp("abc", "abd", 3), strncmp("abc", "abd", 3));
	printf("[\033[1mft_strncmp\033[0m] Result of comparison between 'abc' and 'abd' with n = 2: %i, expected %i\n", ft_strncmp("abc", "abd", 2), strncmp("abc", "abd", 2));
	printf("[\033[1mft_strncmp\033[0m] Result of comparison between 'ab' and 'abc' with n = 3: %i, expected %i\n", ft_strncmp("ab", "abc", 3), strncmp("ab", "abc", 3));
	printf("[\033[1mft_strncmp\033[0m] Result of comparison between 'ab' and 'abc' with n = 2: %i, expected %i\n", ft_strncmp("ab", "abc", 1), strncmp("ab", "abc", 1));
	printf("[\033[1mft_strncmp\033[0m] Result of comparison between 'a' and 'b' with n = 0: %i, expected %i\n", ft_strncmp("a", "b", 0), strncmp("a", "b", 0));
	printf("[\033[1mft_strncmp\033[0m] Result of comparison between '' and 'abc' with n = 2: %i, expected %i\n", ft_strncmp("", "abc", 2), strncmp("", "abc", 2));
	printf("[\033[1mft_strncmp\033[0m] Result of comparison between 'abc' and '' with n = 2: %i, expected %i\n", ft_strncmp("abc", "", 2), strncmp("abc", "", 2));
	printf("[\033[1mft_strncmp\033[0m] Result of comparison between '' and '' with n = 2: %i, expected %i\n", ft_strncmp("", "", 2), strncmp("", "", 2));
	printf("[\033[1mft_strncmp\033[0m] Result of comparison between 'abc' and 'abd' with n = -1: %i, expected %i\n", ft_strncmp("abc", "abd", -1), strncmp("abc", "abd", -1));
	printf("[\033[1mft_strncmp\033[0m] Result of comparison between 'a' and 'b' with n = -3: %i, expected %i\n", ft_strncmp("a", "b", -3), strncmp("a", "b", -3));

	strcpy(s1, "abcdef");
	strcpy(s2, "abcdef");
	printf("[\033[1mft_memcmp\033[0m] Result of comparison between strings %s and %s with n = 6: %i\n", s1, s2, ft_memcmp(s1, s2, 6));
	strcpy(s1, "aqcdef");
	strcpy(s2, "abcdef");
	printf("[\033[1mft_memcmp\033[0m] Result of comparison between strings %s and %s with n = 6: %i\n", s1, s2, ft_memcmp(s1, s2, 6));
	int	tabcmp1[4] = {8, 5, 4, 9};
	int	tabcmp2[4] = {8, 5, 1, 9};
	printf("[\033[1mft_memcmp\033[0m] Result of comparison between tables (below) with n = 2: %i\n", ft_memcmp(tabcmp1, tabcmp2, 2 * sizeof(int)));
	printf("[\033[1mft_memcmp\033[0m] Result of comparison between tables (below) with n = 4: %i\n", ft_memcmp(tabcmp1, tabcmp2, 4 * sizeof(int)));
	printtab(tabcmp1, 4);
	printtab(tabcmp2, 4);
	printf("\n");

	strcpy(s1, "Botte|de|foin");
	strcpy(s2, "");
	printf("[\033[1mft_strchr\033[0m] Result of search for '|' in string '%s' : %s\n", s1, ft_strchr(s1, '|'));
	printf("[\033[1mft_strchr\033[0m] Result of search for '|' in string '%s' : %s\n", s2, ft_strchr(s2, '|'));
	printf("[\033[1mft_strchr\033[0m] Result of search for end-of-string in string '%s' : address %p, expected %p\n", s1, ft_strchr(s1, '\0'), strchr(s1, '\0'));
	printf("[\033[1mft_strrchr\033[0m] Result of search for '|' in string '%s' : %s\n", s1, ft_strrchr(s1, '|'));
	printf("[\033[1mft_strrchr\033[0m] Result of search for '|' in string '%s' : %s\n", s2, ft_strrchr(s2, '|'));
	printf("[\033[1mft_strrchr\033[0m] Result of search for end-of-string in string '%s' : address %p, expected %p\n", s1, ft_strrchr(s1, '\0'), strrchr(s1, '\0'));
	printf("[\033[1mft_strrchr\033[0m] Result of search for ('B' - 100) in string '%s' : address %p, expected %p\n", s1, ft_strrchr(s1, 'B' - 100), strrchr(s1, 'B' - 100));
	printf("[\033[1mft_strrchr\033[0m] Result of search for ('t' - 256) in string '%s' : address %p, expected %p\n", s1, ft_strrchr(s1, 't' - 256), strrchr(s1, 't' - 256));

	printf("[\033[1mft_memchr\033[0m] Result of search for '|' in string '%s' with n = 10 : %s\n", s1, (char *)ft_memchr(s1, '|', 10));
	printf("[\033[1mft_memchr\033[0m] Result of search for '|' in string '%s' with n = 5 : %s\n", s1, (char *)ft_memchr(s1, '|', 5));
	int	tabchr[5] = {0, 1, 2, 3, 4};
	printf("[\033[1mft_memchr\033[0m] Result of search for 65 (char, 1 byte) in int table (4 * 5 bytes) (below) with n = 5 :\n\t%p, expected %p\n",
		ft_memchr(tabchr, 65, 5 * sizeof(int)), memchr(tabchr, 65, 5 * sizeof(int)));
	printf("[\033[1mft_memchr\033[0m] Result of search for 3 (char, 1 byte) in int table (4 * 5 bytes) (below) with n = 3 :\n\t%p, expected %p\n",
		ft_memchr(tabchr, 3, 3 * sizeof(int)), memchr(tabchr, 3, 3 * sizeof(int)));
	printf("[\033[1mft_memchr\033[0m] Result of search for 3 (char, 1 byte) in int table (4 * 5 bytes) (below) with n = 5 :\n\t%p, expected %p\n",
		ft_memchr(tabchr, 3, 5 * sizeof(int)), memchr(tabchr, 3, 5 * sizeof(int)));
	printtab(tabchr, 5);
	printf("\n");

	strcpy(s1, "botte de foin un peu plus grosse un peu plus remplie");
	printf("Search tests on string '%s' of size %lu\n", s1, strlen(s1));
	printf("[\033[1mft_strnstr\033[0m] Result of search for target '%s' in string '%s' with n = 50: %s\n", "peu", s1, ft_strnstr(s1, "peu", 50));
	printf("[\033[1mft_strnstr\033[0m] Result of search for target '%s' in string '%s' with n = 8: %s\n", "peu", s1, ft_strnstr(s1, "peu", 8));
	printf("[\033[1mft_strnstr\033[0m] Result of search for target '%s' in string '%s' with n = 100: %s\n", "absent", s1, ft_strnstr(s1, "absent", 100));
	printf("[\033[1mft_strnstr\033[0m] Result of search for target '%s' in string '%s' with n = 100: %s\n", "remplie", s1, ft_strnstr(s1, "remplie", 100));
	printf("[\033[1mft_strnstr\033[0m] Result of search for target '%s' in string '%s' with n = 50: %s\n", "remplie", s1, ft_strnstr(s1, "remplie", 50));
	printf("[\033[1mft_strnstr\033[0m] Result of search for target '%s' in string '%s' with n = 50: %s\n", "", s1, ft_strnstr(s1, "", 50));
	printf("[\033[1mft_strnstr\033[0m] Result of search for target '%s' in string '%s' with n = 50: %s\n", "remplie", "", ft_strnstr("", "remplie", 50));

	// String and memory change
	printf("\n\033[1;32m--- String and memory change ---\033[0m\n\n");
	strcpy(s1, "abc");
	printf("String before lcopies : '%s'\n", s1);
	printf("[\033[1mft_strlcpy\033[0m] String after copying '%s' with size = %i : '%s', returned %i\n", "def", 4, s1, (int)ft_strlcpy(s1, "def", 4));
	strcpy(s1, "abc");
	printf("[\033[1mft_strlcpy\033[0m] String after copying '%s' with size = %i : '%s', returned %i\n", "def", 2, s1, (int)ft_strlcpy(s1, "def", 2));
	strcpy(s1, "abc");
	printf("[\033[1mft_strlcpy\033[0m] String after copying '%s' with size = %i : '%s', returned %i\n", "def", 1, s1, (int)ft_strlcpy(s1, "def", 1));
	strcpy(s1, "abc");
	printf("[\033[1mft_strlcpy\033[0m] String after copying '%s' with size = %i : '%s', returned %i\n", "def", 0, s1, (int)ft_strlcpy(s1, "def", 0));
	strcpy(s1, "abc");
	printf("[\033[1mft_strlcpy\033[0m] String after copying '%s' with size = %i : '%s', returned %i\n", "d", 4, s1, (int)ft_strlcpy(s1, "d", 4));
	strcpy(s1, "ABC");
	printf("String before lconcatenations : '%s'\n", s1);
	printf("[\033[1mft_strlcat\033[0m] String after cating '%s' with size = %i : '%s', returned %i\n", "def", 7, s1, (int)ft_strlcat(s1, "def", 7));
	strcpy(s1, "ABC");
	printf("[\033[1mft_strlcat\033[0m] String after cating '%s' with size = %i : '%s', returned %i\n", "def", 5, s1, (int)ft_strlcat(s1, "def", 5));
	strcpy(s1, "ABC");
	printf("[\033[1mft_strlcat\033[0m] String after cating '%s' with size = %i : '%s', returned %i\n", "def", 2, s1, (int)ft_strlcat(s1, "def", 2));
	strcpy(s1, "ABC");
	printf("[\033[1mft_strlcat\033[0m] String after cating '%s' with size = %i : '%s', returned %i\n", "", 7, s1, (int)ft_strlcat(s1, "", 7));

	strcpy(s1, "abcd-efgh-ijkl");
	printf("Memory before memory setting : ");
	printmem(s1, 14);
	ft_bzero(s1, 4);
	ft_memset(s1 + 5, 65, 4);
	printf("\n[\033[1mft_memset, ft_bzero\033[0m] Memory after applying bzero on first third and memset with char 'A' on second third : ");
	printmem(s1, 14);
	ft_bzero(s1 + 5, 0);
	ft_memset(s1, 65, 0);
	printf("\n[\033[1mft_memset, ft_bzero\033[0m] Memory after applying bzero and memset with n = 0 : ");
	printmem(s1, 14);

	int	tabmem1[5] = {0,200,400,600,800};
	int	tabmem2[5] = {100,300,500,700,900};
	printf("\nMemory (2 arrays of 5 ints each) before memory copying :\ntab1 ");
	printtab(tabmem1, 5);
	printmem(tabmem1, 5 * sizeof(int));
	printf("\ntab2 ");
	printtab(tabmem2, 5);
	printmem(tabmem2, 5 * sizeof(int));
	ft_memcpy(tabmem1, tabmem2, 2 * sizeof(int));
	printf("\n[\033[1mft_memcpy\033[0m] Memory of tab1 after copying tab2 into tab1 with size = 2 : ");
	printtab(tabmem1, 5);
	printmem(tabmem1, 5 * sizeof(int));
	ft_memcpy(tabmem1, tabmem2, 4 * sizeof(int));
	printf("\n[\033[1mft_memcpy\033[0m] Memory of tab1 after copying tab2 into tab1 with size = 4 : ");
	printtab(tabmem1, 5);
	printmem(tabmem1, 5 * sizeof(int));

	printf("\nMemory of tab2 before memory moving :\ntab2 ");
	printtab(tabmem2, 5);
	printmem(tabmem2, 5 * sizeof(int));
	ft_memmove(tabmem2, tabmem2 + 2, 3 * sizeof(int));
	printf("\n[\033[1mft_memmove\033[0m] Memory of tab1 after memmove with overlap : src is the last 3 ints of tab 2 : ");
	printtab(tabmem2, 5);
	printmem(tabmem2, 5 * sizeof(int));
	ft_memmove(tabmem2 + 3, tabmem2, 2 * sizeof(int));
	printf("\n[\033[1mft_memmove\033[0m] Memory of tab1 after memmove with overlap : src is the first 2 ints of tab 2 : ");
	printtab(tabmem2, 5);
	printmem(tabmem2, 5 * sizeof(int));
	ft_memmove(tabmem2, tabmem2, 5 * sizeof(int));
	printf("\n[\033[1mft_memmove\033[0m] Memory of tab1 after move with full overlap (should change nothing) : ");
	printtab(tabmem2, 5);
	printmem(tabmem2, 5 * sizeof(int));

	// Integer-string conversion
	printf("\n\n\033[1;32m--- Integer-string conversion ---\033[0m\n\n");
	printf("[\033[1mft_atoi\033[0m] Conversion of string '%s' : %i\n", "0", ft_atoi("0"));
	printf("[\033[1mft_atoi\033[0m] Conversion of string '%s' : %i\n", "   -1", ft_atoi("-1"));
	printf("[\033[1mft_atoi\033[0m] Conversion of string '%s' : %i\n", "   +-259173", ft_atoi("   +-259173"));
	printf("[\033[1mft_atoi\033[0m] Conversion of string '%s' : %i\n", " \t  +25917 3", ft_atoi(" \t  +25917 3"));
	printf("[\033[1mft_atoi\033[0m] Conversion of string '%s' : %i\n", "2147483647", ft_atoi("2147483647"));
	printf("[\033[1mft_atoi\033[0m] Conversion of string '%s' : %i\n", "-2147483648", ft_atoi("-2147483648"));
	printf("[\033[1mft_atoi\033[0m] Conversion of string '%s' : %i\n", "-2147483649", ft_atoi("-2147483649"));

	printf("[\033[1mft_itoa\033[0m] Conversion of integer %i : '%s'\n", 0, ft_itoa(0));
	printf("[\033[1mft_itoa\033[0m] Conversion of integer %i : '%s'\n", -1, ft_itoa(-1));
	printf("[\033[1mft_itoa\033[0m] Conversion of integer %i : '%s'\n", -729, ft_itoa(-729));
	printf("[\033[1mft_itoa\033[0m] Conversion of integer %i : '%s'\n", 2147483647, ft_itoa(2147483647));
	printf("[\033[1mft_itoa\033[0m] Conversion of integer %i : '%s'\n", atoi("-2147483648"), ft_itoa(-2147483648));

	// Memory allocation
	printf("\n\n\033[1;32m--- Memory allocation ---\033[0m\n\n");
	int	*res1;
	res1 = ft_calloc(5, sizeof(int));
	res1[4] = 2000;
	printf("[\033[1mft_calloc\033[0m] Memory of a tab of 5 ints allocated with calloc at address %p,\n\tand with last int set to 2000 : ", res1);
	printtab(res1, 5);
	printmem(res1, 5 * sizeof(int));
	res1 = ft_calloc(1000000000, sizeof(int));
	printf("\n[\033[1mft_calloc\033[0m] Address of a tab of 1 billion ints allocated with calloc (should be null) : %p\n", res1);

	strcpy(s1, "xyz");
	char *sdup1 = ft_strdup(s1);
	printf("[\033[1mft_strdup\033[0m] Result of duplicating string '%s' : '%s'\n", s1, sdup1);
	sdup1[0] = '!';
	printf("\tafter modification of first character on the duplicate of '%s' : '%s'\n", s1, sdup1);
	strcpy(s1, "");
	sdup1 = ft_strdup(s1);
	printf("[\033[1mft_strdup\033[0m] Result of duplicating string '%s' : '%s'\n", s1, sdup1);

	strcpy(s1, "abcdefghijklmnopqrstuvwxyz");
	sdup1 = ft_substr(s1, 3, 5);
	printf("[\033[1mft_substr\033[0m] Result of replicating 5-char substring of '%s' starting at 3 : '%s'\n", s1, sdup1);
	sdup1[0] = '!';
	printf("\tafter modification of first character on the substring of '%s' : '%s'\n", s1, sdup1);
	sdup1 = ft_substr(s1, 0, 26);
	printf("[\033[1mft_substr\033[0m] Result of replicating 26-char substring of '%s' starting at 0 : '%s'\n", s1, sdup1);
	sdup1 = ft_substr(s1, 20, 10);
	printf("[\033[1mft_substr\033[0m] Result of replicating 10-char substring of '%s' starting at 20 : '%s'\n", s1, sdup1);
	sdup1 = ft_substr(s1, 30, 10);
	printf("[\033[1mft_substr\033[0m] Result of replicating 10-char substring of '%s' starting at 30 : '%s'\n", s1, sdup1);
	sdup1 = ft_substr(s1, 20, 0);
	printf("[\033[1mft_substr\033[0m] Result of replicating 0-char substring of '%s' starting at 20 : '%s'\n", s1, sdup1);
	sdup1 = ft_substr("tripouille", 100, 1);
	printf("[\033[1mft_substr\033[0m] Result of replicating 1-char substring of 'tripouille' starting at 100 : '%s'\n", sdup1);
	sdup1 = ft_substr("1", 42, 42000000);
	printf("[\033[1mft_substr\033[0m] Result of replicating 42000000-char substring of '1' starting at 42 : '%s'\n", sdup1);

	strcpy(s1, "abcccXBBYCCZbbbc");
	sdup1 = ft_strtrim(s1, "abc");
	printf("[\033[1mft_strtrim\033[0m] Result of trimming string '%s' with set 'abc' : '%s'\n", s1, sdup1);
	sdup1[0] = '!';
	printf("\tafter modification of first character of the trimmed string ('%s') : '%s'\n", s1, sdup1);
	sdup1 = ft_strtrim(s1, "");
	printf("[\033[1mft_strtrim\033[0m] Result of trimming string '%s' with set '' : '%s'\n", s1, sdup1);
	sdup1 = ft_strtrim(s1, "abX");
	printf("[\033[1mft_strtrim\033[0m] Result of trimming string '%s' with set 'abX' : '%s'\n", s1, sdup1);
	sdup1 = ft_strtrim(s1, "abcXYZ");
	printf("[\033[1mft_strtrim\033[0m] Result of trimming string '%s' with set 'abcXYZ' : '%s'\n", s1, sdup1);
	sdup1 = ft_strtrim(s1, "abcBCXYZ");
	printf("[\033[1mft_strtrim\033[0m] Result of trimming string '%s' with set 'abcBCXYZ' : '%s'\n", s1, sdup1);

	strcpy(s1, "botte|de||foin|des||separateurs");
	char	**parts = ft_split(s1, '|');
	printf("[\033[1mft_split\033[0m] Tokens received when splitting '%s' by '|' : ", s1);
	printparts(parts);
	sdup1 = ft_strjoin(parts[0], parts[1]);
	printf("\n[\033[1mft_strjoin\033[0m] String received when joining the first 2 of these tokens : '%s'\n", sdup1);
	parts = ft_split(s1, ' ');
	printf("[\033[1mft_split\033[0m] Tokens received when splitting '%s' by ' ' : ", s1);
	printparts(parts);
	strcpy(s1, "||||||||");
	parts = ft_split(s1, '|');
	printf("\n[\033[1mft_split\033[0m] Tokens received when splitting '%s' by '|' : ", s1);
	printparts(parts);
	sdup1 = ft_strjoin("", "abc");
	printf("\n[\033[1mft_strjoin\033[0m] String received when joining '' with 'abc' : '%s'\n", sdup1);

	// Application of functions by function pointers
	printf("\n\033[1;32m--- Application of functions by function pointers ---\033[0m\n\n");
	strcpy(s1, "abcdef ghijkl MNOPQR");
	sdup1 = ft_strmapi(s1, &_toupper);
	printf ("[\033[1mft_strmapi\033[0m] New string result of applying toupper to '%s' : '%s'\n", s1, sdup1);
	sdup1[0] = '!';
	printf("\tafter modification of first character of the new string ('%s') : '%s'\n", s1, sdup1);
	sdup1 = ft_strmapi(s1, &_toupper_even);
	printf ("[\033[1mft_strmapi\033[0m] New string result of applying toupper_even to '%s' : '%s'\n", s1, sdup1);

	ft_striteri(s1, &_toupperat);
	printf ("[\033[1mft_striteri\033[0m] Original string after applying toupperat : '%s'\n", s1);
	ft_striteri(s1, &_tolowerat_even);
	printf ("[\033[1mft_striteri\033[0m] Original string after applying tolowerat_even : '%s'\n", s1);

	if (ac >= 2)
	{
		t_list	*start_elem;
		t_list	*start_elem2;
		t_list	*new;
		t_list	*todel;
		int		ind;

		printf("\033[1;31m=== TESTS ON LIBFT BONUS FUNCTIONS ===\033[0m\n\n");

		// List build
		printf("\n\033[1;32m--- List building ---\033[0m\n\n");
		ind = 1;
		start_elem = NULL;
		while (ind < ac)
		{
			new = ft_lstnew(av[ind]);
			ft_lstadd_front(&start_elem, new);
			ind++;
		}
		printf("[ft_lstnew, ft_lstadd_front] -----> List built with add_front :\n");
		display_list(start_elem);

		ind = 1;
		start_elem2 = NULL;
		while (ind < ac)
		{
			new = ft_lstnew(av[ind]);
			ft_lstadd_back(&start_elem2, new);
			ind++;
		}
		printf("\n[ft_lstnew, ft_lstadd_back] -----> List built with add_back :\n");
		display_list(start_elem2);

		// List inspect
		printf("\n\033[1;32m--- List inspect ---\033[0m\n\n");
		printf("[ft_lstlast] Last element of list 1 : ");
		display_elem(ft_lstlast(start_elem));
		printf("[ft_lstlast] Last element of list 2 : ");
		display_elem(ft_lstlast(start_elem2));
		printf("[ft_lstsize] Size of list 1 : %i", ft_lstsize(start_elem));
		printf("\n[ft_lstsize] Size of list 2 : %i", ft_lstsize(start_elem2));

		// List deletion
		printf("\n\n\033[1;32m--- List deletion ---\033[0m\n\n");
		todel = ft_lstat(start_elem2, ac - 4);
		if (todel)
			ft_lstclear(&(todel->next), &free_content);
		printf("[ft_lstdelone, ft_lstclear] List 2 after deleting last 2 elements (if there are at least 3) :\n");
		display_list(start_elem2);
		ft_lstclear(&start_elem2, &free_content);
		printf("\n[ft_lstdelone, ft_lstclear] List 2 after deleting all remaining elements :\n");
		display_list(start_elem2);

		// List function mapping
		printf("\n\n\033[1;32m--- List function mapping ---\033[0m\n\n");
		start_elem2 = ft_lstmap(start_elem, &ft_strdup_upper, &free_content);
		printf("\n[ft_lstmap] Duplicate of list 1 after strdup_upper :\n");
		display_list(start_elem2);
		printf("\toriginal list 1 :\n");
		display_list(start_elem);
		ft_lstiter(start_elem, &str_toupperat_even);
		printf("[ft_lstiter] Original list 1 after iterating str_toupperat_even :\n");
		display_list(start_elem);

		ft_lstclear(&start_elem, &free_content);
		ft_lstclear(&start_elem2, &free_content_duplicate);
	}
}
