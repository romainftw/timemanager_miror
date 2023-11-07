defmodule TimemanagerWeb.AuthenticationController do
  use TimemanagerWeb, :controller
  alias Timemanager.Users
  alias Timemanager.Users.User
  alias TimemanagerWeb.Users.Guardian

  def login(conn, %{"email" => email, "password" => password}) do
    case Guardian.authenticate(email, password) do
      {:ok, user, token} ->
        conn
        |> put_status(:ok)
        |> json(%{user: user, token: token})
      {:error, :unauthorized} ->
        conn
        |> put_status(:unauthorized)
        |> json(%{error: "Unauthorized"})
      _ ->
        conn
        |> put_status(:internal_server_error)
        |> json(%{error: "Internal Server Error"})
    end
  end

end
