open Account;
open CQES;

let resolve = (command, state, events) => List.fold_left((response, event) => {
  switch (event, state##data, command##data) {
  | (AccountCreated(_), _, _) =>
    { "message": "Creating Account Accepted" } |> Reply.toJs(`Resolved)
  | (PasswordConfirmed, ActiveAccount(_), _) =>
    { "message": "Account Verified" } |> Reply.toJs(`Resolved)
  | (PasswordRejected, EmptyState, _) =>
    { "message": "Account Destroyed" } |> Reply.toJs(`Rejected)
  | (UserLogged(_), ActiveAccount(_), _) =>
    { "message": "User logged in" } |> Reply.toJs(`Resolved)
  | (UserLoginFailed(_), ActiveAccount(_), _) =>
    { "message": "Bad password" } |> Reply.toJs(`Rejected)
  | (_, _, _) => response
  }
}, Reply.toJs(`Resolved, Js.Obj.empty()), events);
