#include "grid_2d.h"
#include "global.h"

void gridInit(Grid *g) {
	g->sizeX = M;
	g->sizeY = N;
	g->time = 0;
	g->maxTime = maxTime;
	g->type = tmZGrid;
	g->cdtds = Sc;
	int m, n;

	g->hx	= new double[M * (N - 1)];
	g->chxh = new double[M * (N - 1)];
	g->chxe = new double[M * (N - 1)];
	g->hy	= new double[(M - 1) * N];
	g->chyh = new double[(M - 1) * N];
	g->chye = new double[(M - 1) * N];
	g->ez	= new double[M    *    N];
	g->ceze = new double[M    *    N];
	g->cezh = new double[M    *    N];
	g->ez_float = new float[M * N];

	//	Set the magnetic-field Hx update coefficients and initialize Hx
	for (m = 0; m < g->sizeY - 1; m++) {
		for (n = 0; n < g->sizeX; n++) {
			int offset = n + m * g->sizeX;
			g->chxh[offset] = 1.0;
			g->chxe[offset] = Sc / imp0;
			g->hx[offset] = 0.0;
		}
	}

	//	Set the magnetic-field Hy update coefficients and initialize Hy
	for (m = 0; m < g->sizeY-1; m++) {
		for (n = 0; n < g->sizeX; n++) {
			int offset = n + m * g->sizeX;
			g->chyh[offset] = 1.0;
			g->chye[offset] = Sc / imp0;
			g->hy[offset] = 0.0;
		}
	}

	// Set electric field and coefficients
	for (m = 0; m < g->sizeY; m++) {
		for (n = 0; n < g->sizeX; n++) {
			int offset = n + m * g->sizeX;
			g->ceze[offset] = 1.0;
			g->cezh[offset] = Sc * imp0;
			g->ez[offset] = 0;
			g->ez_float[offset] = 0;
		}
	}

	/*	Set the electric-field update coefficients	*/
	for (m = 0; m < SizeX; m++){
		for (n = 0; n < SizeY; n++) {
			int check = (double)sqrt((double)((m - SizeX / 2) *(m - SizeX / 2) + (n - SizeY / 2)*(n - SizeY / 2)));
			if (check < r1) {
				Ceze(m, n) = 0;
				Cezh(m, n) = 0;
			}
			else if (check > r2) {
				Ceze(m, n) = 0;
				Cezh(m, n) = 0;
			}
		}
	}
	/*else if (mm >= barpos_x1 && mm <= barpos_x2 && nn >= barpos_y1 && nn <= barpos_y2) {
	Ceze(mm, nn) = 0.7;
	Cezh(mm, nn) = 0;// 130.0 * Cdtds * imp0;
	}*/
	/*else {
	Ceze(mm, nn) = 1.0;
	Cezh(mm, nn) = Cdtds * imp0;
	}
	}
	}*/

}
