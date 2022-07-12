#include "libft.h"

/*
**	Check long options
*/

static int	check_long_opt(char * const argv[], int optindex,
	const struct option *longopts, int *longindex, int *requires_arg)
{
	int	nb_matches = 0;
	int	last_has_arg = -1;
	int	last_val = -1;
	int	i = 0;
	int	res_index = 0;

	if (!longopts)
		return -1;
	//	Search for the current option in the longopts array
	while (1)
	{
		struct option current_opt = longopts[i];
		if (current_opt.name == 0 && current_opt.has_arg == 0
			&& current_opt.flag == 0 && current_opt.val == 0)
			break;
		if (ft_optbegin(current_opt.name, argv[optindex] + 2)
			&& (current_opt.has_arg != last_has_arg
				|| current_opt.val != last_val))
		{
			last_has_arg = current_opt.has_arg;
			last_val = current_opt.val;
			if (longindex != NULL)
				(*longindex) = i;
			res_index = i;
			nb_matches++;
		}
		i++;
	}
	//	More than one match is ambiguous
	if (nb_matches > 1)
	{
		ft_dprintf(STDERR_FILENO, "%s: option '--%s' is ambiguous; possibilities:",
			argv[0], argv[optindex] + 2);
		i = 0;
		//	Print every possible option starting with this
		while (1)
		{
			struct option current_opt = longopts[i];
			if (current_opt.name == 0 && current_opt.has_arg == 0
				&& current_opt.flag == 0 && current_opt.val == 0)
				break;
			if (ft_strbegin(current_opt.name, argv[optindex] + 2))
				ft_dprintf(STDERR_FILENO, " '--%s'", current_opt.name);
			i++;
		}
		ft_dprintf(STDERR_FILENO, "\n");
		return '?';
	}
	//	Only one match, we are good
	else if (nb_matches == 1)
	{
		if (longopts[res_index].has_arg == required_argument)
			*requires_arg = 1;
		if (longopts[res_index].flag == NULL)
			return longopts[res_index].val;
		else
		{
			*(longopts[res_index].flag) = longopts[res_index].val;
			return 0;
		}
	}
	//	Current option is not valid
	ft_dprintf(STDERR_FILENO, "%s: unrecognized option '%s'\n",
		argv[0], argv[optindex]);
	return '?';
}

/*
**	Check if the character belongs to the option string
*/

static int	check_short_opt(char c, const char *optstring, int *requires_arg)
{
	size_t	i = 0;

	while (optstring[i])
	{
		if (optstring[i] != ':' && c == optstring[i])
		{
			//	Option that requires an argument
			if (optstring[i + 1] == ':')
				*requires_arg = 1;
			return c;
		}
		i++;
	}
	//	Character is not an option
	return '?';
}

/*
**	When an option requires an argument, set it according
**	to optindex and nextchar
*/

static int	set_long_optarg(char * const argv[], char **optarg, int optindex, int nextchar)
{
	//	Current argv is not finished: arg is everything 
	//	starting from the next character
	nextchar += 2;
	if (argv[optindex][nextchar] == '=')
		nextchar++;
	if (argv[optindex][nextchar])
	{
		*optarg = argv[optindex] + nextchar;
	}
	//	Arg is in the next argv
	else
	{
		if (argv[optindex + 1] == NULL)
		{
			ft_dprintf(STDERR_FILENO, "%s: option '%s' requires an argument\n",
				argv[0], argv[optindex]);
			return -1;
		}
		*optarg = argv[optindex + 1];
	}
	return 0;
}

/*
**	When an option requires an argument, set it according
**	to optindex and nextchar
*/

static int set_short_optarg(char * const argv[], char **optarg, int optindex, int nextchar)
{
	//	Current argv is not finished: arg is everything 
	//	starting from the next character
	if (argv[optindex][nextchar + 1])
		*optarg = argv[optindex] + nextchar + 1;
	//	Arg is in the next argv
	else
	{
		if (argv[optindex + 1] == NULL)
		{
			ft_dprintf(STDERR_FILENO, "%s: option requires an argument -- '%c'\n",
				argv[0], argv[optindex][nextchar]);
			return -1;
		}
		*optarg = argv[optindex + 1];
	}
	return 0;
}

/*
**	Run through the option line 
*/

static int	parse_option_line(char * const argv[], const char *optstring,
	const struct option *longopts, int *longindex,
	char **optarg, int *optindex, int *nextchar)
{
	int	ret;
	int	requires_arg = 0;

	//	Long option (starting with '--')
	if (ft_strbegin(argv[*optindex], "--"))
	{
		ret = check_long_opt(argv, *optindex, longopts, longindex, &requires_arg);
		//	Valid option
		if (ret != '?')
		{
			if (requires_arg == 1)
			{
				if (set_long_optarg(argv, optarg, *optindex, *nextchar))
					return '?';
			}
			//	Skip to after the option
			else
				(*nextchar) += ft_strlen(argv[*optindex] + 2);
		}
		//	Invalid option
		return ret;
	}
	//	Short option (starting with '-')
	else
	{
		ret = check_short_opt(argv[*optindex][*nextchar], optstring, &requires_arg);
		//	Invalid option
		if (ret == '?')
			ft_dprintf(STDERR_FILENO, "%s: invalid option -- '%c'\n",
				argv[0], argv[*optindex][*nextchar]);
		//	Option that requires an arg
		else if (requires_arg == 1)
		{
			if (set_short_optarg(argv, optarg, *optindex, *nextchar))
				return '?';
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
	int	ret;
	static int	optindex = 1;
	static int	nextchar = 1;

	*optarg = NULL;
	if (optindex == argc)
		return -1;
	//	Search for a '-' or a '--' in argv
	while (optindex < argc)
	{
		if (is_arg_an_option_line(argv[optindex]))
		{
			ret = parse_option_line(argv, optstring, longopts, longindex,
				optarg, &optindex, &nextchar);
			//	Found a valid option
			if (ret != '?')
			{
				//	Next char is the end of the current argv or 
				//	a required arg for an option?
				//	-> Check next argv
				if (argv[optindex][nextchar + 1] == 0 || *optarg != NULL)
				{
					optindex++;
					nextchar = 1;
				}
				else
					nextchar++;
			}
			return ret;
		}
		//	Did not find any option in this argv, keep looking
		else
			optindex++;
	}
	return -1;
}
