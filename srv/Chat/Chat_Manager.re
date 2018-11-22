open Chat;

let empty = () => [];

let handle = (state, command) => {
  switch (command##data, state##data) {
  | (AddUser({ login }), _) => [ UserAdded({ login: login }) ]
  | (_, _) => empty()
  }
};

