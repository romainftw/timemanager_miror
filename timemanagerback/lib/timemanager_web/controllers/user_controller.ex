defmodule TimemanagerWeb.UserController do
  use TimemanagerWeb, :controller

  @derive {Jason.Encoder, only: [:id, :username, :email, :inserted_at, :updated_at]}
  alias Timemanager.Users
  alias Timemanager.Users.User

  action_fallback TimemanagerWeb.FallbackController

  def options(conn, _params) do
    conn
    |> put_resp_header("access-control-allow-origin", "*")
    |> put_resp_header("access-control-allow-methods", "GET, POST, PUT, DELETE, OPTIONS")
    |> put_resp_header("access-control-allow-headers", "authorization, content-type, accept")
    |> json(%{})
  end

  def user(conn, %{"email" => email, "username" => username}) do # create
     user = Users.get_user_by_username!(username: username, email: email)
     #query = Timemanager.User |> Ecto.Query.where(email: email)
     render(conn, :show, user: user)
   end
  def index(conn, _params) do
    users = Users.list_users()
    render(conn, :index, users: users)
  end

  def create(conn, %{"user" => user_params}) do
    with {:ok, %User{} = user} <- Users.create_user(user_params) do
     conn
      |> put_status(:created)
      |> put_resp_header("location", ~p"/api/users/#{user}")
      |> render("show.json", user: user)

    end

  end

  def show(conn, %{"id" => id}) do
    user = Users.get_user!(id)
    render(conn, :show, user: user)
  end

  def update(conn, %{"id" => id, "user" => user_params}) do
    user = Users.get_user!(id)

    with {:ok, %User{} = user} <- Users.update_user(user, user_params) do
      render(conn, :show, user: user)
    end
  end

  def delete(conn, %{"id" => id}) do
    user = Users.get_user!(id)

    with {:ok, %User{}} <- Users.delete_user(user) do
      send_resp(conn, :no_content, "")
    end
  end
end
