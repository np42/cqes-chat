open Chat;
open CQES;

let apply = (state, events: list(event)) => List.fold_left((state, event) => {
  switch (event, state##data) {
  | (UserAdded({ login }), EmptyState) =>
    ActiveChat({ users: [| login |] })
  | (UserAdded({ login }), ActiveChat({ users })) =>
    ActiveChat({ users: Js.Array.concat(users, [| login |]) })
  | (_, state) => state
  } |> State.next(state)
}, state, events);
