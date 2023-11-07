defmodule TimemanagerWeb.WorkingtimeController do
  use TimemanagerWeb, :controller

  alias Timemanager.Workingtimes
  alias Timemanager.Workingtimes.Workingtime

  action_fallback TimemanagerWeb.FallbackController

  def index(conn,  _params) do
    workingtimes = Workingtimes.list_workingtimes()
    render(conn, :index, workingtimes: workingtimes)
  end

  def showWorkingTimeByUserStartAndEnd(conn,  %{"userID"=> user_id, "end" => enddate, "start" => start}) do
    user_id = String.to_integer(user_id)
    workingtimes = Workingtimes.get_workingtime_by_user_id_and_dates!(user_id, start, enddate)
    render(conn, :index, workingtimes: workingtimes)
  end

  def create(conn, %{"workingtime" => workingtime_params}) do
    with {:ok, %Workingtime{} = workingtime} <- Workingtimes.create_workingtime(workingtime_params) do
      conn
      |> put_status(:created)
      |> put_resp_header("location", ~p"/api/workingtimes/#{workingtime}")
      |> render(:show, workingtime: workingtime)
    end
  end

  def show(conn, %{"id" => id }) do
    id = String.to_integer(id)
    workingtime = Workingtimes.get_workingtime!(id)
    render(conn, :show, workingtime: workingtime)
  end

  def update(conn, %{"id" => id, "workingtime" => workingtime_params}) do
    id = String.to_integer(id)
    workingtime = Workingtimes.get_workingtime!(id)

    with {:ok, %Workingtime{} = workingtime} <- Workingtimes.update_workingtime(workingtime, workingtime_params) do
      render(conn, :show, workingtime: workingtime)
    end
  end

  def delete(conn, %{"id" => id}) do
    workingtime = Workingtimes.get_workingtime!(id)

    with {:ok, %Workingtime{}} <- Workingtimes.delete_workingtime(workingtime) do
      send_resp(conn, :no_content, "")
    end
  end

  def showWorkingtimeByUser(conn, %{"userID" => user_id }) do
    workingtimes =  Workingtimes.get_workingtimes_by_user_id(user_id)

    render(conn, :index, workingtimes: workingtimes)
  end
  def getUserWorkingHours(conn, %{"userID" => user_id}) do
    user_id = String.to_integer(user_id)
    result = Workingtimes.get_working_hours_of_user!(user_id)
    render(conn, %{data: result})
  end

  def getUserWorkingHoursToday(conn, %{"userID" => user_id}) do
    user_id = String.to_integer(user_id)
    result = Workingtimes.get_current_day_working_hours!(user_id)
    render(conn, %{data: result})
  end

  def getUserWorkingHoursThisWeek(conn, %{"userID" => user_id}) do
    user_id = String.to_integer(user_id)
    result = Workingtimes.get_current_week_working_hours_of_user!(user_id)
    render(conn, %{data: result})
  end
end
