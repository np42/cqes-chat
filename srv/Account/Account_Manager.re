open Account;

let empty = () => [];

let handle = (state, command) => {
  switch (command##data, state##data) {
  | (Authenticate(data), EmptyState) =>
      [ AccountCreated({ login: data.login, password: data.password }) ]

  | (Authenticate(data), ActiveAccount({ password })) =>
    if (password == data.password) [ UserLogged({ date: Js.Date.make() }) ]
    else [ UserLoginFailed({ date: Js.Date.make() }) ]

  | (VerifyPassword(data), CreatingAccount({ password })) =>
    if (password == data.password) [ PasswordConfirmed ]
    else [ PasswordRejected ]

  | (_, _) => empty()
  }
}
