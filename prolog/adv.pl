% The professor tossed the animal with a suddenly grabbed large stone.
% The doctor did not hunt in East Africa and was not attacked by a hippopotamus.
% The colonel’s rhino adventure was not in Central Africa, where one of the hunters chased away an animal with his bare hands.
% The bison attacked one of the hunters in North Africa.
% The fire chief hunted in South Africa.
% The puma was hit in the head by the captain with an empty gun.
% The hunter in West Africa did not have any guns, and he was not the one who fight his attacker with a garment.
% The elephant was not chased away with a stick.

hunter(professor).
hunter(doctor).
hunter(colonel).
hunter(fire_chief).
hunter(captain).
animal(rhino).
animal(bison).
animal(puma).
animal(hippo).
animal(elephant).
tool(stick).
tool(empty_gun).
tool(garment).
tool(hands).
tool(stone).
location(north_africa).
location(central_africa).
location(south_africa).
location(west_africa).
location(east_africa).

adventure([H, A, T, L]) :-
    hunter(H),
    animal(A),
    tool(T),
    location(L),
    not( invalid([H, A, T, L]) ),
    iff( H = professor, T = stone),
    iff( H = colonel, A = rhino),
    iff( H = fire_chief, L = south_africa),
    iff( A = bison, L = north_africa),
    iff( T = hands, L = central_africa),
    iff( H = captain, A = puma),
    iff( H = captain, T = empty_gun).


all_adventures([
    [A1, T1, L1],
    [A2, T2, L2],
    [A3, T3, L3],
    [A4, T4, L4],
    [A5, T5, L5]
    ]) :-
    adventure([professor, A1, T1, L1]),
    adventure([doctor, A2, T2, L2]),
    adventure([colonel, A3, T3, L3]),
    adventure([fire_chief, A4, T4, L4]),
    adventure([captain, A5, T5, L5]),
    
    all_different_atoms([A1, A2, A3, A4, A5]),
    all_different_atoms([T1, T2, T3, T4, T5]),
    all_different_atoms([L1, L2, L3, L4, L5]).


invalid_list([
    [doctor, _, _, east_africa],
    [doctor, hippo, _, _],
    [colonel, _, _, central_africa],
    [_, rhino, _, central_africa],
    [_, _, empty_gun, west_africa],
    [_, _, garment, west_africa],
    [_, elephant, stick, _]
]).
invalid(A) :- invalid_list(LL), member(A, LL).

iff(A, B) :- A , B ; not(A) , not(B).

all_different_atoms(X):- \+((select(M,X,Y), member(M,Y))).
