defmodule TodolistWeb.ClockController do
  use TodolistWeb, :controller

  alias Todolist.TimeTracker
  alias Todolist.TimeTracker.Clock

  action_fallback TodolistWeb.FallbackController

  def index(conn, _params) do
    clocks = TimeTracker.list_clocks()
    render(conn, :index, clocks: clocks)
  end

  def create(conn, %{"clock" => clock_params}) do
    with {:ok, %Clock{} = clock} <- TimeTracker.create_clock(clock_params) do
      conn
      |> put_status(:created)
      |> put_resp_header("location", ~p"/api/clocks/#{clock}")
      |> render(:show, clock: clock)
    end
  end

  def show(conn, %{"id" => id}) do
    clock = TimeTracker.get_clock!(id)
    render(conn, :show, clock: clock)
  end

  def update(conn, %{"id" => id, "clock" => clock_params}) do
    clock = TimeTracker.get_clock!(id)

    with {:ok, %Clock{} = clock} <- TimeTracker.update_clock(clock, clock_params) do
      render(conn, :show, clock: clock)
    end
  end

  def delete(conn, %{"id" => id}) do
    clock = TimeTracker.get_clock!(id)

    with {:ok, %Clock{}} <- TimeTracker.delete_clock(clock) do
      send_resp(conn, :no_content, "")
    end
  end
end
