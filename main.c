#include <libcmmk/libcmmk.h>

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h> /* usleep() */
#include <signal.h>
#include <time.h> /* do we need this? */
#endif

#include <string.h> /* memset() */
#include <stdio.h>
#include <stdlib.h>


int all(struct cmmk *dev, struct rgb color) {
	cmmk_set_all_single(dev, &color);
	return 0;
}

int single(struct cmmk *dev, int row, int col, struct rgb color)
{
    cmmk_set_single_key(dev, row, col, &color);
	return 0;
}

struct rgb get_color(int r, int g, int b) {
	struct rgb colorobj = MKRGBS(r, g, b);
	return colorobj;
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	struct cmmk state;

	int product;
    int row, col;
	struct rgb color;

	if (cmmk_find_device(&product) != 0) {
		printf("No product found\n");
		return 1;
	}

	if (cmmk_attach(&state, product, -1) != 0) {
		printf("Unable to attach to product\n");
		return 1;
	}

    char* command = argv[1];

    if (strcmp(command, "reset") == 0) {
        cmmk_set_control_mode(&state, CMMK_FIRMWARE);
    } else if (strcmp(command, "manual") == 0) {
        cmmk_set_control_mode(&state, CMMK_MANUAL);
    } else if (strcmp(command, "single") == 0) {
        row = atoi(argv[2]);
        col = atoi(argv[3]);
		color = get_color(
			atoi(argv[4]),
			atoi(argv[5]),
			atoi(argv[6])
		);
        single(&state, row, col, color);
	} else if (strcmp(command, "all") == 0) {
		color = get_color(
			atoi(argv[2]),
			atoi(argv[3]),
			atoi(argv[4])
		);
		all(&state, color);
    } else {
        printf("Not a valid command: %s\n", command);
    }

	cmmk_detach(&state);

	return 0;
}
