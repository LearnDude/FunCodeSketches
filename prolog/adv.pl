% The professor tossed the animal with a suddenly grabbed large stone.
% The doctor did not hunt in East Africa and was not attacked by a hippopotamus.
% The colonel’s rhino adventure was not in Central Africa, where one of the hunters chased away an animal with his bare hands.
% The bison attacked one of the hunters in North Africa.
% The fire chief hunted in South Africa.
% The puma was hit in the head by the captain with an empty gun.
% The hunter in West Africa did not have any guns, and he was not the one who fight his attacker with a garment.
% The elephant was not chased away with a stick.

:- use_module(library(clpfd)).

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
    [H1, A1, T1, L1],
    [H2, A2, T2, L2],
    [H3, A3, T3, L3],
    [H4, A4, T4, L4],
    [H5, A5, T5, L5]
    ]) :-
    hunter(H1),
    hunter(H2),
    hunter(H3),
    hunter(H4),
    hunter(H5),
    animal(A1),
    animal(A2),
    animal(A3),
    animal(A4),
    animal(A5),
    tool(T1),
    tool(T2),
    tool(T3),
    tool(T4),
    tool(T5),
    location(L1),
    location(L2),
    location(L3),
    location(L4),
    location(L5),
    no_reuse(H1, H2, H3, H4, H5),
    no_reuse(A1, A2, A3, A4, A5),
    no_reuse(T1, T2, T3, T4, T5),
    no_reuse(L1, L2, L3, L4, L5),
    adventure([H1, A1, T1, L1]),
    adventure([H2, A2, T2, L2]),
    adventure([H3, A3, T3, L3]),
    adventure([H4, A4, T4, L4]),
    adventure([H5, A5, T5, L5]).


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

no_reuse(H1, H2, H3, H4, H5) :-
    H1 \= H2,
    H1 \= H3,
    H1 \= H4,
    H1 \= H5,
    H2 \= H3,
    H2 \= H4,
    H2 \= H5,
    H3 \= H4,
    H3 \= H5,
    H4 \= H5.

% X = [professor, bison, stone, north_africa] ;
% % X = [professor, hippo, stone, west_africa] ;
% % X = [professor, hippo, stone, east_africa] ;
% % X = [professor, elephant, stone, west_africa] ;
% % X = [professor, elephant, stone, east_africa] ;
% % X = [doctor, bison, stick, north_africa] ;
% % X = [doctor, bison, garment, north_africa] ;
% X = [doctor, elephant, hands, central_africa] ;
% X = [colonel, rhino, stick, west_africa] ;
% % X = [colonel, rhino, stick, east_africa] ;
% % X = [colonel, rhino, garment, east_africa] ;
% % X = [fire_chief, hippo, stick, south_africa] ;
% X = [fire_chief, hippo, garment, south_africa] ;
% % X = [fire_chief, elephant, garment, south_africa] ;
% X = [captain, puma, empty_gun, east_africa] ;