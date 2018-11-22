open Chat;
open CQES;

let decode = state =>
  switch (state##status |> Js.Null_undefined.toOption) {
  | Some("ActiveChat") => ActiveChat(sActiveChatFromJs(state##data))
  | _ => EmptyState
  } |> State.fromJs(state);

let encode = state =>
  switch state##data {
  | ActiveChat(data) => State.toJs(state##version, "ActiveChat", data |> sActiveChatToJs)
  | _ => State.toJs(state##version, "EmptyState", Js.Null_undefined.null)
  }
;
