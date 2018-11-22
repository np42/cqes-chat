open Account;
open CQES;

let decode = command =>
  switch command##order {
  | "Authenticate" => Authenticate(cAuthenticateFromJs(command##data))
  | "VerifyPassword" => VerifyPassword(cVerifyPasswordFromJs(command##data))
  | _ => NoCommand
  } |> Command.fromJs(command);
