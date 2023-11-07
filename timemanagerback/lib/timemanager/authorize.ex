defmodule Timemanager.Authorize do
  import Timemanager.Authorization
  import Phoenix.Controller
  import Plug.Conn

  def init(opts), do: opts

  def call(conn, opts) do
    current_user = Guardian.Plug.current_resource(conn)

    role = case current_user do
      nil -> ""
      _ -> current_user.role
    end
    resource = Keyword.get(opts, :resource)
    action = action_name(conn)

    check(action, role, resource)
    |> maybe_continue(conn)
  end

  defp maybe_continue(true, conn), do: conn

  defp maybe_continue(false, conn) do
    conn
    |> put_status(403)
    |> put_resp_content_type("application/json")
    |> send_resp(403,  "Forbidden")
    |> halt()
  end


  defp check(:index, role, resource) do
    can(role) |> read?(resource)
  end

  defp check(action, role, resource) when action in [:new, :create] do
    can(role) |> create?(resource)
  end
  defp check(action, role, resource) when action in [:edit, :update] do
    can(role) |> update?(resource)
  end
  defp check(:delete, role, resource) do
    can(role) |> delete?(resource)
  end
  defp check(_action, _role, _resource), do: false

end
