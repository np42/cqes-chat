open Account;
open CQES;

let fromJs = event =>
  switch event##kind {
  | "AccountCreated" => AccountCreated(eAccountCreatedFromJs(event##data))
  | "UserLogged" => UserLogged(eUserLoggedFromJs(event##data))
  | "UserLoginFailed" => UserLoginFailed(eUserLoginFailedFromJs(event##data))
  | "PasswordConfirmed" => PasswordConfirmed
  | "PasswordRejected" => PasswordRejected
  | _ => NoEvent
  }
;

let toJs = event =>
  switch event {
  | AccountCreated(data) => eAccountCreatedToJs(data) |> js
  | UserLogged(data) => eUserLoggedToJs(data) |> js
  | UserLoginFailed(data) => eUserLoginFailedToJs(data) |> js
  | PasswordConfirmed => Js.Obj.empty() |> js
  | PasswordRejected => Js.Obj.empty() |> js
  | _ => Js.Obj.empty() |> js
  }
;
