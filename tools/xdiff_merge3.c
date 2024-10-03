

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include "xdiff.h"
#include "xtestutils.h"



static int xdlt_outf(void *priv, mmbuffer_t *mb, int nbuf) {
	int i;
        if ( priv == stdout )
          puts("stdout:");
        if ( priv == stderr )
          puts("stderr:");

	for (i = 0; i < nbuf; i++)
		if (!fwrite(mb[i].ptr, mb[i].size, 1, (FILE *) priv))
			return -1;

	return 0;
}

int main(int argc, char *argv[]) {
	mmfile_t mfo, mf1, mf2;
	xdemitcb_t ecb, rjecb;

        ecb.priv = stdout;
        ecb.outf = xdlt_outf;
        rjecb.priv = stderr;
        rjecb.outf = xdlt_outf;

	if (argc < 4) {
		printf("%s mfo mf1 mf2\n", argv[0]);
		return 1;
	}
        
	if (xdlt_load_mmfile(argv[1], &mfo, 0) < 0) {
          perror(argv[1]);
          return 1;
        }
	if (xdlt_load_mmfile(argv[2], &mf1, 0) < 0) {
          perror(argv[1]);
          return 1;
        }
	if (xdlt_load_mmfile(argv[3], &mf2, 0) < 0) {
          perror(argv[1]);
          return 1;
        }
  
}
