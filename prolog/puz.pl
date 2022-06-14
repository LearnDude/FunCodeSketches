ltr(a).
ltr(b).
ltr(c).
num(one).
num(two).
num(three).

invalid_list([[b,_],[a,one]]).
invalid(E) :- 
    invalid_list(LL),
    member(E, LL).

required_list([[_,two]]).
required(E) :- 
    required_list(LL),
    member(E, LL).

combo([L,N]) :-
    ltr(L),
    num(N),
    not(invalid([L,N])),
    required([L,N]).
