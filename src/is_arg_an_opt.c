#include "libft.h"

int		is_arg_an_opt(char **argv, int argi, const char *optstring,
						const struct option *longopts)
{
	size_t	len = ft_strlen(argv[argi]);
	if (len <= 1)
		return 0;
	//	Arg is exactly '--'
	if (argv[argi][0] == '-' && argv[argi][1] == '-'
		&& len == 2)
		return 0;
	if (argv[argi][0] == '-')
		return 1;
	return 0;
	(void)optstring;
	(void)longopts;
}
