defmodule Timemanager.Users.RoleCheck do
  import Plug.Conn

  def init(_), do: %{}
  def call(conn,opts) do
    required_role = Map.get(opts, :role)


    case Guardian.Plug.current_resource(conn) do
      nil ->
        conn
        |> put_status(401)
        |> put_resp_content_type("application/json")
        |> send_resp(401,  "Unauthorized")
        |> halt()
      %Timemanager.Users.User{} = user ->
        if has_required_role?(user, required_role) do
          conn
        else
          conn
          |> put_status(403)
          |> put_resp_content_type("application/json")
          |> send_resp(403,  "Unauthorized")
          |> halt()
        end
        {:error, _reason} ->
          conn
          |> Timemanager.Users.ErrorHandler.auth_error({:unauthorized, :no_token_provided}, [])
          |> halt()
    end
  end

  defp has_required_role?(user, required_role) do

    user.role == required_role
  end
end
