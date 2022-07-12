#include "libft.h"

static int	check_short_opt(char c, const char *optstring, int *requires_arg)
{
	size_t	i = 0;

	while (optstring[i])
	{
		if (optstring[i] != ':' && c == optstring[i])
		{
			if (optstring[i + 1] == ':')
				*requires_arg = 1;
			return c;
		}
		i++;
	}
	//	Character is not an option
	return '?';
}

static int	parse_option_line(char * const argv[], const char *optstring,
	char **optarg, int optindex, int nextchar)
{
	int	ret;
	int	requires_arg = 0;

	if (ft_strbegin(argv[optindex], "--"))
	{
	}
	else
	{
		ret = check_short_opt(argv[optindex][nextchar], optstring, &requires_arg);
		if (requires_arg == 1)
		{
			if (argv[optindex][nextchar + 1])
				*optarg = argv[optindex] + nextchar + 1;
			else
				*optarg = argv[optindex +1];
		}
		return ret;
	}
	return 0;
}

/*
**	Checks if the given string is an option line (starting with '-')
*/

static inline int	is_arg_an_option_line(char *argv)
{
	return (ft_strlen(argv) > 1 && argv[0] == '-');
}

int		ft_getopt_long(int argc, char * const argv[],
						const char *optstring, char **optarg,
						const struct option *longopts, int *longindex)
{
	(void)longopts;
	(void)longindex;
	(void)optarg;
	int	ret;
	static int	optindex = 1;
	static int	nextchar = 1;

	//ft_printf("Optindex = %d\n", optindex);
	//ft_printf("Next char = %d\n", nextchar);
	if (optindex == argc)
		return -1;
	//ft_printf("next char will be '%c'\n", argv[optindex][nextchar]);
	//	Search for a '-' or a '--' in argv
	while (optindex < argc)
	{
		if (is_arg_an_option_line(argv[optindex]))
		{
			ret = parse_option_line(argv, optstring, optarg, optindex, nextchar);
			//	Found an invalid option
			if (ret == '?')
				return ret;
			//	Found a valid option
			else
			{
				//	Finished parsing the current '-' options
				//	-> check next args
				if (argv[optindex][nextchar + 1] == 0)
				{
					optindex++;
					nextchar = 1;
				}
				else
					nextchar++;
				return ret;
			}
		}
		else
			optindex++;
	}
	return -1;
}
