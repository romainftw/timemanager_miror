# Timemanager



# Installation

Install postgres, erlang and elixir

CREATE DATABASE 'database name';

mix ecto.migrate

# Environment variables

Install inotify-tools on your machine to read env file.

Add the following variables to a .env file:

`PG_USER` <br />
`PG_PWD` <br />
`PG_DATABASE` <br />


# Run
To start your Phoenix server:

  * Run `mix setup` to install and setup dependencies
  * Start Phoenix endpoint with `mix phx.server` or inside IEx with `iex -S mix phx.server`

Now you can visit [`localhost:4000`](http://localhost:4000) from your browser.

Ready to run in production? Please [check our deployment guides](https://hexdocs.pm/phoenix/deployment.html).

## Learn more

  * Official website: https://www.phoenixframework.org/
  * Guides: https://hexdocs.pm/phoenix/overview.html
  * Docs: https://hexdocs.pm/phoenix
  * Forum: https://elixirforum.com/c/phoenix-forum
  * Source: https://github.com/phoenixframework/phoenix
