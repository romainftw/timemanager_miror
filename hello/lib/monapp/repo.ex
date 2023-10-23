defmodule Todolist.Repo do
  use Ecto.Repo,
    otp_app: :monapp,
    adapter: Ecto.Adapters.Postgres
end
