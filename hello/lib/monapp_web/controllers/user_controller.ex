defmodule TodolistWeb.PostController do
  use TodolistWeb, :controller

  def index(conn, _params) do
    posts = Todolist.Repo.all(Todolist.Post)
    if posts do
      conn
      |> put_status(:ok)
    end
  end

  def show(conn, %{"id" => id}) do

    post = Todolist.Repo.get(Post, id)
    if post do
      conn
      |> put_status(:ok)
    else
      conn
      |> put_status(404)
    end

  end
end
