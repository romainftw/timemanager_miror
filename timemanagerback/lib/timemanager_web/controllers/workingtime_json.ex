defmodule TimemanagerWeb.WorkingtimeJSON do
  alias Timemanager.Workingtimes.Workingtime

  @doc """
  Renders a list of workingtimes.
  """
  def index(%{workingtimes: workingtimes}) do
    %{data: for(workingtime <- workingtimes, do: data(workingtime))}
  end

  @doc """
  Renders a single workingtime.
  """
  def show(%{workingtime: workingtime}) do
    %{data: data(workingtime)}
  end

  defp data(%Workingtime{} = workingtime) do
    %{
      id: workingtime.id,
      start: workingtime.start,
      end: workingtime.end,

    }
  end
  def render("getUserWorkingHours.json", %{data: result}) do
    %{data: result}
  end


  def render("getUserWorkingHoursToday.json", %{data: result}) do
    %{data: result}
  end
  def render("getUserWorkingHoursThisWeek.json", %{data: result}) do
    %{data: result}
  end

end
