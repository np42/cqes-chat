/* Command */
[@bs.deriving jsConverter]
type cAuthenticate = { login: string, password: string };

[@bs.deriving jsConverter]
type cVerifyPassword = { password: string };

type command =
  | NoCommand
  | Authenticate(cAuthenticate)
  | VerifyPassword(cVerifyPassword)
;


/* Event */
[@bs.deriving jsConverter]
type eAccountCreated = { login: string, password: string };

[@bs.deriving jsConverter]
type eUserLogged = { date: Js.Date.t };

[@bs.deriving jsConverter]
type eUserLoginFailed = { date: Js.Date.t };

type event =
  | NoEvent
  | AccountCreated(eAccountCreated)
  | PasswordConfirmed
  | PasswordRejected
  | UserLogged(eUserLogged)
  | UserLoginFailed(eUserLoginFailed)
;

/* State */
[@bs.deriving jsConverter]
type sCreatingAccount = { login: string, password: string };

[@bs.deriving jsConverter]
type sActiveAccount = { login: string, password: string };

type state =
  | EmptyState
  | CreatingAccount(sCreatingAccount)
  | ActiveAccount(sActiveAccount)
;
