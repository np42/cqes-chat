open Chat;
open CQES;

let decode = command =>
  switch command##order {
  | "AddUser" => AddUser(cAddUserFromJs(command##data))
  | _ => NoCommand
  } |> Command.fromJs(command);
