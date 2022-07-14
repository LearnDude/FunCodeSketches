a.
b.
c.
d.
e.
lst([a,b,c]).
% not(isfirst(L,_)) :- L = [].
% isfirst(L,x) :- L = [L0|Ls] , x = L0.
% isin(L,x) :- L = [L0|Ls] , (x = L0 ; isin(Ls,x)).


% at(0, L, X) :-
%     L = [L0 | Ls],
%     X = L0.

% at(I, L, X) :- 
%     L = [L0 | Ls],
%     at(I - 1, Ls, X). 

% function to find the element at index I in list L
at(0, [], _) :- write("Index error").
at(0, [L0 | _], X) :- X = L0.
% at(I, L, X) :- L = [_ | Ls], I > 0, In is I - 1 , at(In, Ls, X).
at(I, L, X) :- L = [_ | Ls], I > 0, at(dec(I), Ls, X).

% filter(L,P) :- L = [L0 | Ls], (P(L0) -> filter(Ls,P); filter(Ls,P)).

as --> [].
as --> [a], as.


