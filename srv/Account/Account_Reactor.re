open Account;

let produce = (state, events: list(event), requester) => List.iter(event => {
  switch (state##data, event) {
  | (ActiveAccount({ login }), PasswordConfirmed) => {
      requester("Chat", "AddUser", { "login": login }, ())
    }
  | (_, _) => ()
  }
}, events);
