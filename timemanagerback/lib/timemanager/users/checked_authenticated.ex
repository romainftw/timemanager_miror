defmodule Timemanager.Users.CheckAuthenticated do
  import Plug.Conn

  def init(opts), do: opts

  def call(conn, opts) do
    role = Keyword.get(opts, :role)
    IO.inspect(role)
    case Guardian.Plug.current_resource(conn) do
      nil ->
        conn
        |> put_status(401)
        |> put_resp_content_type("application/json")
        |> send_resp(401,  "Unauthorized")
        |> halt()
       %Timemanager.Users.User{} = user ->
        conn
      {:error, _reason} ->
        conn
        |> Timemanager.Users.ErrorHandler.auth_error({:unauthorized, :no_token_provided}, [])
        |> halt()
    end
  end
end
