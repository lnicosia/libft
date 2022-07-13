#include "libft.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int opt;
	int	digit_optind = 0;
	int	option_index = 0;
	char *ft_optarg = NULL;
	char *optstring = "hvVt:4";

	static struct option long_options[] =
	{
		{"help",	no_argument,		0, 0},
		{"verbose",	no_argument,		0, 'v'},
		{"version",	no_argument,		0, 'V'},
		{"ttl",		required_argument,	0, 0},
		{"optional",optional_argument,  0, 0},
		{0,			0,			 		0, 0}
	};
	printf("\n--FT_GETOPT--\n");
	while ((opt = ft_getopt_long(ac, av, optstring, &ft_optarg,
		long_options, &option_index)) != -1)
	{
		switch (opt)
		{
			case 0:
				printf("Long option '%s'", long_options[option_index].name);
				if (ft_optarg)
					printf(" with value = '%s'", ft_optarg);
				printf("\n");
				break;
			case 'h':
				printf("-h\n");
				break;
			case 'v':
				printf("-v\n");
				break;
			case 'V':
				printf("-V\n");
				break;
			case 't':
				printf("-t with value = '%s'\n", ft_optarg);
				break;
			case '?':
				dprintf(STDERR_FILENO, "'?'\n");
				dprintf(STDERR_FILENO, "long_index = %d\n", option_index);
				opt = -1;
				break;
			case -1:
				printf("End of options\n");
				break;
			default:
				printf("?? ft_getopt returned character code 0%o ??\n", opt);
				opt = -1;
				break;
		}
		if (opt == -1)
			break;
	}
	printf("\n--GETOPT--\n");
	while ((opt = getopt_long(ac, av, optstring,
		long_options, &option_index)) != -1)
	{
		switch (opt)
		{
			case 0:
				printf("Long option '%s'", long_options[option_index].name);
				if (optarg)
					printf(" with value = '%s'", optarg);
				printf("\n");
				break;
			case 'h':
				printf("-h\n");
				break;
			case 'v':
				printf("-v\n");
				break;
			case 'V':
				printf("-V\n");
				break;
			case 't':
				printf("-t with value = '%s'\n", optarg);
				break;
			case '?':
				dprintf(STDERR_FILENO, "'?'\n");
				dprintf(STDERR_FILENO, "long_index = %d\n", option_index);
				opt = -1;
				break;
			case -1:
				printf("End of options\n");
				break;
			default:
				printf("?? ft_getopt returned character code 0%o ??\n", opt);
				opt = -1;
				break;
		}
		if (opt == -1)
			break;
	}
	return 0;
}
