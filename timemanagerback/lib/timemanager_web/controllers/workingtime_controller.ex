defmodule TimemanagerWeb.WorkingtimeController do
  use TimemanagerWeb, :controller

  alias Timemanager.Workingtimes
  alias Timemanager.Workingtimes.Workingtime

  action_fallback TimemanagerWeb.FallbackController

  def index(conn,  %{"userID"=> user_id, "end" => enddate, "start" => start}) do

    workingtimes = Workingtimes.get_workingtime_by_user_id_and_dates!(user_id,start,enddate)
    

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
    workingtime = Workingtimes.get_workingtime!(id)
    render(conn, :show, workingtime: workingtime)
  end

  def update(conn, %{"id" => id, "workingtime" => workingtime_params}) do
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

  def showWorkingtimeByUser(conn, %{"userID" => user_id, "id"=> id }) do
    workingtime = Workingtimes.get_workingtime_by_user_id!(user_id,id)
    render(conn, :show, workingtime: workingtime)
  end

end
