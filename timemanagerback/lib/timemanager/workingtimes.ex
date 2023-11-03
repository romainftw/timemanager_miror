defmodule Timemanager.Workingtimes do
  @moduledoc """
  The Workingtimes context.
  """

  import Ecto.Query, warn: false

  alias Timemanager.Repo

  alias Timemanager.Workingtimes.Workingtime

  @doc """
  Returns the list of workingtimes.

  ## Examples

      iex> list_workingtimes()
      [%Workingtime{}, ...]

  """
 # def list_workingtimes do
    #Repo.all(Workingtime)
  #end
  def list_workingtimes do
    # from(wt in Workingtime, select: wt)
    # query = from wt in "workingtimes",
    # select:  %{id: wt.id, start: wt.start, end: wt.end}
    Repo.all(Workingtime)
  end

  @doc """
  Gets a single workingtime.

  Raises `Ecto.NoResultsError` if the Workingtime does not exist.

  ## Examples

      iex> get_workingtime!(123)
      %Workingtime{}

      iex> get_workingtime!(456)
      ** (Ecto.NoResultsError)

  """
  #def get_workingtime!(id), do: Repo.get!(Workingtime, id)
  def get_workingtime!(id) do
    Repo.get!(Workingtime, id)
  end

  # /récupérer les horaire de travail du mois courant
  def get_working_hours_of_user!(user_id) do

    start_date = DateTime.utc_now() |> DateTime.to_naive() |> Timex.beginning_of_month()
    end_date = DateTime.utc_now() |> DateTime.to_naive() |> Timex.end_of_month()

    query =
      from wt in "workingtimes",
      where: wt.user_id == ^user_id and
            wt.start >= ^start_date and
            wt.start <= ^end_date,
      select: %{
        date: fragment("date_trunc('day', ?)", wt.start),
        total_hours: fragment("SUM(EXTRACT(EPOCH FROM (? - ?))/ 3600 )", wt.end, wt.start)
      },
      group_by: fragment("date_trunc('day', ?)", wt.start)

    Repo.all(query)
  end
  # /récupérer les horaire de travail du mois courant
  def get_current_week_working_hours_of_user!(user_id) do

    start_date = DateTime.utc_now() |> DateTime.to_naive() |> Timex.beginning_of_week()
    end_date = DateTime.utc_now() |> DateTime.to_naive() |> Timex.end_of_week()

    query =
      from wt in "workingtimes",
      where: wt.user_id == ^user_id and
            wt.start >= ^start_date and
            wt.start <= ^end_date,
      select: %{
        date: fragment("date_trunc('day', ?)", wt.start),
        total_hours: fragment("SUM(EXTRACT(EPOCH FROM (? - ?))/ 3600 )", wt.end, wt.start)
      },
      group_by: fragment("date_trunc('day', ?)", wt.start)

    Repo.all(query)
  end
  # récupérer les horaire de tavail de du jour courant
  def get_current_day_working_hours!(user_id) do
    start_of_day = DateTime.utc_now() |> DateTime.to_naive() |> Timex.beginning_of_day()
    end_of_day =  DateTime.utc_now() |> DateTime.to_naive() |> Timex.end_of_day()

    query = from wt in "workingtimes",
    where: wt.user_id == ^user_id and wt.start >= ^start_of_day and wt.end < ^end_of_day,
    select: fragment("SUM(EXTRACT(EPOCH FROM (? - ?)) /3600)", wt.end, wt.start)
    Repo.all(query)
  end

  def get_working_time!(params), do: Repo.get_by!(Workingtime, params)

  def get_workingtime_by_user_id_and_dates!(user_id,start,enddate) do
    start_date =
      Ecto.DateTime.cast!(start, Ecto.DateTime)
      |> Ecto.DateTime.to_naive()

    end_date =
      Ecto.DateTime.cast!(enddate, Ecto.DateTime)
      |> Ecto.DateTime.to_naive()
    query =
      from wt in "workingtimes",
      where: wt.user_id == ^user_id and wt.start >= ^startdate and wt.end <= ^enddate,
      select:  %{id: wt.id, start: wt.start, end: wt.end}

    Repo.all(query)
  end


  def current_user_workingtime!(user_id) do
    naive_datetime = NaiveDateTime.local_now()

    query =
      from wt in "workingtimes",
      where: wt.user_id == ^user_id and wt.start <= ^naive_datetime and wt.end >= ^naive_datetime,
      select:  %{id: wt.id, start: wt.start, end: wt.end}

    Repo.all(query)
  end

  def get_workingtime_by_user_id!(user_id) do
    parsed_user_id = String.to_integer(user_id)
    query =
      from wt in "workingtimes",
      where: wt.user_id == ^parsed_user_id ,
      select:  %{id: wt.id, start: wt.start, end: wt.end}

    Repo.all(query)
  end

  def get_workingtimes_by_user_id(user_id) do
    from(w in Workingtime, where: w.user_id == ^user_id) |> Repo.all()
  end

  @doc """
  Creates a workingtime.

  ## Examples

      iex> create_workingtime(%{field: value})
      {:ok, %Workingtime{}}

      iex> create_workingtime(%{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def create_workingtime(attrs \\ %{}) do
    %Workingtime{}
    |> Workingtime.changeset(attrs)
    |> Repo.insert()
  end

  @doc """
  Updates a workingtime.

  ## Examples

      iex> update_workingtime(workingtime, %{field: new_value})
      {:ok, %Workingtime{}}

      iex> update_workingtime(workingtime, %{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def update_workingtime(%Workingtime{} = workingtime, attrs) do
    workingtime
    |> Workingtime.changeset(attrs)
    |> Repo.update()
  end

  @doc """
  Deletes a workingtime.

  ## Examples

      iex> delete_workingtime(workingtime)
      {:ok, %Workingtime{}}

      iex> delete_workingtime(workingtime)
      {:error, %Ecto.Changeset{}}

  """
  def delete_workingtime(%Workingtime{} = workingtime) do
    Repo.delete(workingtime)
  end

  @doc """
  Returns an `%Ecto.Changeset{}` for tracking workingtime changes.

  ## Examples

      iex> change_workingtime(workingtime)
      %Ecto.Changeset{data: %Workingtime{}}

  """
  def change_workingtime(%Workingtime{} = workingtime, attrs \\ %{}) do
    Workingtime.changeset(workingtime, attrs)
  end
end
