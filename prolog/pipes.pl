:- use_module(library(clpfd)).

pipe(s, a, 5, "sa5").
pipe(s, b, 3, "sb3").
pipe(a, e, 2, "ae2").
pipe(b, e, 1, "be1").
pipe(b, a, 3, "ba3").

buildPipe( From, To, Length, Pipes, Sols) :-
    pipe( PFrom, To, PLength, Name),
    Ln #= Length + PLength,
    buildPipe( From, PFrom, Ln, [Name | Pipes], Sols).

buildPipe( From, From, Length, Pipes, Sols) :-
    Sols = [ Length, Pipes ].