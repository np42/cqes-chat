/* Command */

[@bs.deriving jsConverter]
type cAddUser = { login: string };

type command =
  | NoCommand
  | AddUser(cAddUser)
;

/* Event */

[@bs.deriving jsConverter]
type eUserAdded = { login: string };

type event =
  | NoEvent
  | UserAdded(eUserAdded)
;

/* State */

[@bs.deriving jsConverter]
type sActiveChat = {
  users: array(string)
};

type state =
  | EmptyState
  | ActiveChat(sActiveChat)
;
