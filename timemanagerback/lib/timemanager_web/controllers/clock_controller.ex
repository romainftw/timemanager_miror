defmodule TimemanagerWeb.ClockController do
  use TimemanagerWeb, :controller
  import NaiveDateTime
  import Calendar

  alias Timemanager.Clocks
  alias Timemanager.Clocks.Clock

  alias Timemanager.Workingtimes
  alias Timemanager.Workingtimes.Workingtime

  plug Timemanager.Authorize, resource: Timemanager.Clocks.Clock

  action_fallback TimemanagerWeb.FallbackController

  def create(conn, %{"clock" => clock_params}) do
    currentTime = NaiveDateTime.local_now()
    userWorkingTimes = Workingtimes.current_user_workingtime!(clock_params["user_id"])

    if length(userWorkingTimes) == 0 do
      newClock = %{"time" => currentTime, "user_id" => clock_params["user_id"], "status" => false}
      with {:ok, %Clock{} = clock} <- Clocks.create_clock(newClock) do
        conn
        |> put_status(:created)
        |> put_resp_header("location", ~p"/api/clocks/#{clock}")
        |> render(:show, clock: clock)
      end
    else
      newClock = %{"time" => currentTime, "user_id" => clock_params["user_id"], "status" => true}
      with {:ok, %Clock{} = clock} <- Clocks.create_clock(newClock) do
        conn
        |> put_status(:created)
        |> put_resp_header("location", ~p"/api/clocks/#{clock}")
        |> render(:show, clock: clock)
      end
    end

  end

  # def show(conn, %{"id" => id}) do
  #   clock = Clocks.get_clock!(id)
  #   render(conn, :show, clock: clock)
  # end
  def show(conn, %{"id" => id}) do
    case Clocks.get_clock!(id) do
      clock when clock != nil ->
        render(conn, :show, clock: clock)
      nil ->
        conn
        |> put_status(404)
        |> put_resp_content_type("application/json")
        |> json(%{error: "Not found"})
    end
  end


end
