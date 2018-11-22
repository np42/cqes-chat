open Chat;

let produce = (state, events: list(event), requester) => List.iter(event => {
  switch (state##data, event) {
  | (ActiveChat(_), UserAdded({ login })) => {
      requester("API", "AddUser", { "login": login }, ())
    }
  | (_, _) => ()
  }
}, events);

