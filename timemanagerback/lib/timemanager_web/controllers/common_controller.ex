defmodule TimemanagerWeb.CommonController do
  use TimemanagerWeb, :controller


  action_fallback TimemanagerWeb.FallbackController

  def options(conn, _params) do
    conn
    |> put_resp_header("access-control-allow-origin", "*")
    |> put_resp_header("access-control-allow-methods", "GET, POST, PUT, DELETE, OPTIONS")
    |> put_resp_header("access-control-allow-headers", "authorization, content-type, accept")
    |> json(%{})
  end

end
