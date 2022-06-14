a.
b.
c.
d.
e.
lst([a,b,c]).
not(isfirst(L,_)) :- L = [].
isfirst(L,x) :- L = [L0|Ls] , x = L0.
isin(L,x) :- L = [L0|Ls] , (x = L0 ; isin(Ls,x)).
