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

% State assoc([ key-Value, ...]), Conditions [key-[loValue,hiValue], ...]
% only checks state variables that are in the conditions list
stateCheck( State, []).

stateCheck( State, Conditions) :-
    Conditions = [Key-Interval | Rest],
    get_assoc(Key, State, V),
    Interval = [Lo,Hi],
    write([Key, Lo, Hi, V]),
    V #>= Lo,
    V #=< Hi,
    stateCheck( State, Rest).

tst :-
    list_to_assoc([b-7, a-3, c-55], State),
    Conditions = [a-[0,10], b-[0,10]],
    stateCheck( State, Conditions).
    

% action( assoc PreState, list<pair<symbol,list>> StateUpdates, list PreCond, list PostCond, int Duration, string Name)
action( PreState, [t-500], [t-[0,20], p-[680,720]], [t-[480,520], p-[680,720]], 3, "Heat to 500").
action( PreState, [t-20], [t-[200,600], p-[680,720]], [t-[0,30], p-[680,720]], 3, "Cool to 20").
% action( [T,P], (T #> 450, P #> 650), P #= 3, 4, "Depressurize to 3").

% applyAction( assoc State, list<pair<symbol,list>> PreCond, list<pair<symbol,list>> PostCond, int Time, list<action> Actions, list Sols) :-
applyAction( State, PreCond, PostCond, Time, Actions, Sols) :-
    action( APreState, APostState, APreCond, APostCond, ADuration, AName),
    stateCheck( State, APostCond),
    NewTime #= Time + Duration,
    applyAction( State, PreCond, ActionPreCond, NewTime, [Name | Actions], Sols).

applyAction( PreCond, PreCond, Time, Actions, Sols) :-
    Sols = [Time , Actions].

% updateState( assoc State, list Updates)
updateState( State, Updates) :-


main :-
    bagof([Time, Solution], applyAction(start, end, 0, [], [Time, Solution]), Bag),
    sort(Bag, Sorted),
    write(Sorted).
    