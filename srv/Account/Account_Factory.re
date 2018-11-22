open Account;
open CQES;

let apply = (state, events: list(event)) => List.fold_left((state, event) => {
  switch (event, state##data) {
  | (AccountCreated(data), EmptyState) =>
    CreatingAccount({ login: data.login, password: data.password })

  | (PasswordConfirmed, CreatingAccount({ login, password })) =>
    ActiveAccount({ login, password })

  | (_, ActiveAccount(_) as state) => state
  | (_, _) => EmptyState
  } |> State.next(state)
}, state, events);
