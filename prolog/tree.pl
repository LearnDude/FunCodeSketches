
leaf(Data).
% node(Data, Left, Right) :-
%     ((leaf(Left), Left(LeftData), LeftData #> Data)
%     ;
%     (node(Left, _, _), Left(LeftData, _, _), LeftData #> Data)),
%     ((leaf(Right), Right(RightData), RightData #> Data)
%     ;
%     (node(Right, _, _), Right(RightData, _, _), RightData #> Data)).

% node0(1, 
%     node(6, leaf(7), leaf(8)), 
%     node(11, leaf(12), leaf(13))).
    
node(Data, Left, Right) :-
    node(Left, _, _) ; leaf(Left),
    node(Right, _, _) ; leaf(Right).
