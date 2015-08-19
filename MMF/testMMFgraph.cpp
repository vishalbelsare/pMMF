/* 
    pMMF is an open source software library for efficiently computing
    the MMF factorization of large matrices.

    Copyright (C) 2015 Risi Kondor, Nedelina Teneva, Pramod Mudrakarta
    
    This file is part of pMMF.

    pMMF is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



#include "Log.hpp"
#include "MMF.hpp"

#include "MatrixX.hpp"
#include "MMFglobal.hpp"

typedef Cmatrix BLOCK;

int main(int argc, char** argv) {

	int n = 10;
	if (argc >= 2)
		sscanf(argv[1], "%d", &n);
	int nclusters = 1;
	if (argc >= 3)
		sscanf(argv[2], "%d", &nclusters);

	MMFmatrix<BLOCK> A(n, Random());
	cout << A << endl;

	mlog.verbosity = 0;
	MMF mmf(A,
			MMFparams::k(2).ndensestages(2).nsparsestages(2).nclusters(
					nclusters));

	Rstream s(cout);
	mmf.graph(s);
}
