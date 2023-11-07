defmodule TimemanagerWeb.ClockController do
  use TimemanagerWeb, :controller
  import NaiveDateTime
  import Calendar

  alias Timemanager.Clocks
  alias Timemanager.Clocks.Clock

  alias Timemanager.Workingtimes
  alias Timemanager.Workingtimes.Workingtime

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

  def show(conn, %{"id" => id}) do
    clock = Clocks.get_clock!(id)
    render(conn, :show, clock: clock)
  end


end
