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

adventure([H, A, T, L]) :- hunter(H), tool(T), location(L), animal(A).


% The professor tossed the animal with a suddenly grabbed large stone.
adventure([professor, _, stone, _]).

% The doctor did not hunt in East Africa and was not attacked by a hippopotamus.
\adventure([doctor, _, _, east_africa]).
\adventure([doctor, hippo, _, _]).

% The colonel’s rhino adventure was not in Central Africa, where one of the hunters chased away an animal with his bare hands.
adventure( [colonel, rhino, _, _] ).
\adventure([colonel, _, _, central_africa]).
\adventure([_, _, rhino, central_africa]).
\adventure([_, _, hands, central_africa]).

% The bison attacked one of the hunters in North Africa.
adventure( [bison, _, _, north_africa] ).

% The fire chief hunted in South Africa.
adventure( [fire_chief, _, _, south_africa] ).

% The puma was hit in the head by the captain with an empty gun.
adventure( [captain, puma, empty_gun, _] ).

% The hunter in West Africa did not have any guns, and he was not the one who fight his attacker with a garment.
\adventure( [_, _, empty_gun, west_africa] ).
\adventure([_, _, garment, west_africa]).

% The elephant was not chased away with a stick.
\adventure([_, elephant, stick, _]).

