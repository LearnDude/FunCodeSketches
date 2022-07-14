:- use_module(library(clpfd)).


ch(a).
ch(b).
ch(c).
ch(d).

test([X,Y,Z]) :-
    ch(X),
    ch(Y),
    ch(Z),
    X \= Y,
    X \= Z,
    Y \= Z.

test2([X,Y,Z]) :-
    ch(X),
    ch(Y),
    ch(Z),
   all_different([X,Y,Z]).
   