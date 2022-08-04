:- use_module(library(clpfd)).

% action(start, a, 5, "sa5").
% action(start, b, 3, "sb3").
% action(a, end, 2, "ae2").
% action(b, end, 1, "be1").
% action(b, a, 3, "ba3").

start([T,P]) :-
    T #= 20,
    P #= 700.

end([T,P]) :-
    T #= 500,
    P #= 3.

state([T,P]).

action( [T,P], (T #< 50 , P #> 650), T #= 500, 3, "Heat to 500").
action( [T,P], (T #> 450, P #> 650), P #= 3, 4, "Depressurize to 3").

applyAction( State, PreCond, PostCond, Time, Actions, Sols) :-
    State = [T,P],
    PreCond,
    action( State, ActionPreCond, PostCond, Duration, Name),
    NewTime #= Time + Duration,
    applyAction( State, PreCond, ActionPreCond, NewTime, [Name | Actions], Sols).

applyAction( PreCond, PreCond, Time, Actions, Sols) :-
    Sols = [Time , Actions].

main :-
    bagof([Time, Solution], applyAction(start, end, 0, [], [Time, Solution]), Bag),
    sort(Bag, Sorted),
    write(Sorted).
    