open Account;
open CQES;

let decode = state =>
  switch (state##status |> Js.Null_undefined.toOption) {
  | Some("CreatingAccount") => CreatingAccount(sCreatingAccountFromJs(state##data))
  | Some("ActiveAccount") => ActiveAccount(sActiveAccountFromJs(state##data))
  | _ => EmptyState
  } |> State.fromJs(state);

let encode = state =>
  switch state##data {
  | CreatingAccount(data) => State.toJs(state##version, "CreatingAccount", data |> sCreatingAccountToJs)
  | ActiveAccount(data) => State.toJs(state##version, "ActiveAccount", data |> sActiveAccountToJs)
  | _ => State.toJs(state##version, "EmptyState", Js.Null_undefined.null)
  }
;
