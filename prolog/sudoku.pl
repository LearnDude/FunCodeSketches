cell(a1).
cell(a2).
cell(a3).
cell(a4).
cell(a5).
cell(a6).
cell(a7).
cell(a8).
cell(a9).
cell(b1).
cell(b2).
cell(b3).
cell(b4).
cell(b5).
cell(b6).
cell(b7).
cell(b8).
cell(b9).
cell(c1).
cell(c2).
cell(c3).
cell(c4).
cell(c5).
cell(c6).
cell(c7).
cell(c8).
cell(c9).
cell(c1).
cell(c2).
cell(c3).
cell(c4).
cell(c5).
cell(c6).
cell(c7).
cell(c8).
cell(c9).
cell(d1).
cell(d2).
cell(d3).
cell(d4).
cell(d5).
cell(d6).
cell(d7).
cell(d8).
cell(d9).
cell(e1).
cell(e2).
cell(e3).
cell(e4).
cell(e5).
cell(e6).
cell(e7).
cell(e8).
cell(e9).
cell(f1).
cell(f2).
cell(f3).
cell(f4).
cell(f5).
cell(f6).
cell(f7).
cell(f8).
cell(f9).
cell(g1).
cell(g2).
cell(g3).
cell(g4).
cell(g5).
cell(g6).
cell(g7).
cell(g8).
cell(g9).
cell(h1).
cell(h2).
cell(h3).
cell(h4).
cell(h5).
cell(h6).
cell(h7).
cell(h8).
cell(h9).
cell(i1).
cell(i2).
cell(i3).
cell(i4).
cell(i5).
cell(i6).
cell(i7).
cell(i8).
cell(i9).

solve_sudoku()


all_different_atoms(X):- \+((select(M,X,Y), member(M,Y))).